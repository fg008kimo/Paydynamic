CREATE OR REPLACE FUNCTION sp_non_holiday_delete(
	in_country		non_holiday.nh_country%type,
	in_date			non_holiday.nh_date%type)
  RETURN NUMBER IS

BEGIN

    DELETE FROM non_holiday
        WHERE   nh_country=in_country
        AND     nh_date=in_date;

    IF SQL%ROWCOUNT = 0 THEN
       RETURN 1;
    ELSE
       RETURN 0;
    END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_non_holiday_delete;
/
