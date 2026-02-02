CREATE OR REPLACE FUNCTION sp_mms_txn_header_rec (
  in_req_txn_id         mms_txn_header.mth_client_ref%type,
  in_req_status         mms_txn_header.mth_status%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin

	select count(*)
	into   iCnt
	from   mms_txn_header
	where  mth_client_ref = NVL(in_req_txn_id, mth_client_ref)
	and    mth_status = NVL(in_req_status, mth_status);

        
        if iCnt > 0 THEN
		OPEN out_cursor for
        	select	mth_txn_id, 
			mth_org_txn_id,
			mth_service_code,
			mth_mmc_node_id,
			mth_status,
			mth_ar_ind,
			mth_internal_code,
			mth_response_code,
			mth_txn_code,
			mth_process_type,
			mth_process_code,
			mth_host_posting_date,
			mth_tm_date,
			mth_tm_time,
			mth_local_tm_date,
			mth_local_tm_time,
			mth_transmission_datetime,
			mth_transaction_amount,
			mth_transaction_ccy
        	from    mms_txn_header
		where   mth_client_ref = NVL(in_req_txn_id, mth_client_ref)
		and     mth_status = NVL(in_req_status, mth_status)
		order by mth_txn_id;

		RETURN 0;
	end if;

	RETURN 1;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_mms_txn_header_rec;
/
