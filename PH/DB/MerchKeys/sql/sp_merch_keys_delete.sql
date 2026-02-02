CREATE OR REPLACE FUNCTION sp_merch_keys_delete(
	in_merchant_id		merch_keys.merchant_id%type,
	in_key			merch_keys.key%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM merch_keys
	WHERE	key=in_key
	AND	merchant_id=in_merchant_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_keys_delete;
/
