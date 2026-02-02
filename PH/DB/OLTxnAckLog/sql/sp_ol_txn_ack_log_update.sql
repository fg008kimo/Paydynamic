create or replace function sp_ol_txn_ack_log_update(
       in_txn_id                                ol_txn_ack_log.oal_txn_id%type,
       in_org_txn_id                            ol_txn_ack_log.oal_org_txn_id%type,
       in_status				ol_txn_ack_log.oal_status%type,
       in_internal_code				ol_txn_ack_log.oal_internal_code%type,
       in_update_user                           ol_txn_ack_log.oal_update_user%type)
  RETURN NUMBER IS
begin

  update ol_txn_ack_log
  set oal_status = NVL(in_status, oal_status),
      oal_internal_code = NVL(in_internal_code, oal_internal_code)
  where oal_txn_id = in_txn_id
    and oal_org_txn_id = in_org_txn_id
    and oal_create_timestamp = (select max(oal_create_timestamp)
			        from  ol_txn_ack_log
                               where  oal_txn_id = in_txn_id
                                 and  oal_org_txn_id = in_org_txn_id
                              );

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_ol_txn_ack_log_update;
/
