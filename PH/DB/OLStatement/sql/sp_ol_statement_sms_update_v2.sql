CREATE OR REPLACE FUNCTION sp_ol_statement_sms_upd_v2(
	in_stat_txn_id		ol_statement_detail.olsd_stat_txn_id%type,
	in_int_bank_code	ol_statement_detail.olsd_int_bank_code%type,
	in_bank_acct_num	ol_statement_detail.olsd_bank_acct_num%type,
	in_statement_date	ol_statement_detail.olsd_statement_date%type,
	in_amt_type		ol_statement_detail.olsd_amt_type%type,
	in_txn_amount		ol_statement_detail.olsd_txn_amount%type,
	in_file_id		ol_statement_detail.olsd_file_id%type,
	in_statement_seq	ol_statement_detail.olsd_statement_seq%type,
	in_statement_ref	ol_statement_detail.olsd_statement_ref%type,
	in_statement_time	ol_statement_detail.olsd_statement_time%type,
	in_tfr_bank_name	ol_statement_detail.olsd_tfr_bank_name%type,
	in_tfr_bank_acct_num	ol_statement_detail.olsd_tfr_bank_acct_num%type,
	in_tfr_type		ol_statement_detail.olsd_tfr_type%type,
	in_tfr_channel		ol_statement_detail.olsd_tfr_channel%type,
	in_tfr_text		ol_statement_detail.olsd_tfr_text%type,
	in_tfr_customer_text	ol_statement_detail.olsd_tfr_customer_text%type,
	in_sender_name		ol_statement_detail.olsd_sender_name%type,
	in_txn_ref_num		ol_statement_detail.olsd_txn_ref_num%type,
	in_keywords_mapping	ol_statement_detail.olsd_keywords_mapping%type,
	in_balance		ol_statement_detail.olsd_balance%type,
	in_update_user		ol_statement_detail.olsd_update_user%type,
	in_raw_date		ol_statement_detail.olsd_raw_date%type,
	in_raw_time		ol_statement_detail.olsd_raw_time%type,
	in_sender_baid_name	ol_statement_detail.olsd_sender_baid_name%type,
	in_recipient_baid_name 	ol_statement_detail.olsd_recipient_baid_name%type,
	in_client_name 		ol_statement_detail.olsd_client_name%type)
  RETURN NUMBER IS
BEGIN

	UPDATE	ol_statement_detail
	SET	olsd_update_timestamp = sysdate,
		olsd_update_user = NVL(in_update_user,olsd_update_user),
		olsd_file_id = NVL(in_file_id,olsd_file_id),
		olsd_statement_seq = NVL(in_statement_seq,olsd_statement_seq),
		olsd_statement_ref = NVL(in_statement_ref,olsd_statement_ref),
		olsd_statement_date = NVL(in_statement_date,olsd_statement_date),
		olsd_statement_time = NVL(in_statement_time,olsd_statement_time),
		olsd_statement_timestamp = to_date(in_statement_date||NVL(in_statement_time,olsd_statement_time),'YYYYMMDDHH24MISS'),
		olsd_tfr_bank_name = NVL(in_tfr_bank_name,olsd_tfr_bank_name),
		olsd_tfr_bank_acct_num = NVL(in_tfr_bank_acct_num,olsd_tfr_bank_acct_num),
		olsd_tfr_type = NVL(in_tfr_type,olsd_tfr_type),
		olsd_tfr_channel = NVL(in_tfr_channel,olsd_tfr_channel),
		olsd_tfr_text = NVL(in_tfr_text,olsd_tfr_text),
		olsd_tfr_customer_text = NVL(in_tfr_customer_text,olsd_tfr_customer_text),
		olsd_sender_name = NVL(in_sender_name,olsd_sender_name),
		olsd_txn_ref_num = NVL(in_txn_ref_num,olsd_txn_ref_num),
		olsd_keywords_mapping = NVL(in_keywords_mapping,olsd_keywords_mapping),
		olsd_balance = NVL(in_balance,olsd_balance),
		olsd_raw_date = NVL(in_raw_date,olsd_raw_date),
		olsd_raw_time = NVL(in_raw_time,olsd_raw_time),
		olsd_sender_baid_name = NVL(in_sender_baid_name,olsd_sender_baid_name),
		olsd_recipient_baid_name = NVL(in_recipient_baid_name,olsd_recipient_baid_name),
		olsd_client_name = NVL(in_client_name,olsd_client_name)
	WHERE	olsd_stat_txn_id = in_stat_txn_id;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_ol_statement_sms_upd_v2;
/

