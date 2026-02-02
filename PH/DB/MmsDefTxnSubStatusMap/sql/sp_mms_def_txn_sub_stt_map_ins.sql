CREATE OR REPLACE FUNCTION sp_mms_def_txn_sub_stt_map_ins (
	in_txn_code		mms_def_txn_sub_status_map.tss_txn_code%type,
	in_sub_status		mms_def_txn_sub_status_map.tss_sub_status%type,
	in_create_user		mms_def_txn_sub_status_map.tss_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO mms_def_txn_sub_status_map (
		tss_txn_code,
		tss_sub_status,
		tss_create_user,
		tss_create_timestamp,
		tss_update_user,
		tss_update_timestamp
		)
	VALUES (	
		in_txn_code,
		in_sub_status,
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

END sp_mms_def_txn_sub_stt_map_ins;
/
