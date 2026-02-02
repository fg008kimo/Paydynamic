CREATE OR REPLACE FUNCTION sp_ol_get_last_upd_bk_accts_dt(
	in_req_datetime            	DATE,
	in_int_bank_code                OL_BANK_ACCTS.OB_INT_BANK_CODE%type,
        in_bank_acct_num                OL_BANK_ACCTS.OB_BANK_ACCT_NUM%type,
	in_max_bank_acct_cnt           	INTEGER,
	out_cursor       		OUT SYS_REFCURSOR)
RETURN NUMBER IS
	iCnt    integer := 0;
BEGIN

	WITH bank_list AS (
    		SELECT	ob_int_bank_code AS int_bank_code, 
        	        ob_bank_acct_num AS bank_acct_num
    		FROM  	ol_bank_accts
    		WHERE   (   (ob_update_timestamp > in_req_datetime)
        	             OR
        	            (   ob_update_timestamp = in_req_datetime
        	                AND
        	                (  (ob_bank_acct_num > NVL(in_bank_acct_num, ob_bank_acct_num)) OR
        	                   (ob_bank_acct_num = NVL(in_bank_acct_num, ob_bank_acct_num) AND ob_int_bank_code > NVL(in_int_bank_code, ob_int_bank_code))
        	                )
        	            ) 
        	        )     
    		AND    	ob_int_bank_code NOT IN ('086000', '886000')
    		UNION  
    		SELECT	obai_int_bank_code AS int_bank_code, 
        	        obai_bank_acct_num AS bank_acct_num
    		FROM  	ol_bank_acct_id
   		WHERE   (   (obai_update_timestamp > in_req_datetime)
        	             OR
        	            (   obai_update_timestamp = in_req_datetime
        	                AND
        	                (  (obai_bank_acct_num > NVL(in_bank_acct_num, obai_bank_acct_num)) OR
        	                   (obai_bank_acct_num = NVL(in_bank_acct_num, obai_bank_acct_num) AND obai_int_bank_code > NVL(in_int_bank_code, obai_int_bank_code))
        	                )
        	            ) 
        	        )     
    		AND   	obai_int_bank_code NOT IN ('086000', '886000')
	)

	SELECT COUNT (*)
	INTO iCnt
       	FROM (
		SELECT	ob_int_bank_code,
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
                	ob_update_timestamp,
                	obai_baid,
                	obai_psp_id,
                	obai_status,
                	obai_update_timestamp,
                	opd_psp_id,
                	opd_bank_acct_type,
                	baid_client_id,
                	baid_client_name,
                	ob_shared_acct,
                	latest_update_ts,
                	CASE WHEN (ob_shared_acct = 0)
                	  	THEN (SELECT	omb_merchant_id
                                      FROM  	ol_merchant_Bank_acct
                                      WHERE     ob_int_bank_code = omb_int_bank_code
                                      AND       ob_bank_acct_num = omb_bank_acct_num
                                      AND       omb_disabled = 0
                                      AND       omb_status = 'O')
                    	    ELSE NULL
                	END AS asso_mid     
        	FROM (
            		SELECT	ob_int_bank_code,
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
                    		ob_update_timestamp,
                    		obai_baid,
                    		obai_psp_id,
                    		obai_status,
                    		obai_update_timestamp,
                    		opd_psp_id,
                    		opd_bank_acct_type,
                    		pm_client_id AS baid_client_id,
                    		pm_client_name AS baid_client_name,
                    		ob_shared_acct,
                    		latest_update_ts,
                    		rn
            		FROM (
                		SELECT 	ob_init_provider_id,
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
                        		CASE WHEN obai_update_timestamp IS NULL
                            			THEN ob_update_timestamp
                            			ELSE GREATEST (ob_update_timestamp, obai_update_timestamp)
                        		END AS latest_update_ts,                                     
                        		row_number() over (partition by  ob_int_bank_code, ob_bank_acct_num
                                            		   order by decode(obai_status, 'O', 1, 2),  
                                            		   obai_update_timestamp desc, 
                                            		   obai_baid desc) as rn        
                		FROM    bank_list, 
                        		ol_bank_accts, 
                        		ol_bank_acct_id, 
                        		ol_psp_detail, 
                        		psp_master
                		WHERE   bank_list.int_bank_code = ob_int_bank_code 
                		AND     bank_list.bank_acct_num = ob_bank_acct_num  
                		AND     ob_int_bank_code  = obai_int_bank_code (+)
                		AND     ob_bank_acct_num  = obai_bank_acct_num (+)
                		AND     NVL(obai_psp_id, '~') = opd_psp_id (+)
                		AND     NVL(opd_client_id, '~') = pm_client_id (+)
            		)
            		WHERE rn = 1
        	) m_rs
    	), psp_master, bank_desc
    	WHERE ob_init_provider_id = pm_client_id
    	AND ob_int_bank_code = internal_bank_code;

	IF iCnt > 0 THEN

		OPEN out_cursor FOR
		
		WITH bank_list AS (
         	       SELECT  ob_int_bank_code AS int_bank_code,
         	               ob_bank_acct_num AS bank_acct_num
         	       FROM    ol_bank_accts
         	       WHERE   (   (ob_update_timestamp > in_req_datetime)
         	                    OR
         	                   (   ob_update_timestamp = in_req_datetime
         	                       AND
         	                       (  (ob_bank_acct_num > NVL(in_bank_acct_num, ob_bank_acct_num)) OR
         	                          (ob_bank_acct_num = NVL(in_bank_acct_num, ob_bank_acct_num) AND ob_int_bank_code > NVL(in_int_bank_code, ob_int_bank_code))
         	                       )
         	                   )
         	               )
         	       AND     ob_int_bank_code NOT IN ('086000', '886000')
         	       UNION
         	       SELECT  obai_int_bank_code AS int_bank_code,
         	               obai_bank_acct_num AS bank_acct_num
         	       FROM    ol_bank_acct_id
         	       WHERE   (   (obai_update_timestamp > in_req_datetime)
         	                    OR
         	                   (   obai_update_timestamp = in_req_datetime
         	                       AND
         	                       (  (obai_bank_acct_num > NVL(in_bank_acct_num, obai_bank_acct_num)) OR
         	                          (obai_bank_acct_num = NVL(in_bank_acct_num, obai_bank_acct_num) AND obai_int_bank_code > NVL(in_int_bank_code, obai_int_bank_code))
         	                       )
         	                   )
         	               )
         	       AND     obai_int_bank_code NOT IN ('086000', '886000')
        	)	

		SELECT  f_provider_name,
        		f_client_id,
        		ob_int_bank_code,
        		ob_bank_acct_num,
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
        		asso_mid,
        		opd_bank_acct_type,         
        		TO_CHAR(ob_update_timestamp, 'YYYYMMDDHH24MISS'),
        		TO_CHAR(obai_update_timestamp, 'YYYYMMDDHH24MISS'),
        		CASE WHEN (overall_RN = total_count)
            			THEN '1'
            			ELSE '0'
        		END AS end_ind
		FROM (
    			SELECT  NVL(baid_client_name, pm_client_name) AS f_provider_name,
            			NVL(baid_client_id, pm_client_id) AS f_client_id,
            			ob_bank_acct_num,
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
            			asso_mid,
            			opd_bank_acct_type,            
            			ob_update_timestamp,
            			obai_update_timestamp,
            			ob_int_bank_code,
            			/*
            			ob_init_provider_id,           
            			baid_tag         
            			obai_psp_id,                         
            			ob_shared_acct,
            			latest_update_ts,
				*/
            			row_number() over (order by latest_update_ts, ob_bank_acct_num, ob_int_bank_code) as overall_RN,
            			count(*) over() as total_count               
       			FROM (        
              			SELECT	ob_int_bank_code,
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
                			ob_update_timestamp,
                			obai_baid,
                			obai_psp_id,
                			obai_status,
                			obai_update_timestamp,
                			opd_psp_id,
                			opd_bank_acct_type,
                			baid_client_id,
                			baid_client_name,
                			ob_shared_acct,
                			latest_update_ts,
                			CASE WHEN (ob_shared_acct = 0)
                    				THEN	(SELECT	omb_merchant_id
                                			FROM   	ol_merchant_Bank_acct
                                			WHERE 	ob_int_bank_code = omb_int_bank_code
                                			AND   	ob_bank_acct_num = omb_bank_acct_num
                                			AND   	omb_disabled = 0
                                			AND   	omb_status = 'O')
                    				ELSE 	NULL
                			END AS asso_mid     
       	 			FROM (
            				SELECT	ob_int_bank_code,
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
                    				ob_update_timestamp,
                    				obai_baid,
                    				obai_psp_id,
                    				obai_status,
                    				obai_update_timestamp,
                    				opd_psp_id,
                    				opd_bank_acct_type,
                    				pm_client_id AS baid_client_id,
                    				pm_client_name AS baid_client_name,
                    				ob_shared_acct,
                    				latest_update_ts,
                    				rn
            				FROM (
                				SELECT	ob_init_provider_id,
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
                        				CASE WHEN obai_update_timestamp IS NULL
                            					THEN ob_update_timestamp
                            					ELSE GREATEST (ob_update_timestamp, obai_update_timestamp)
                        				END AS latest_update_ts,                                     
                        				row_number() over (partition by  ob_int_bank_code, ob_bank_acct_num
                                            				   order by decode(obai_status, 'O', 1, 2),  
                                            				   obai_update_timestamp desc, 
                                            				   obai_baid desc) as rn        
                				FROM    bank_list, 
                        				ol_bank_accts, 
                        				ol_bank_acct_id, 
                        				ol_psp_detail, 
                        				psp_master
                				WHERE   bank_list.int_bank_code = ob_int_bank_code 
                				AND     bank_list.bank_acct_num = ob_bank_acct_num  
                				AND     ob_int_bank_code = obai_int_bank_code (+)
                				AND     ob_bank_acct_num = obai_bank_acct_num (+)
                				AND     NVL(obai_psp_id, '~') = opd_psp_id (+)
                				AND     NVL(opd_client_id, '~') = pm_client_id (+)
            				)
            				WHERE rn = 1
        			) m_rs
    			), psp_master, bank_desc
    			WHERE ob_init_provider_id = pm_client_id
    			AND ob_int_bank_code = internal_bank_code 
		)
		WHERE overall_RN <= in_max_bank_acct_cnt
		order by overall_RN;

		return 0;
	ELSE
		return 2;
  	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_ol_get_last_upd_bk_accts_dt;
/
