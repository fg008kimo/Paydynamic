CREATE OR REPLACE FUNCTION sp_ol_pf_txn_init_dt_insert(
	in_file_id			ol_pf_txn_init_detail.opid_file_id%type,
	in_seq				ol_pf_txn_init_detail.opid_seq%type,
	in_txn_id			ol_pf_txn_init_detail.opid_txn_id%type,
	in_baid				ol_pf_txn_init_detail.opid_baid%type,
	in_report_date			ol_pf_txn_init_detail.opid_report_date%type,
	in_ccy				ol_pf_txn_init_detail.opid_ccy%type,
	in_txn_type			ol_pf_txn_init_detail.opid_txn_type%type,
	in_debit_amt			ol_pf_txn_init_detail.opid_debit_amt%type,
	in_credit_amt			ol_pf_txn_init_detail.opid_credit_amt%type,
	in_baid_name			ol_pf_txn_init_detail.opid_baid_name%type,
	in_remark			ol_pf_txn_init_detail.opid_remark%type,
	in_create_user			ol_pf_txn_init_detail.opid_create_user%type)
  RETURN NUMBER IS
BEGIN

	INSERT INTO ol_pf_txn_init_detail (
		opid_file_id,
		opid_seq,
		opid_txn_id,
		opid_baid,
		opid_report_date,
		opid_ccy,
		opid_txn_type,
		opid_debit_amt,
		opid_credit_amt,
		opid_baid_name,
		opid_remark,
		opid_create_timestamp,
		opid_create_user,
		opid_update_timestamp,
		opid_update_user
		)
	VALUES (	
		in_file_id,
		in_seq,
		in_txn_id,
		in_baid,
		in_report_date,
		in_ccy,
		in_txn_type,
		in_debit_amt,
		in_credit_amt,
		in_baid_name,
		in_remark,
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
	WHEN	OTHERS THEN
		RETURN 9;

END sp_ol_pf_txn_init_dt_insert;
/
