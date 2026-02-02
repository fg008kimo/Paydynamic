CREATE OR REPLACE FUNCTION sp_merch_upload_dt_insert(
	in_batch_id		merchant_upload_file_detail.ud_batch_id%type,
	in_seq_num		merchant_upload_file_detail.ud_seq_num%type,
	in_txn_id		merchant_upload_file_detail.ud_txn_id%type,
	in_aux_txn_id		merchant_upload_file_detail.ud_aux_txn_id%type,
	in_merchant_ref		merchant_upload_file_detail.ud_merchant_ref%type,
	in_country		merchant_upload_file_detail.ud_country%type,
	in_identity_id		merchant_upload_file_detail.ud_identity_id%type,
	in_account_num		merchant_upload_file_detail.ud_account_num%type,
	in_account_name		merchant_upload_file_detail.ud_account_name%type,
	in_bank_name		merchant_upload_file_detail.ud_bank_name%type,
	in_bank_code		merchant_upload_file_detail.ud_bank_code%type,
	in_branch		merchant_upload_file_detail.ud_branch%type,
	in_phone_num		merchant_upload_file_detail.ud_phone_num%type,
	in_province		merchant_upload_file_detail.ud_province%type,
	in_city			merchant_upload_file_detail.ud_city%type,
	in_payout_currency	merchant_upload_file_detail.ud_payout_currency%type,
	in_payout_amount	merchant_upload_file_detail.ud_payout_amount%type,
	in_request_currency	merchant_upload_file_detail.ud_request_currency%type,
	in_request_amount	merchant_upload_file_detail.ud_request_amount%type,
	in_merchant_fee_ccy	merchant_upload_file_detail.ud_merchant_fee_ccy%type,
	in_merchant_fee		merchant_upload_file_detail.ud_merchant_fee%type,
	in_member_fee_ccy	merchant_upload_file_detail.ud_member_fee_ccy%type,
	in_member_fee		merchant_upload_file_detail.ud_member_fee%type,
	in_markup_ccy		merchant_upload_file_detail.ud_markup_ccy%type,
	in_markup_amt		merchant_upload_file_detail.ud_markup_amt%type,
	in_ex_rate		merchant_upload_file_detail.ud_exchange_rate%type,
	in_status		merchant_upload_file_detail.ud_status%type,
	in_remark		merchant_upload_file_detail.ud_remark%type,
	in_user			merchant_upload_file_detail.ud_create_user%type
)
  RETURN NUMBER IS

BEGIN
  INSERT INTO merchant_upload_file_detail(
	ud_batch_id,
	ud_seq_num,
	ud_txn_id,
	ud_aux_txn_id,
	ud_merchant_ref,
	ud_country,
	ud_identity_id,
	ud_account_num,
	ud_account_name,
	ud_bank_name,
	ud_bank_code,
	ud_branch,
	ud_phone_num,
	ud_province,
	ud_city,
	ud_payout_currency,
	ud_payout_amount,
	ud_request_currency,
	ud_request_amount,
	ud_merchant_fee_ccy,
	ud_merchant_fee,
	ud_member_fee_ccy,
	ud_member_fee,
	ud_markup_ccy,
	ud_markup_amt,
	ud_exchange_rate,
	ud_status,
	ud_remark,
	ud_create_timestamp,
        ud_update_timestamp,
        ud_create_user,
        ud_update_user
	)

  VALUES(
	in_batch_id,
	in_seq_num,
	in_txn_id,
	in_aux_txn_id,
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
	in_payout_currency,
	in_payout_amount,
	in_request_currency,
	in_request_amount,
	in_merchant_fee_ccy,
        in_merchant_fee,
        in_member_fee_ccy,
        in_member_fee,
        in_markup_ccy,
        in_markup_amt,
	in_ex_rate,
	in_status,
	in_remark,
	sysdate,
        sysdate,
        in_user,
        in_user
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_upload_dt_insert;
/
