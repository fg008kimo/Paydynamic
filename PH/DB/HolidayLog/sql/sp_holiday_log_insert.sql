CREATE OR REPLACE FUNCTION sp_holiday_log_insert(
	in_action		holiday_log.hl_action%type,
	in_country		holiday_log.hl_country%type,
	in_service_code         holiday_log.hl_service_code%type,
	in_date			holiday_log.hl_date%type,
	in_desc                 holiday_log.hl_desc%type,
	in_create_user		holiday_log.hl_create_user%type)
  RETURN NUMBER IS

BEGIN
    INSERT INTO holiday_log(
	hl_action,
	hl_country,
	hl_service_code,
	hl_date,
	hl_desc,
	hl_create_timestamp,
	hl_create_user
	)
    VALUES(
	in_action,
	in_country,
	in_service_code,
	in_date,
	in_desc,
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

END sp_holiday_log_insert;
/
