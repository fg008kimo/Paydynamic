CREATE OR REPLACE FUNCTION sp_psp_country_insert(
	in_country		psp_country.country%type,
	in_psp_id		psp_country.psp_id%type,
	in_currency_id		psp_country.currency_id%type,
	in_create_user		psp_country.create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO psp_country(
	country,
	psp_id,
	currency_id,
	create_timestamp,
	create_user,
	update_timestamp,
	update_user
	)

  VALUES(
	in_country,
	in_psp_id,
	in_currency_id,
	sysdate,
	in_create_user,
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

END sp_psp_country_insert;
/
