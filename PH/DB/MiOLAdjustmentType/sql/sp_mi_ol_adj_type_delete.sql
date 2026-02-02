CREATE OR REPLACE FUNCTION sp_mi_ol_adj_type_delete(
	in_entity_type		mi_ol_adjustment_type.moat_entity_type%type,
	in_code			mi_ol_adjustment_type.moat_code%type	
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM mi_ol_adjustment_type
	WHERE	moat_entity_type = in_entity_type
	AND	moat_code = in_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_mi_ol_adj_type_delete;
/
