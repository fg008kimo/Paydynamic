CREATE OR REPLACE FUNCTION sp_ol_statement_sms_insert(
	in_int_bank_code ol_statement_detail.olsd_int_bank_code%type,
	in_bank_acct_num ol_statement_detail.olsd_bank_acct_num%type,
	in_baid ol_statement_detail.olsd_baid%type,
	in_input_channel ol_statement_detail.olsd_input_channel%type,
	in_statement_date ol_statement_detail.olsd_statement_date%type,
	in_statement_time ol_statement_detail.olsd_statement_time%type,
	in_balance ol_statement_detail.olsd_balance%type,
	in_amt_type ol_statement_detail.olsd_amt_type%type,
	in_txn_amount ol_statement_detail.olsd_txn_amount%type,
	in_create_user ol_statement_detail.olsd_create_user%type)
RETURN NUMBER IS
	v_stat_txn_id ol_statement_detail.olsd_stat_txn_id%type;
BEGIN
	SELECT 'C' || to_char(STMT_TXN_SEQ.NEXTVAL, 'FM099999999999999')
	INTO v_stat_txn_id
	FROM DUAL;

	INSERT INTO ol_statement_detail (
		olsd_stat_txn_id,
		olsd_int_bank_code,
		olsd_bank_acct_num,
		olsd_baid,
		olsd_input_channel,
		olsd_statement_date,
		olsd_statement_time,
		olsd_statement_timestamp,
		olsd_balance,
		olsd_amt_type,
		olsd_txn_amount,
		olsd_txn_ccy,
		olsd_create_timestamp,
		olsd_create_user,
		olsd_update_timestamp,
		olsd_update_user
	) VALUES (
		v_stat_txn_id,
		in_int_bank_code,
		in_bank_acct_num,
		in_baid,
		in_input_channel,
		in_statement_date,
		NVL(in_statement_time, to_char(sysdate, 'hh24miss')),
		to_date(in_statement_date||NVL(in_statement_time, to_char(sysdate, 'hh24miss')),'YYYYMMDDHH24MISS'),
		in_balance,
		in_amt_type,
		in_txn_amount,
		(select ob_acct_ccy
		 from ol_bank_accts
		 where ob_int_bank_code = in_int_bank_code
		 and ob_bank_acct_num like '%' || substr(in_bank_acct_num, -4, 4)),
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

END sp_ol_statement_sms_insert;
/

