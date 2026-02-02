CREATE OR REPLACE FUNCTION sp_language_delete(
	in_lang_code		language.lang_code%type)
  RETURN NUMBER IS

BEGIN
  DELETE FROM language
	WHERE lang_code=in_lang_code;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_language_delete;
/
