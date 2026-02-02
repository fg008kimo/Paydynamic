DROP FUNCTION sp_ol_psp_detail_insert;

CREATE OR REPLACE FUNCTION sp_ol_psp_detail_insert(
	in_psp_id		ol_psp_detail.opd_psp_id%type,
	in_psp_name		ol_psp_detail.opd_psp_name%type,
	in_disabled		ol_psp_detail.opd_disabled%type,
	in_client_id		ol_psp_detail.opd_client_id%type,
	in_bank_acct_type	ol_psp_detail.opd_bank_acct_type%type,
	in_ccy			ol_psp_detail.opd_currency_id%type,
	in_status		ol_psp_detail.opd_status%type,
	in_payout_split_limit	ol_psp_detail.opd_payout_split_limit%type,
	in_business_type		ol_psp_detail.opd_business_type%type,
	in_code_in_num		ol_psp_detail.opd_code_in_num%type,
	in_create_user		ol_psp_detail.opd_create_user%type
	)
RETURN NUMBER IS

BEGIN
	INSERT INTO ol_psp_detail (
		opd_psp_id,
		opd_psp_name,
		opd_disabled,
		opd_client_id,
		opd_bank_acct_type,
		opd_currency_id,
		opd_status,
		opd_payout_split_limit,
		opd_business_type,
		opd_code_in_num,
		opd_create_user,
		opd_create_timestamp,
		opd_update_user,
		opd_update_timestamp
	)
	VALUES (
		in_psp_id,
		in_psp_name,
		in_disabled,
		in_client_id,
		in_bank_acct_type,
		in_ccy,
		in_status,
		in_payout_split_limit,
		in_business_type,
		in_code_in_num,
		in_create_user,
		sysdate,
		in_create_user,
		sysdate
	);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_ol_psp_detail_insert;
/
