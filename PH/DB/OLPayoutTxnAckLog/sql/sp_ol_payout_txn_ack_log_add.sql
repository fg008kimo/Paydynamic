create or replace function sp_ol_payout_txn_ack_log_add(
       in_txn_id                                ol_payout_txn_ack_log.oaa_txn_id%type,
       in_org_txn_id                            ol_payout_txn_ack_log.oaa_org_txn_id%type,
       in_status				ol_payout_txn_ack_log.oaa_status%type,
       in_update_user                           ol_payout_txn_ack_log.oaa_update_user%type)
  RETURN NUMBER IS
	iCnt    integer := 0;
begin

  insert into ol_payout_txn_ack_log
              ( oaa_txn_id,
		oaa_org_txn_id,
		oaa_status,
		oaa_create_user,
		oaa_create_timestamp,
		oaa_update_user,
		oaa_update_timestamp)
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
end sp_ol_payout_txn_ack_log_add;
/
