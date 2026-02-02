CREATE OR REPLACE FUNCTION sp_ol_statement_tmp_recupd(
	in_file_id		ol_statement_tmp.olst_file_id%type,
	in_seq			ol_statement_tmp.olst_seq%type,
	in_ver			ol_statement_tmp.olst_ver%type,
	in_latest_ver		ol_statement_tmp.olst_latest_ver%type,
	in_disabled             ol_statement_tmp.olst_disabled%type,
	in_sys_seq		ol_statement_tmp.olst_sys_seq%type,
	in_user_seq		ol_statement_tmp.olst_user_seq%type,
	in_update_user		ol_statement_tmp.olst_update_user%type)
  RETURN NUMBER IS
BEGIN

	UPDATE	OL_STATEMENT_TMP
	SET	OLST_LATEST_VER = in_ver - 1,
		OLST_UPDATE_USER = in_update_user,
		OLST_UPDATE_TIMESTAMP = sysdate
	WHERE	OLST_FILE_ID = in_file_id
	AND	OLST_SEQ = in_seq
	AND	OLST_LATEST_VER is NULL
	AND	OLST_DISABLED = 0;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_ol_statement_tmp_recupd;
/
