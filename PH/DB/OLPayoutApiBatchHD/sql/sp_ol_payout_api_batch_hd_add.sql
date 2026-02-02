CREATE OR REPLACE FUNCTION sp_ol_payout_api_batch_hd_add(
	in_batch_id		ol_payout_api_batch_hd.oah_batch_id%type,
	in_txn_code		ol_payout_api_batch_hd.oah_txn_code%type,
	in_status		ol_payout_api_batch_hd.oah_status%type,
	in_ret_code		ol_payout_api_batch_hd.oah_ret_code%type,
	in_add_user		ol_payout_api_batch_hd.oah_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO ol_payout_api_batch_hd(
	oah_batch_id,
	oah_txn_code,
	oah_status,
	oah_ret_code,
	oah_create_user,
	oah_update_user,
	oah_create_timestamp,
	oah_update_timestamp
	)

  VALUES(
	in_batch_id,
	in_txn_code,
	in_status,
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

END sp_ol_payout_api_batch_hd_add;
/
