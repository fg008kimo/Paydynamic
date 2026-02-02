CREATE OR REPLACE FUNCTION sp_adjustment_type_delete(
	in_party_type		adjustment_type.at_party_type%type,
	in_code			adjustment_type.at_code%type	
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM adjustment_type
	WHERE	at_party_type = in_party_type
	AND	at_code = in_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_adjustment_type_delete;
/
