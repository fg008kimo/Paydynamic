CREATE OR REPLACE FUNCTION sp_customer_grp_pmlist_delete
  RETURN NUMBER IS

  iCnt INTEGER := 0;

BEGIN

    select count(1)
    into   iCnt
    from   customer_group_promo_list
    where  cgl_promoted = 'N' 
    and	   cgl_promote_date is NULL
    and	   cgl_promote_timestamp is NULL;

   if iCnt > 0
   then
	delete from   customer_group_promo_list
	where  cgl_promoted = 'N'
	and    cgl_promote_date is NULL
	and    cgl_promote_timestamp is NULL;

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

END sp_customer_grp_pmlist_delete;
/
