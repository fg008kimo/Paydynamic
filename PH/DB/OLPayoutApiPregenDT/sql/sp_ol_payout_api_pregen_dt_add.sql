CREATE OR REPLACE FUNCTION sp_ol_payout_api_pregen_dt_add(
	in_batch_id		ol_payout_api_pregen_dt.oag_batch_id%type,
	in_seq			ol_payout_api_pregen_dt.oag_seq%type,
	in_txn_id		ol_payout_api_pregen_dt.oag_txn_id%type,
	in_psp_id		ol_payout_api_pregen_dt.oag_psp_id%type,
	in_bank_code		ol_payout_api_pregen_dt.oag_bank_code%type,
	in_file_id		ol_payout_api_pregen_dt.oag_file_id%type,
	in_add_user		ol_payout_api_pregen_dt.oag_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO ol_payout_api_pregen_dt(
	oag_batch_id,
	oag_seq,
	oag_txn_id,
	oag_psp_id,
	oag_bank_code,
	oag_file_id,
	oag_create_user,
	oag_update_user,
	oag_create_timestamp,
	oag_update_timestamp
	)

  VALUES(
	in_batch_id,
	in_seq,
	in_txn_id,
	in_psp_id,
	in_bank_code,
	in_file_id,
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

END sp_ol_payout_api_pregen_dt_add;
/
