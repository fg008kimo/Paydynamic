create or replace function sp_mms_txn_header_insert(
        in_txn_id                             mms_txn_header.th_txn_id%type,
        in_org_txn_id                         mms_txn_header.th_org_txn_id%type,
        in_client_txn_id                      mms_txn_header.th_client_txn_id%type,
        in_input_channel                      mms_txn_header.th_input_channel%type,
        in_mmc_node_id                        mms_txn_header.th_mmc_node_id%type,
        in_service_code                       mms_txn_header.th_service_code%type,
        in_status                             mms_txn_header.th_status%type,
        in_ar_ind                             mms_txn_header.th_ar_ind%type,
        in_txn_code                           mms_txn_header.th_txn_code%type,
        in_process_type                       mms_txn_header.th_process_type%type,
        in_process_code                       mms_txn_header.th_process_code%type,
        in_client_id                          mms_txn_header.th_client_id%type,
        in_merchant_id                        mms_txn_header.th_merchant_id%type,
        in_psp_id                             mms_txn_header.th_psp_id%type,
        in_transmission_datetime              mms_txn_header.th_transmission_datetime%type,
        in_posting_datetime                   mms_txn_header.th_posting_datetime%type,
        in_internal_code                      mms_txn_header.th_internal_code%type,    
        in_response_code                      mms_txn_header.th_response_code%type,
        in_transaction_amount                 mms_txn_header.th_transaction_amount%type,
        in_net_amount                         mms_txn_header.th_net_amount%type,
        in_net_cyy                            mms_txn_header.th_net_ccy%type,
        in_create_user                        mms_txn_header.th_create_user%type,
        in_update_user                        mms_txn_header.th_update_user%type
        )
  RETURN NUMBER IS
begin

  insert into mms_txn_header (
                  th_txn_id,
                  th_org_txn_id,
                  th_client_txn_id,
                  th_input_channel,
                  th_mmc_node_id,
                  th_service_code,
                  th_status,
                  th_ar_ind,
                  th_txn_code,
                  th_process_type,
                  th_process_code,
                  th_client_id,
                  th_merchant_id,
                  th_psp_id,
                  th_transmission_datetime,
                  th_posting_datetime,
                  th_internal_code,    
                  th_response_code,
                  th_transaction_amount,
                  th_net_amount,
                  th_net_ccy,
                  th_create_timestamp,
                  th_update_timestamp,
                  th_create_user,
                  th_update_user)
           values(
                in_txn_id,
                in_org_txn_id,
                in_client_txn_id,
                in_input_channel,
                in_mmc_node_id,
                in_service_code,
                in_status,
                in_ar_ind,
                in_txn_code,
                in_process_type,
                in_process_code,
                in_client_id,
                in_merchant_id,
                in_psp_id,
                in_transmission_datetime,
                in_posting_datetime,
                in_internal_code,
                in_response_code,
                in_transaction_amount,
                in_net_amount,
                in_net_cyy,
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
