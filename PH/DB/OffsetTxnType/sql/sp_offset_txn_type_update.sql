CREATE OR REPLACE FUNCTION sp_offset_txn_type_update(
	in_party_type		offset_txn_type.ott_party_type%type,
	in_txn_code		offset_txn_type.ott_txn_code%type,
	in_desc			offset_txn_type.ott_desc%type,
	in_amt_type		offset_txn_type.ott_amt_type%type,
	in_bal_type		offset_txn_type.ott_bal_type%type,
	in_allow_modify		offset_txn_type.ott_allow_modify%type,
	in_allow_bal_negative	offset_txn_type.ott_allow_bal_negative%type,
	in_nature		offset_txn_type.ott_nature%type,
	in_disabled		offset_txn_type.ott_disabled%type,
	in_update_user		offset_txn_type.ott_update_user%type
	)
  RETURN NUMBER IS

BEGIN

  UPDATE offset_txn_type 
     SET ott_desc = in_desc,
	 ott_amt_type = in_amt_type,
	 ott_bal_type = in_bal_type,
	 ott_allow_modify = in_allow_modify,
	 ott_allow_bal_negative = in_allow_bal_negative,
	 ott_nature = in_nature,
	 ott_disabled = in_disabled,
         ott_update_user = in_update_user,
         ott_update_timestamp = sysdate
   WHERE ott_party_type = in_party_type
     AND ott_txn_code = in_txn_code;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_offset_txn_type_update;
/
