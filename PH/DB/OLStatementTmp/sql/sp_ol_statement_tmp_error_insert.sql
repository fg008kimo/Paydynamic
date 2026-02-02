CREATE OR REPLACE FUNCTION sp_ol_statement_tmp_error_ins(
	in_file_id		ol_statement_tmp_error.se_file_id%type,
	in_seq			ol_statement_tmp_error.se_seq%type,
	in_ver			ol_statement_tmp_error.se_ver%type,
	in_result		ol_statement_tmp_error.se_result%type,
	in_create_user		ol_statement_tmp_error.se_create_user%type)
  RETURN NUMBER IS
BEGIN

	INSERT INTO ol_statement_tmp_error (
		se_error_id,
		se_file_id,
		se_seq,
		se_ver,
		se_result,
		se_create_timestamp,
		se_create_user
		)
	VALUES (ODI_ERROR_SEQ.NEXTVAL,
		in_file_id,
		in_seq,
		in_ver,
		in_result,
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

END sp_ol_statement_tmp_error_ins;
/
