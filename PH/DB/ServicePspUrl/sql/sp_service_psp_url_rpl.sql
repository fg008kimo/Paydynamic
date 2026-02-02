CREATE OR REPLACE FUNCTION sp_service_psp_url_rpl(
	in_replicate_psp_id       service_psp_url.pu_psp_id%type,
	in_create_psp_id          service_psp_url.pu_psp_id%type,
	in_url                    service_psp_url.pu_url%type,
	in_create_user            service_psp_url.pu_create_user%type
)
RETURN NUMBER IS
	iServPspUrlRecCnt             INTEGER := 0;
	iTxnBeUrlRecCnt               INTEGER := 0;
	hv_service_code               service_psp_url.pu_service_code%type;
BEGIN

	SELECT COUNT(1)
	INTO iServPspUrlRecCnt
	FROM service_psp_url
	WHERE pu_psp_id = in_replicate_psp_id;

	IF iServPspUrlRecCnt > 1
	THEN
		RETURN 2;
	END IF;

-- Get Service code from txn_be_url
	SELECT COUNT(1)
	INTO iTxnBeUrlRecCnt
	FROM txn_be_url
	WHERE psp_id = in_replicate_psp_id;

	IF iTxnBeUrlRecCnt > 1 or iTxnBeUrlRecCnt = 0
	THEN
		RETURN 2;
	END IF;
		
		
	SELECT service_code
	INTO hv_service_code
	FROM txn_be_url
	WHERE psp_id = in_replicate_psp_id;
	
	
  INSERT INTO service_psp_url(
		pu_service_code,
		pu_psp_id,
		pu_url,
		pu_effect_date,
		pu_disabled,
		pu_create_timestamp,
		pu_update_timestamp,
		pu_create_user,
		pu_update_user
	)
	VALUES(
		hv_service_code,
		in_create_psp_id,
		in_url,
		sysdate,
		0,
		sysdate,
		sysdate,
		in_create_user,
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

END sp_service_psp_url_rpl;
/

