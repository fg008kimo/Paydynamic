CREATE OR REPLACE FUNCTION sp_psp_keys_delete(
	in_psp_id		psp_keys.psp_id%type,
	in_key			psp_keys.key%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM psp_keys
	WHERE	key=in_key
	AND	psp_id=in_psp_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_psp_keys_delete;
/
