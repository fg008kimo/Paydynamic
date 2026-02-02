CREATE OR REPLACE FUNCTION sp_offset_txn_type_delete(
	in_party_type		offset_txn_type.ott_party_type%type,
	in_txn_code		offset_txn_type.ott_txn_code%type	
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM offset_txn_type
	WHERE	ott_party_type = in_party_type
	AND	ott_txn_code = in_txn_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_offset_txn_type_delete;
/
