CREATE OR REPLACE FUNCTION sp_psp_keys_rpl(
	in_replicate_psp_id      psp_keys.psp_id%type,
	in_create_psp_id         psp_keys.psp_id%type,
	in_key_value             psp_keys.key_value%type,
	in_create_user           psp_keys.create_user%type
)
RETURN NUMBER IS
	iRecCnt		      	  INTEGER := 0;

BEGIN

	SELECT COUNT(1)
	INTO iRecCnt
	FROM psp_keys
	WHERE psp_id = in_replicate_psp_id;

	IF iRecCnt > 1 or iRecCnt = 0
	THEN
		RETURN 2;
	END IF;
  
  
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
	update_user,
	update_timestamp,
	effect_date
	)
	SELECT  in_create_psp_id, 
			key,
			in_key_value,
			key_id,
			key_uid,
			privatepem,
			publiccert,
			passphrase,
			in_create_user,
			sysdate,			
			in_create_user,
			sysdate,
			sysdate
	from psp_keys
	where psp_id = in_replicate_psp_id;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_psp_keys_rpl;
/

