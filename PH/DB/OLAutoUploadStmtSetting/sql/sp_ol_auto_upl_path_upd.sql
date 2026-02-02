CREATE OR REPLACE FUNCTION sp_ol_auto_upl_path_upd(
	in_server_id         IN	  ol_auto_upload_stmt_setting.oaus_server_id%TYPE,
	in_prov_pathname     IN	  ol_auto_upload_stmt_setting.oaus_provider_pathname%TYPE,
	in_nature            IN	  ol_auto_upload_stmt_setting.oaus_nature%TYPE,
	in_level             IN	  ol_auto_upload_stmt_setting.oaus_level%TYPE,
	in_disabled          IN	  ol_auto_upload_stmt_setting.oaus_disabled%TYPE,
	in_prov_id           IN	  ol_auto_upload_stmt_setting.oaus_provider_id%TYPE,
	in_nature_path       IN	  ol_auto_upload_stmt_setting.oaus_nature_path%TYPE,
	in_process_bank_code IN	  ol_auto_upload_stmt_setting.oaus_process_bank_code%TYPE,
	in_update_user       IN   ol_auto_upload_stmt_setting.oaus_update_user%TYPE
)
return number is
begin
	update ol_auto_upload_stmt_setting
	  set oaus_provider_pathname = in_prov_pathname,
	      oaus_update_timestamp = sysdate,
	      oaus_update_user = in_update_user
        where oaus_provider_id = in_prov_id
          and oaus_nature = in_nature;

	if SQL%ROWCOUNT = 0 THEN
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
				oaus_process_bank_code
			)
			VALUES (
				OL_AUTO_UPLOAD_STMT_JOB_SEQ.NEXTVAL,
				in_server_id,
				in_prov_pathname,
				in_nature,
				in_level,
				sysdate,
				in_update_user,
				sysdate,
				in_update_user,
				in_disabled,
				in_prov_id,
				in_nature_path,
				in_process_bank_code
			);

			if SQL%ROWCOUNT = 0 THEN
				return 1;
			else
				return 0;
			end if;

	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_ol_auto_upl_path_upd;
/
