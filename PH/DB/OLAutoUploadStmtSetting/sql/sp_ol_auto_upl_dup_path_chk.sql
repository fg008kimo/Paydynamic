CREATE OR REPLACE FUNCTION sp_ol_auto_upl_dup_path_chk (
	in_prov_id          IN  ol_auto_upload_stmt_setting.oaus_provider_id%TYPE,
	in_prov_pathname    IN  ol_auto_upload_stmt_setting.oaus_provider_pathname%TYPE)
RETURN NUMBER IS
	iCnt Integer := 0;
BEGIN

	select count(1) 
	into	iCnt
	from ol_auto_upload_stmt_setting 
	where oaus_provider_pathname = in_prov_pathname 
	and oaus_provider_id <> NVL(in_prov_id,0);
	
	if iCnt > 0 then
		return 1;
	else
		return 0;
	end if;
	

EXCEPTION
	WHEN OTHERS THEN
		return 9;
END sp_ol_auto_upl_dup_path_chk;
/
