CREATE OR REPLACE FUNCTION sp_holiday_delete(
	in_country		holiday.h_country%type,
	in_service_code         holiday.h_service_code%type,
	in_date			holiday.h_date%type)
  RETURN NUMBER IS

BEGIN

    DELETE FROM holiday
        WHERE   h_country=in_country
	AND     h_service_code=in_service_code
        AND     h_date=in_date;

    IF SQL%ROWCOUNT = 0 THEN
       RETURN 1;
    ELSE
       RETURN 0;
    END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_holiday_delete;
/
