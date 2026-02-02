CREATE OR REPLACE FUNCTION sp_psp_keys_insert(
	in_psp_id		psp_keys.psp_id%type,
        in_key			psp_keys.key%type,
        in_key_value		psp_keys.key_value%type,
	in_key_id		psp_keys.key_id%type,
	in_key_uid		psp_keys.key_uid%type,
	in_privatepem		psp_keys.privatepem%type,
	in_publiccert		psp_keys.publiccert%type,
	in_passphrase		psp_keys.passphrase%type,
	in_create_user		psp_keys.create_user%type,
	in_effect_date		psp_keys.effect_date%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO psp_keys(
	psp_id,
        key,
        key_value,
	key_id,
	key_uid,
	privatepem,
	publiccert,
	passphrase,
	create_user,
	create_timestamp,
	effect_date
	)

  VALUES(
	in_psp_id,
	in_key,
        in_key_value,
	in_key_id,
	in_key_uid,
	in_privatepem,
	in_publiccert,
	in_passphrase,
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

END sp_psp_keys_insert;
/
