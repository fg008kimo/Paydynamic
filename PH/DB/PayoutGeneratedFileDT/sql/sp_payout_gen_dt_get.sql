CREATE OR REPLACE FUNCTION sp_payout_gen_dt_get(
  in_file_id			payout_generated_file_dt.fd_file_id%type,
  in_txn_list			VARCHAR2,
  in_upload_status		merchant_upload_file_detail.ud_status%type,
  in_status			payout_generated_file_dt.fd_status%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	select count(*)
	  into	iCnt
	  from	payout_generated_file_dt,
	  	payout_generated_file_hd,
		merchant_upload_file_detail
	  where fd_file_id = fh_file_id
	  and	fd_upload_txn_id = ud_txn_id
	  and	fh_status = 1
	  and	(fd_status = in_status or in_status is NULL)
	  and	(fd_file_id = in_file_id or in_file_id is NULL)
	  and	(ud_status  = in_upload_status or in_upload_status is NULL)
	  and	(fd_upload_txn_id in (SELECT REGEXP_SUBSTR (in_txn_list,'[^,]+',1,LEVEL) token
		FROM DUAL CONNECT BY LEVEL <= LENGTH (in_txn_list)- LENGTH (REPLACE(in_txn_list,',',''))+ 1)
		or in_txn_list is NULL)
	  and	ud_disabled=0;

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	fd_file_id,
			fd_batch_id,
			fd_seq_num,
                        fd_txn_id,
                        fd_upload_txn_id,
                        fd_merchant_ref,
                        fd_country,
                        fd_identity_id,
                        fd_account_num,
                        fd_account_name,
                        fd_bank_name,
                        fd_bank_code,
                        fd_branch,
                        fd_phone_num,
                        fd_province,
                        fd_city,
                        fd_payout_amount,
                        fd_request_amount,
                        fd_payout_currency,
                        fd_request_currency,
                        fh_filename,
                        fh_file_pid,
			client_id,
			fh_ccy_id,
			fh_txn_count,
			fh_total_txn_amt,
			tp_service_fee
		from	payout_generated_file_dt,
			payout_generated_file_hd,
			merchant_upload_file_detail,
			psp_detail,
			txn_psp_detail
	  	where	fd_file_id = fh_file_id
	  	and	fd_upload_txn_id = ud_txn_id
	  	and	fd_txn_id = tp_txn_id
	  	and	fh_status = 1
	  	and	(fd_status = in_status or in_status is NULL)
	  	and	(fd_file_id = in_file_id or in_file_id is NULL)
	 	and	(ud_status  = in_upload_status or in_upload_status is NULL)
		and	(fd_upload_txn_id in (SELECT REGEXP_SUBSTR (in_txn_list,'[^,]+',1,LEVEL) token
			FROM DUAL CONNECT BY LEVEL <= LENGTH (in_txn_list)- LENGTH (REPLACE(in_txn_list,',',''))+ 1)
			or in_txn_list is NULL)
		and	psp_id = fh_file_pid
	 	and	ud_disabled=0
		order by fd_batch_id, fd_seq_num;

		return 1;
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_payout_gen_dt_get;
/
