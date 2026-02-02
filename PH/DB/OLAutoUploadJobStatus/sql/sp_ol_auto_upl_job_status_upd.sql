CREATE OR REPLACE FUNCTION sp_ol_auto_upl_job_status_upd (
   in_nature_path       	ol_auto_upload_job_status.oaujs_nature_path%TYPE,
   in_provider_path          	ol_auto_upload_job_status.oaujs_provider_path%TYPE,
   in_process_bank    		ol_auto_upload_job_status.oaujs_process_bank%TYPE,
   in_exclude_mode           	ol_auto_upload_job_status.oaujs_exclude_mode%TYPE,
   in_job_seq           	ol_auto_upload_job_status.oaujs_job_seq%TYPE,
   in_status             	ol_auto_upload_job_status.oaujs_status%TYPE,
   in_update_user             	ol_auto_upload_job_status.oaujs_update_user%TYPE)
   RETURN NUMBER
IS
BEGIN

	UPDATE  ol_auto_upload_job_status
        SET     oaujs_status = in_status,
                oaujs_update_timestamp = SYSDATE,
                oaujs_update_user = in_update_user
        WHERE   oaujs_job_seq = in_job_seq
	AND	oaujs_nature_path = in_nature_path
	AND	oaujs_provider_path = in_provider_path
	AND	oaujs_process_bank = in_process_bank
	AND	oaujs_exclude_mode = in_exclude_mode;	

	IF SQL%ROWCOUNT = 0 THEN
                RETURN 1;
        ELSE
                RETURN 0;
        END IF;

EXCEPTION
   WHEN OTHERS THEN
      	RETURN 9;
END sp_ol_auto_upl_job_status_upd;
/

