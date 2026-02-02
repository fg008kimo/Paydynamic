CREATE OR REPLACE FUNCTION sp_psp_request_txn_url_rpl(
	in_replicate_psp_id             psp_request_txn_url.psp_id%type,
	in_create_psp_id                psp_request_txn_url.psp_id%type,
	in_request_function             psp_request_txn_url.request_function%type,
	in_create_user                  psp_request_txn_url.create_user%type
)
RETURN NUMBER IS
	iRecCnt		      	  INTEGER := 0;
BEGIN

	SELECT COUNT(1)
	INTO iRecCnt
	FROM psp_request_txn_url
	WHERE psp_id = in_replicate_psp_id;

	IF iRecCnt > 1 or iRecCnt = 0
	THEN
		RETURN 2;
	END IF;


  INSERT INTO psp_request_txn_url(
		psp_id,
		txn_code,
		request_function,
		action,
		create_timestamp,
		update_timestamp,
		create_user,
		update_user,
		url_method,
		payment_method,
		effect_date
	)
	SELECT  
		in_create_psp_id,
		txn_code,
		in_request_function,
		action,
		sysdate,
		sysdate,
		in_create_user,
		in_create_user,
		url_method,
		payment_method,
		sysdate
	from psp_request_txn_url
	where psp_id = in_replicate_psp_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_psp_request_txn_url_rpl;
/

