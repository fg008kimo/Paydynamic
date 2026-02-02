CREATE OR REPLACE FUNCTION sp_mms_bank_detail_range (
  in_start_bank_id	mms_bank_detail.bd_bank_id%type,
  in_disabled           mms_bank_detail.bd_disabled%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin

	select count(*)
	into   icnt
	from   mms_bank_detail
	where  bd_bank_id >= NVL(in_start_bank_id , bd_bank_id)
	and    bd_disabled = in_disabled;
        
        if iCnt > 0 THEN
		OPEN out_cursor for
		select bd_bank_id,
		       bd_bank_name,
		       bd_bank_acct
		from   mms_bank_detail
		where  bd_bank_id >= NVL(in_start_bank_id, bd_bank_id)
		and    bd_disabled = in_disabled
		order by bd_bank_id;

		RETURN 0;
	end if;

	RETURN 1;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_mms_bank_detail_range;
/
