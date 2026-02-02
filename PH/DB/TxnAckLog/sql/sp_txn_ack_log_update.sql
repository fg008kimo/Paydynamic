create or replace function sp_txn_ack_log_update(
       in_txn_id                                txn_ack_log.al_txn_id%type,
       in_org_txn_id                            txn_ack_log.al_org_txn_id%type,
       in_status				txn_ack_log.al_status%type,
       in_internal_code				txn_ack_log.al_internal_code%type,
       in_update_user                           txn_ack_log.al_update_user%type)
  RETURN NUMBER IS
begin

  update txn_ack_log
  set al_status = NVL(in_status, al_status),
      al_internal_code = NVL(in_internal_code, al_internal_code)
  where al_txn_id = in_txn_id
    and al_org_txn_id = in_org_txn_id
    and al_create_timestamp = (select max(al_create_timestamp)
			        from  txn_ack_log
                               where  al_txn_id = in_txn_id
                                 and  al_org_txn_id = in_org_txn_id
                              );

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_txn_ack_log_update;
/
