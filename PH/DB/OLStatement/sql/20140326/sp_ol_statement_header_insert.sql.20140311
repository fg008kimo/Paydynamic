CREATE OR REPLACE FUNCTION sp_ol_statement_header_insert(
	in_filename		ol_statement_header.olsh_filename%type,
	in_int_bank_code	ol_statement_header.olsh_int_bank_code%type,
	in_bank_acct_num	ol_statement_header.olsh_bank_acct_num%type,
	in_baid			ol_statement_header.olsh_baid%type,
	in_sms_count		ol_statement_header.olsh_sms_count%type,
	in_skip_count		ol_statement_header.olsh_skip_count%type,
	in_hold_count		ol_statement_header.olsh_hold_count%type,
	in_accept_count		ol_statement_header.olsh_accept_count%type,
	in_total_count		ol_statement_header.olsh_total_count%type,
	in_create_user		ol_statement_header.olsh_create_user%type)
  RETURN NUMBER IS
BEGIN

	INSERT INTO ol_statement_header (
		olsh_filename,
		olsh_int_bank_code,
		olsh_bank_acct_num,
		olsh_baid,
		olsh_sms_count,
		olsh_skip_count,
		olsh_hold_count,
		olsh_accept_count,
		olsh_total_count,
		olsh_create_timestamp,
		olsh_create_user,
		olsh_update_timestamp,
		olsh_update_user
		)
	VALUES (	
		in_filename,
		in_int_bank_code,
		in_bank_acct_num,
		in_baid,
		in_sms_count,
		in_skip_count,
		in_hold_count,
		in_accept_count,
		in_total_count,
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

END sp_ol_statement_header_insert;
/
