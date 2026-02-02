CREATE OR REPLACE FUNCTION sp_merch_keys_insert(
	in_merchant_id		merch_keys.merchant_id%type,
        in_key			merch_keys.key%type,
        in_key_value		merch_keys.key_value%type,
	in_create_user		merch_keys.create_user%type,
	in_effect_date		merch_keys.effect_date%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO merch_keys(
	merchant_id,
        key,
        key_value,
	create_user,
	create_timestamp,
	update_user,
	update_timestamp,
	effect_date
	)

  VALUES(
	in_merchant_id,
	in_key,
        in_key_value,
	in_create_user,
	sysdate,
	in_create_user,
	sysdate,
	in_effect_date
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_keys_insert;
/
