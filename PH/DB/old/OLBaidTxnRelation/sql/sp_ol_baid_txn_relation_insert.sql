DROP FUNCTION sp_ol_baid_txn_relation_insert;

CREATE OR REPLACE FUNCTION sp_ol_baid_txn_relation_insert(
	in_txn_id		ol_baid_txn_relation.btr_txn_id%type,
	in_baid_txn_id		ol_baid_txn_relation.btr_baid_txn_id%type,
	in_create_user		ol_baid_txn_relation.btr_create_user%type
	)
RETURN NUMBER IS
	iCnt	integer := 0;
BEGIN
	SELECT COUNT(*)
	INTO	iCnt
	FROM	ol_baid_txn_relation
	WHERE	btr_txn_id = in_txn_id
	AND	btr_baid_txn_id = in_baid_txn_id;

	IF iCnt > 0 THEN
		INSERT INTO ol_baid_txn_relation(
			btr_txn_id,
			btr_baid_txn_id,
			btr_create_timestamp,
			btr_update_timestamp,
			btr_create_user,
			btr_update_user
		)
		VALUES(
			in_txn_id,
			in_baid_txn_id,
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
END sp_ol_baid_txn_relation_insert;
/


