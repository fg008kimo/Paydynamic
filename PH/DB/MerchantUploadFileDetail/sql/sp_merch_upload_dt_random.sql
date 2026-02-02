CREATE OR REPLACE FUNCTION sp_merch_upload_dt_random(
  in_merchant_id		merchant_upload_file_header.uh_merchant_id%type,
  in_batch_id_list		VARCHAR2,
  in_bank_name			merchant_upload_file_detail.ud_bank_name%type,
  in_status			merchant_upload_file_detail.ud_status%type,
  in_batch_mode			merchant_upload_file_detail.ud_batch_mode%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	select count(ud_txn_id)
	  into	iCnt
	  from	merchant_upload_file_detail,
		merchant_upload_file_header
	  where ud_batch_id = uh_batch_id
	  and	(ud_batch_id in (SELECT REGEXP_SUBSTR (in_batch_id_list,'[^,]+',1,LEVEL) token
				  FROM DUAL CONNECT BY LEVEL <= LENGTH (in_batch_id_list)- LENGTH (REPLACE(in_batch_id_list,',',''))+ 1)
		or in_batch_id_list is NULL)
	  and	(ud_bank_name like in_bank_name or in_bank_name is NULL)
	  and	(uh_merchant_id = in_merchant_id or in_merchant_id is NULL)
	  and	uh_disabled=0
	  and	ud_disabled=0
	  and	ud_status = in_status 
	  and	ud_batch_mode = in_batch_mode
	  and   ud_pregen_psp_id IS NULL;

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	
			ud_txn_id,
                        ud_batch_id,
                        ud_seq_num,
                        ud_aux_txn_id,
                        ud_merchant_ref,
                        ud_country,
                        ud_identity_id,
                        ud_account_num,
                        ud_account_name,
                        ud_bank_name,
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
                        ud_generated_file_name,
                        ud_psp_batch_id,
                        ud_fundout_date,
                        ud_service_fee
		from	(SELECT * FROM merchant_upload_file_detail
			 where (ud_bank_name like in_bank_name or in_bank_name is NULL)
			 and   ud_disabled=0
			 and   (ud_batch_id in (SELECT REGEXP_SUBSTR (in_batch_id_list,'[^,]+',1,LEVEL) token
				FROM DUAL CONNECT BY LEVEL <= LENGTH (in_batch_id_list)- LENGTH (REPLACE(in_batch_id_list,',',''))+ 1)
				or in_batch_id_list is NULL)
			 and   ud_status = in_status
			 and   ud_batch_mode = in_batch_mode
			 and   ud_pregen_psp_id IS NULL
			 ORDER BY dbms_random.value),
			merchant_upload_file_header
	  	where	ud_batch_id = uh_batch_id
		and   (uh_merchant_id = in_merchant_id or in_merchant_id is NULL)
		and   uh_disabled=0
		for update;

		return 1;
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_merch_upload_dt_random;
/
