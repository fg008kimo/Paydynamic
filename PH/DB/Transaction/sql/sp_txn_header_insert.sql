create or replace function sp_txn_header_insert(
       in_txn_id                                txn_header.th_txn_id%type,
       in_org_txn_id                          	txn_header.th_org_txn_id%type,
       in_input_channel                      	txn_header.th_input_channel%type,
       in_status                                txn_header.th_status%type,
       in_ar_ind                                txn_header.th_ar_ind%type,
       in_sub_status                            txn_header.th_sub_status%type,
       in_txn_code                             	txn_header.th_txn_code%type,
       in_process_type                         	txn_header.th_process_type%type,
       in_process_code                         	txn_header.th_process_code%type,
       in_merchant_id                           txn_header.th_merchant_id%type,
       in_merchant_ref				txn_header.th_merchant_ref%type,
       in_client_id                             txn_header.th_client_id%type,
       in_host_posting_date                     txn_header.th_host_posting_date%type,
       in_transmission_datetime                 txn_header.th_transmission_datetime%type,
       in_internal_code                         txn_header.th_internal_code%type,
       in_response_code                         txn_header.th_response_code%type,
       in_transaction_amt                       txn_header.th_transaction_amount%type,
       in_net_amt                               txn_header.th_net_amount%type,
       in_net_ccy			        txn_header.th_net_ccy%type,
       in_tm_date                               txn_header.th_tm_date%type,
       in_tm_time                               txn_header.th_tm_time%type,
       in_local_tm_date                         txn_header.th_local_tm_date%type,
       in_local_tm_time                         txn_header.th_local_tm_time%type,
       in_create_user                           txn_header.th_create_user%type,
       in_update_user                           txn_header.th_update_user%type,
       in_client_ip				txn_header.th_client_ip%type,
       in_service_code				txn_header.th_service_code%type,
       in_approval_date				txn_header.th_approval_date%type)

  RETURN NUMBER IS
begin

  insert into txn_header
              (th_txn_id,
                th_org_txn_id,
                th_input_channel,
                th_status,
                th_ar_ind,
                th_sub_status,
                th_txn_code,
		th_process_type,
		th_process_code,
                th_merchant_id,
		th_merchant_ref,
                th_client_id,
                th_host_posting_date,
                th_transmission_datetime,
                th_internal_code,
                th_response_code,
                th_transaction_amount,
                th_net_amount,
		th_net_ccy,
                th_tm_date,
                th_tm_time,
                th_local_tm_date,
                th_local_tm_time,
                th_create_user,
                th_create_timestamp,
                th_update_user,
                th_update_timestamp,
		th_client_ip,
		th_service_code,
		th_approval_date)
         values(in_txn_id,
                in_org_txn_id,
                in_input_channel,
                in_status,
                in_ar_ind,
                in_sub_status,
                in_txn_code,
		in_process_type,
		in_process_code,
                in_merchant_id,
		in_merchant_ref,
                in_client_id,
                in_host_posting_date,
                in_transmission_datetime,
                in_internal_code,
                in_response_code,
                in_transaction_amt,
                in_net_amt,
		in_net_ccy,
                in_tm_date,
                in_tm_time,
                in_local_tm_date,
                in_local_tm_time,
                in_create_user,
                sysdate,
                in_update_user,
                sysdate,
		in_client_ip,
		in_service_code,
		in_approval_date);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_txn_header_insert;
/
