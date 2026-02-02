CREATE OR REPLACE FUNCTION sp_ol_statement_header_upd_v2(
	in_file_id		ol_statement_header.olsh_file_id%type,
	in_baid			ol_statement_header.olsh_baid%type,
	in_sms_count		ol_statement_header.olsh_sms_count%type,
	in_skip_count		ol_statement_header.olsh_skip_count%type,
	in_hold_count		ol_statement_header.olsh_hold_count%type,
	in_accept_count		ol_statement_header.olsh_accept_count%type,
	in_total_count		ol_statement_header.olsh_total_count%type,
	in_message_code		ol_statement_header.olsh_message_code%type,
	in_format_id		ol_statement_header.olsh_format_id%type,
	in_ver			ol_statement_header.olsh_ver%type,
	in_status		ol_statement_header.olsh_status%type,
	in_split_count		ol_statement_header.olsh_split_count%type,
	in_add_count		ol_statement_header.olsh_add_count%type,
	in_update_count		ol_statement_header.olsh_update_count%type,
	in_delete_count		ol_statement_header.olsh_delete_count%type,
	in_file_count		ol_statement_header.olsh_file_count%type,
	in_update_user		ol_statement_header.olsh_update_user%type)
  RETURN NUMBER IS
BEGIN

	UPDATE	ol_statement_header
	SET	olsh_update_timestamp = sysdate,
		olsh_update_user = NVL(in_update_user,olsh_update_user),
		olsh_baid = NVL(in_baid,olsh_baid),
		olsh_sms_count = NVL(in_sms_count,olsh_sms_count),
		olsh_total_count = NVL(in_total_count,olsh_total_count),
		olsh_accept_count = NVL(in_accept_count,olsh_accept_count),
		olsh_skip_count = NVL(in_skip_count,olsh_skip_count),
		olsh_hold_count = NVL(in_hold_count,olsh_hold_count),
		olsh_message_code = NVL(in_message_code,olsh_message_code),
		olsh_format_id = NVL(in_format_id,olsh_format_id),
		olsh_ver = NVL(in_ver,olsh_ver),
		olsh_status = NVL(in_status,olsh_status),
		olsh_split_count = NVL(in_split_count,olsh_split_count),
		olsh_add_count = NVL(in_add_count,olsh_add_count),
		olsh_update_count = NVL(in_update_count,olsh_update_count),
		olsh_delete_count = NVL(in_delete_count,olsh_delete_count),
		olsh_file_count = NVL(in_file_count,olsh_file_count)
	WHERE	olsh_file_id = in_file_id;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_ol_statement_header_upd_v2;
/

