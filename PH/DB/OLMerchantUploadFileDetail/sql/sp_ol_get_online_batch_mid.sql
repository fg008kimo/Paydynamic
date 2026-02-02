CREATE OR REPLACE FUNCTION sp_ol_get_online_batch_mid(
  in_merchant_id		ol_merchant_upload_file_header.ouh_merchant_id%type,
  in_batch_mode			ol_merchant_upload_file_detail.oud_batch_mode%type,
  in_status			ol_merchant_upload_file_detail.oud_status%type,
  in_disabled		        ol_merchant_upload_file_detail.oud_disabled%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin

	select count(*)
	  into	iCnt
	  from	ol_merchant_upload_file_detail,
		ol_merchant_upload_file_header
	  where	oud_batch_id = ouh_batch_id
	  and	oud_disabled = in_disabled
	  and	oud_disabled = ouh_disabled
	  and   oud_batch_mode = in_batch_mode
	  and	oud_status = in_status
	  and	ouh_merchant_id = in_merchant_id;

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	oud_batch_id,
                        oud_seq_num,
                        ouh_merchant_id,
                        ouh_service_code,
                        oud_txn_id,
                        oud_aux_txn_id,
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
                        oud_response_code,
                        oud_remark,
                        oud_generated_file_name,
                        oud_psp_batch_id,
                        oud_fundout_date,
                        oud_service_fee,
                        oud_pregen_psp_id
		from	ol_merchant_upload_file_detail,
			ol_merchant_upload_file_header
		where	oud_batch_id = ouh_batch_id
		and	oud_disabled = in_disabled
		and	oud_disabled = ouh_disabled
		and	oud_batch_mode = in_batch_mode
		and	oud_status = in_status
		and	ouh_merchant_id = in_merchant_id
		order by oud_batch_id, oud_seq_num;

		return 1;
	
	else
		return 0;

	end if;


exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_ol_get_online_batch_mid;
/
