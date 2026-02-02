CREATE OR REPLACE FUNCTION sp_ol_statement_tmp_utsupd(
	in_file_id		ol_statement_tmp.olst_file_id%type,
	in_seq			ol_statement_tmp.olst_seq%type,
	in_ver			ol_statement_tmp.olst_ver%type,
	in_create_user		ol_statement_tmp.olst_create_user%type,
	in_create_timestamp	VARCHAR2)
  RETURN NUMBER IS
BEGIN

	UPDATE	OL_STATEMENT_TMP
	SET	OLST_CREATE_USER = in_create_user,
		OLST_CREATE_TIMESTAMP = to_date(in_create_timestamp, 'YYYYMMDD HH24MISS')
	WHERE	OLST_FILE_ID = in_file_id
	AND	OLST_SEQ = in_seq
	AND	OLST_VER = in_ver;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_ol_statement_tmp_utsupd;
/
