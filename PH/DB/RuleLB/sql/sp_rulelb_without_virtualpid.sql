CREATE OR REPLACE FUNCTION sp_rulelb_without_virtualpid (
   in_merchant_id        MERCH_DETAIL.MERCHANT_ID%TYPE,
   in_channel_code       rule_psp_lb_criteria.rc_channel_code%TYPE,
   in_service_code       RULE_PSP_LB_CRITERIA.RC_SERVICE_CODE%TYPE,
   in_country            rule_psp_lb_criteria.rc_country%TYPE,
   in_ccy                RULE_PSP_LB_CRITERIA.RC_CCY%TYPE,
   in_group              customer_group_detail.cgd_code%TYPE,
   in_card_type		 rule_psp_lb_criteria.rc_card_type_opt%TYPE,
   in_amount             rule_psp_lb_criteria.RC_MAX_TRANSACTION_AMOUNT%TYPE,
   out_cursor        OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
BEGIN
   OPEN out_cursor FOR

  SELECT rc_customer_segment
    FROM (  SELECT rc_customer_segment, rm_psp_id
              FROM (SELECT rc_party_id,
                          rc_customer_segment,
                           rp_pool_id,
                           rc_business_type
                      FROM rule_psp_lb_criteria, rule_psp_lb_pools
                     WHERE     rc_criteria_pool_id = rp_criteria_pool_id
                           AND RULE_SCHEDULE_PKG.InRunningPeriod (
                                  rc_scheduler_id) = 1
                           AND rc_disabled = 0
                           AND rp_disabled = 0
                           AND rc_customer_segment IS NOT NULL
                           AND rc_party_id = in_merchant_id
                           AND rc_channel_code = in_channel_code
                           AND rc_service_code = in_service_code
                           AND rc_country = in_country
                           AND rc_ccy = in_ccy
                           AND rc_card_type_opt = in_card_type
			   AND (RC_MIN_TRANSACTION_AMOUNT <= in_amount
                                  AND (RC_MAX_TRANSACTION_AMOUNT = 0
                                    or RC_MAX_TRANSACTION_AMOUNT >= in_amount))),
                   (SELECT business_type
                      FROM merch_detail, clients
                     WHERE     merchant_id = in_merchant_id
                           AND disabled = 0
                           AND merch_detail.status = 'O'
                           AND merch_detail.client_id = clients.client_id
                           AND clients.status = 'O'),
                   (SELECT rm_pool_id, rm_psp_id
                      FROM rule_psp_lb_mapping
                     WHERE rm_disabled = 0),
                   (SELECT CGR_GROUP_CODE
                      FROM CUSTOMER_GROUP_RULES
                     WHERE     cgr_merchant_id = in_merchant_id
                           AND cgr_from_group_code = in_group
                           AND CGR_DISABLED = 0),
                   (SELECT PSP_ID AS r_psp_id,
                           currency_id,
                           client_id,
                           psp_name,
                           psp_channel_code,deposit_card_type
                      FROM psp_detail, psp_master
                     WHERE     client_id = pm_client_id
                           AND disabled = 0
                           AND online_mode = 'Y'
                           AND status = 'O'
                           AND pm_status = 'O')
             WHERE     rp_pool_id = rm_pool_id
                   AND rc_business_type = business_type
                   AND CGR_GROUP_CODE = rc_customer_segment
                   AND rm_psp_id = r_psp_id
		   AND ((deposit_card_type = in_card_type) or deposit_card_type = 'A')
                   AND psp_channel_code <> 'VRT'
          GROUP BY rc_customer_segment, rm_psp_id)
  GROUP BY rc_customer_segment; 


   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_rulelb_without_virtualpid;
/
