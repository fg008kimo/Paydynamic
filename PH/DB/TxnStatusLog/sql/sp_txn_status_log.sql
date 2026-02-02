CREATE OR REPLACE FUNCTION sp_txn_status_log_insert(
	in_txn_id		txn_status_log.ts_txn_id%type,
	in_status		txn_status_log.ts_status%type,
	in_ar_ind		txn_status_log.ts_ar_ind%type,
	in_sub_status		txn_status_log.ts_sub_status%type,
	in_create_user		txn_status_log.ts_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO txn_status_log(
		ts_txn_id,
		ts_status,
		ts_ar_ind,
		ts_sub_status,
		ts_create_user
		)
	VALUES (	
		in_txn_id,
		in_status,
		in_ar_ind,
		in_sub_status,
		in_create_user);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_txn_status_log_insert;
/
