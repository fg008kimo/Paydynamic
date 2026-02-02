CREATE OR REPLACE FUNCTION sp_ol_po_app_tmp_get_seqlist(
  in_batch_id			ol_payout_approve_tmp.opt_id%type,
  in_status			ol_merchant_upload_file_detail.oud_status%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	select count(oud_txn_id)
	  into	iCnt
	  from	ol_merchant_upload_file_detail,
		ol_merchant_upload_file_header,
		ol_payout_approve_tmp
	  where oud_batch_id = ouh_batch_id
	  and	oud_txn_id = opt_txn_id
	  and	ouh_disabled=0
	  and	oud_disabled=0
	  and	oud_status = in_status
	  and	opt_id = in_batch_id;

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	oud_batch_id,
                        oud_seq_num
		from	ol_merchant_upload_file_detail,
			ol_merchant_upload_file_header,
			ol_payout_approve_tmp
		where opt_id = in_batch_id
		and   oud_disabled=0
		and   oud_txn_id = opt_txn_id
		and   oud_batch_id = ouh_batch_id
		and   oud_status = in_status
		and   ouh_disabled=0
		ORDER BY oud_batch_id,oud_seq_num;

		return 1;

	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_ol_po_app_tmp_get_seqlist;
/

