CREATE OR REPLACE FUNCTION sp_ol_statement_upd_rn_file(
	in_file_id              ol_statement_header.olsh_file_id%type,
	in_renamed_filename	ol_statement_header.olsh_renamed_filename%type)
  RETURN NUMBER IS
BEGIN

	UPDATE	ol_statement_header
	SET	olsh_renamed_filename = in_renamed_filename
	WHERE	olsh_file_id = in_file_id;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_ol_statement_upd_rn_file;
/

