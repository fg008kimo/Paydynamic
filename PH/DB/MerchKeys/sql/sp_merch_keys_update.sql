CREATE OR REPLACE FUNCTION sp_merch_keys_update(
	in_merchant_id		merch_keys.merchant_id%type,
        in_key			merch_keys.key%type,
        in_key_value		merch_keys.key_value%type,
	in_update_user		merch_keys.update_user%type,
	in_effect_date		merch_keys.effect_date%type)
  RETURN NUMBER IS

BEGIN
  UPDATE merch_keys
     SET key_value = in_key_value,
         effect_date = in_effect_date,
         update_user = in_update_user,
         update_timestamp = sysdate
   WHERE merchant_id = in_merchant_id
     AND key = in_key;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_keys_update;
/
