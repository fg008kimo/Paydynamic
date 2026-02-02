CREATE OR REPLACE FUNCTION sp_payout_approve_tmp_dt_get(
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
	  and	pt_id = in_batch_id
	  and	pt_txn_id = ud_txn_id
	  and	uh_disabled=0
	  and	ud_disabled=0
	  and	(ud_status = in_status or in_status is NULL);

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	ud_batch_id,
			ud_seq_num,
                        ud_txn_id,
                        ud_merchant_ref,
                        ud_country,
                        ud_identity_id,
                        ud_account_num,
                        ud_account_name,
                        ud_bank_name,
                        ud_bank_code,
                        ud_branch,
                        ud_phone_num,
                        ud_province,
                        ud_city,
                        ud_payout_amount,
                        ud_request_amount,
                        ud_payout_currency,
                        ud_request_currency,
                        ud_member_fee_ccy,
                        ud_member_fee,
                        ud_merchant_fee_ccy,
                        ud_merchant_fee,
                        ud_markup_ccy,
                        ud_markup_amt,
                        ud_exchange_rate,
                        ud_status,
                        ud_response_code,
                        ud_remark,
                        ud_batch_mode,
                        ud_generated_file_name,
                        ud_psp_batch_id,
                        ud_fundout_date,
                        ud_service_fee,
                        ud_psp_id,
                        ud_generated_file_id,
			ud_approve_id,
			uh_merchant_id,
			uh_service_code
		from	merchant_upload_file_detail,
			merchant_upload_file_header,
			payout_approve_tmp
	  	where	ud_batch_id = uh_batch_id
		and	pt_id = in_batch_id
		and	pt_txn_id = ud_txn_id
		and	uh_disabled=0
		and	ud_disabled=0
		and	(ud_status = in_status or in_status is NULL)
		order by ud_batch_id, ud_seq_num
		;

		return 1;
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_payout_approve_tmp_dt_get;
/
