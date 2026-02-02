CREATE OR REPLACE FUNCTION sp_ol_txn_relation_insert(
	in_party		ol_txn_relation.otr_party_type%type,
	in_p1_txn_id		ol_txn_relation.otr_p1_txn_id%type,
	in_p2_txn_id		ol_txn_relation.otr_p2_txn_id%type,
	in_txn_level		ol_txn_relation.otr_txn_level%type,
	in_relation_type	ol_txn_relation.otr_relation_type%type,
	in_create_user		ol_txn_relation.otr_create_user%type)
  RETURN NUMBER IS
BEGIN
	INSERT INTO OL_TXN_RELATION(
		otr_party_type,
		otr_p1_txn_id,
		otr_p2_txn_id,
		otr_txn_level,
		otr_relation_type,
		otr_relation_timestamp,
		otr_create_timestamp,
		otr_create_user,
		otr_update_timestamp,
		otr_update_user
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

END sp_ol_txn_relation_insert;
/
