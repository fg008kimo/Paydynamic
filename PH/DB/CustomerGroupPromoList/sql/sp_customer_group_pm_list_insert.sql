CREATE OR REPLACE FUNCTION sp_customer_grp_pmlist_insert(
	in_merchant_id		customer_group_promo_list.cgl_merchant_id%type,
	in_cust_id		customer_group_promo_list.cgl_cust_id%type,
	in_group		customer_group_promo_list.cgl_from_group%type,
	in_create_user		customer_group_promo_list.cgl_create_user%type)
  RETURN NUMBER IS

  iCnt INTEGER := 0;

BEGIN

    select count(1)
    into   iCnt
    from   customer_group_promo_list
    where  cgl_merchant_id = in_merchant_id
    and	   cgl_cust_id = in_cust_id;

   if iCnt = 0
   then

    INSERT INTO customer_group_promo_list (
	cgl_merchant_id,
	cgl_cust_id,
	cgl_from_group,
	cgl_promoted,
	cgl_create_timestamp,
	cgl_create_user,
	cgl_update_timestamp,
	cgl_update_user
	)

    VALUES(
	in_merchant_id,
	in_cust_id,
	in_group,
	'N',
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

   else
       return 0;

   end if;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_customer_grp_pmlist_insert;
/
