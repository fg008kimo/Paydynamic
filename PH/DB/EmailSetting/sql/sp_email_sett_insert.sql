CREATE OR REPLACE FUNCTION sp_email_sett_insert (
	in_email_id             email_setting.es_email_id%TYPE,
	in_party_type      	email_setting.es_party_type%TYPE,
	in_party_id        	email_setting.es_party_id%TYPE,
	in_funct	      	email_setting.es_funct%TYPE,
	in_default         	email_setting.es_default%TYPE,	
	in_disabled        	email_setting.es_disabled%TYPE,
	in_create_user         	email_setting.es_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO email_setting (
	es_email_id,
     	es_party_type,
       	es_party_id,
      	es_funct,
       	es_default,
     	es_disabled,
     	es_create_user,
       	es_update_user,
     	es_create_timestamp,
       	es_update_timestamp
	)

  VALUES (
	in_email_id,
       	in_party_type,
       	in_party_id,
      	in_funct,
       	in_default,
      	in_disabled,
       	in_create_user,
       	in_create_user,
       	SYSDATE,
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

END sp_email_sett_insert;
/

