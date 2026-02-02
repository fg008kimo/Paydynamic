CREATE OR REPLACE FUNCTION sp_ol_auto_upl_sett_log_ins (
	in_job_id            IN	  ol_auto_upload_stmt_sett_log.oaul_job_id%TYPE,
	in_server_id         IN	  ol_auto_upload_stmt_sett_log.oaul_server_id%TYPE,
	in_prov_pathname_fr  IN	  ol_auto_upload_stmt_sett_log.oaul_provider_pathname_fr%TYPE,
	in_prov_pathname_to  IN	  ol_auto_upload_stmt_sett_log.oaul_provider_pathname_to%TYPE,
	in_nature            IN	  ol_auto_upload_stmt_sett_log.oaul_nature%TYPE,
	in_level             IN	  ol_auto_upload_stmt_sett_log.oaul_level%TYPE,
	in_disabled          IN	  ol_auto_upload_stmt_sett_log.oaul_disabled%TYPE,
	in_prov_id           IN	  ol_auto_upload_stmt_sett_log.oaul_provider_id%TYPE,
	in_nature_path       IN	  ol_auto_upload_stmt_sett_log.oaul_nature_path%TYPE,
	in_process_bank_code IN	  ol_auto_upload_stmt_sett_log.oaul_process_bank_code%TYPE,
	in_create_user       IN   ol_auto_upload_stmt_sett_log.oaul_create_user%TYPE)
RETURN NUMBER IS
BEGIN
	INSERT INTO ol_auto_upload_stmt_sett_log (
		oaul_log_id,
		oaul_job_id,
		oaul_server_id,
		oaul_provider_pathname_fr,
		oaul_provider_pathname_to,
		oaul_nature,
		oaul_level,
		oaul_create_timestamp,
		oaul_create_user,
		oaul_update_timestamp,
		oaul_update_user,
		oaul_disabled,
		oaul_provider_id,
		oaul_nature_path,
		oaul_process_bank_code)
	VALUES (
		OL_AUTO_UPLOAD_STMT_LOG_SEQ.NEXTVAL,
		in_job_id,
		in_server_id,
		in_prov_pathname_fr,
		in_prov_pathname_to,
		in_nature,
		in_level,
		sysdate,
		in_create_user,
		sysdate,
		in_create_user,
		in_disabled,
		in_prov_id,
		in_nature_path,
		in_process_bank_code);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_ol_auto_upl_sett_log_ins;
/
