CREATE OR REPLACE FUNCTION sp_mms_txn_code_delete(
        in_txn_code                     mms_txn_code.mtc_code%type
        )
  RETURN NUMBER IS

BEGIN
  DELETE FROM mms_txn_code
        WHERE   mtc_code = in_txn_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_mms_txn_code_delete;
/
