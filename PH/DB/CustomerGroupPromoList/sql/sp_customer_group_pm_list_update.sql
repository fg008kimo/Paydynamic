CREATE OR REPLACE FUNCTION sp_customer_grp_pmlist_update(
	in_merchant_id		customer_group_promo_list.cgl_merchant_id%type,
	in_cust_id		customer_group_promo_list.cgl_cust_id%type,
	in_to_group		customer_group_promo_list.cgl_to_group%type,
	in_promo_date		customer_group_promo_list.cgl_promote_date%type,
	in_update_user		customer_group_promo_list.cgl_update_user%type)
  RETURN NUMBER IS

BEGIN

    update customer_group_promo_list
    set	cgl_to_group= in_to_group,
	cgl_promote_date = in_promo_date,
	cgl_promoted= 'Y',
	cgl_update_timestamp = sysdate,
	cgl_promote_timestamp = sysdate,
	cgl_update_user = in_update_user
    where cgl_merchant_id = in_merchant_id
    and	  cgl_cust_id = in_cust_id;

    IF SQL%ROWCOUNT = 0 THEN
       RETURN 1;
    ELSE
       RETURN 0;
    END IF;


EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_customer_grp_pmlist_update;
/
