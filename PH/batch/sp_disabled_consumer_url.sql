CREATE OR REPLACE FUNCTION sp_disabled_consumer_url(
	in_merchant_id	service_consumer_url.cu_merchant_id%type,
	in_url		service_consumer_url.cu_url%type
	)
  RETURN NUMBER IS

BEGIN
  	UPDATE	service_consumer_url
	SET	cu_disabled = 1,
		cu_update_timestamp = sysdate
	WHERE	cu_merchant_id=in_merchant_id
	AND	cu_url=in_url;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_disabled_consumer_url;
/
