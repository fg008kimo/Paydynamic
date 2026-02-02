CREATE OR REPLACE FUNCTION sp_ol_statement_header_ins_v2(
	in_file_id		ol_statement_header.olsh_file_id%type,
	in_filename		ol_statement_header.olsh_filename%type,
	in_int_bank_code	ol_statement_header.olsh_int_bank_code%type,
	in_bank_acct_num	ol_statement_header.olsh_bank_acct_num%type,
	in_baid			ol_statement_header.olsh_baid%type,
	in_sms_count		ol_statement_header.olsh_sms_count%type,
	in_skip_count		ol_statement_header.olsh_skip_count%type,
	in_hold_count		ol_statement_header.olsh_hold_count%type,
	in_accept_count		ol_statement_header.olsh_accept_count%type,
	in_total_count		ol_statement_header.olsh_total_count%type,
	in_message_code		ol_statement_header.olsh_message_code%type,
	in_org_filename		ol_statement_header.olsh_org_filename%type,
	in_format_id		ol_statement_header.olsh_format_id%type,
	in_ver			ol_statement_header.olsh_ver%type,
	in_status		ol_statement_header.olsh_status%type,
	in_split_count		ol_statement_header.olsh_split_count%type,
	in_add_count		ol_statement_header.olsh_add_count%type,
	in_update_count		ol_statement_header.olsh_update_count%type,
	in_delete_count		ol_statement_header.olsh_delete_count%type,
	in_file_count		ol_statement_header.olsh_file_count%type,
	in_create_user		ol_statement_header.olsh_create_user%type)
  RETURN NUMBER IS
BEGIN

	INSERT INTO ol_statement_header (
		olsh_file_id,
		olsh_filename,
		olsh_int_bank_code,
		olsh_bank_acct_num,
		olsh_baid,
		olsh_sms_count,
		olsh_skip_count,
		olsh_hold_count,
		olsh_accept_count,
		olsh_total_count,
		olsh_message_code,
		olsh_org_filename,
		olsh_format_id,
		olsh_ver,
		olsh_status,
		olsh_split_count,
		olsh_add_count,
		olsh_update_count,
		olsh_delete_count,
		olsh_file_count,
		olsh_create_timestamp,
		olsh_create_user,
		olsh_update_timestamp,
		olsh_update_user
		)
	VALUES (	
		in_file_id,
		in_filename,
		in_int_bank_code,
		in_bank_acct_num,
		in_baid,
		in_sms_count,
		in_skip_count,
		in_hold_count,
		in_accept_count,
		in_total_count,
		in_message_code,
		in_org_filename,
		in_format_id,
		in_ver,
		in_status,
		in_split_count,
		in_add_count,
		in_update_count,
		in_delete_count,
		in_file_count,
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

END sp_ol_statement_header_ins_v2;
/
