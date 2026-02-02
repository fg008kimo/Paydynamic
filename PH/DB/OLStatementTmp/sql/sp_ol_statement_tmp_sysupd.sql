CREATE OR REPLACE FUNCTION sp_ol_statement_tmp_sysupd(
	in_file_id		ol_statement_tmp.olst_file_id%type,
	in_seq			ol_statement_tmp.olst_seq%type,
	in_ver			ol_statement_tmp.olst_ver%type,
	in_sys_seq		ol_statement_tmp.olst_sys_seq%type,
	in_skip			ol_statement_tmp.olst_skip%type,
	in_statement_date	ol_statement_tmp.olst_statement_date%type,
	in_statement_time	ol_statement_tmp.olst_statement_time%type)
  RETURN NUMBER IS
BEGIN

	UPDATE	OL_STATEMENT_TMP
	SET	OLST_SYS_SEQ = in_sys_seq
	WHERE	OLST_FILE_ID = in_file_id
	AND	OLST_SEQ = in_seq;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	END IF;

	UPDATE	OL_STATEMENT_TMP
	SET	OLST_SKIP = in_skip,
		OLST_STATEMENT_DATE = in_statement_date,
		OLST_STATEMENT_TIME = in_statement_time
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

END sp_ol_statement_tmp_sysupd;
/
