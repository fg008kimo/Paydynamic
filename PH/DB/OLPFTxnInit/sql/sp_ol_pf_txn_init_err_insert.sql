CREATE OR REPLACE FUNCTION sp_ol_pf_txn_init_err_insert(
	in_file_id		ol_pf_txn_init_error.opie_file_id%type,
	in_result		ol_pf_txn_init_error.opie_result%type,
	in_line			ol_pf_txn_init_error.opie_line%type,
	in_create_user		ol_pf_txn_init_error.opie_create_user%type)
  RETURN NUMBER IS
BEGIN

	INSERT INTO ol_pf_txn_init_error (
		opie_error_id,
		opie_file_id,
		opie_result,
		opie_line,
		opie_create_timestamp,
		opie_create_user
		)
	VALUES (/*(select NVL(max(opie_error_id),0)+1 from ol_pf_txn_init_error)*/
		PFI_ERROR_SEQ.NEXTVAL,
		in_file_id,
		in_result,
		in_line,
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

END sp_ol_pf_txn_init_err_insert;
/
