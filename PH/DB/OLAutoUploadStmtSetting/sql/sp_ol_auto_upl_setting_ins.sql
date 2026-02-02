CREATE OR REPLACE FUNCTION sp_ol_auto_upl_setting_ins (
	in_server_id         IN	  ol_auto_upload_stmt_setting.oaus_server_id%TYPE,
	in_prov_pathname     IN	  ol_auto_upload_stmt_setting.oaus_provider_pathname%TYPE,
	in_nature            IN	  ol_auto_upload_stmt_setting.oaus_nature%TYPE,
	in_level             IN	  ol_auto_upload_stmt_setting.oaus_level%TYPE,
	in_disabled          IN	  ol_auto_upload_stmt_setting.oaus_disabled%TYPE,
	in_prov_id           IN	  ol_auto_upload_stmt_setting.oaus_provider_id%TYPE,
	in_nature_path       IN	  ol_auto_upload_stmt_setting.oaus_nature_path%TYPE,
	in_process_bank_code IN	  ol_auto_upload_stmt_setting.oaus_process_bank_code%TYPE,
	in_create_user       IN	  ol_auto_upload_stmt_setting.oaus_create_user%TYPE
)
RETURN NUMBER IS
BEGIN
	INSERT INTO ol_auto_upload_stmt_setting (
		oaus_job_id,
		oaus_server_id,
		oaus_provider_pathname,
		oaus_nature,
		oaus_level,
		oaus_create_timestamp,
		oaus_create_user,
		oaus_update_timestamp,
		oaus_update_user,
		oaus_disabled,
		oaus_provider_id,
		oaus_nature_path,
		oaus_process_bank_code)
	VALUES (
		OL_AUTO_UPLOAD_STMT_JOB_SEQ.NEXTVAL,
		in_server_id,
		in_prov_pathname,
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
END sp_ol_auto_upl_setting_ins;
/
