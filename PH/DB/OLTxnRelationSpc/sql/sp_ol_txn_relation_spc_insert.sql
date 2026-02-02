CREATE OR REPLACE FUNCTION sp_ol_txn_relation_spc_insert(
	in_party		ol_txn_relation_spc.otrs_party_type%type,
	in_p1_txn_id		ol_txn_relation_spc.otrs_p1_txn_id%type,
	in_p2_txn_id		ol_txn_relation_spc.otrs_p2_txn_id%type,
	in_txn_level		ol_txn_relation_spc.otrs_txn_level%type,
	in_relation_type	ol_txn_relation_spc.otrs_relation_type%type,
	in_create_user		ol_txn_relation_spc.otrs_create_user%type)
  RETURN NUMBER IS
BEGIN
	INSERT INTO OL_TXN_RELATION_SPC(
		otrs_party_type,
		otrs_p1_txn_id,
		otrs_p2_txn_id,
		otrs_txn_level,
		otrs_relation_type,
		otrs_relation_timestamp,
		otrs_create_timestamp,
		otrs_create_user,
		otrs_update_timestamp,
		otrs_update_user
		)
	VALUES (
		in_party,
		in_p1_txn_id,
		in_p2_txn_id,
		in_txn_level,
		in_relation_type,
                systimestamp,
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

END sp_ol_txn_relation_spc_insert;
/
