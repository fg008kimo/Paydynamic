create or replace function sp_mmc_txn_detail_insert(
       in_txn_id                                mmc_txn_detail.mcd_txn_id%type,
       in_dtl_txn_id                            mmc_txn_detail.mcd_dtl_txn_id%type,
       in_txn_code                              mmc_txn_detail.mcd_txn_code%type,
       in_merchant_id                           mmc_txn_detail.mcd_merchant_id%type,
       in_psp_id    				mmc_txn_detail.mcd_psp_id%type,
       in_mb_id					mmc_txn_detail.mcd_mb_id%type,
       in_bank_id                               mmc_txn_detail.mcd_bank_id%type,
       in_status				mmc_txn_detail.mcd_status%type,
       in_ar_ind				mmc_txn_detail.mcd_ar_ind%type,
       in_transmission_datetime	 	 	mmc_txn_detail.mcd_transmission_datetime%type,
       in_isd_ind                               mmc_txn_detail.mcd_isd_ind%type,
       in_txn_amt				mmc_txn_detail.mcd_txn_amt%type,
       in_txn_ccy				mmc_txn_detail.mcd_txn_ccy%type,
       in_adjustment				mmc_txn_detail.mcd_adjustment%type,
       in_exchange_rate				mmc_txn_detail.mcd_exchange_rate%type,
       in_processing_cost			mmc_txn_detail.mcd_processing_cost%type,
       in_bank_charge				mmc_txn_detail.mcd_bank_charge%type,
       in_bank_charge_refund			mmc_txn_detail.mcd_bank_charge_refund%type,
       in_filing_number				mmc_txn_detail.mcd_filing_number%type,
       in_create_user				mmc_txn_detail.mcd_create_user%type,
       in_update_user				mmc_txn_detail.mcd_update_user%type
)
  RETURN NUMBER IS
Begin
     Update mmc_txn_detail
     	set mcd_txn_code = in_txn_code,	
            mcd_merchant_id = in_merchant_id,
            mcd_psp_id = in_psp_id,
            mcd_mb_id = in_mb_id,
            mcd_bank_id = in_bank_id, 
            mcd_status = in_status,
            mcd_ar_ind = in_ar_ind,
	    mcd_transmission_datetime = in_transmission_datetime,
            mcd_isd_ind = in_isd_ind,
	    mcd_txn_amt = in_txn_amt,
	    mcd_txn_ccy = in_txn_ccy,
	    mcd_adjustment = in_adjustment,
	    mcd_exchange_rate = in_exchange_rate,
	    mcd_processing_cost = in_processing_cost,
	    mcd_bank_charge = in_bank_charge,
	    mcd_bank_charge_refund = in_bank_charge_refund,
	    mcd_filing_number = in_filing_number,
            mcd_update_timestamp = sysdate,
            mcd_update_user = in_update_user
      Where mcd_txn_id = in_txn_id
        and mcd_dtl_txn_id = in_dtl_txn_id;

     IF SQL%ROWCOUNT = 0 THEN
        insert into mmc_txn_detail
                     (mcd_txn_id,
		      mcd_dtl_txn_id,
		      mcd_txn_code,
	              mcd_merchant_id,
		      mcd_psp_id,
	              mcd_mb_id,
	              mcd_bank_id,
		      mcd_status,
		      mcd_ar_ind,
		      mcd_transmission_datetime,
		      mcd_isd_ind,
		      mcd_txn_amt,
		      mcd_txn_ccy,
		      mcd_adjustment,
		      mcd_exchange_rate,
		      mcd_processing_cost,
		      mcd_bank_charge,
		      mcd_bank_charge_refund,
		      mcd_filing_number,
                      mcd_create_user,
                      mcd_create_timestamp,
                      mcd_update_user,
                      mcd_update_timestamp
                      )
          values(in_txn_id,
       	         in_dtl_txn_id,
		 in_txn_code,
                 in_merchant_id,
                 in_psp_id,
                 in_mb_id,
                 in_bank_id,
       		 in_status,
	         in_ar_ind,
		 in_transmission_datetime,
       		 in_isd_ind,
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
                 in_update_user,
                 sysdate
                 );

          IF SQL%ROWCOUNT = 0 THEN
             RETURN 1;
          ELSE
             RETURN 0;
          END IF;
      Else
          Return 0;
       End If;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mmc_txn_detail_insert;
/
