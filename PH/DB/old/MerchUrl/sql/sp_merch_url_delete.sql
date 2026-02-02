CREATE OR REPLACE FUNCTION sp_merch_url_delete(
	in_merchant_id		merch_url.merchant_id%type,
	in_url			merch_url.url%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM merch_url
	WHERE	merchant_id=in_merchant_id
	AND	url=in_url;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_url_delete;
/
