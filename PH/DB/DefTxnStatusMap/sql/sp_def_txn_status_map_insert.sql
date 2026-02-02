CREATE OR REPLACE FUNCTION sp_def_txn_status_map_insert (
	in_type			def_txn_status_map.dm_type%type,
	in_status		def_txn_status_map.dm_status%type,
	in_ar_ind		def_txn_status_map.dm_ar_ind%type,
	in_txn_code		def_txn_status_map.dm_txn_code%type,
	in_status_desc		def_txn_status_map.dm_status_desc%type,
	in_create_user		adjustment_type.at_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO def_txn_status_map (
		dm_type,
		dm_status,
		dm_ar_ind,
		dm_txn_code,
		dm_status_desc,
		dm_create_user,
		dm_create_timestamp,
		dm_update_user,
		dm_update_timestamp
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

END sp_def_txn_status_map_insert;
/
