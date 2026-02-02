CREATE OR REPLACE FUNCTION sp_ol_po_api_match_pgen_status(
   in_action_id       	OL_PAYOUT_API_PREGEN_HD.OAP_ACTION_ID%TYPE,
   in_status       	OL_PAYOUT_API_PREGEN_HD.OAP_STATUS%TYPE)

RETURN NUMBER IS
        iCnt    integer := 0;

BEGIN
 
   SELECT count(*)
   INTO iCnt
   FROM ol_payout_api_pregen_hd
   WHERE oap_action_id = in_action_id
   AND oap_status != in_status;

   IF iCnt > 0 THEN
	RETURN 0;
   ELSE
	IF (in_status = 'W') THEN
		SELECT count(*)
   		INTO iCnt
   		FROM ol_payout_api_pregen_hd
   		WHERE oap_action_id = in_action_id
		AND oap_status = in_status
		AND (oap_pregen_ret_code is not NULL OR oap_gen_ret_code is not NULL);
		
		IF iCnt > 0 THEN
			RETURN 0;
		ELSE
			SELECT count(*)
                	INTO iCnt
                	FROM ol_payout_api_pregen_hd
                	WHERE oap_action_id = in_action_id
                	AND oap_status = in_status
                	AND (oap_pregen_ret_code is NULL AND oap_gen_ret_code is NULL);

			IF iCnt > 0 THEN
                        	RETURN 1;
                	ELSE
				RETURN 0;
			END IF;
		END IF;
	ELSIF (in_status = 'V') THEN
		SELECT count(*)
                INTO iCnt
                FROM ol_payout_api_pregen_hd
                WHERE oap_action_id = in_action_id
		AND oap_status = in_status
                AND (oap_pregen_ret_code != 0 OR oap_gen_ret_code is not NULL);
                
                IF iCnt > 0 THEN
                        RETURN 0;
                ELSE
			SELECT count(*)
                	INTO iCnt
                	FROM ol_payout_api_pregen_hd
                	WHERE oap_action_id = in_action_id
                	AND oap_status = in_status
                	AND (oap_pregen_ret_code = 0 AND oap_gen_ret_code is NULL);
			
			IF iCnt > 0 THEN
                                RETURN 1;
                        ELSE
                                RETURN 0;
                        END IF;
                END IF;
	ELSE
		RETURN 0;	
	END IF;
   END IF;

   RETURN 0;		

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;

END sp_ol_po_api_match_pgen_status;
/
