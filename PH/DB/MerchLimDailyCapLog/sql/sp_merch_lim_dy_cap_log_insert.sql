CREATE OR REPLACE FUNCTION sp_merch_lim_dy_cap_log_insert(
	in_merchant_id          merch_lim_daily_cap_log.mldcl_merchant_id%type,
        in_service_code         merch_lim_daily_cap_log.mldcl_service_code%type,
        in_country              merch_lim_daily_cap_log.mldcl_country%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO merch_lim_daily_cap_log(
		mldcl_merchant_id,
		mldcl_service_code,
		mldcl_country,
		mldcl_log_seq,
		mldcl_daily_cap,
		mldcl_disabled,
		mldcl_create_timestamp,
		mldcl_create_user,
        	mldcl_update_timestamp,
        	mldcl_update_user
		)
	
	(SELECT mldc_merchant_id,
		mldc_service_code,
		mldc_country,
		(SELECT NVL (MAX (mldcl_log_seq), 0) + 1
                FROM    merch_lim_daily_cap_log
                WHERE   mldcl_merchant_id = in_merchant_id
                AND     mldcl_service_code = in_service_code
                AND     mldcl_country = in_country),
		mldc_daily_cap,
                mldc_disabled,
                mldc_create_timestamp,
                mldc_create_user,
                mldc_update_timestamp,
                mldc_update_user	
	FROM	merch_lim_daily_cap
	WHERE   mldc_merchant_id = in_merchant_id);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_lim_dy_cap_log_insert;
/

