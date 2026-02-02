CREATE OR REPLACE FUNCTION sp_txn_alert_log_updatets(
        in_report_type                  txn_alert_log.tal_report_type%type,
        in_txn_id                       txn_alert_log.tal_txn_id%type,
        in_update_user                  txn_alert_log.tal_update_user%type)
  RETURN NUMBER IS

BEGIN

  UPDATE txn_alert_log
     SET tal_send_alert_timestamp = sysdate,
         tal_alert_sent = 1,
         tal_update_user = in_update_user,
         tal_update_timestamp = sysdate
   WHERE tal_report_type = in_report_type
     AND tal_txn_id = in_txn_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_txn_alert_log_updatets;
/
