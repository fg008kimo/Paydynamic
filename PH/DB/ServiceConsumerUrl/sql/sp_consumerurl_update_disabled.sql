CREATE OR REPLACE FUNCTION sp_consumerurl_update_disabled(
	in_service_code		service_consumer_url.cu_service_code%type,
	in_merchant_id		service_consumer_url.cu_merchant_id%type,
	in_country		service_consumer_url.cu_country%type,
	in_url			service_consumer_url.cu_url%type,
	in_disabled		service_consumer_url.cu_disabled%type,
	in_update_user		service_consumer_url.cu_update_user%type
	)
  RETURN NUMBER IS

BEGIN

  UPDATE service_consumer_url 
     SET cu_disabled = in_disabled,
         cu_update_user = in_update_user,
         cu_update_timestamp = sysdate
   WHERE cu_service_code = in_service_code
     AND cu_merchant_id = in_merchant_id
     AND cu_country = in_country
     AND cu_url = in_url;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_consumerurl_update_disabled;
/
