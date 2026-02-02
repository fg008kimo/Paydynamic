CREATE OR REPLACE FUNCTION sp_map_txn_element_delete(
	in_txn_code			map_txn_element.mt_txn_code%type,
	in_element			map_txn_element.mt_element%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM map_txn_element
	WHERE	mt_txn_code = in_txn_code
	AND	mt_element = in_element;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_map_txn_element_delete;
/
