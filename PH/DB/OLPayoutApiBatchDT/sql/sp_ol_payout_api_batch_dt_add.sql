CREATE OR REPLACE FUNCTION sp_ol_payout_api_batch_dt_add(
	in_batch_id		ol_payout_api_batch_dt.oad_batch_id%type,
	in_seq			ol_payout_api_batch_dt.oad_seq%type,
	in_txn_id		ol_payout_api_batch_dt.oad_txn_id%type,
	in_ret_code		ol_payout_api_batch_dt.oad_ret_code%type,
	in_add_user		ol_payout_api_batch_dt.oad_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO ol_payout_api_batch_dt(
	oad_batch_id,
	oad_seq,
	oad_txn_id,
	oad_ret_code,
	oad_create_user,
	oad_update_user,
	oad_create_timestamp,
	oad_update_timestamp
	)

  VALUES(
	in_batch_id,
	in_seq,
	in_txn_id,
	in_ret_code,
	in_add_user,
	in_add_user,
	sysdate,
	sysdate
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_payout_api_batch_dt_add;
/
