CREATE OR REPLACE FUNCTION sp_ol_txn_status_log_insert(
	in_txn_id		ol_txn_status_log.ots_txn_id%type,
	in_status		ol_txn_status_log.ots_status%type,
	in_ar_ind		ol_txn_status_log.ots_ar_ind%type,
	in_sub_status		ol_txn_status_log.ots_sub_status%type,
	in_create_user		ol_txn_status_log.ots_create_user%type)
  RETURN NUMBEr IS
BEGIN
	IF in_status IS NOT NULL OR
		in_ar_ind IS NOT NULL OR
		in_sub_status Is NOT NULL
	THEN
		INSERT INTO ol_txn_status_log(
			ots_txn_id,
			ots_status,
			ots_ar_ind,
			ots_sub_status,
			ots_create_user
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
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_ol_txn_status_log_insert;
/
