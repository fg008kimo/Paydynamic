create or replace function sp_mmc_txn_header_insert(
        in_txn_id                             mmc_txn_header.mch_txn_id%type,
        in_org_txn_id                         mmc_txn_header.mch_org_txn_id%type,
	in_server_ref			      mmc_txn_header.mch_server_ref%type,
        in_status                             mmc_txn_header.mch_status%type,
        in_ar_ind                             mmc_txn_header.mch_ar_ind%type,
        in_txn_code                           mmc_txn_header.mch_txn_code%type,
        in_process_type                       mmc_txn_header.mch_process_type%type,
        in_process_code                       mmc_txn_header.mch_process_code%type,
	in_host_posting_date		      mmc_txn_header.mch_host_posting_date%type,
	in_tm_date			      mmc_txn_header.mch_tm_date%type,
	in_tm_time			      mmc_txn_header.mch_tm_time%type,
	in_local_tm_date		      mmc_txn_header.mch_local_tm_date%type,
	in_local_tm_time		      mmc_txn_header.mch_local_tm_time%type,
	in_transmission_datetime	      mmc_txn_header.mch_transmission_datetime%type,
	in_transaction_amount	      	      mmc_txn_header.mch_transaction_amount%type,
	in_transaction_ccy	      	      mmc_txn_header.mch_transaction_ccy%type,
        in_create_user                        mmc_txn_header.mch_create_user%type,
        in_update_user                        mmc_txn_header.mch_update_user%type
        )
  RETURN NUMBER IS
begin

  insert into mmc_txn_header (
                  mch_txn_id,
                  mch_org_txn_id,
		  mch_server_ref,
                  mch_status,
                  mch_ar_ind,
                  mch_txn_code,
                  mch_process_type,
                  mch_process_code,
		  mch_host_posting_date,
		  mch_tm_date,
		  mch_tm_time,
                  mch_local_tm_date,
		  mch_local_tm_time,
		  mch_transmission_datetime,
		  mch_transaction_amount,
		  mch_transaction_ccy,
                  mch_create_timestamp,
                  mch_update_timestamp,
                  mch_create_user,
                  mch_update_user)
           values(
                in_txn_id,
                in_org_txn_id,
		in_server_ref,
                in_status,
                in_ar_ind,
                in_txn_code,
                in_process_type,
                in_process_code,
		in_host_posting_date,
		in_tm_date,
		in_tm_time,
                in_local_tm_date,
		in_local_tm_time,
		in_transmission_datetime,
		in_transaction_amount,
		in_transaction_ccy,
                sysdate,
                sysdate,
                in_create_user,
                in_update_user);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mmc_txn_header_insert;
/
