CREATE OR REPLACE FUNCTION sp_non_holiday_insert(
	in_country		non_holiday.nh_country%type,
	in_date			non_holiday.nh_date%type,
	in_desc			non_holiday.nh_desc%type,
	in_create_user		non_holiday.nh_create_user%type)
  RETURN NUMBER IS

BEGIN
    INSERT INTO non_holiday(
	nh_country,
	nh_date,
	nh_desc,
	nh_create_timestamp,
	nh_create_user,
	nh_update_timestamp,
	nh_update_user
	)

    VALUES(
	in_country,
	in_date,
	in_desc,
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

END sp_non_holiday_insert;
/
