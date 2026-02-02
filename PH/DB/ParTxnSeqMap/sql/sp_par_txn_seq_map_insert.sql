CREATE OR REPLACE FUNCTION sp_par_txn_seq_map_insert (
        in_order_id             par_txn_seq_map.ts_order_id%type,
        in_conv_txn_seq         par_txn_seq_map.ts_conv_txn_seq%type,
	in_create_user		par_payout_upload.pu_create_user%type
)
  RETURN NUMBER IS

BEGIN

  INSERT INTO par_txn_seq_map (
        ts_order_id,
	ts_conv_txn_seq,
        ts_create_timestamp,
	ts_create_user,
	ts_update_timestamp,
	ts_update_user
	)
  VALUES(
	in_order_id,
	in_conv_txn_seq,
	sysdate,
	in_create_user,
	sysdate,
	in_create_user
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_par_txn_seq_map_insert; 
/

