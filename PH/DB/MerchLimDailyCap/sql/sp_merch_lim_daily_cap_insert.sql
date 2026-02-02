DROP FUNCTION SP_MERCH_LIM_DAILY_CAP_INSERT;

CREATE OR REPLACE FUNCTION sp_merch_lim_daily_cap_insert(
	in_merchant_id		merch_lim_daily_cap.mldc_merchant_id%type,
	in_service_code		merch_lim_daily_cap.mldc_service_code%type,
	in_country		merch_lim_daily_cap.mldc_country%type,
        in_daily_cap           	merch_lim_daily_cap.mldc_daily_cap%type,
        in_disabled           	merch_lim_daily_cap.mldc_disabled%type,
	in_create_user		merch_lim_daily_cap.mldc_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO merch_lim_daily_cap(
	mldc_merchant_id,
	mldc_service_code,
	mldc_country,
	mldc_daily_cap,
	mldc_disabled,
	mldc_create_timestamp,
	mldc_create_user,
        mldc_update_timestamp,
        mldc_update_user
	)

  VALUES(
	in_merchant_id,
	in_service_code,
	in_country,
	in_daily_cap,
	in_disabled,
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

END sp_merch_lim_daily_cap_insert;
/

