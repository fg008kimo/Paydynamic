CREATE OR REPLACE FUNCTION sp_psp_url_insert(
	in_psp_id		psp_url.psp_id%type,
	in_url			psp_url.url%type,
	in_effect_date		psp_url.effect_date%type,
	in_create_user		psp_url.create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO psp_url(
	psp_id,
	url,
	effect_date,
	create_timestamp,
	create_user
	)

  VALUES(
	in_psp_id,
	in_url,
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

END sp_psp_url_insert;
/
