CREATE OR REPLACE FUNCTION sp_offset_txn_type_insert(
	in_party_type		offset_txn_type.ott_party_type%type,
	in_txn_code		offset_txn_type.ott_txn_code%type,
	in_desc			offset_txn_type.ott_desc%type,
	in_amt_type		offset_txn_type.ott_amt_type%type,
	in_bal_type		offset_txn_type.ott_bal_type%type,
	in_nature		offset_txn_type.ott_nature%type,
	in_disabled		offset_txn_type.ott_disabled%type,
	in_create_user		offset_txn_type.ott_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO offset_txn_type (
		ott_party_type,
		ott_txn_code,
		ott_desc,
		ott_amt_type,
		ott_bal_type,
		ott_nature,
		ott_disabled,
		ott_create_timestamp,
		ott_create_user,
		ott_update_timestamp,
		ott_update_user
		)
	VALUES (	
		in_party_type,
		in_txn_code,
		in_desc,
		in_amt_type,
		in_bal_type,
		in_nature,
		in_disabled,
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

END sp_offset_txn_type_insert;
/
