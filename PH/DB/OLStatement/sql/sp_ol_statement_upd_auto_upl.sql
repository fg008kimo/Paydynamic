CREATE OR REPLACE FUNCTION sp_ol_statement_upd_auto_upl(
	in_file_id              ol_statement_header.olsh_file_id%type,
	in_acct_type		ol_statement_header.olsh_acct_type%type,
	in_auto_upload		ol_statement_header.olsh_auto_upload%type)
  RETURN NUMBER IS
BEGIN

	UPDATE	ol_statement_header
	SET	olsh_acct_type = in_acct_type,
		olsh_auto_upload = in_auto_upload
	WHERE	olsh_file_id = in_file_id;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_ol_statement_upd_auto_upl;
/

