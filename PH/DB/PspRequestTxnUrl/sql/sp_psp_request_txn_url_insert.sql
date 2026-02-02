CREATE OR REPLACE FUNCTION sp_psp_request_txn_url_insert(
	in_psp_id		psp_request_txn_url.psp_id%type,
	in_txn_code		psp_request_txn_url.txn_code%type,
	in_request_function	psp_request_txn_url.request_function%type,
	in_action		psp_request_txn_url.action%type,
	in_effect_date		psp_request_txn_url.effect_date%type,
	in_create_user		psp_request_txn_url.create_user%type,
	in_url_method		psp_request_txn_url.url_method%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO psp_request_txn_url(
	psp_id,
	txn_code,
	request_function,
        action,
	effect_date,
	create_timestamp,
	create_user,
	url_method
	)

  VALUES(
	in_psp_id,
	in_txn_code,
	in_request_function,
        in_action,
	in_effect_date,
	sysdate,
	in_create_user,
	in_url_method
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_psp_request_txn_url_insert;
/
