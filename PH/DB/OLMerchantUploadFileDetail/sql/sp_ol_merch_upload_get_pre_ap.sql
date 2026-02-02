CREATE OR REPLACE FUNCTION sp_ol_merch_upload_get_pre_ap(
  in_pre_id			ol_merchant_upload_file_detail.oud_preapprove_id%type,
  in_status			ol_merchant_upload_file_detail.oud_status%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	select count(*)
	  into	iCnt
	  from	ol_merchant_upload_file_detail,
		ol_merchant_upload_file_header
	  where oud_batch_id = ouh_batch_id
	  and	oud_status = in_status
	  and	oud_preapprove_id = in_pre_id
	  and	ouh_disabled=0
	  and	oud_disabled=0;

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	oud_batch_id,
			oud_seq_num,
                        oud_txn_id,
                        oud_merchant_ref,
                        oud_country,
                        oud_identity_id,
                        oud_account_num,
                        oud_account_name,
                        oud_bank_name,
                        oud_bank_code,
                        oud_branch,
                        oud_phone_num,
                        oud_province,
                        oud_city,
                        oud_payout_amount,
                        oud_request_amount,
                        oud_payout_currency,
                        oud_request_currency,
                        oud_member_fee_ccy,
                        oud_member_fee,
                        oud_merchant_fee_ccy,
                        oud_merchant_fee,
                        oud_markup_ccy,
                        oud_markup_amt,
                        oud_exchange_rate,
                        oud_status,
                        oud_response_code,
                        oud_remark,
                        oud_batch_mode,
                        oud_generated_file_name,
                        oud_psp_batch_id,
                        oud_fundout_date,
                        oud_service_fee,
                        oud_psp_id,
                        oud_generated_file_id,
			oud_approve_id,
			ouh_merchant_id,
			ouh_service_code
		from	ol_merchant_upload_file_detail,
			ol_merchant_upload_file_header
	  	where	oud_batch_id = ouh_batch_id
		and	oud_status = in_status
		and	oud_preapprove_id = in_pre_id
		and	ouh_disabled=0
		and	oud_disabled=0
		order by oud_batch_id, oud_seq_num;

		return 1;
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_ol_merch_upload_get_pre_ap;
/
