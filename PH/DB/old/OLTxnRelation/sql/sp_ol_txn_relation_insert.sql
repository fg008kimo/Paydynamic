DROP FUNCTION sp_ol_txn_relation_insert;

CREATE OR REPLACE FUNCTION sp_ol_txn_relation_insert(
	in_fr_txn_party_type 	ol_txn_relation.otr_fr_txn_party_type%type,
	in_fr_txn_id		ol_txn_relation.otr_fr_txn_id%type,
	in_to_txn_party_type	ol_txn_relation.otr_to_txn_party_type%type,
	in_to_txn_id		ol_txn_relation.otr_to_txn_id%type,
	in_create_user		ol_txn_relation.otr_create_user%type
	)
RETURN NUMBER IS
	iCnt integer := 0;

BEGIN
	SELECT	COUNT(*)
	INTO	iCnt
        FROM	ol_txn_relation
        WHERE	otr_fr_txn_party_type = in_fr_txn_party_type
        AND	otr_fr_txn_id = in_fr_txn_id
        AND	otr_to_txn_party_type = in_to_txn_party_type
        AND	otr_to_txn_id = in_to_txn_id;

	IF iCnt > 0 THEN
		INSERT INTO ol_txn_relation(
			otr_fr_txn_party_type,
			otr_fr_txn_id,
			otr_to_txn_party_type,
			otr_to_txn_id,
			otr_create_timestamp,
			otr_update_timestamp,
			otr_create_user,
			otr_update_user
		)
		VALUES(
			in_fr_txn_party_type,
			in_fr_txn_id,
			in_to_txn_party_type,
			in_to_txn_id,
			sysdate,
			sysdate,
			in_create_user,
			in_create_user
		);

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
END sp_ol_txn_relation_insert;
/


