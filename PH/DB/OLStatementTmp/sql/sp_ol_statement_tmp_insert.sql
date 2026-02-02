CREATE OR REPLACE FUNCTION sp_ol_statement_tmp_insert(
	in_file_id		ol_statement_tmp.olst_file_id%type,
	in_seq			ol_statement_tmp.olst_seq%type,
	in_ver			ol_statement_tmp.olst_ver%type,
	in_latest_ver		ol_statement_tmp.olst_latest_ver%type,
	in_disabled		ol_statement_tmp.olst_disabled%type,
	in_int_bank_code	ol_statement_tmp.olst_int_bank_code%type,
	in_bank_acct_num	ol_statement_tmp.olst_bank_acct_num%type,
	in_sys_seq		ol_statement_tmp.olst_sys_seq%type,
	in_user_seq		ol_statement_tmp.olst_user_seq%type,
	in_skip			ol_statement_tmp.olst_skip%type,
	in_raw_date		ol_statement_tmp.olst_raw_date%type,
	in_raw_time		ol_statement_tmp.olst_raw_time%type,
	in_statement_date	ol_statement_tmp.olst_statement_date%type,
	in_statement_time	ol_statement_tmp.olst_statement_time%type,
	in_tfr_bank_name	ol_statement_tmp.olst_tfr_bank_name%type,
	in_tfr_bank_acct_num	ol_statement_tmp.olst_tfr_bank_acct_num%type,
	in_tfr_type		ol_statement_tmp.olst_tfr_type%type,
	in_tfr_channel		ol_statement_tmp.olst_tfr_channel%type,
	in_tfr_text		ol_statement_tmp.olst_tfr_text%type,
	in_tfr_customer_text	ol_statement_tmp.olst_tfr_customer_text%type,
	in_sender_name		ol_statement_tmp.olst_sender_name%type,
	in_txn_ref_num		ol_statement_tmp.olst_txn_ref_num%type,
	in_balance		ol_statement_tmp.olst_balance%type,
	in_amt_type		ol_statement_tmp.olst_amt_type%type,
	in_txn_amount		ol_statement_tmp.olst_txn_amount%type,
	in_bank_charge		ol_statement_tmp.olst_bank_charge%type,
	in_sender_baid_name	ol_statement_tmp.olst_sender_baid_name%type,
	in_recipient_baid_name 	ol_statement_tmp.olst_recipient_baid_name%type,
	in_client_name 		ol_statement_tmp.olst_client_name%type,
	in_create_user		ol_statement_tmp.olst_create_user%type)
  RETURN NUMBER IS
BEGIN
	INSERT INTO ol_statement_tmp (
		olst_file_id,
		olst_seq,
		olst_ver,
		olst_latest_ver,
		olst_disabled,
		olst_int_bank_code,
		olst_bank_acct_num,
		olst_sys_seq,
		olst_user_seq,
		olst_skip,
		olst_raw_date,
		olst_raw_time,
		olst_statement_date,
		olst_statement_time,
		olst_tfr_bank_name,
		olst_tfr_bank_acct_num,
		olst_tfr_type,
		olst_tfr_channel,
		olst_tfr_text,
		olst_tfr_customer_text,
		olst_sender_name,
		olst_txn_ref_num,
		olst_balance,
		olst_amt_type,
		olst_txn_amount,
		olst_bank_charge,
		olst_sender_baid_name,
		olst_recipient_baid_name,
		olst_client_name,
		olst_create_timestamp,
		olst_create_user,
		olst_update_timestamp,
		olst_update_user
		)
	VALUES (	
		in_file_id,
		in_seq,
		in_ver,
		in_latest_ver,
		in_disabled,
		in_int_bank_code,
		in_bank_acct_num,
		in_sys_seq,
		in_user_seq,
		in_skip,
		in_raw_date,
		in_raw_time,
		in_statement_date,
		in_statement_time,
		in_tfr_bank_name,
		in_tfr_bank_acct_num,
		in_tfr_type,
		in_tfr_channel,
		in_tfr_text,
		in_tfr_customer_text,
		in_sender_name,
		in_txn_ref_num,
		in_balance,
		in_amt_type,
		in_txn_amount,
		in_bank_charge,
		in_sender_baid_name,
		in_recipient_baid_name,
		in_client_name,
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

END sp_ol_statement_tmp_insert;
/
