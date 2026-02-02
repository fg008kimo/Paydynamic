CREATE OR REPLACE FUNCTION sp_email_sett_upd_def(
	in_funct		email_setting.es_funct%type,
	in_party_id		email_setting.es_party_id%type,
	in_party_type		email_setting.es_party_type%type,
	in_default		email_setting.es_default%type,
	in_update_user		email_setting.es_update_user%type)
  RETURN NUMBER IS
BEGIN
	
	UPDATE 	EMAIL_SETTING
	SET     ES_DEFAULT = in_default,
		ES_UPDATE_USER = in_update_user,
		ES_UPDATE_TIMESTAMP = sysdate
        WHERE   ES_FUNCT = in_funct
        AND     ES_PARTY_ID = in_party_id
        AND     ES_PARTY_TYPE = in_party_type
	AND	ES_DISABLED = 0;

	IF SQL%ROWCOUNT = 0 THEN
                RETURN 2;
        ELSE
                RETURN 0;
        END IF;

EXCEPTION
        WHEN OTHERS THEN
                RETURN 9;

END sp_email_sett_upd_def;
/
