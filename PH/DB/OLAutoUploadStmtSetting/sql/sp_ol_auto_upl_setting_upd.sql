CREATE OR REPLACE FUNCTION sp_ol_auto_upl_setting_upd (
   in_nature               	ol_auto_upload_stmt_setting.oaus_nature%TYPE,
   in_provider_id             	ol_auto_upload_stmt_setting.oaus_provider_id%TYPE,
   in_disabled                	ol_auto_upload_stmt_setting.oaus_disabled%TYPE,
   in_update_user               ol_auto_upload_stmt_setting.oaus_update_user%TYPE)
  RETURN NUMBER IS

BEGIN

	UPDATE  ol_auto_upload_stmt_setting
	SET     oaus_disabled = in_disabled,
	       	oaus_update_timestamp = SYSDATE,
	      	oaus_update_user = in_update_user
	WHERE   oaus_nature = in_nature
	AND     oaus_provider_id = in_provider_id
	AND     oaus_disabled <> in_disabled;
	
	RETURN 0;

EXCEPTION
   WHEN OTHERS THEN
        RETURN 9;
END sp_ol_auto_upl_setting_upd;
/
