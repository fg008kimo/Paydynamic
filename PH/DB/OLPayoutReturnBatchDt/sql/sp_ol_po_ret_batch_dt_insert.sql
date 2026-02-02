CREATE OR REPLACE FUNCTION sp_ol_po_ret_batch_dt_insert(
	in_batch_id		ol_payout_return_batch_dt.prd_batch_id%type,
	in_seq			ol_payout_return_batch_dt.prd_seq%type,
	in_txn_date		ol_payout_return_batch_dt.prd_txn_date%type,
	in_upload_txn_id	ol_payout_return_batch_dt.prd_upload_txn_id%type,
	in_txn_id		ol_payout_return_batch_dt.prd_txn_id%type,
	in_bank_name		ol_payout_return_batch_dt.prd_bank_name%type,
	in_branch		ol_payout_return_batch_dt.prd_branch%type,
	in_account_name		ol_payout_return_batch_dt.prd_account_name%type,
	in_account_num		ol_payout_return_batch_dt.prd_account_num%type,
	in_amount		ol_payout_return_batch_dt.prd_amount%type,
	in_province		ol_payout_return_batch_dt.prd_province%type,
	in_city			ol_payout_return_batch_dt.prd_city%type,
	in_reason		ol_payout_return_batch_dt.prd_reason%type,
	in_process_bank_name	ol_payout_return_batch_dt.prd_process_bank_name%type,
	in_is_valid		ol_payout_return_batch_dt.prd_is_valid%type,
	in_status		ol_payout_return_batch_dt.prd_status%type,
	in_create_user		ol_payout_return_batch_dt.prd_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO ol_payout_return_batch_dt(
	prd_batch_id,
	prd_seq,
	prd_txn_date,
	prd_upload_txn_id,
	prd_txn_id,
	prd_bank_name,
	prd_branch,
	prd_account_name,
	prd_account_num,
	prd_amount,
	prd_province,
	prd_city,
	prd_reason,
	prd_process_bank_name,
	prd_is_valid,
	prd_status,
	prd_create_timestamp,
        prd_update_timestamp,
        prd_create_user,
        prd_update_user
	)

  VALUES(
	in_batch_id,
	in_seq,
	in_txn_date,
	in_upload_txn_id,
	in_txn_id,
	in_bank_name,
	in_branch,
	in_account_name,
	in_account_num,
	in_amount,
	in_province,
	in_city,
	in_reason,
	in_process_bank_name,
	in_is_valid,
	in_status,
	sysdate,
        sysdate,
        in_create_user,
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

END sp_ol_po_ret_batch_dt_insert;
/
