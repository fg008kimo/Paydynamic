CREATE OR REPLACE FUNCTION sp_email_sett_hist_insert (
   in_party_type	email_setting_history.esh_party_type%TYPE,
   in_party_id		email_setting_history.esh_party_id%TYPE,
   in_funct		email_setting_history.esh_funct%TYPE,
   in_email_id		email_setting_history.esh_email_id%TYPE,
   in_default          	email_setting_history.esh_default%TYPE,
   in_disabled         	email_setting_history.esh_disabled%TYPE,
   in_log_seq		email_setting_history.esh_log_seq%TYPE,
   in_create_user      	email_setting_history.esh_create_user%TYPE) 
  RETURN NUMBER
IS
BEGIN
   INSERT INTO email_setting_history (esh_party_type,
				  esh_party_id,
				  esh_funct,
				  esh_email_id,
				  esh_default,
				  esh_disabled,
				  esh_log_seq,
				  esh_create_user,
				  esh_create_timestamp)

   VALUES (
        in_party_type,
        in_party_id,
        in_funct,
        in_email_id,
        in_default,
        in_disabled,
        in_log_seq,
        in_create_user,
        SYSDATE
        );
	
   IF SQL%ROWCOUNT = 0
   THEN
      RETURN 1;
   ELSE
      RETURN 0;
   END IF;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_email_sett_hist_insert;
/

