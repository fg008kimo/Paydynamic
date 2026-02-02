create or replace function sp_mms_txn_header_insert(
        in_txn_id                             mms_txn_header.mth_txn_id%type,
        in_org_txn_id                         mms_txn_header.mth_org_txn_id%type,
	in_next_txn_id			      mms_txn_header.mth_next_txn_id%type,
	in_service_code			      mms_txn_header.mth_service_code%type,
	in_mmc_node_id			      mms_txn_header.mth_mmc_node_id%type,
	in_client_ref			      mms_txn_header.mth_client_ref%type,
        in_status                             mms_txn_header.mth_status%type,
        in_ar_ind                             mms_txn_header.mth_ar_ind%type,
        in_txn_code                           mms_txn_header.mth_txn_code%type,
        in_process_type                       mms_txn_header.mth_process_type%type,
        in_process_code                       mms_txn_header.mth_process_code%type,
	in_host_posting_date		      mms_txn_header.mth_host_posting_date%type,
	in_tm_date			      mms_txn_header.mth_tm_date%type,
	in_tm_time			      mms_txn_header.mth_tm_time%type,
	in_local_tm_date		      mms_txn_header.mth_local_tm_date%type,
	in_local_tm_time		      mms_txn_header.mth_local_tm_time%type,
	in_transmission_datetime	      mms_txn_header.mth_transmission_datetime%type,
	in_transaction_amount	      	      mms_txn_header.mth_transaction_amount%type,
	in_transaction_ccy	      	      mms_txn_header.mth_transaction_ccy%type,
        in_create_user                        mms_txn_header.mth_create_user%type,
        in_update_user                        mms_txn_header.mth_update_user%type
        )
  RETURN NUMBER IS
begin

  insert into mms_txn_header (
                  mth_txn_id,
                  mth_org_txn_id,
		  mth_next_txn_id,
		  mth_service_code,
		  mth_mmc_node_id,
		  mth_client_ref,
                  mth_status,
                  mth_ar_ind,
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
		  mth_transaction_ccy,
                  mth_create_timestamp,
                  mth_update_timestamp,
                  mth_create_user,
                  mth_update_user)
           values(
                in_txn_id,
                in_org_txn_id,
		in_next_txn_id,
		in_service_code,
		in_mmc_node_id,
		in_client_ref,
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
end sp_mms_txn_header_insert;
/
