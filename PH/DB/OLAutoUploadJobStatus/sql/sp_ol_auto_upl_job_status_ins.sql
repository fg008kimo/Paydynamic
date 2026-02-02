CREATE OR REPLACE FUNCTION sp_ol_auto_upl_job_status_ins (
   in_nature_path		ol_auto_upload_job_status.oaujs_nature_path%TYPE,
   in_provider_path          	ol_auto_upload_job_status.oaujs_provider_path%TYPE,
   in_process_bank    		ol_auto_upload_job_status.oaujs_process_bank%TYPE,
   in_exclude_mode           	ol_auto_upload_job_status.oaujs_exclude_mode%TYPE,
   in_job_seq           	ol_auto_upload_job_status.oaujs_job_seq%TYPE,
   in_status             	ol_auto_upload_job_status.oaujs_status%TYPE,
   in_create_user             	ol_auto_upload_job_status.oaujs_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN

   UPDATE ol_auto_upload_job_status
   SET    oaujs_status = in_status,
          oaujs_job_seq = in_job_seq,
          oaujs_update_timestamp = sysdate,
          oaujs_update_user = in_create_user
   WHERE  oaujs_nature_path = in_nature_path
   AND    oaujs_provider_path = in_provider_path
   AND    oaujs_process_bank = in_process_bank
   AND    oaujs_exclude_mode = in_exclude_mode;

   IF SQL%ROWCOUNT = 0 THEN

      INSERT INTO ol_auto_upload_job_status (
                              	oaujs_nature_path,
				oaujs_provider_path,
				oaujs_process_bank,
				oaujs_exclude_mode,
				oaujs_job_seq,
				oaujs_status,
                              	oaujs_create_timestamp,
                              	oaujs_create_user,
                              	oaujs_update_timestamp,
                              	oaujs_update_user)
        VALUES (in_nature_path,
		in_provider_path,
		in_process_bank,
		in_exclude_mode,
		in_job_seq,
		in_status,
                SYSDATE,
                in_create_user,
                SYSDATE,
                in_create_user);

     IF SQL%ROWCOUNT = 0 THEN
     	RETURN 1;
     ELSE
       	RETURN 0;
     END IF;

   ELSE
	RETURN 0;
   END IF;

EXCEPTION
   WHEN OTHERS THEN
      	RETURN 9;
END sp_ol_auto_upl_job_status_ins;
/

