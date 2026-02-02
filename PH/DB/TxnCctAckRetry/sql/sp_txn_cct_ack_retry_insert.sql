create or replace function sp_txn_cct_ack_retry_insert(
       in_merchant_id                           txn_cct_ack_retry.ta_merchant_id%type,
       in_merchant_ref                          txn_cct_ack_retry.ta_merchant_ref%type,
       in_local_tm_date                        	txn_cct_ack_retry.ta_local_tm_date%type,
       in_local_tm_time                        	txn_cct_ack_retry.ta_local_tm_time%type,
       in_status				txn_cct_ack_retry.ta_status%type,
       in_create_user                           txn_cct_ack_retry.ta_create_user%type,
       in_update_user                           txn_cct_ack_retry.ta_update_user%type)
  RETURN NUMBER IS
begin

  update txn_cct_ack_retry
     set ta_status = in_status,
         ta_local_tm_date = in_local_tm_date,
	 ta_local_tm_time = in_local_tm_time,
         ta_resend_count = ta_resend_count + 1,
         ta_next_try =  sysdate + power(2,ta_resend_count)*5 /1440,
         ta_update_user = in_update_user,
         ta_update_timestamp = sysdate
   where ta_merchant_id = in_merchant_id
     and ta_merchant_ref = in_merchant_ref;

  IF SQL%ROWCOUNT = 0 then
  insert into txn_cct_ack_retry
              (ta_merchant_id,
		ta_merchant_ref,
		ta_status,
		ta_local_tm_date,
		ta_local_tm_time,
                ta_next_try,
		ta_create_user,
		ta_create_timestamp,
		ta_update_user,
		ta_update_timestamp)
         values(in_merchant_id,
		in_merchant_ref,
		in_status,
		in_local_tm_date,
		in_local_tm_time,
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
end sp_txn_cct_ack_retry_insert;
/
