create or replace function sp_ol_txn_ack_retry_insert(
       in_batch_txn_id                          ol_txn_ack_retry.ota_batch_txn_id%type,
       in_txn_id                                ol_txn_ack_retry.ota_txn_id%type,
       in_local_tm_date                        	ol_txn_ack_retry.ota_local_tm_date%type,
       in_local_tm_time                        	ol_txn_ack_retry.ota_local_tm_time%type,
       in_status				ol_txn_ack_retry.ota_status%type,
       in_create_user                           ol_txn_ack_retry.ota_create_user%type,
       in_update_user                           ol_txn_ack_retry.ota_update_user%type)
  RETURN NUMBER IS
begin

  update ol_txn_ack_retry
     set ota_status = in_status,
         ota_local_tm_date = in_local_tm_date,
	 ota_local_tm_time = in_local_tm_time,
         ota_resend_count = ota_resend_count + 1,
         ota_next_try =  sysdate + power(2,ota_resend_count)*5 /1440,
         ota_update_user = NVL(in_update_user, ota_update_user),
         ota_update_timestamp = sysdate
   where ota_batch_txn_id = in_batch_txn_id
     and ota_txn_id = in_txn_id ;

  IF SQL%ROWCOUNT = 0 then
  insert into ol_txn_ack_retry
              (ota_batch_txn_id,
                ota_txn_id,
		ota_status,
		ota_local_tm_date,
		ota_local_tm_time,
                ota_next_try,
		ota_create_user,
		ota_create_timestamp,
		ota_update_user,
		ota_update_timestamp)
         values(in_batch_txn_id,
         	in_txn_id,
		in_status,
		in_local_tm_date,
		in_local_tm_time,
		sysdate + 1 /1440,
                NVL(in_create_user, 'SYSTEM'),
                sysdate,
                NVL(in_update_user, 'SYSTEM'),
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
end sp_ol_txn_ack_retry_insert;
/
