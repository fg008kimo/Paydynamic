CREATE OR REPLACE FUNCTION sp_check_payout_group (
  in_num_of_day			INTEGER,
  in_group			OL_PAYOUT_GRP_LIST.OGL_GROUP%TYPE,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
	  into iCnt
    	from OL_PAYOUT_GRP_LIST
       where OGL_GROUP = in_group
	 and OGL_DISABLED = 0
	 and OGL_POSTING_DATE <= to_char(sysdate - in_num_of_day,'YYYYMMDD');

	if iCnt > 0 THEN
	      OPEN out_cursor for
	      select OGL_BANK_ACCT_NUM,
                     OGL_BANK_ACCT_NAME,
		     OGL_POSTING_DATE
    		from OL_PAYOUT_GRP_LIST
		where OGL_GROUP = in_group
		and OGL_DISABLED = 0
		and OGL_POSTING_DATE <= to_char(sysdate - in_num_of_day,'YYYYMMDD');

		RETURN 1;

	end if;

	RETURN 0;


 exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_check_payout_group;
/
