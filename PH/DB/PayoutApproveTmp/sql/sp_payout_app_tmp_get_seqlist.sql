CREATE OR REPLACE FUNCTION sp_payout_app_tmp_get_seqlist(
  in_batch_id			payout_approve_tmp.pt_id%type,
  in_status			merchant_upload_file_detail.ud_status%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	select count(ud_txn_id)
	  into	iCnt
	  from	merchant_upload_file_detail,
		merchant_upload_file_header,
		payout_approve_tmp
	  where ud_batch_id = uh_batch_id
	  and	ud_txn_id = pt_txn_id
	  and	uh_disabled=0
	  and	ud_disabled=0
	  and	ud_status = in_status
	  and	pt_id = in_batch_id;

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	ud_batch_id,
                        ud_seq_num
		from	merchant_upload_file_detail,
			merchant_upload_file_header,
			payout_approve_tmp
		where pt_id = in_batch_id
		and   ud_disabled=0
		and   ud_txn_id = pt_txn_id
		and   ud_batch_id = uh_batch_id
		and   ud_status = in_status
		and   uh_disabled=0
		ORDER BY ud_batch_id,ud_seq_num;

		return 1;

	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_payout_app_tmp_get_seqlist;
/

