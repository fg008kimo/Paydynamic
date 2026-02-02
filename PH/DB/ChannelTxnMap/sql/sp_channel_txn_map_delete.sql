CREATE OR REPLACE FUNCTION sp_channel_txn_map_delete(
	in_channel_code			channel_txn_map.ct_channel_code%type,
	in_txn_code			channel_txn_map.ct_txn_code%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM channel_txn_map
	WHERE ct_channel_code = in_channel_code	
	AND ct_txn_code = in_txn_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_channel_txn_map_delete;
/
