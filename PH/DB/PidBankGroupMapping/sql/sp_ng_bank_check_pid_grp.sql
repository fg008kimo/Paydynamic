CREATE OR REPLACE FUNCTION sp_ng_bank_check_pid_grp (
   in_psp_id	     psp_detail.psp_id%TYPE,
   in_service_code   pid_bank_group_mapping.pgm_service_code%TYPE)

RETURN NUMBER IS
	iCnt    integer := 0;

BEGIN

   SELECT       count(*)
   INTO         iCnt
   FROM		pid_bank_group_mapping
   WHERE	pgm_service_code = in_service_code
   AND		pgm_disabled = 0;			

   IF iCnt > 0 THEN	
   		SELECT 	count(*)
   		INTO 	iCnt
   		FROM 	pid_bank_group_mapping,
        		(SELECT nbxa_pid_group,
                		internal_bank_code,
                		bank_group
        		FROM 	psp_detail, 
		    		bank_mapping, 
				bank_desc
       	 		WHERE psp_id = in_psp_id
        		AND ((overrided_bank_code_channel IS NOT NULL and overrided_bank_code_channel = bm_psp_channel_id)
            	     	     OR (overrided_bank_code_channel IS NULL and psp_channel_code = bm_psp_channel_id))
        		AND bm_int_bank_code = internal_bank_code        
        		AND bm_disabled = 0)
   		WHERE   (((pgm_bank_code = internal_bank_code) or (pgm_bank_code = bank_group) or (pgm_bank_group = internal_bank_code))
   	    	 	 AND (bank_group IS NOT NULL)
       	    		)
   		AND 	pgm_pid_group = nbxa_pid_group    
   		AND	pgm_service_code = in_service_code	
   		AND	pgm_disabled = 0;
 
   		IF iCnt > 0 THEN
        		RETURN 1;
		ELSE
			RETURN 0;
   		END IF;
   ELSE
		RETURN 1;	
   END IF;	

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_ng_bank_check_pid_grp;
/
