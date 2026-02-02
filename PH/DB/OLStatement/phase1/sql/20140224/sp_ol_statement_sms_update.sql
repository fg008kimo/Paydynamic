CREATE OR REPLACE FUNCTION sp_ol_statement_sms_update(
	in_int_bank_code	ol_statement_detail.olsd_int_bank_code%type,
	in_bank_acct_num	ol_statement_detail.olsd_bank_acct_num%type,
	in_baid			ol_statement_detail.olsd_baid%type,
	in_statement_date	ol_statement_detail.olsd_statement_date%type,
	in_amt_type		ol_statement_detail.olsd_amt_type%type,
	in_txn_amount		ol_statement_detail.olsd_txn_amount%type,
	in_filename		ol_statement_detail.olsd_filename%type,
	in_statement_seq	ol_statement_detail.olsd_statement_seq%type,
	in_statement_time	ol_statement_detail.olsd_statement_time%type,
	in_tfr_bank_name	ol_statement_detail.olsd_tfr_bank_name%type,
	in_tfr_bank_acct_num	ol_statement_detail.olsd_tfr_bank_acct_num%type,
	in_tfr_type		ol_statement_detail.olsd_tfr_type%type,
	in_tfr_channel		ol_statement_detail.olsd_tfr_channel%type,
	in_tfr_text		ol_statement_detail.olsd_tfr_text%type,
	in_tfr_customer_text	ol_statement_detail.olsd_tfr_customer_text%type,
	in_sender_name		ol_statement_detail.olsd_sender_name%type,
	in_txn_ref_num		ol_statement_detail.olsd_txn_ref_num%type,
	in_balance		ol_statement_detail.olsd_balance%type,
	in_update_user		ol_statement_detail.olsd_update_user%type,
	out_txn_id		OUT ol_statement_detail.olsd_txn_id%type)
  RETURN NUMBER IS
	statementRef	ol_statement_detail.olsd_statement_ref%type;
BEGIN
	select	to_char(OMT_TXN_SEQ.NEXTVAL, 'FM0999999999999999')
	into	statementRef
	from	dual;

	SELECT MIN(olsd_txn_id)
	INTO out_txn_id
	FROM	ol_statement_detail
					WHERE olsd_int_bank_code = in_int_bank_code
					AND olsd_bank_acct_num = in_bank_acct_num
					AND olsd_baid = in_baid
					AND olsd_statement_date = in_statement_date
					AND olsd_txn_amount = in_txn_amount
					AND olsd_amt_type = in_amt_type
					AND olsd_input_channel = 'SMS_STMT'
					AND olsd_statement_ref is NULL;

	UPDATE	ol_statement_detail
	SET	olsd_update_timestamp = sysdate,
		olsd_update_user = NVL(in_update_user,olsd_update_user),
		olsd_filename = NVL(in_filename,olsd_filename),
		olsd_statement_seq = NVL(in_statement_seq,olsd_statement_seq),
		olsd_statement_ref = statementRef,
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
		olsd_balance = NVL(in_balance,olsd_balance)
	WHERE	olsd_txn_id = out_txn_id;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_ol_statement_sms_update;
/

