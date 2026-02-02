CREATE OR REPLACE FUNCTION sp_merch_upload_dt_get_by_job(
  in_batch_id			merchant_upload_file_detail.ud_batch_id%type,
  in_last_seq			merchant_upload_file_detail.ud_seq_num%type,
  in_status			merchant_upload_file_detail.ud_status%type,
  in_bank_name			merchant_upload_file_detail.ud_bank_name%type,
  in_min_amt			merchant_upload_file_detail.ud_request_amount%type,
  in_max_amt			merchant_upload_file_detail.ud_request_amount%type,
  in_count			INTEGER,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	/*select count(ud_txn_id)
	  into	iCnt
	  from	merchant_upload_file_detail,
		merchant_upload_file_header
	  where ud_batch_id = uh_batch_id
	  and	ud_batch_id = in_batch_id 
	  and	(ud_bank_name like in_bank_name or in_bank_name is NULL)
	  and	uh_disabled=0
	  and	ud_disabled=0
	  and	ud_status = in_status 
	  and   (ud_request_amount >= in_min_amt or in_min_amt is NULL)
	  and   (ud_request_amount <= in_max_amt or in_max_amt is NULL)
	  and	ud_seq_num <= in_last_seq;
	*/
	  --and	rownum <= in_count;

	--if iCnt > 0 THEN
		OPEN out_cursor for
		select	
                        ud_batch_id,
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
                        ud_response_code,
                        ud_remark,
                        ud_batch_mode,
			uh_merchant_id,
			uh_service_code
		from	merchant_upload_file_detail,merchant_upload_file_header
		where (ud_bank_name like in_bank_name or in_bank_name is NULL)
		and   ud_disabled=0
		and   ud_batch_id = in_batch_id
		and   ud_batch_id = uh_batch_id
		and   ud_status = in_status
		and   uh_disabled=0
	  	and   (ud_request_amount >= in_min_amt or in_min_amt is NULL)
	  	and   (ud_request_amount <= in_max_amt or in_max_amt is NULL)
		and   ud_seq_num <= in_last_seq
	  	--and   rownum <= in_count
		ORDER BY dbms_random.value
		for update nowait;

		return 1;
		
	--end if;

	--return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_merch_upload_dt_get_by_job;
/
