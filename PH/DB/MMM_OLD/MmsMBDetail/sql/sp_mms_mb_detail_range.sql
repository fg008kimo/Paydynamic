CREATE OR REPLACE FUNCTION sp_mms_mb_detail_range (
  in_start_mb_id	mms_mb_detail.md_mb_id%type,
  in_disabled           mms_mb_detail.md_disabled%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin

	select count(*)
	into   icnt
	from   mms_mb_detail
	where  md_mb_id >= NVL(in_start_mb_id, md_mb_id)
	and    md_disabled = in_disabled;
        
        if iCnt > 0 THEN
		OPEN out_cursor for
		select md_mb_id, 
		       md_mb_name
		from   mms_mb_detail
		where  md_mb_id >= NVL(in_start_mb_id, md_mb_id)
		and    md_disabled = in_disabled
		order by md_mb_id;

		RETURN 0;
	end if;

	RETURN 1;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_mms_mb_detail_range;
/
