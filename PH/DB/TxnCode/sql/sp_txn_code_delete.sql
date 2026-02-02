CREATE OR REPLACE FUNCTION sp_txn_code_delete(
	in_txn_code			txn_code.tc_code%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM txn_code
	WHERE	tc_code = in_txn_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_txn_code_delete;
/
