CREATE OR REPLACE FUNCTION sp_merch_upload_dt_random_rec(
  in_merchant_id		merchant_upload_file_header.uh_merchant_id%type,
  in_batch_id_list		VARCHAR2,
  in_bank_name			merchant_upload_file_detail.ud_bank_name%type,
  in_status			merchant_upload_file_detail.ud_status%type,
  in_batch_mode			merchant_upload_file_detail.ud_batch_mode%type,
  in_payout_ccy			merchant_upload_file_detail.ud_payout_currency%type,
  in_pregen_id			payout_generated_tmp.pt_id%type,
  in_psp_id			psp_detail.psp_id%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	select count(ud_txn_id)
	  into	iCnt
	  from	merchant_upload_file_detail,
		merchant_upload_file_header
	  where ud_batch_id = uh_batch_id
	  and   (ud_batch_id in (SELECT REGEXP_SUBSTR (in_batch_id_list,'[^,]+',1,LEVEL) token
		FROM DUAL CONNECT BY LEVEL <= LENGTH (in_batch_id_list)- LENGTH (REPLACE(in_batch_id_list,',',''))+ 1)
		or in_batch_id_list is NULL)
	  and	(ud_bank_name like in_bank_name or in_bank_name is NULL)
	  and	(select ud_bank_name from
		   (select '%' || re_bank_name || '%' as bname
		    from rule_payout_exclude,
			 psp_detail
		    where re_psp_client_id = client_id
		    and psp_id = in_psp_id
		    and re_disabled = 0
		   )
		where ud_bank_name like bname) is null
	  and	(select re_acct_num
		 from	rule_payout_exclude_bk_acct,
			psp_detail
		 where	re_psp_client_id = client_id
		 and	psp_id = in_psp_id
		 and	re_disabled = 0
		 and	re_acct_name = ud_account_name
		 and	re_acct_num = ud_account_num
		) is null
	  and	(uh_merchant_id = in_merchant_id or in_merchant_id is NULL)
	  and	uh_disabled=0
	  and	ud_disabled=0
	  and	ud_status = in_status 
	  and	ud_batch_mode = in_batch_mode
	  and   ud_payout_currency = in_payout_ccy
	  and	ud_txn_id not in (select pt_txn_id from payout_generated_tmp where pt_id = in_pregen_id);

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	
			ud_txn_id,
                        ud_payout_amount
		from	(SELECT 
				ud_txn_id,
				ud_batch_id,
				ud_payout_amount
 			 FROM merchant_upload_file_detail
			 where (ud_bank_name like in_bank_name or in_bank_name is NULL)
			 and	(select ud_bank_name from
				 (select '%' || re_bank_name || '%' as bname
				  from rule_payout_exclude,
				  psp_detail
				  where re_psp_client_id = client_id
				  and psp_id = in_psp_id
				  and re_disabled = 0
				 )
				 where ud_bank_name like bname) is null
			 and	(select re_acct_num
				 from	rule_payout_exclude_bk_acct,
				 psp_detail
				 where	re_psp_client_id = client_id
				 and	psp_id = in_psp_id
				 and	re_disabled = 0
				 and	re_acct_name = ud_account_name 
				 and	re_acct_num = ud_account_num
				) is null
			 and   ud_disabled=0
			 and   (ud_batch_id in (SELECT REGEXP_SUBSTR (in_batch_id_list,'[^,]+',1,LEVEL) token
				FROM DUAL CONNECT BY LEVEL <= LENGTH (in_batch_id_list)- LENGTH (REPLACE(in_batch_id_list,',',''))+ 1)
				or in_batch_id_list is NULL)
			 and   ud_status = in_status
			 and   ud_batch_mode = in_batch_mode
			 and   ud_payout_currency = in_payout_ccy
			 and   ud_txn_id not in (select pt_txn_id from payout_generated_tmp where pt_id = in_pregen_id)
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
END sp_merch_upload_dt_random_rec;
/
