CREATE OR REPLACE FUNCTION sp_ol_txn_psp_dt_getbydlvid(
  in_dlv_id	            	ol_txn_psp_detail.otp_delivery_id%type,
  in_sub_status                 ol_txn_header.oth_sub_status%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin

	select count(*)
	  into	iCnt
	  from	ol_txn_psp_detail, ol_txn_header
	  where	otp_delivery_id=in_dlv_id
	   and  oth_txn_id = otp_txn_id
           and  oth_sub_status = in_sub_status;

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	otp_txn_id
		from	ol_txn_psp_detail, ol_txn_header
		where	otp_delivery_id=in_dlv_id
		and     oth_txn_id = otp_txn_id
                and     oth_sub_status = in_sub_status
		order by otp_txn_id;

		return 1;
	
	else
		return 0;
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_ol_txn_psp_dt_getbydlvid;
/
