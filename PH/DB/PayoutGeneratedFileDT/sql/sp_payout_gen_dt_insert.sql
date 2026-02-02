CREATE OR REPLACE FUNCTION sp_payout_gen_dt_insert(
	in_file_id		payout_generated_file_dt.fd_file_id%type,
	in_batch_id		payout_generated_file_dt.fd_batch_id%type,
	in_seq_num		payout_generated_file_dt.fd_seq_num%type,
	in_merchant_ref		payout_generated_file_dt.fd_merchant_ref%type,
	in_country		payout_generated_file_dt.fd_country%type,
	in_identity_id		payout_generated_file_dt.fd_identity_id%type,
	in_account_num		payout_generated_file_dt.fd_account_num%type,
	in_account_name		payout_generated_file_dt.fd_account_name%type,
	in_bank_name		payout_generated_file_dt.fd_bank_name%type,
	in_bank_code		payout_generated_file_dt.fd_bank_code%type,
	in_branch		payout_generated_file_dt.fd_branch%type,
	in_phone_num		payout_generated_file_dt.fd_phone_num%type,
	in_province		payout_generated_file_dt.fd_province%type,
	in_city			payout_generated_file_dt.fd_city%type,
	in_payout_amount	payout_generated_file_dt.fd_payout_amount%type,
	in_request_amount	payout_generated_file_dt.fd_request_amount%type,
	in_payout_currency	payout_generated_file_dt.fd_payout_currency%type,
	in_request_currency	payout_generated_file_dt.fd_request_currency%type,
	in_txn_id		payout_generated_file_dt.fd_txn_id%type,
	in_upload_txn_id	payout_generated_file_dt.fd_upload_txn_id%type,
	in_status		payout_generated_file_dt.fd_status%type,
	in_add_user		payout_generated_file_dt.fd_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO payout_generated_file_dt(
	fd_file_id,
	fd_txn_id,
	fd_upload_txn_id,
	fd_batch_id,
	fd_seq_num,
	fd_merchant_ref,
	fd_country,
	fd_identity_id,
	fd_account_num,
	fd_account_name,
	fd_bank_name,
	fd_bank_code,
	fd_branch,
	fd_phone_num,
	fd_province,
	fd_city,
	fd_payout_amount,
	fd_request_amount,
	fd_payout_currency,
	fd_request_currency,
	fd_status,
	fd_create_user,
	fd_update_user,
	fd_create_timestamp,
	fd_update_timestamp
	)

  VALUES(
	in_file_id,
	in_txn_id,
	in_upload_txn_id,
	in_batch_id,
	in_seq_num,
	in_merchant_ref,
	in_country,
	in_identity_id,
	in_account_num,
	in_account_name,
	in_bank_name,
	in_bank_code,
	in_branch,
	in_phone_num,
	in_province,
	in_city,
	in_payout_amount,
	in_request_amount,
	in_payout_currency,
	in_request_currency,
	in_status,
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

END sp_payout_gen_dt_insert;
/
