create or replace function sp_mi_acr_inout_his_insert(
       in_batch_id	   MI_ACR_INOUT_HISTORY.mah_batch_id%type,
       in_txn_date	   MI_ACR_INOUT_HISTORY.mah_txn_date%type,
       in_bank_id	   MI_ACR_INOUT_HISTORY.mah_bank_id%type,
       in_from_ccy	   MI_ACR_INOUT_HISTORY.mah_from_ccy%type,
       in_from_amt	   MI_ACR_INOUT_HISTORY.mah_from_amt%type,
       in_bank_ccy	   MI_ACR_INOUT_HISTORY.mah_bank_ccy%type,
       in_bank_amt	   MI_ACR_INOUT_HISTORY.mah_bank_amt%type,
       in_old_rate	   MI_ACR_INOUT_HISTORY.mah_old_rate%type,
       in_new_rate	   MI_ACR_INOUT_HISTORY.mah_new_rate%type,
       in_org_bank_bal	   MI_ACR_INOUT_HISTORY.mah_org_bank_bal%type,
       in_bank_bal	   MI_ACR_INOUT_HISTORY.mah_bank_bal%type,
       in_txn_code	   MI_ACR_INOUT_HISTORY.mah_txn_code%type,
       in_fund_type	   MI_ACR_INOUT_HISTORY.mah_fund_type%type,
       in_txn_id	   MI_ACR_INOUT_HISTORY.mah_txn_id%type,
       in_time		   varchar2,
       in_acr_prorata	   MI_ACR_INOUT_HISTORY.mah_acr_prorata%type,
       in_user		   MI_ACR_INOUT_HISTORY.mah_create_user%type)
  RETURN NUMBER IS
begin

	insert into
	MI_ACR_INOUT_HISTORY
		(mah_batch_id,
		 mah_txn_date,
		 mah_bank_id,
		 mah_from_ccy,
		 mah_from_amt,
		 mah_bank_ccy,
		 mah_bank_amt,
		 mah_old_rate,
		 mah_new_rate,
		 mah_org_bank_bal,
		 mah_bank_bal,
		 mah_txn_code,
		 mah_fund_type,
		 mah_txn_id,
		 mah_time,
		 mah_acr_prorata,
		 mah_create_user,
		 mah_update_user
                 )
         
    	values
	(in_batch_id,
	 in_txn_date,
	 in_bank_id,
	 in_from_ccy,
	 in_from_amt,
	 in_bank_ccy,
	 in_bank_amt,
	 in_old_rate,
	 in_new_rate,
	 in_org_bank_bal,
	 in_bank_bal,
	 in_txn_code,
	 in_fund_type,
	 in_txn_id,
	 to_date(in_time,'YYYYMMDDHH24MISS'),
	 in_acr_prorata,
	 in_user,
	 in_user
	);

	IF SQL%ROWCOUNT > 0 THEN
		return 0;
	else
		return 1;
	end if;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mi_acr_inout_his_insert;
/
