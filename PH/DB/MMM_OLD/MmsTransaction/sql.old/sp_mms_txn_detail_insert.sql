create or replace function sp_mms_txn_detail_insert(
       in_txn_id                                mms_txn_detail.mtd_txn_id%type,
       in_sd_ind                                mms_txn_detail.mtd_sd_ind%type,
       in_merchant_id				mms_txn_detail.mtd_merchant_id%type,
       in_psp_id				mms_txn_detail.mtd_psp_id%type,
       in_mb_id					mms_txn_detail.mtd_mb_id%type,
       in_bank_id				mms_txn_detail.mtd_bank_id%type,
       in_transmission_datetime	 	 	mms_txn_detail.mtd_transmission_datetime%type,
       in_txn_amt				mms_txn_detail.mtd_txn_amt%type,
       in_txn_ccy				mms_txn_detail.mtd_txn_ccy%type,
       in_adjustment                            mms_txn_detail.mtd_adjustment%type,
       in_exchange_rate                         mms_txn_detail.mtd_exchange_rate%type,
       in_processing_cost                   	mms_txn_detail.mtd_processing_cost%type,
       in_bank_charge                           mms_txn_detail.mtd_bank_charge%type,
       in_bank_charge_refund                    mms_txn_detail.mtd_bank_charge_refund%type,
       in_filing_number                         mms_txn_detail.mtd_filing_number%type,
       in_country				mms_txn_detail.mtd_country%type,
       in_encrypt_type				mms_txn_detail.mtd_encrypt_type%type,
       in_version_no				mms_txn_detail.mtd_version_no%type,
       in_create_user				mms_txn_detail.mtd_create_user%type,
       in_update_user				mms_txn_detail.mtd_update_user%type
)
  RETURN NUMBER IS
Begin
     Update mms_txn_detail
     	set mtd_merchant_id = in_merchant_id,
	    mtd_psp_id = in_psp_id,
	    mtd_mb_id = in_mb_id,
	    mtd_bank_id = in_bank_id,
	    mtd_transmission_datetime = in_transmission_datetime,
	    mtd_txn_amt = in_txn_amt,
            mtd_txn_ccy = in_txn_ccy,
            mtd_adjustment = in_adjustment,
            mtd_exchange_rate = in_exchange_rate,
            mtd_processing_cost = in_processing_cost,
            mtd_bank_charge = in_bank_charge,
            mtd_bank_charge_refund = in_bank_charge_refund,
            mtd_filing_number = in_filing_number,
	    mtd_country = in_country,
	    mtd_encrypt_type = in_encrypt_type,
	    mtd_version_no = in_version_no,
	    mtd_sd_ind = in_sd_ind
      Where mtd_txn_id = in_txn_id;

     IF SQL%ROWCOUNT = 0 THEN
        insert into mms_txn_detail
                     (mtd_txn_id,
		      mtd_sd_ind,
		      mtd_merchant_id,
		      mtd_psp_id,
		      mtd_mb_id,
		      mtd_bank_id,
		      mtd_transmission_datetime,
		      mtd_txn_amt,
                      mtd_txn_ccy,
                      mtd_adjustment,
                      mtd_exchange_rate,
                      mtd_processing_cost,
                      mtd_bank_charge,
                      mtd_bank_charge_refund,
                      mtd_filing_number,
		      mtd_country,
		      mtd_encrypt_type,
		      mtd_version_no,
                      mtd_create_user,
                      mtd_create_timestamp,
                      mtd_update_user,
                      mtd_update_timestamp
                      )
          values(in_txn_id,
		     in_sd_ind,
		     in_merchant_id,
		     in_psp_id,
		     in_mb_id,
		     in_bank_id,
		     in_transmission_datetime,
		     in_txn_amt,
                     in_txn_ccy,
                     in_adjustment,
                     in_exchange_rate,
                     in_processing_cost,
                     in_bank_charge,
                     in_bank_charge_refund,
                     in_filing_number,
                     in_country,
		     in_encrypt_type,
		     in_version_no,
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
end sp_mms_txn_detail_insert;
/
