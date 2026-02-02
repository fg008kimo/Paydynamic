CREATE OR REPLACE FUNCTION sp_ol_merch_upload_dt_po_grp(
  in_merchant_id		ol_merchant_upload_file_header.ouh_merchant_id%type,
  in_batch_mode			ol_merchant_upload_file_detail.oud_batch_mode%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	select count(oud_txn_id)
	  into	iCnt
	  from	ol_merchant_upload_file_detail,
		ol_merchant_upload_file_header,
		ol_merch_detail
	  where oud_batch_id = ouh_batch_id
	  and	(ouh_merchant_id = in_merchant_id or in_merchant_id is NULL)
	  and	ouh_merchant_id = md_merchant_id
	  and	md_support_payout_grp = 1
	  and	ouh_disabled=0
	  and	oud_disabled=0
	  and	oud_batch_mode = in_batch_mode
	  and   oud_psp_payout_grp IS NULL
	  and   oud_merchant_payout_grp IS NOT NULL;

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	
			oud_txn_id,
                        oud_batch_id,
                        oud_seq_num,
                        oud_aux_txn_id,
                        oud_merchant_ref,
                        oud_account_num,
                        oud_account_name,
                        oud_bank_name,
                        oud_branch,
                        oud_batch_mode,
			oud_merchant_payout_grp
		from	(SELECT * FROM ol_merchant_upload_file_detail
			 where oud_disabled=0
			 and   oud_batch_mode = in_batch_mode
			 AND   oud_status in(69,65)
			 and   oud_psp_payout_grp IS NULL
			 and   oud_merchant_payout_grp IS NOT NULL
			),
			ol_merchant_upload_file_header,
			ol_merch_detail
	  	where	oud_batch_id = ouh_batch_id
		and   (ouh_merchant_id = in_merchant_id or in_merchant_id is NULL)
		and   ouh_merchant_id = md_merchant_id
		and   md_support_payout_grp = 1
		and   ouh_disabled=0;

		return 1;
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_ol_merch_upload_dt_po_grp;
/
