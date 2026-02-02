CREATE OR REPLACE FUNCTION sp_payout_record_insert(
	in_batch_id		payout_record.batch_id%type,
	in_seq_num		payout_record.seq_num%type,
	in_merchant_id		payout_record.merchant_id%type,
	in_merchant_ref		payout_record.merchant_ref%type,
	in_country		payout_record.country%type,
	in_identity_id		payout_record.identity_id%type,
	in_account_num		payout_record.account_num%type,
	in_account_name		payout_record.account_name%type,
	in_bank_name		payout_record.bank_name%type,
	in_bank_code		payout_record.bank_code%type,
	in_branch		payout_record.branch%type,
	in_phone_num		payout_record.phone_num%type,
	in_province		payout_record.province%type,
	in_city			payout_record.city%type,
	in_amount		payout_record.amount%type,
	in_payout_currency	payout_record.payout_currency%type,
	in_dest_currency	payout_record.dest_currency%type,
	in_checksum		payout_record.checksum%type,
	in_status		payout_record.status%type,
	in_resp_code		payout_record.response_code%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO payout_record(
	batch_id,
	seq_num,
	merchant_id,
	merchant_ref,
	country,
	identity_id,
	account_num,
	account_name,
	bank_name,
	bank_code,
	branch,
	phone_num,
	province,
	city,
	amount,
	payout_currency,
	dest_currency,
	checksum,
	status,
	response_code
	)

  VALUES(
	in_batch_id,
	in_seq_num,
	in_merchant_id,
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
	in_amount,
	in_payout_currency,
	in_dest_currency,
	in_checksum,
	in_status,
	in_resp_code
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_payout_record_insert;
/
