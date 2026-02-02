CREATE OR REPLACE FUNCTION sp_ol_stmt_txn_relation_insert(
	in_stmt_txn_id		ol_stmt_txn_relation.ostp_stmt_txn_id%type,
	in_txn_id		ol_stmt_txn_relation.ostp_txn_id%type,
	in_create_user		ol_stmt_txn_relation.ostp_create_user%type)
  RETURN NUMBER IS
	iCnt    integer := 0;
BEGIN

  select count(*)
  into iCnt
  from ol_stmt_txn_relation
  where ostp_stmt_txn_id = in_stmt_txn_id 
  and	ostp_txn_id = in_txn_id;

  if iCnt = 0 then

	INSERT INTO OL_STMT_TXN_RELATION(
		ostp_stmt_txn_id,
		ostp_txn_id,
                ostp_relation_timestamp,
		ostp_create_timestamp,
		ostp_create_user,
		ostp_update_timestamp,
		ostp_update_user
		)
	VALUES (
		in_stmt_txn_id,
		in_txn_id,
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
   ELSE
	RETURN 0;
   END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_ol_stmt_txn_relation_insert;
/
