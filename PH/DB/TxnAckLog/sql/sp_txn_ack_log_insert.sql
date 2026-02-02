create or replace function sp_txn_ack_log_insert(
       in_txn_id                                txn_ack_log.al_txn_id%type,
       in_org_txn_id                            txn_ack_log.al_org_txn_id%type,
       in_status				txn_ack_log.al_status%type,
       in_update_user                           txn_ack_log.al_update_user%type)
  RETURN NUMBER IS
	iCnt    integer := 0;
begin

  insert into txn_ack_log
              (al_txn_id,
		al_org_txn_id,
		al_status,
		al_create_user,
		al_create_timestamp,
		al_update_user,
		al_update_timestamp)
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
end sp_txn_ack_log_insert;
/
