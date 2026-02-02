CREATE OR REPLACE FUNCTION sp_rulelb_match_mccy (
   in_channel_code         rule_psp_lb_criteria.rc_channel_code%TYPE,
   in_service_code         rule_psp_lb_criteria.rc_service_code%TYPE,
   in_country              rule_psp_lb_criteria.rc_country%TYPE,
   in_ccy                  rule_psp_lb_criteria.rc_ccy%TYPE,
   in_merchant_id          rule_psp_lb_criteria.rc_party_id%TYPE,
   in_card_type		   rule_psp_lb_criteria.rc_card_type_opt%TYPE,
   in_restricted_ip	   rule_psp_lb_criteria.rc_allow_special_region%TYPE,
   in_amount		   rule_psp_lb_criteria.RC_MAX_TRANSACTION_AMOUNT%TYPE,
   out_cursor          OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
   iCnt   INTEGER := 0;
BEGIN
   SELECT COUNT (*)
     INTO iCnt
     FROM rule_psp_lb_criteria,
         (SELECT business_type,
                 merchant_id
          FROM merch_detail, clients
          WHERE     merchant_id = in_merchant_id
          AND disabled = 0
          AND merch_detail.status = 'O'
          AND merch_detail.client_id = clients.client_id
          AND clients.status = 'O')
   WHERE     RULE_SCHEDULE_PKG.InRunningPeriod (rc_scheduler_id) = 1
         AND rc_disabled = 0
         AND rc_party_id = in_merchant_id
         AND rc_party_id = merchant_id
         AND rc_business_type = business_type
         AND rc_ccy = in_ccy
         AND rc_channel_code = in_channel_code
         AND rc_service_code = in_service_code
         AND rc_country = in_country
         AND rc_card_type_opt = in_card_type
	 AND rc_allow_special_region = in_restricted_ip
         AND rc_customer_segment IS NULL
         AND (    RC_MIN_TRANSACTION_AMOUNT <= in_amount
              AND (   RC_MAX_TRANSACTION_AMOUNT = 0
                   OR RC_MAX_TRANSACTION_AMOUNT >= in_amount)); 

   IF iCnt > 0
   THEN
      OPEN out_cursor FOR
           SELECT rc_min_transaction_amount,
                  rc_max_transaction_amount,
                  rc_criteria_pool_id,
                  rc_scheduler_id,
                  rc_priority
	   FROM rule_psp_lb_criteria,
		(select Round(DBMS_RANDOM.Value(1, 9)) num from dual),
		(SELECT business_type,
                 	merchant_id
          	FROM merch_detail, clients
          	WHERE     merchant_id = in_merchant_id
          	AND disabled = 0
          	AND merch_detail.status = 'O'
          	AND merch_detail.client_id = clients.client_id
          	AND clients.status = 'O')
   	   WHERE     RULE_SCHEDULE_PKG.InRunningPeriod (rc_scheduler_id) = 1
	   AND rc_disabled = 0
	   AND rc_party_id = in_merchant_id
	   AND rc_party_id = merchant_id
	   AND rc_business_type = business_type
	   AND rc_ccy = in_ccy
	   AND rc_channel_code = in_channel_code
	   AND rc_service_code = in_service_code
	   AND rc_country = in_country
	   AND rc_card_type_opt = in_card_type
	   AND rc_allow_special_region = in_restricted_ip
	   AND rc_customer_segment IS NULL
	   AND (    RC_MIN_TRANSACTION_AMOUNT <= in_amount
              AND (   RC_MAX_TRANSACTION_AMOUNT = 0
                   OR RC_MAX_TRANSACTION_AMOUNT >= in_amount)) 
	   ORDER BY rc_priority DESC, num;

      RETURN 1;

   END IF;

   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 0;
END sp_rulelb_match_mccy;
/
