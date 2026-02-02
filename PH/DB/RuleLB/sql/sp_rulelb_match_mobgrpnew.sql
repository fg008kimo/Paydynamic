


CREATE OR REPLACE FUNCTION sp_rulelb_match_mobgrpnew (
   in_channel_code         rule_psp_lb_criteria.rc_channel_code%TYPE,
   in_service_code         rule_psp_lb_criteria.rc_service_code%TYPE,
   in_country              rule_psp_lb_criteria.rc_country%TYPE,
   in_ccy                  rule_psp_lb_criteria.rc_ccy%TYPE,
   in_merchant_id          rule_psp_lb_criteria.rc_party_id%TYPE,
   in_group                customer_group_detail.cgd_code%TYPE,
   in_card_type		   rule_psp_lb_criteria.rc_card_type_opt%TYPE,
   in_sarip	   	   INTEGER,
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
	  system_parameter,
          (SELECT business_type,
                  merchant_id
           FROM merch_detail, clients
           WHERE     merchant_id = in_merchant_id
           AND disabled = 0
           AND merch_detail.status = 'O'
           AND merch_detail.client_id = clients.client_id
           AND clients.status = 'O')
   WHERE RULE_SCHEDULE_PKG.InRunningPeriod (rc_scheduler_id) = 1
         AND rc_disabled = 0
         AND rc_party_id = in_merchant_id
         AND rc_party_id = merchant_id
         AND rc_business_type = business_type
         AND rc_ccy = in_ccy
         AND rc_channel_code = in_channel_code
         AND rc_service_code = in_service_code
         AND rc_country = in_country
         AND rc_card_type_opt = in_card_type
	 AND sp_code = 'LB_SMALL_AMT'
	 AND
	 (
	     (in_sarip = 1
     	      AND
	      (
             	  (rc_allow_special_region = in_restricted_ip and rc_allow_special_region = 1
            	   AND  rc_min_transaction_amount <= in_amount
                   AND  ((rc_max_transaction_amount >= in_amount AND rc_max_transaction_amount > 0)
                	 OR rc_max_transaction_amount = 0)
               	   AND  rc_customer_segment is NULL
              	  )
              	  OR
		  (rc_allow_special_region = in_restricted_ip and rc_allow_special_region = 0
              	   AND (rc_max_transaction_amount > 0
              	   AND rc_max_transaction_amount >= in_amount
               	   AND rc_max_transaction_amount <= sp_val)
               	   AND rc_customer_segment is NULL
           	  )
              )
      	    )
	    OR
 	    (in_sarip = 0
	     AND rc_allow_special_region = in_restricted_ip and rc_allow_special_region = 0
	     AND rc_min_transaction_amount <= in_amount
	     AND ((rc_max_transaction_amount >= in_amount AND rc_max_transaction_amount > 0)
	       	  OR rc_max_transaction_amount = 0)
	     AND
	     (
		 (rc_customer_segment = in_group
		  AND (in_merchant_id IN (SELECT CGM_MERCHANT_ID
					  FROM CUSTOMER_GROUP_MERCHANT
					  WHERE CGM_DISABLED = 0
					  AND CGM_PHASE > 0))
		 )
		 OR
		 (rc_customer_segment IS NULL
		  AND (in_merchant_id IN (SELECT CGM_MERCHANT_ID
					  FROM CUSTOMER_GROUP_MERCHANT
					  WHERE CGM_DISABLED = 0
					  AND CGM_PHASE > 0)
		  AND in_group = (SELECT CG_CODE
			 	  FROM CUSTOMER_GROUP
				  WHERE CG_CODE = in_group
				  AND CG_BACKUP_BY_OVERFLOW = 1))
		 )
		 OR
		 (in_group IS NULL
		  AND (in_merchant_id IN (SELECT CGM_MERCHANT_ID
					  FROM CUSTOMER_GROUP_MERCHANT
					  WHERE CGM_DISABLED = 0
					  AND CGM_PHASE > 0)
		  AND rc_customer_segment = (SELECT CG_CODE
					     FROM CUSTOMER_GROUP
					     WHERE CG_CODE = rc_customer_segment
					     AND CG_BACKUP_BY_OVERFLOW = 0)
	 	  AND rc_customer_segment IN (SELECT CGR_GROUP_CODE
					      FROM CUSTOMER_GROUP_RULES
					      WHERE CGR_MERCHANT_ID = in_merchant_id
					      AND CGR_FROM_GROUP_CODE IS NULL
					      AND CGR_DISABLED = 0))
		 )
	     )
	    )
	);

   IF iCnt > 0
   THEN
      OPEN out_cursor FOR
           SELECT rc_min_transaction_amount,
                  rc_max_transaction_amount,
                  rc_criteria_pool_id,
                  rc_scheduler_id,
                  rc_priority
	   FROM rule_psp_lb_criteria,
		system_parameter,
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
	   AND sp_code = 'LB_SMALL_AMT'
           AND
           (
             (in_sarip = 1
              AND
              (
                  (rc_allow_special_region = in_restricted_ip and rc_allow_special_region = 1
                   AND  rc_min_transaction_amount <= in_amount
                   AND  ((rc_max_transaction_amount >= in_amount AND rc_max_transaction_amount > 0)
                         OR rc_max_transaction_amount = 0)
                   AND  rc_customer_segment is NULL
                  )
                  OR
                  (rc_allow_special_region = in_restricted_ip and rc_allow_special_region = 0
                   AND (rc_max_transaction_amount > 0
                   AND rc_max_transaction_amount >= in_amount
                   AND rc_max_transaction_amount <= sp_val)
                   AND rc_customer_segment is NULL
                  )
              )
            )
            OR
            (in_sarip = 0
             AND rc_allow_special_region = in_restricted_ip and rc_allow_special_region = 0
             AND rc_min_transaction_amount <= in_amount
             AND ((rc_max_transaction_amount >= in_amount AND rc_max_transaction_amount > 0)
                  OR rc_max_transaction_amount = 0)
             AND
             (
                 (rc_customer_segment = in_group
                  AND (in_merchant_id IN (SELECT CGM_MERCHANT_ID
                                          FROM CUSTOMER_GROUP_MERCHANT
                                          WHERE CGM_DISABLED = 0
                                          AND CGM_PHASE > 0))
                 )
                 OR
                 (rc_customer_segment IS NULL
                  AND (in_merchant_id IN (SELECT CGM_MERCHANT_ID
                                          FROM CUSTOMER_GROUP_MERCHANT
                                          WHERE CGM_DISABLED = 0
                                          AND CGM_PHASE > 0)
                  AND in_group = (SELECT CG_CODE
                                  FROM CUSTOMER_GROUP
                                  WHERE CG_CODE = in_group
                                  AND CG_BACKUP_BY_OVERFLOW = 1))
                 )
                 OR
                 (in_group IS NULL
                  AND (in_merchant_id IN (SELECT CGM_MERCHANT_ID
                                          FROM CUSTOMER_GROUP_MERCHANT
                                          WHERE CGM_DISABLED = 0
                                          AND CGM_PHASE > 0)
                  AND rc_customer_segment = (SELECT CG_CODE
                                             FROM CUSTOMER_GROUP
                                             WHERE CG_CODE = rc_customer_segment
                                             AND CG_BACKUP_BY_OVERFLOW = 0)
                  AND rc_customer_segment IN (SELECT CGR_GROUP_CODE
                                              FROM CUSTOMER_GROUP_RULES
                                              WHERE CGR_MERCHANT_ID = in_merchant_id
                                              AND CGR_FROM_GROUP_CODE IS NULL
                                              AND CGR_DISABLED = 0))
                 )
             )
            )
	   )
	   ORDER BY rc_priority DESC, num;

      RETURN 1;

   END IF;

   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 0;
END sp_rulelb_match_mobgrpnew;
/

