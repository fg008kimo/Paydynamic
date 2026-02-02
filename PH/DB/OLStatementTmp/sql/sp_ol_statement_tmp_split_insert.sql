CREATE OR REPLACE FUNCTION sp_ol_statement_tmp_split_ins(
	in_file_id		ol_statement_tmp_split.olss_file_id%type,
	in_seq			ol_statement_tmp_split.olss_seq%type,
	in_ver			ol_statement_tmp_split.olss_ver%type,
	in_statement_ref	ol_statement_tmp_split.olss_statement_ref%type,
	in_create_user		ol_statement_tmp_split.olss_create_user%type)
  RETURN NUMBER IS
BEGIN
	INSERT INTO ol_statement_tmp_split (
		olss_file_id,
		olss_seq,
		olss_ver,
		olss_statement_ref,
		olss_create_timestamp,
		olss_create_user
		)
	VALUES (	
		in_file_id,
		in_seq,
		in_ver,
		in_statement_ref,
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

END sp_ol_statement_tmp_split_ins;
/
