CREATE OR REPLACE FUNCTION sp_merch_upload_dt_get_palist(
  in_batch_id			merchant_upload_file_detail.ud_batch_id%type,
  in_pre_approve_id		merchant_upload_file_detail.ud_preapprove_id%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	select count(ud_txn_id)
	  into	iCnt
	  from	merchant_upload_file_detail,
		merchant_upload_file_header
	  where ud_batch_id = uh_batch_id
	  and	ud_batch_id = in_batch_id
	  and	uh_disabled=0
	  and	ud_disabled=0
	  and	ud_preapprove_id= in_pre_approve_id; 
	
	if iCnt > 0 THEN
		OPEN out_cursor for
		select	
                        ud_seq_num
		from	merchant_upload_file_detail,merchant_upload_file_header
		where ud_preapprove_id=in_pre_approve_id
		and   ud_batch_id = uh_batch_id
		and   ud_batch_id = in_batch_id
		and   uh_disabled=0
		and   ud_disabled=0
		ORDER BY ud_seq_num;

		return 1;
		
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_merch_upload_dt_get_palist;
/
