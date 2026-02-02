create or replace function sp_ol_txn_ack_log_insert(
       in_txn_id                                ol_txn_ack_log.oal_txn_id%type,
       in_org_txn_id                            ol_txn_ack_log.oal_org_txn_id%type,
       in_status				ol_txn_ack_log.oal_status%type,
       in_update_user                           ol_txn_ack_log.oal_update_user%type)
  RETURN NUMBER IS
	iCnt    integer := 0;
begin

  insert into ol_txn_ack_log
              (oal_txn_id,
		oal_org_txn_id,
		oal_status,
		oal_create_user,
		oal_create_timestamp,
		oal_update_user,
		oal_update_timestamp)
         values(in_txn_id,
		in_org_txn_id,
		in_status,
                in_update_user,
                sysdate,
                in_update_user,
                sysdate);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_ol_txn_ack_log_insert;
/
