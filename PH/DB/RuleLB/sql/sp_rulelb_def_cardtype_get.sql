CREATE OR REPLACE FUNCTION sp_rulelb_def_cardtype_get(
   in_option_bank  	BANK_MAPPING.BM_INT_BANK_CODE%TYPE,
   in_merchant_id       MERCH_DETAIL.MERCHANT_ID%TYPE,
   in_channel_code      rule_psp_lb_criteria.rc_channel_code%TYPE,
   in_service_code      rule_psp_lb_criteria.rc_service_code%TYPE,
   in_country           rule_psp_lb_criteria.rc_country%TYPE,
   in_ccy				RULE_PSP_LB_CRITERIA.RC_CCY%TYPE,
   in_device_type       PID_BANK_GROUP_MAPPING.PGM_DEVICE_TYPE%TYPE,
   in_restricted_ip     rule_psp_lb_criteria.rc_allow_special_region%TYPE,
   in_amount            rule_psp_lb_criteria.RC_MAX_TRANSACTION_AMOUNT%TYPE,
   out_cursor       	OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
BEGIN
   OPEN out_cursor FOR

      SELECT	bank_group,
        	bm_int_bank_code,
		client_id,
		rpp_psp_id,
		currency_id,
		remaining_limit,
		credit_option,
		debit_option
	FROM 	(SELECT bank_group,
                	bm_int_bank_code,
			nbxa_pid_group,
			client_id,
			rpp_psp_id,
			currency_id,
			remaining_limit,
			NVL(pbm_display_order,'9999') display_order_1,
			NVL(pbm_display_order,fe_display_order) display_order_2,
			credit_option,
			debit_option
		FROM 	(SELECT	psp_name,
				nbxa_pid_group,
				client_id,
				rpp_psp_id,
				currency_id,
				rpp_limit,
				remaining_limit,
				psp_channel_code,
				overrided_bank_code_channel,
				rm_psp_id,
				rc_service_code,
				credit_option,
				debit_option,
				deposit_card_type
			FROM 	(SELECT	rm_psp_id,
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
					WHERE  	RULE_SCHEDULE_PKG.InRunningPeriod (rc_scheduler_id) = 1
					AND 	rc_criteria_pool_id = rp_criteria_pool_id
					AND 	rc_disabled = 0
					AND 	rp_disabled = 0
					AND 	rc_party_id = in_merchant_id
					AND 	rc_ccy = in_ccy
					AND 	rc_channel_code = in_channel_code
					AND 	rc_service_code = in_service_code
					AND 	rc_country = in_country
					AND 	rc_allow_special_region = in_restricted_ip
					AND 	rc_customer_segment is NULL
					AND 	(RC_MIN_TRANSACTION_AMOUNT <= in_amount
						 AND (RC_MAX_TRANSACTION_AMOUNT = 0
						 OR RC_MAX_TRANSACTION_AMOUNT >= in_amount))),
					(SELECT	business_type,
						merchant_id,
						clients.client_id
					FROM 	merch_detail,
						clients
					WHERE  	merchant_id = in_merchant_id
					AND 	disabled = 0
					AND 	merch_detail.status = 'O'
					AND 	merch_detail.client_id = clients.client_id
					AND 	clients.status = 'O'),
						(rule_psp_lb_mapping)
				WHERE  	rc_business_type = business_type
				AND 	rp_pool_id = rm_pool_id
				AND 	rm_disabled = 0
				AND 	((rc_party_type = 'M' AND rc_party_id = merchant_id)
					 OR (rc_party_type = 'C' AND rc_party_id = client_id)
					 OR (rc_party_type = 'G'))
				GROUP BY rm_psp_id, rc_service_code,credit_option,debit_option),
				(SELECT	psp_name,
					nbxa_pid_group,
					client_id,
					psp_channel_code,
					overrided_bank_code_channel,
					deposit_card_type,
					rpp_psp_id,
					currency_id,
					rpp_limit,
					CASE WHEN rpp_limit = 0 THEN rpp_limit ELSE rpp_limit - NVL (tc_total_counter, 0) END AS remaining_limit
				FROM 	(SELECT	rpp_psp_id,
						currency_id,
						rpp_limit,
						client_id,
						psp_name,
						nbxa_pid_group,
						psp_channel_code,
						overrided_bank_code_channel,
						deposit_card_type
					FROM 	(SELECT	rpp_psp_id,
							rpp_limit
						FROM 	rule_psp_lb_psp
						WHERE 	rpp_disabled = 0),
						(SELECT PSP_ID AS r_psp_id,
							currency_id,
							client_id,
							psp_name,
							nbxa_pid_group,
							psp_channel_code,
							overrided_bank_code_channel,
							deposit_card_type
						FROM 	psp_detail,
							psp_master,
							(SELECT bm_psp_channel_id
							FROM 	bank_mapping
							WHERE 	bm_int_bank_code = in_option_bank
							AND	bm_disabled = 0)
						WHERE  	client_id = pm_client_id
						AND 	disabled = 0
						AND 	online_mode = 'Y'
						AND 	status = 'O'
						AND 	pm_status = 'O'
						AND 	((overrided_bank_code_channel IS NOT NULL and overrided_bank_code_channel = bm_psp_channel_id)
							 OR (overrided_bank_code_channel IS NULL and psp_channel_code = bm_psp_channel_id)))
					WHERE rpp_psp_id = r_psp_id)
--
				LEFT JOIN	(SELECT		SUM (tc_total_counter) AS tc_total_counter,
								tc_party_id AS party_psp_id
						FROM 		txn_counters
						WHERE  		tc_party_type = 'P'
						AND 		tc_category = 'AMT'
						AND 		tc_type = 'D'
						GROUP BY	tc_party_id)
				ON rpp_psp_id = party_psp_id)
--
			WHERE	rm_psp_id = rpp_psp_id
			and ((deposit_card_type = 'D' and debit_option = 1) or (deposit_card_type = 'C' and credit_option = 1) or deposit_card_type = 'A')) a
--
		LEFT JOIN	(SELECT	bm_int_bank_code,
					bm_psp_channel_id,
					fe_display_order,
					bs_service_code,
					bank_group,
					pgm_pid_group
				FROM 	bank_mapping,
					bank_desc,
					bank_service_mapping,
					pid_bank_group_mapping
				WHERE  	bm_disabled = 0
				AND 	internal_bank_code = bm_int_bank_code
				AND 	bs_disabled = 0
				AND 	internal_bank_code = bs_int_bank_code
				AND 	(((pgm_bank_code = internal_bank_code) or (pgm_bank_code = bank_group) or (pgm_bank_group = internal_bank_code))
					 AND (bank_group IS NOT NULL)
					)
			        AND	pgm_service_code = in_service_code
				AND     pgm_device_type = in_device_type
				AND 	pgm_disabled = 0
				) b
		ON ((a.overrided_bank_code_channel IS NOT NULL AND b.bm_psp_channel_id = a.overrided_bank_code_channel)
		    OR (a.overrided_bank_code_channel IS NULL AND b.bm_psp_channel_id = a.psp_channel_code))
		AND b.bs_service_code = a.rc_service_code
--
		LEFT JOIN 	(SELECT	pbm_bank_code,
					pbm_service_code,
					pbm_display_order
				FROM 	paypage_bank_mapping
				WHERE 	pbm_disabled = 0) c
		ON  c.pbm_bank_code = b.bm_int_bank_code
		AND c.pbm_service_code = a.rc_service_code
--
		WHERE nbxa_pid_group = pgm_pid_group
		group by	bank_group,
                    		bm_int_bank_code,
				nbxa_pid_group,
				client_id,
				rpp_psp_id,
				currency_id,
				remaining_limit,
				NVL(pbm_display_order, '9999'),
				NVL(pbm_display_order, fe_display_order),
				credit_option,
				debit_option
		ORDER BY	display_order_1,
				display_order_2,
				client_id,
				rpp_psp_id)
	--WHERE remaining_limit >= in_amount
	ORDER BY	display_order_1,
			display_order_2,
			credit_option desc,
			remaining_limit DESC;

   RETURN 0;

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_rulelb_def_cardtype_get;
/

