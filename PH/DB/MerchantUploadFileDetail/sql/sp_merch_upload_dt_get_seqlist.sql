CREATE OR REPLACE FUNCTION sp_merch_upload_dt_get_seqlist(
  in_batch_id			merchant_upload_file_detail.ud_batch_id%type,
  in_last_seq			merchant_upload_file_detail.ud_seq_num%type,
  in_status			merchant_upload_file_detail.ud_status%type,
  in_bank_name			merchant_upload_file_detail.ud_bank_name%type,
  in_min_amt			merchant_upload_file_detail.ud_request_amount%type,
  in_max_amt			merchant_upload_file_detail.ud_request_amount%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin
	select count(ud_txn_id)
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
	
	if iCnt > 0 THEN
		OPEN out_cursor for
		select	
                        ud_seq_num
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
		ORDER BY ud_seq_num;

		return 1;
		
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_merch_upload_dt_get_seqlist;
/
