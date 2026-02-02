DROP FUNCTION sp_mob_bank_def_grp;

CREATE OR REPLACE FUNCTION sp_mob_bank_def_grp (
   in_merchant_id        MERCH_DETAIL.MERCHANT_ID%TYPE,
   out_cursor        OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
BEGIN
   OPEN out_cursor FOR

	select	mbs_group
	from	mob_bank_selection,
		customer_group_rules
	where cgr_group_code = mbs_group
	and cgr_merchant_id = in_merchant_id
	and cgr_from_group_code is null
	and mbs_def_assign_grp = 1
	and mbs_disabled = 0
	and cgr_disabled = 0;


   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_mob_bank_def_grp;
/
