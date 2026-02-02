CREATE OR REPLACE FUNCTION sp_merch_upload_dt_get(
  in_batch_id			merchant_upload_file_detail.ud_batch_id%type,
  in_seq_num			merchant_upload_file_detail.ud_seq_num%type,
  in_bank_name			merchant_upload_file_detail.ud_bank_name%type,
  in_status			merchant_upload_file_detail.ud_status%type,
  in_min_amt			merchant_upload_file_detail.ud_request_amount%type,
  in_max_amt			merchant_upload_file_detail.ud_request_amount%type,
  in_file_id			merchant_upload_file_detail.ud_generated_file_id%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	select count(*)
	  into	iCnt
	  from	merchant_upload_file_detail,
		merchant_upload_file_header
	  where ud_batch_id = uh_batch_id
	  and	(ud_status = in_status or in_status is NULL)
	  and	(ud_batch_id = in_batch_id or in_batch_id is NULL)
	  and	(ud_seq_num = in_seq_num  or in_seq_num is NULL)
	  and	(ud_bank_name like in_bank_name or in_bank_name is NULL)
	  and   (ud_request_amount >= in_min_amt or in_min_amt is NULL)
	  and   (ud_request_amount <= in_max_amt or in_max_amt is NULL)
	  and	(ud_generated_file_id = in_file_id or in_file_id is NULL)
	  and	uh_disabled=0
	  and	ud_disabled=0;

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
			merchant_upload_file_header
	  	where	ud_batch_id = uh_batch_id
		and	(ud_status = in_status or in_status is NULL)
		and	(ud_batch_id = in_batch_id or in_batch_id is NULL)
		and	(ud_seq_num = in_seq_num  or in_seq_num is NULL)
		and	(ud_bank_name like in_bank_name or in_bank_name is NULL)
		and   (ud_request_amount >= in_min_amt or in_min_amt is NULL)
		and   (ud_request_amount <= in_max_amt or in_max_amt is NULL)
		and	(ud_generated_file_id = in_file_id or in_file_id is NULL)
		and	uh_disabled=0
		and	ud_disabled=0
		order by ud_batch_id, ud_seq_num
		;

		return 1;
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_merch_upload_dt_get;
/
