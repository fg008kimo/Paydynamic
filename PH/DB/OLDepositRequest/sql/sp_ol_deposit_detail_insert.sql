CREATE OR REPLACE FUNCTION sp_ol_deposit_detail_insert(
	in_file_id			ol_deposit_request_detail.oldd_file_id%type,
	in_deposit_seq			ol_deposit_request_detail.oldd_deposit_seq%type,
	in_int_bank_code		ol_deposit_request_detail.oldd_int_bank_code%type,
	in_bank_acct_num		ol_deposit_request_detail.oldd_bank_acct_num%type,
	in_service_code			ol_deposit_request_detail.oldd_service_code%type,
	in_country			ol_deposit_request_detail.oldd_country%type,
	in_merchant_ref			ol_deposit_request_detail.oldd_merchant_ref%type,
	in_cust_deposit_datetime	ol_deposit_request_detail.oldd_cust_deposit_datetime%type,
	in_deposit_bank			ol_deposit_request_detail.oldd_deposit_bank%type,
	in_deposit_ref			ol_deposit_request_detail.oldd_deposit_ref%type,
	in_deposit_amount		ol_deposit_request_detail.oldd_deposit_amount%type,
	in_deposit_ccy			ol_deposit_request_detail.oldd_deposit_ccy%type,
	in_deposit_flow			ol_deposit_request_detail.oldd_deposit_flow%type,
	in_cust_deposit_dt_prov		ol_deposit_request_detail.oldd_cust_deposit_dt_prov%type,
	in_create_user			ol_deposit_request_detail.oldd_create_user%type)
  RETURN NUMBER IS
BEGIN

	INSERT INTO ol_deposit_request_detail (
		oldd_file_id,
		oldd_deposit_seq,
		oldd_int_bank_code,
		oldd_bank_acct_num,
		oldd_service_code,
		oldd_country,
		oldd_merchant_ref,
		oldd_cust_deposit_datetime,
		oldd_deposit_bank,
		oldd_deposit_ref,
		oldd_deposit_amount,
		oldd_deposit_ccy,
		oldd_deposit_flow,
		oldd_cust_deposit_dt_prov,
		oldd_create_timestamp,
		oldd_create_user,
		oldd_update_timestamp,
		oldd_update_user
		)
	VALUES (	
		in_file_id,
		in_deposit_seq,
		in_int_bank_code,
		in_bank_acct_num,
		in_service_code,
		in_country,
		in_merchant_ref,
		in_cust_deposit_datetime,
		in_deposit_bank,
		in_deposit_ref,
		in_deposit_amount,
		in_deposit_ccy,
		in_deposit_flow,
		in_cust_deposit_dt_prov,
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

END sp_ol_deposit_detail_insert;
/
