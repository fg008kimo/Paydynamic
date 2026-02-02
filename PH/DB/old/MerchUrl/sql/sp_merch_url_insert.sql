CREATE OR REPLACE FUNCTION sp_merch_url_insert(
	in_merchant_id		merch_url.merchant_id%type,
	in_url			merch_url.url%type,
	in_create_user		merch_url.create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO merch_url(
	merchant_id,
	url,
	create_timestamp,
	update_timestamp,
	create_user
	)

  VALUES(
	in_merchant_id,
	in_url,
        sysdate,
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

END sp_merch_url_insert;
/
