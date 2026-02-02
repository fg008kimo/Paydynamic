CREATE OR REPLACE FUNCTION sp_customer_grp_dtl_update(
	in_code			customer_group_detail.cgd_code%type,
	in_merchant_id		customer_group_detail.cgd_merchant_id%type,
	in_cust_id		customer_group_detail.cgd_cust_id%type,
	in_update_user		customer_group_detail.cgd_update_user%type)
  RETURN NUMBER IS

BEGIN

    update customer_group_detail
    set	cgd_code = in_code,
	cgd_update_timestamp = sysdate,
	cgd_update_user = in_update_user
    where cgd_merchant_id = in_merchant_id
    and	  cgd_cust_id = in_cust_id;

    IF SQL%ROWCOUNT = 0 THEN
       RETURN 1;
    ELSE
       RETURN 0;
    END IF;



EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_customer_grp_dtl_update;
/
