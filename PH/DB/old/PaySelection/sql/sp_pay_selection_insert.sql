CREATE OR REPLACE FUNCTION sp_pay_selection_insert(
	in_seq_num		pay_selection.seq_num%type,
	in_file_seq		pay_selection.file_seq%type,
	in_merchant_ref		pay_selection.merchant_ref%type,
	in_account_num		pay_selection.account_num%type,
	in_account_name		pay_selection.account_name%type,
	in_bank_name		pay_selection.bank_name%type,
	in_branch		pay_selection.branch%type,
	in_amount		pay_selection.amount%type,
	in_payout_currency	pay_selection.currency%type,
	in_province		pay_selection.province%type,
	in_city			pay_selection.city%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO pay_selection(
	seq_num,
	file_seq,
	merchant_ref,
	account_num,
	account_name,
	bank_name,
	branch,
	amount,
	currency,
	province,
	city
	)

  VALUES(
	in_seq_num,
	in_file_seq,
	in_merchant_ref,
	in_account_num,
	in_account_name,
	in_bank_name,
	in_branch,
	in_amount,
	in_payout_currency,
	in_province,
	in_city
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_pay_selection_insert;
/
