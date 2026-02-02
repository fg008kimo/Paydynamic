create or replace function sp_mms_reverse_retry(
       in_txn_id                          mms_reverse_retry.mv_txn_id%type,
       in_dtl_txn_id                                mms_reverse_retry.mv_dtl_txn_id%type,
       in_local_tm_date                        	mms_reverse_retry.mv_local_tm_date%type,
       in_local_tm_time                        	mms_reverse_retry.mv_local_tm_time%type,
       in_status				mms_reverse_retry.mv_status%type,
       in_create_user                           mms_reverse_retry.mv_create_user%type,
       in_update_user                           mms_reverse_retry.mv_update_user%type)
  RETURN NUMBER IS
begin

  update mms_reverse_retry
     set mv_status = in_status,
         mv_local_tm_date = in_local_tm_date,
	 mv_local_tm_time = in_local_tm_time,
         mv_resend_count = mv_resend_count + 1,
         mv_next_try =  sysdate + power(2,mv_resend_count)*5 /1440,
         mv_update_user = NVL(in_update_user, mv_update_user),
         mv_update_timestamp = sysdate
   where mv_txn_id = in_txn_id
     and mv_dtl_txn_id = in_dtl_txn_id ;

  IF SQL%ROWCOUNT = 0 then
  insert into mms_reverse_retry
              (mv_txn_id,
                mv_dtl_txn_id,
		mv_status,
		mv_local_tm_date,
		mv_local_tm_time,
                mv_next_try,
		mv_create_user,
		mv_create_timestamp,
		mv_update_user,
		mv_update_timestamp)
         values(in_txn_id,
         	in_dtl_txn_id,
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
end sp_mms_reverse_retry;
/
