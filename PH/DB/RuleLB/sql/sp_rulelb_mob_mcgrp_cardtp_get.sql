CREATE OR REPLACE FUNCTION sp_rulelb_mob_mcgrp_cardtp_get (
   in_option_bank  	BANK_MAPPING.BM_INT_BANK_CODE%TYPE,
   in_merchant_id       MERCH_DETAIL.MERCHANT_ID%TYPE,
   in_channel_code      rule_psp_lb_criteria.rc_channel_code%TYPE,
   in_service_code      rule_psp_lb_criteria.rc_service_code%TYPE,
   in_country           rule_psp_lb_criteria.rc_country%TYPE,
   in_ccy               RULE_PSP_LB_CRITERIA.RC_CCY%TYPE,
   in_group             customer_group_detail.cgd_code%TYPE,
   in_ip_region_code	PSP_RESTRICT_IP_REGION.PIR_REGION_CODE%TYPE,
   in_restricted_ip     rule_psp_lb_criteria.rc_allow_special_region%TYPE,
   in_amount            rule_psp_lb_criteria.RC_MAX_TRANSACTION_AMOUNT%TYPE,
   out_cursor       	OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
BEGIN
   OPEN out_cursor FOR
	SELECT bm_int_bank_code,
       	       client_id,
               rpp_psp_id,
               currency_id,
               remaining_limit,
       	       credit_option,
               debit_option
	FROM   (SELECT 	bm_int_bank_code,
		       	client_id,
		       	rpp_psp_id,
		       	currency_id,
		 	remaining_limit,
			fe_display_order,
			credit_option,
			debit_option
		FROM 	(SELECT psp_name,
                        	client_id,
                       	 	rpp_psp_id,
                        	currency_id,
                        	rpp_limit,
                        	remaining_limit,
                        	psp_channel_code,
                        	overrided_bank_code_channel,
                        	rc_service_code,
				credit_option,
				debit_option,
				deposit_card_type,
				pd_restrict_deposit_ip
			FROM 	(SELECT rm_psp_id,
					rc_service_code,
					credit_option,
					debit_option
                        	FROM 	(SELECT rc_channel_code,
                                        	rc_service_code,
                                        	rc_payment_method,
                                        	rc_country,
                                        	rc_ccy,
                                        	rc_party_type,
                                        	rc_party_id,
                                        	rc_business_type,
                                        	rc_customer_segment,
                                        	rp_criteria_pool_id,
                                        	rp_pool_id,
						case when rc_card_type_opt = 'C' then 1 else 0 end credit_option,
						case when rc_card_type_opt = 'D' then 1 else 0 end debit_option
					FROM 	rule_psp_lb_criteria,
                                     		rule_psp_lb_pools
					WHERE 	RULE_SCHEDULE_PKG.InRunningPeriod (rc_scheduler_id) = 1
					AND 	rc_criteria_pool_id = rp_criteria_pool_id
					AND 	rc_disabled = 0
					AND 	rp_disabled = 0
                                	AND 	rc_ccy = in_ccy
                                	AND 	rc_party_id = in_merchant_id
					AND 	rc_channel_code = in_channel_code
					AND 	rc_service_code = in_service_code
					AND 	rc_country = in_country
					AND 	rc_allow_special_region = in_restricted_ip
					AND 	(RC_MIN_TRANSACTION_AMOUNT <= in_amount
						 AND (RC_MAX_TRANSACTION_AMOUNT = 0 OR RC_MAX_TRANSACTION_AMOUNT >= in_amount))
					AND 	(
						 (rc_customer_segment = in_group
						  AND (in_merchant_id IN (SELECT CGM_MERCHANT_ID
								       FROM CUSTOMER_GROUP_MERCHANT
								       WHERE CGM_DISABLED = 0
								       AND CGM_PHASE > 0)))
                                     		 OR (rc_customer_segment IS NULL
                                         	     AND (in_merchant_id IN (SELECT CGM_MERCHANT_ID
							     		   FROM CUSTOMER_GROUP_MERCHANT
									   WHERE CGM_DISABLED = 0
									   AND CGM_PHASE > 0)
                                                  	      AND in_group = (SELECT CG_CODE
									     FROM CUSTOMER_GROUP
									     WHERE CG_CODE = in_group
									     AND CG_BACKUP_BY_OVERFLOW = 1)))
						 OR (in_group IS NULL
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
										      AND CGR_DISABLED = 0)))
						)
					),
                                	(SELECT business_type,
                                        	merchant_id,
                                        	clients.client_id
                                 	FROM merch_detail, clients
                                 	WHERE merchant_id = in_merchant_id
                                 	AND disabled = 0
                                 	AND merch_detail.status = 'O'
                                 	AND merch_detail.client_id = clients.client_id
                                 	AND clients.status = 'O'),
                                 	(rule_psp_lb_mapping)
				WHERE rc_business_type = business_type
				AND rp_pool_id = rm_pool_id
				AND rm_disabled = 0
				AND ((rc_party_type = 'M' AND rc_party_id = merchant_id)
                              	     OR (rc_party_type = 'C' AND rc_party_id = client_id)
                              	     OR (rc_party_type = 'G'))
				GROUP BY rm_psp_id, rc_service_code,credit_option,debit_option),
                        	(SELECT psp_name,
                                	client_id,
                                	psp_channel_code,
                                	overrided_bank_code_channel,
					deposit_card_type,
					pd_restrict_deposit_ip,
                                	rpp_psp_id,
                                	currency_id,
                                	rpp_limit,
                                	CASE WHEN rpp_limit = 0 THEN rpp_limit ELSE rpp_limit - NVL (tc_total_counter, 0) END AS remaining_limit
				FROM 	(SELECT rpp_psp_id,
                                        	currency_id,
                                        	rpp_limit,
                                        	client_id,
                                        	psp_name,
                                        	psp_channel_code,
                                        	overrided_bank_code_channel,
						deposit_card_type,
						pd_restrict_deposit_ip
					FROM 	(SELECT rpp_psp_id, rpp_limit
						FROM rule_psp_lb_psp
						WHERE rpp_disabled = 0),
						(SELECT r_psp_id,
                                                   	currency_id,
                                                   	client_id,
                                                   	psp_name,
                                                   	psp_channel_code,
                                                   	overrided_bank_code_channel,
                                                   	deposit_card_type,
                                                   	pd_restrict_deposit_ip
						FROM	(SELECT PSP_ID AS r_psp_id,
								currency_id,
								client_id,
								psp_name,
								psp_channel_code,
								overrided_bank_code_channel,
								deposit_card_type,
								pd_restrict_deposit_ip
							FROM psp_detail,
							     psp_master,
							     (SELECT bm_psp_channel_id
                                                	      FROM   bank_mapping
                                                	      WHERE  bm_int_bank_code = in_option_bank
                                                	      AND    bm_disabled = 0)
							WHERE client_id = pm_client_id
							AND disabled = 0
							AND online_mode = 'Y'
							AND status = 'O'
							AND pm_status = 'O'
							AND psp_channel_code <> 'VRT'
					 		AND ((overrided_bank_code_channel IS NOT NULL and overrided_bank_code_channel = bm_psp_channel_id)
							     OR (overrided_bank_code_channel IS NULL and psp_channel_code = bm_psp_channel_id)))
						LEFT JOIN
                                                   	(SELECT pir_psp_id,
								pir_region_code
                                                     	 FROM   psp_restrict_ip_region
                                                     	 WHERE  pir_disabled = 0) 
                                             	ON     	(pir_psp_id = r_psp_id)
                                            	WHERE 	(pd_restrict_deposit_ip = 0 OR (pd_restrict_deposit_ip = 1 AND pir_region_code = in_ip_region_code))
                                            	GROUP BY r_psp_id,
                                                     	 currency_id,
                                                     	 client_id,
                                                     	 psp_name,
                                                     	 psp_channel_code,
                                                     	 overrided_bank_code_channel,
                                                     	 deposit_card_type,
                                                     	 pd_restrict_deposit_ip)
					WHERE rpp_psp_id = r_psp_id)
--
				LEFT JOIN (SELECT SUM (tc_total_counter) AS tc_total_counter,
						  tc_party_id AS party_psp_id
					   FROM txn_counters
					   WHERE tc_party_type = 'P'
					   AND tc_category = 'AMT'
					   AND tc_type = 'D'
					   GROUP BY tc_party_id)
				ON rpp_psp_id = party_psp_id)
--
			WHERE rm_psp_id = rpp_psp_id
			and ((deposit_card_type = 'D' and debit_option = 1) or (deposit_card_type = 'C' and credit_option = 1) or deposit_card_type = 'A')) a
--
		LEFT JOIN (SELECT bm_int_bank_code,
				  bm_psp_channel_id,
				  fe_display_order,
				  bs_service_code
			   FROM bank_mapping, bank_desc, bank_service_mapping
			   WHERE bm_disabled = 0
			   AND internal_bank_code = bm_int_bank_code
			   AND bs_disabled = 0
			   AND internal_bank_code = bs_int_bank_code) b
		ON ((a.overrided_bank_code_channel IS NOT NULL AND b.bm_psp_channel_id = a.overrided_bank_code_channel)
		     OR (a.overrided_bank_code_channel IS NULL AND b.bm_psp_channel_id = a.psp_channel_code))
		    AND b.bs_service_code = a.rc_service_code
--
		ORDER BY fe_display_order, client_id, rpp_psp_id)
	--WHERE remaining_limit >= in_amount
	ORDER BY fe_display_order, credit_option DESC, remaining_limit DESC;

   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_rulelb_mob_mcgrp_cardtp_get;
/

