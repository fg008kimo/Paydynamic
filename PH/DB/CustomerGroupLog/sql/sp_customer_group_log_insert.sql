CREATE OR REPLACE FUNCTION sp_customer_grp_log_insert(
	in_from_code		customer_group_log.cgl_from_code%type,
	in_to_code		customer_group_log.cgl_to_code%type,
	in_merchant_id		customer_group_log.cgl_merchant_id%type,
	in_cust_id		customer_group_log.cgl_cust_id%type,
	in_create_user		customer_group_log.cgl_create_user%type)
  RETURN NUMBER IS

BEGIN

    INSERT INTO customer_group_log(
	cgl_from_code,
	cgl_to_code,
	cgl_merchant_id,
	cgl_cust_id,
	cgl_create_timestamp,
	cgl_create_user,
	cgl_update_timestamp,
	cgl_update_user
	)

    VALUES(
	in_from_code,
	in_to_code,
	in_merchant_id,
	in_cust_id,
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

END sp_customer_grp_log_insert;
/
