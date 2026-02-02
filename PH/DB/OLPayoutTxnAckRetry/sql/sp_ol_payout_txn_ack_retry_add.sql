create or replace function sp_ol_payout_txn_ack_retry_add(
       in_batch_txn_id                          ol_payout_txn_ack_retry.oar_batch_txn_id%type,
       in_txn_id                                ol_payout_txn_ack_retry.oar_txn_id%type,
       in_local_tm_date                        	ol_payout_txn_ack_retry.oar_local_tm_date%type,
       in_local_tm_time                        	ol_payout_txn_ack_retry.oar_local_tm_time%type,
       in_status				ol_payout_txn_ack_retry.oar_status%type,
       in_create_user                           ol_payout_txn_ack_retry.oar_create_user%type,
       in_update_user                           ol_payout_txn_ack_retry.oar_update_user%type)
  RETURN NUMBER IS
begin

  update ol_payout_txn_ack_retry
     set oar_status = in_status,
         oar_local_tm_date = in_local_tm_date,
	 oar_local_tm_time = in_local_tm_time,
         oar_resend_count = oar_resend_count + 1,
         oar_next_try =  sysdate + power(2,oar_resend_count)*5 /1440,
         oar_update_user = NVL(in_update_user, oar_update_user),
         oar_update_timestamp = sysdate
   where oar_batch_txn_id = in_batch_txn_id
     and oar_txn_id = in_txn_id ;

  IF SQL%ROWCOUNT = 0 then
  insert into ol_payout_txn_ack_retry
              (oar_batch_txn_id,
                oar_txn_id,
		oar_status,
		oar_local_tm_date,
		oar_local_tm_time,
                oar_next_try,
		oar_create_user,
		oar_create_timestamp,
		oar_update_user,
		oar_update_timestamp)
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
end sp_ol_payout_txn_ack_retry_add;
/
