CREATE OR REPLACE FUNCTION sp_mms_stl_bank_detail_range (
  in_start_stlbank_id	mms_stl_bank_detail.sbd_stl_bank_id%type,
  in_disabled           mms_stl_bank_detail.sbd_disabled%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin

	select count(*)
	into   icnt
	from   mms_stl_bank_detail
	where  sbd_stl_bank_id >= NVL(in_start_stlbank_id , sbd_stl_bank_id)
	and    sbd_disabled = in_disabled;
        
        if iCnt > 0 THEN
		OPEN out_cursor for
		select sbd_stl_bank_id,
		       sbd_stl_bank_name,
		       sbd_stl_bank_acct
		from   mms_stl_bank_detail
		where  sbd_stl_bank_id >= NVL(in_start_stlbank_id, sbd_stl_bank_id)
		and    sbd_disabled = in_disabled
		order by sbd_stl_bank_id;

		RETURN 0;
	end if;

	RETURN 1;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_mms_stl_bank_detail_range;
/
