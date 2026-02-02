CREATE OR REPLACE FUNCTION sp_ol_statement_header_update(
	in_filename		ol_statement_header.olsh_filename%type,
	in_sms_count		ol_statement_header.olsh_sms_count%type,
	in_skip_count		ol_statement_header.olsh_skip_count%type,
	in_hold_count		ol_statement_header.olsh_hold_count%type,
	in_accept_count		ol_statement_header.olsh_accept_count%type,
	in_total_count		ol_statement_header.olsh_total_count%type,
	in_update_user		ol_statement_header.olsh_update_user%type)
  RETURN NUMBER IS
BEGIN

	UPDATE	ol_statement_header
	SET	olsh_update_timestamp = sysdate,
		olsh_update_user = NVL(in_update_user,olsh_update_user),
		olsh_sms_count = NVL(in_sms_count,olsh_sms_count),
		olsh_total_count = NVL(in_total_count,olsh_total_count),
		olsh_accept_count = NVL(in_accept_count,olsh_accept_count),
		olsh_skip_count = NVL(in_skip_count,olsh_skip_count),
		olsh_hold_count = NVL(in_hold_count,olsh_hold_count)
	WHERE	olsh_filename = in_filename;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_ol_statement_header_update;
/

