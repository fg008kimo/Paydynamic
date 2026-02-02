CREATE OR REPLACE FUNCTION sp_mms_rule_tolerance_lvl_del(
        in_txn_code                         mms_rule_tolerance_level.mtl_txn_code%type
        )
  RETURN NUMBER IS

BEGIN
  DELETE FROM mms_rule_tolerance_level
        WHERE   mtl_txn_code = in_txn_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_mms_rule_tolerance_lvl_del;
/
