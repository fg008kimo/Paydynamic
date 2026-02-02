CREATE OR REPLACE FUNCTION sp_mms_def_txn_sub_stt_map_del(
        in_txn_code                 mms_def_txn_sub_status_map.tss_txn_code%type
        )
  RETURN NUMBER IS

BEGIN
  DELETE FROM mms_def_txn_sub_status_map
        WHERE   tss_txn_code  = in_txn_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_mms_def_txn_sub_stt_map_del;
/
