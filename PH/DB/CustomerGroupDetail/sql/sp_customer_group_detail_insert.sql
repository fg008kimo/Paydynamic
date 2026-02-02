CREATE OR REPLACE FUNCTION sp_customer_grp_dtl_insert(
	in_code			customer_group_detail.cgd_code%type,
	in_merchant_id		customer_group_detail.cgd_merchant_id%type,
	in_cust_id		customer_group_detail.cgd_cust_id%type,
	in_create_user		customer_group_detail.cgd_create_user%type)
  RETURN NUMBER IS

BEGIN

    INSERT INTO customer_group_detail (
	cgd_code,
	cgd_merchant_id,
	cgd_cust_id,
	cgd_create_timestamp,
	cgd_create_user,
	cgd_update_timestamp,
	cgd_update_user
	)

    VALUES(
	in_code,
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

END sp_customer_grp_dtl_insert;
/
