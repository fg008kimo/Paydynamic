CREATE OR REPLACE FUNCTION sp_map_txn_element_insert(
	in_txn_code		map_txn_element.mt_txn_code%type,
	in_element		map_txn_element.mt_element%type,
	in_desc			map_txn_element.mt_desc%type,
	in_user			map_txn_element.mt_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO map_txn_element(
		mt_txn_code,
		mt_element,
		mt_desc,
		mt_create_timestamp,
		mt_create_user,
		mt_update_timestamp,
		mt_update_user
		)
	VALUES (	
		in_txn_code,
		in_element,
		in_desc,
		sysdate,
		in_user,
		sysdate,
		in_user
		);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_map_txn_element_insert;
/
