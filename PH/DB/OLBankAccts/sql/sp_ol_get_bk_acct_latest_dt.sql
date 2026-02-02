CREATE OR REPLACE FUNCTION sp_ol_get_bk_acct_latest_dt(
	in_int_bank_code               	OL_BANK_ACCTS.OB_INT_BANK_CODE%type,
	in_bank_acct_num               	OL_BANK_ACCTS.OB_BANK_ACCT_NUM%type,
	out_cursor       		OUT SYS_REFCURSOR)
RETURN NUMBER IS
	iCnt    integer := 0;
BEGIN

	SELECT COUNT (*)
	INTO iCnt
	FROM	(SELECT ob_int_bank_code,
                        ob_bank_acct_num,
                        ob_registered_mobile,
                  	ob_status_type,
                     	ob_init_provider_id,
                   	ob_bank_acct_short_name,
                     	ob_owner_name,
                     	ob_city,
                     	ob_acct_type,
                     	ob_province,
                     	ob_branch_name,
                     	obai_baid,
                     	obai_psp_id,
                     	obai_status,
                     	opd_bank_acct_type,
                   	pm_client_id AS baid_client_id,
                    	pm_client_name AS baid_client_name,
                      	ob_shared_acct,
                   	rn
           	 FROM   (SELECT ob_init_provider_id,
                              	ob_int_bank_code,
                             	ob_bank_acct_num,
                            	ob_status_type,
                             	ob_acct_type,
                            	ob_bank_acct_short_name,
                              	ob_owner_name,
                            	ob_province,
                             	ob_city,
                              	ob_branch_name,
                            	ob_registered_mobile,
                             	ob_update_timestamp,
                            	pm_client_id,
                            	pm_client_name,
                            	obai_baid,
                             	obai_status,
                               	opd_bank_acct_type,
                              	obai_update_timestamp,
                               	ob_shared_acct,
                              	opd_psp_id,
                               	obai_psp_id,
                               	ROW_NUMBER () OVER (PARTITION BY ob_int_bank_code,
                                                                 ob_bank_acct_num
                                                    ORDER BY DECODE (obai_status, 'O', 1, 2),
                                                             obai_update_timestamp DESC,
                                                             obai_baid DESC) AS rn
                      	 FROM   ol_bank_accts,
                               	ol_bank_acct_id,
                               	ol_psp_detail,
                               	psp_master
                       	 WHERE  ob_int_bank_code = in_int_bank_code
                       	 AND 	ob_bank_acct_num = in_bank_acct_num
                         AND 	ob_int_bank_code = obai_int_bank_code(+)
                         AND 	ob_bank_acct_num = obai_bank_acct_num(+)
                         AND 	NVL (obai_psp_id, '~') = opd_psp_id(+)
                         AND 	NVL (opd_client_id, '~') = pm_client_id(+))
                 WHERE rn = 1) m_rs,
               	psp_master,
                bank_desc
     	WHERE   ob_init_provider_id = pm_client_id
     	AND     ob_int_bank_code = internal_bank_code;

	IF iCnt > 0 THEN

		OPEN out_cursor FOR
		SELECT	NVL (baid_client_name, pm_client_name) AS provider_name,
			NVL (baid_client_id, pm_client_id) AS client_id,
			ob_status_type,
			obai_baid,
			obai_status,
			ob_acct_type,
			bank_name,
			bank_abbrev_name,
			ob_owner_name,
                        ob_province,
                        ob_city,
                        ob_branch_name,
                        ob_registered_mobile,	
       			ob_bank_acct_short_name,
       			CASE
           			WHEN 	(ob_shared_acct = 0)
           			THEN 	(SELECT	omb_merchant_id
                  			 FROM 	ol_merchant_Bank_acct
                 		 	 WHERE 	ob_int_bank_code = omb_int_bank_code
                       			 AND 	ob_bank_acct_num = omb_bank_acct_num
                       			 AND 	omb_disabled = 0
                       			 AND 	omb_status = 'O')
           			ELSE 	NULL
       			END AS asso_mid,
       			opd_bank_acct_type
  		FROM	(SELECT	ob_int_bank_code,
               			ob_bank_acct_num,
               			ob_registered_mobile,
               			ob_status_type,
               			ob_init_provider_id,
               			ob_bank_acct_short_name,
               			ob_owner_name,
               			ob_city,
               			ob_acct_type,
               			ob_province,
               			ob_branch_name,
               			obai_baid,
               			obai_psp_id,
               			obai_status,
               			opd_bank_acct_type,
               			pm_client_id   AS baid_client_id,
               			pm_client_name AS baid_client_name,
               			ob_shared_acct,
               			rn
          		 FROM 	(SELECT	ob_init_provider_id,
                       			ob_int_bank_code,
                       			ob_bank_acct_num,
                       			ob_status_type,
                       			ob_acct_type,
                       			ob_bank_acct_short_name,
                       			ob_owner_name,
                       			ob_province,
                       			ob_city,
                       			ob_branch_name,
                       			ob_registered_mobile,
                       			ob_update_timestamp,
                       			pm_client_id,
                       			pm_client_name,
                       			obai_baid,
                       			obai_status,
                       			opd_bank_acct_type,
                       			obai_update_timestamp,
                       			ob_shared_acct,
                       			opd_psp_id,
                       			obai_psp_id,
                       			ROW_NUMBER () OVER (PARTITION BY ob_int_bank_code, 
									 ob_bank_acct_num
                           				    ORDER BY DECODE (obai_status, 'O', 1, 2),
                               					     obai_update_timestamp DESC,
                               					     obai_baid DESC) AS rn
                  		 FROM 	ol_bank_accts,
                       			ol_bank_acct_id,
                       			ol_psp_detail,
                       			psp_master
                 		 WHERE 	ob_int_bank_code = in_int_bank_code
                       		 AND 	ob_bank_acct_num = in_bank_acct_num
                       		 AND 	ob_int_bank_code = obai_int_bank_code(+)
                      	 	 AND 	ob_bank_acct_num = obai_bank_acct_num(+)
                       		 AND 	NVL (obai_psp_id, '~') = opd_psp_id(+)
                       		 AND 	NVL (opd_client_id, '~') = pm_client_id(+))
         		 WHERE rn = 1) m_rs,
       			psp_master,
       			bank_desc
		WHERE	ob_init_provider_id = pm_client_id
      	 	AND 	ob_int_bank_code = internal_bank_code;

		return 0;
	ELSE
		return 2;
  	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_ol_get_bk_acct_latest_dt;
/
