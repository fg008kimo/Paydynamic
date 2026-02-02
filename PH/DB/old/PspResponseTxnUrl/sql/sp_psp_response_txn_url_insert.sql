CREATE OR REPLACE FUNCTION sp_psp_response_txn_url_insert(
	in_psp_id		psp_response_txn_url.psp_id%type,
	in_txn_code		psp_response_txn_url.txn_code%type,
	in_response_function	psp_response_txn_url.response_function%type,
	in_effect_date		psp_response_txn_url.effect_date%type,
	in_create_user		psp_response_txn_url.create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO psp_response_txn_url(
	psp_id,
	txn_code,
	response_function,
	effect_date,
	create_timestamp,
	create_user
	)

  VALUES(
	in_psp_id,
	in_txn_code,
	in_response_function,
	in_effect_date,
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

END sp_psp_response_txn_url_insert;
/
