create or replace function sp_ol_payout_txn_ack_log_upd(
       in_txn_id                                ol_payout_txn_ack_log.oaa_txn_id%type,
       in_org_txn_id                            ol_payout_txn_ack_log.oaa_org_txn_id%type,
       in_status				ol_payout_txn_ack_log.oaa_status%type,
       in_internal_code				ol_payout_txn_ack_log.oaa_internal_code%type,
       in_update_user                           ol_payout_txn_ack_log.oaa_update_user%type)
  RETURN NUMBER IS
begin

  update ol_payout_txn_ack_log
  set oaa_status = NVL(in_status, oaa_status),
      oaa_internal_code = NVL(in_internal_code, oaa_internal_code)
  where oaa_txn_id = in_txn_id
    and oaa_org_txn_id = in_org_txn_id
    and oaa_create_timestamp = (select max(oaa_create_timestamp)
			        from  ol_payout_txn_ack_log
                               where  oaa_txn_id = in_txn_id
                                 and  oaa_org_txn_id = in_org_txn_id
                              );

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_ol_payout_txn_ack_log_upd;
/
