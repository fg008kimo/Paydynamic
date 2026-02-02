CREATE OR REPLACE FUNCTION sp_ol_merch_upload_dt_random(
  in_merchant_id		ol_merchant_upload_file_header.ouh_merchant_id%type,
  in_batch_id_list		VARCHAR2,
  in_bank_name			ol_merchant_upload_file_detail.oud_bank_name%type,
  in_status			ol_merchant_upload_file_detail.oud_status%type,
  in_batch_mode			ol_merchant_upload_file_detail.oud_batch_mode%type,
  in_merch_grp			ol_merchant_upload_file_detail.oud_merchant_payout_grp%type,
  in_psp_grp			ol_merchant_upload_file_detail.oud_psp_payout_grp%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	select count(oud_txn_id)
	  into	iCnt
	  from	ol_merchant_upload_file_detail,
		ol_merchant_upload_file_header
	  where oud_batch_id = ouh_batch_id
	  and	(oud_batch_id in (SELECT REGEXP_SUBSTR (in_batch_id_list,'[^,]+',1,LEVEL) token
				  FROM DUAL CONNECT BY LEVEL <= LENGTH (in_batch_id_list)- LENGTH (REPLACE(in_batch_id_list,',',''))+ 1)
		or in_batch_id_list is NULL)
	  and	(oud_bank_name like in_bank_name or in_bank_name is NULL)
	  and	(ouh_merchant_id = in_merchant_id or in_merchant_id is NULL)
	  and	(oud_psp_payout_grp = in_psp_grp or in_psp_grp is NULL)
	  and	(oud_merchant_payout_grp = in_merch_grp or in_merch_grp is NULL)
	  and	ouh_disabled=0
	  and	oud_disabled=0
	  and	(oud_status = in_status or in_status is NULL)
	  and	oud_batch_mode = in_batch_mode
	  and   oud_pregen_psp_id IS NULL;

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	
			oud_txn_id,
                        oud_batch_id,
                        oud_seq_num,
                        oud_aux_txn_id,
                        oud_merchant_ref,
                        oud_country,
                        oud_identity_id,
                        oud_account_num,
                        oud_account_name,
                        oud_bank_name,
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
                        oud_batch_mode,
                        oud_generated_file_name,
                        oud_psp_batch_id,
                        oud_fundout_date,
                        oud_service_fee,
			oud_merchant_payout_grp,
			oud_psp_payout_grp
		from	(SELECT * FROM ol_merchant_upload_file_detail
			 where (oud_bank_name like in_bank_name or in_bank_name is NULL)
			 and   oud_disabled=0
			 and   (oud_batch_id in (SELECT REGEXP_SUBSTR (in_batch_id_list,'[^,]+',1,LEVEL) token
				FROM DUAL CONNECT BY LEVEL <= LENGTH (in_batch_id_list)- LENGTH (REPLACE(in_batch_id_list,',',''))+ 1)
				or in_batch_id_list is NULL)
			 and   (oud_status = in_status or in_status is NULL)
			 and   oud_batch_mode = in_batch_mode
			 and   oud_pregen_psp_id IS NULL
			 ORDER BY dbms_random.value),
			ol_merchant_upload_file_header
	  	where	oud_batch_id = ouh_batch_id
		and   (ouh_merchant_id = in_merchant_id or in_merchant_id is NULL)
		and   (oud_psp_payout_grp = in_psp_grp or in_psp_grp is NULL)
		and   (oud_merchant_payout_grp = in_merch_grp or in_merch_grp is NULL)
		and   ouh_disabled=0;

		return 1;
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_ol_merch_upload_dt_random;
/
