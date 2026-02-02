create or replace function sp_mms_instant_txn_inq_dt_ins (
	in_inq_id				mms_instant_txn_inq_dt.mid_inq_id%type,
	in_txn_id				mms_instant_txn_inq_dt.mid_txn_id%type,
	in_dtl_txn_id				mms_instant_txn_inq_dt.mid_dtl_txn_id%type,
	in_txn_code				mms_instant_txn_inq_dt.mid_txn_code%type,
	in_merchant_id				mms_instant_txn_inq_dt.mid_merchant_id%type,
	in_psp_id				mms_instant_txn_inq_dt.mid_psp_id%type,
	in_mb_id				mms_instant_txn_inq_dt.mid_mb_id%type,
	in_bank_id				mms_instant_txn_inq_dt.mid_bank_id%type,
	in_status				mms_instant_txn_inq_dt.mid_status%type,
	in_ar_ind				mms_instant_txn_inq_dt.mid_ar_ind%type,
	in_isd_ind				mms_instant_txn_inq_dt.mid_isd_ind%type,
	in_txn_date				mms_instant_txn_inq_dt.mid_txn_date%type,
	in_txn_amt				mms_instant_txn_inq_dt.mid_txn_amt%type,
	in_txn_ccy				mms_instant_txn_inq_dt.mid_txn_ccy%type,
	in_adjustment				mms_instant_txn_inq_dt.mid_adjustment%type,
	in_exchange_rate			mms_instant_txn_inq_dt.mid_exchange_rate%type,
	in_processing_cost			mms_instant_txn_inq_dt.mid_processing_cost%type,
	in_bank_charge				mms_instant_txn_inq_dt.mid_bank_charge%type,
	in_bank_charge_refund			mms_instant_txn_inq_dt.mid_bank_charge_refund%type,
	in_filing_number			mms_instant_txn_inq_dt.mid_filing_number%type,
	in_create_user				mms_instant_txn_inq_dt.mid_create_user%type
)
  RETURN NUMBER IS
Begin
	insert into mms_instant_txn_inq_dt
			(mid_inq_id,
			mid_txn_id,
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
			mid_filing_number,
			mid_create_user,
			mid_create_timestamp,
			mid_update_user,
			mid_update_timestamp
			)
		values (
		        in_inq_id,
		        in_txn_id,
		        in_dtl_txn_id,
		        in_txn_code,
		        in_merchant_id,
		        in_psp_id,
		        in_mb_id,
			in_bank_id,
		        in_status,
		        in_ar_ind,
		        in_isd_ind,
		        in_txn_date,
		        in_txn_amt,
		        in_txn_ccy,
		        in_adjustment,
		        in_exchange_rate,
		        in_processing_cost,
		        in_bank_charge,
		        in_bank_charge_refund,
		        in_filing_number,
		        in_create_user,
			sysdate,
			in_create_user,
			sysdate
			);

          IF SQL%ROWCOUNT = 0 THEN
             RETURN 1;
          ELSE
             RETURN 0;
          END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mms_instant_txn_inq_dt_ins;
/
