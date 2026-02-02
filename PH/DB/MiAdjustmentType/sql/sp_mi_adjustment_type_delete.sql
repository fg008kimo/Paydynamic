CREATE OR REPLACE FUNCTION sp_mi_adjustment_type_delete(
	in_entity_type		mi_adjustment_type.mat_entity_type%type,
	in_code			mi_adjustment_type.mat_code%type	
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM mi_adjustment_type
	WHERE	mat_entity_type = in_entity_type
	AND	mat_code = in_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_mi_adjustment_type_delete;
/
