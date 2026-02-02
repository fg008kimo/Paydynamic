CREATE OR REPLACE FUNCTION sp_language_insert(
	in_lang_code		language.lang_code%type,
	in_description		language.description%type,
	in_active_ind		language.active_ind%type,
	in_create_user		language.create_user%type,
	in_update_user		language.update_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO language(
	lang_code,
	description,
	active_ind, 
	create_user,
	update_user,
	create_timestamp,
	update_timestamp
	)

  VALUES(
	in_lang_code,
	in_description,
	in_active_ind, 
	in_create_user, 
	in_update_user, 
	sysdate,
	sysdate
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_language_insert;
/
