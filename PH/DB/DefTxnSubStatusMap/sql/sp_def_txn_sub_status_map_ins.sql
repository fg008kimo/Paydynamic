CREATE OR REPLACE FUNCTION sp_def_txn_sub_status_map_ins (
	in_txn_code		def_txn_sub_status_map.dsm_txn_code%type,
	in_sub_status		def_txn_sub_status_map.dsm_sub_status%type,
	in_create_user		def_txn_sub_status_map.dsm_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO def_txn_sub_status_map (
		dsm_txn_code,
		dsm_sub_status,
		dsm_create_user,
		dsm_create_timestamp,
		dsm_update_user,
		dsm_update_timestamp
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

END sp_def_txn_sub_status_map_ins;
/
