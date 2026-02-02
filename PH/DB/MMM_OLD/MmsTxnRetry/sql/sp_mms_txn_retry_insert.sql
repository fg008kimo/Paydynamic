create or replace function sp_mms_txn_retry_insert(
     	in_txn_id				mms_txn_retry.mt_txn_id%type, 
     	in_process_type				mms_txn_retry.mt_process_type%type, 
     	in_process_code				mms_txn_retry.mt_process_code%type, 
	in_node_id				mms_txn_retry.mt_node_id%type,
	in_txn_amount				mms_txn_retry.mt_txn_amount%type,
	in_txn_ccy				mms_txn_retry.mt_txn_ccy%type,
       	in_psp_id	                        mms_txn_retry.mt_psp_id%type,
       	in_merchant_id                          mms_txn_retry.mt_merchant_id%type,
       	in_txn_datetime                       	mms_txn_retry.mt_txn_datetime%type,
       	in_status				mms_txn_retry.mt_status%type,
       	in_create_user                          mms_txn_retry.mt_create_user%type,
       	in_update_user                          mms_txn_retry.mt_update_user%type)
  RETURN NUMBER IS
begin

  update mms_txn_retry
     set mt_status = in_status,
         mt_resend_count = mt_resend_count + 1,
         mt_next_try =  sysdate + power(2,mt_resend_count)*5 /1440,
         mt_update_user = in_update_user,
         mt_update_timestamp = sysdate
   where mt_txn_id = in_txn_id;

  IF SQL%ROWCOUNT = 0 then
  insert into mms_txn_retry
              (mt_txn_id,
		mt_process_type,
		mt_process_code,
		mt_node_id,
		mt_txn_amount,
		mt_txn_ccy,
		mt_psp_id,
		mt_merchant_id,
		mt_txn_datetime,
		mt_status,
                mt_next_try,
		mt_create_user,
		mt_create_timestamp,
		mt_update_user,
		mt_update_timestamp)
         values(in_txn_id,
		in_process_type,
		in_process_code,
		in_node_id,
		in_txn_amount,
		in_txn_ccy,
		in_psp_id,
		in_merchant_id,
		in_txn_datetime,
		in_status,
		sysdate + 1 /1440,
                in_create_user,
                sysdate,
                in_update_user,
                sysdate);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;
else 
	return 0;
end if;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mms_txn_retry_insert;
/
