CREATE OR REPLACE FUNCTION sp_ol_auto_upl_err_log_ins (
   in_job_seq           	ol_auto_upload_err_log.oauel_job_seq%TYPE,
   in_nature          		ol_auto_upload_err_log.oauel_nature%TYPE,
   in_provider_id          	ol_auto_upload_err_log.oauel_provider_id%TYPE,
   in_provider_name          	ol_auto_upload_err_log.oauel_provider%TYPE,
   in_int_bank_code          	ol_auto_upload_err_log.oauel_int_bank_code%TYPE,
   in_bank_name          	ol_auto_upload_err_log.oauel_bank_name%TYPE,
   in_bank_acct_short_name    	ol_auto_upload_err_log.oauel_acct_short_name%TYPE,
   in_bank_acct_num            	ol_auto_upload_err_log.oauel_acct_num%TYPE,
   in_stmt_filename            	ol_auto_upload_err_log.oauel_stmt_filename%TYPE,
   in_status             	ol_auto_upload_err_log.oauel_status%TYPE,
   in_err_code        		ol_auto_upload_err_log.oauel_err_code%TYPE,
   in_create_user             	ol_auto_upload_err_log.oauel_create_user%TYPE)
   RETURN NUMBER 
IS
BEGIN

   INSERT INTO ol_auto_upload_err_log (oauel_job_seq,
				oauel_nature,
				oauel_provider_id,
				oauel_provider,
				oauel_int_bank_code,
				oauel_bank_name,
				oauel_acct_short_name,
				oauel_acct_num,
				oauel_stmt_filename,
				oauel_status,
				oauel_err_code,
                              	oauel_create_timestamp,
                              	oauel_create_user,
                              	oauel_update_timestamp,
                              	oauel_update_user)
        VALUES (in_job_seq,
		in_nature,
		in_provider_id,
		in_provider_name,
		in_int_bank_code,
		in_bank_name,
		in_bank_acct_short_name,
		in_bank_acct_num,
		in_stmt_filename,
		in_status,
		in_err_code,
                SYSDATE,
                in_create_user,
                SYSDATE,
                in_create_user);

   IF SQL%ROWCOUNT = 0 THEN
     	RETURN 1;
   ELSE
       	RETURN 0;
   END IF;

EXCEPTION
   WHEN OTHERS THEN
      	RETURN 9;
END sp_ol_auto_upl_err_log_ins;
/

