CREATE OR REPLACE FUNCTION sp_psp_url_rpl(
	in_replicate_psp_id     psp_url.psp_id%type,
	in_create_psp_id        psp_url.psp_id%type,
	in_url                  psp_url.url%type,
	in_create_user          psp_url.create_user%type
)
RETURN NUMBER IS
	iRecCnt		      	  INTEGER := 0;
BEGIN

	SELECT COUNT(1)
	INTO iRecCnt
	FROM psp_url
	WHERE psp_id = in_replicate_psp_id;

	IF iRecCnt > 1 or iRecCnt = 0
	THEN
		RETURN 2;
	END IF;


  INSERT INTO psp_url(
	psp_id,
	url,
	effect_date,
	create_timestamp,
	update_timestamp,
	create_user,
	update_user,
	is_redirect_url
	)
	SELECT  
		in_create_psp_id, 
		in_url,
		'19000101',
		sysdate,
		sysdate,
		in_create_user,
		in_create_user,
		is_redirect_url
	from psp_url
	where psp_id = in_replicate_psp_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_psp_url_rpl;
/

