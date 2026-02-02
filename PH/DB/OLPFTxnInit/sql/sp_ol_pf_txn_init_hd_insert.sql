CREATE OR REPLACE FUNCTION sp_ol_pf_txn_init_hd_insert(
	in_file_id		ol_pf_txn_init_header.opih_file_id%type,
	in_filename		ol_pf_txn_init_header.opih_filename%type,
	in_accept_count		ol_pf_txn_init_header.opih_accept_count%type,
	in_total_count		ol_pf_txn_init_header.opih_total_count%type,
	in_status		ol_pf_txn_init_header.opih_status%type,
	in_create_user		ol_pf_txn_init_header.opih_create_user%type)
  RETURN NUMBER IS
BEGIN

	INSERT INTO ol_pf_txn_init_header (
		opih_file_id,
		opih_filename,
		opih_accept_count,
		opih_total_count,
		opih_status,
		opih_create_timestamp,
		opih_create_user,
		opih_update_timestamp,
		opih_update_user
		)
	VALUES (	
		in_file_id,
		in_filename,
		in_accept_count,
		in_total_count,
		in_status,
		sysdate,
		in_create_user,
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

END sp_ol_pf_txn_init_hd_insert;
/
