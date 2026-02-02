CREATE OR REPLACE FUNCTION sp_mms_def_txn_status_map_ins (
	in_type			mms_def_txn_status_map.tsm_type%type,
	in_status		mms_def_txn_status_map.tsm_status%type,
	in_ar_ind		mms_def_txn_status_map.tsm_ar_ind%type,
	in_txn_code		mms_def_txn_status_map.tsm_txn_code%type,
	in_status_desc		mms_def_txn_status_map.tsm_status_desc%type,
	in_create_user		mms_def_txn_status_map.tsm_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO mms_def_txn_status_map (
		tsm_type,
		tsm_status,
		tsm_ar_ind,
		tsm_txn_code,
		tsm_status_desc,
		tsm_create_user,
		tsm_create_timestamp,
		tsm_update_user,
		tsm_update_timestamp
		)
	VALUES (	
		in_type,
		in_status,
		in_ar_ind, 
		in_txn_code,
		in_status_desc,
		in_create_user,
		sysdate,
		in_create_user,
		sysdate
		);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_mms_def_txn_status_map_ins;
/
