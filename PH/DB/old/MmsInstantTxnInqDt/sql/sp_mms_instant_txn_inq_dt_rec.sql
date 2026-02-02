CREATE OR REPLACE FUNCTION sp_mms_instant_txn_inq_dt_rec (
  in_inq_id             mms_instant_txn_inq_dt.mid_inq_id%type,
  in_start_txn_id	mms_instant_txn_inq_dt.mid_txn_id%type,
  in_start_dtl_txn_id	mms_instant_txn_inq_dt.mid_dtl_txn_id%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
	into   iCnt
	from   mms_instant_txn_inq_dt
	where  mid_inq_id = in_inq_id 
	and    ( (mid_txn_id > NVL(in_start_txn_id, mid_txn_id) ) or
                 ((mid_txn_id >= NVL(in_start_txn_id, mid_txn_id) ) and (mid_dtl_txn_id >= NVL(in_start_dtl_txn_id, mid_dtl_txn_id)))
	       );
		

        if iCnt > 0 THEN
		OPEN out_cursor for
                select mid_txn_id,
                       mid_dtl_txn_id,
                       mid_txn_code,
                       mid_merchant_id,
                       mid_psp_id,
                       mid_mb_id,
                       mid_bank_id,
                       mid_status,
                       mid_ar_ind,
                       mid_isd_ind,
                       mid_txn_date,
                       mid_txn_amt,
                       mid_txn_ccy,
                       mid_adjustment,
                       mid_exchange_rate,
                       mid_processing_cost,
                       mid_bank_charge,
                       mid_bank_charge_refund,
                       mid_filing_number
		from   mms_instant_txn_inq_dt
		where  mid_inq_id = in_inq_id 
		and    ( (mid_txn_id > NVL(in_start_txn_id, mid_txn_id) ) or
                 	 ((mid_txn_id >= NVL(in_start_txn_id, mid_txn_id) ) and (mid_dtl_txn_id >= NVL(in_start_dtl_txn_id, mid_dtl_txn_id)))
               		)
                order by mid_txn_id, mid_dtl_txn_id;

		RETURN 0;
	end if;

	RETURN 1;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_mms_instant_txn_inq_dt_rec;
/
