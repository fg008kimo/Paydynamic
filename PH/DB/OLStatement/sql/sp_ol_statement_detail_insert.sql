CREATE OR REPLACE FUNCTION sp_ol_statement_detail_insert(
	in_stat_txn_id		ol_statement_detail.olsd_stat_txn_id%type,
	in_file_id		ol_statement_detail.olsd_file_id%type,
	in_int_bank_code	ol_statement_detail.olsd_int_bank_code%type,
	in_bank_acct_num	ol_statement_detail.olsd_bank_acct_num%type,
	in_baid			ol_statement_detail.olsd_baid%type,
	in_statement_seq	ol_statement_detail.olsd_statement_seq%type,
	in_txn_id		ol_statement_detail.olsd_txn_id%type,
	in_statement_ref	ol_statement_detail.olsd_statement_ref%type,
	in_input_channel	ol_statement_detail.olsd_input_channel%type,
	in_statement_date	ol_statement_detail.olsd_statement_date%type,
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
	in_amt_type		ol_statement_detail.olsd_amt_type%type,
	in_txn_amount		ol_statement_detail.olsd_txn_amount%type,
	in_txn_ccy		ol_statement_detail.olsd_txn_ccy%type,
	in_create_user		ol_statement_detail.olsd_create_user%type)
  RETURN NUMBER IS
BEGIN
	INSERT INTO ol_statement_detail (
		olsd_stat_txn_id,
		olsd_file_id,
		olsd_int_bank_code,
		olsd_bank_acct_num,
		olsd_baid,
		olsd_statement_seq,
		olsd_txn_id,
		olsd_statement_ref,
		olsd_input_channel,
		olsd_statement_date,
		olsd_statement_time,
		olsd_statement_timestamp,
		olsd_tfr_bank_name,
		olsd_tfr_bank_acct_num,
		olsd_tfr_type,
		olsd_tfr_channel,
		olsd_tfr_text,
		olsd_tfr_customer_text,
		olsd_sender_name,
		olsd_txn_ref_num,
		olsd_keywords_mapping,
		olsd_balance,
		olsd_amt_type,
		olsd_txn_amount,
		olsd_txn_ccy,
		olsd_create_timestamp,
		olsd_create_user,
		olsd_update_timestamp,
		olsd_update_user
		)
	VALUES (	
		in_stat_txn_id,
		in_file_id,
		in_int_bank_code,
		in_bank_acct_num,
		in_baid,
		case when in_statement_seq is null
			then (select NVL(MAX(olsd_statement_seq),0)+1 from ol_statement_detail where olsd_file_id = in_file_id)
			else in_statement_seq
		end,
		in_txn_id,
		in_statement_ref,
		in_input_channel,
		in_statement_date,
		in_statement_time,
		to_date(in_statement_date||in_statement_time,'YYYYMMDDHH24MISS'),
		in_tfr_bank_name,
		in_tfr_bank_acct_num,
		in_tfr_type,
		in_tfr_channel,
		in_tfr_text,
		in_tfr_customer_text,
		in_sender_name,
		in_txn_ref_num,
		in_keywords_mapping,
		in_balance,
		in_amt_type,
		in_txn_amount,
		in_txn_ccy,
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

END sp_ol_statement_detail_insert;
/
