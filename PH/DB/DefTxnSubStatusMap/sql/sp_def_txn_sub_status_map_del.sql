CREATE OR REPLACE FUNCTION sp_def_txn_sub_status_map_del(
        in_txn_code                 def_txn_sub_status_map.dsm_txn_code%type
        )
  RETURN NUMBER IS

BEGIN
  DELETE FROM def_txn_sub_status_map
        WHERE   dsm_txn_code  = in_txn_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_def_txn_sub_status_map_del;
/
