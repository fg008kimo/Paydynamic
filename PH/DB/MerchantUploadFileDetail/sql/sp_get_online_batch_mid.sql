CREATE OR REPLACE FUNCTION sp_get_online_batch_mid(
  in_merchant_id		merchant_upload_file_header.uh_merchant_id%type,
  in_batch_mode			merchant_upload_file_detail.ud_batch_mode%type,
  in_status			merchant_upload_file_detail.ud_status%type,
  in_disabled		        merchant_upload_file_detail.ud_disabled%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin

	select count(*)
	  into	iCnt
	  from	merchant_upload_file_detail,
		merchant_upload_file_header
	  where	ud_batch_id = uh_batch_id
	  and	ud_disabled = in_disabled
	  and	ud_disabled = uh_disabled
	  and   ud_batch_mode = in_batch_mode
	  and	ud_status = in_status
	  and	uh_merchant_id = in_merchant_id;

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	ud_batch_id,
                        ud_seq_num,
                        uh_merchant_id,
                        uh_service_code,
                        ud_txn_id,
                        ud_aux_txn_id,
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
                        ud_response_code,
                        ud_remark,
                        ud_generated_file_name,
                        ud_psp_batch_id,
                        ud_fundout_date,
                        ud_service_fee,
                        ud_pregen_psp_id
		from	merchant_upload_file_detail,
			merchant_upload_file_header
		where	ud_batch_id = uh_batch_id
		and	ud_disabled = in_disabled
		and	ud_disabled = uh_disabled
		and	ud_batch_mode = in_batch_mode
		and	ud_status = in_status
		and	uh_merchant_id = in_merchant_id
		order by ud_batch_id, ud_seq_num;

		return 1;
	
	else
		return 0;

	end if;


exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_get_online_batch_mid;
/
