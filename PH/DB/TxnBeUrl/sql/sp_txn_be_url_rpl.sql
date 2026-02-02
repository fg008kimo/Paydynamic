CREATE OR REPLACE FUNCTION sp_txn_be_url_rpl(
	in_replicate_psp_id            txn_be_url.psp_id%type,
	in_create_psp_id               txn_be_url.psp_id%type,
	in_create_user                 txn_be_url.create_user%type
)
RETURN NUMBER IS
	iRecCnt		      	  INTEGER := 0;
BEGIN

	SELECT COUNT(1)
	INTO iRecCnt
	FROM txn_be_url
	WHERE psp_id = in_replicate_psp_id;

	IF iRecCnt > 1 or iRecCnt = 0
	THEN
		RETURN 2;
	END IF;


  INSERT INTO txn_be_url(
		txn_code,
		service_code,
		psp_id,
		path,
		effect_date,
		disabled,
		create_timestamp,
		update_timestamp,
		create_user,
		update_user,
		override_domain
	)
	SELECT  
		txn_code,
		service_code,
		in_create_psp_id,
		path,
		sysdate,
		0,
		sysdate,
		sysdate,
		in_create_user,
		in_create_user,
		override_domain
	from txn_be_url
	where psp_id = in_replicate_psp_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_txn_be_url_rpl;
/

