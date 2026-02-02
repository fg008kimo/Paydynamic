create or replace function sp_txn_alert_log_insert(	
	in_report_type           	txn_alert_log.tal_report_type%type,
       	in_txn_id			txn_alert_log.tal_txn_id%type,
	in_alert_sent        		txn_alert_log.tal_alert_sent%type,
	in_create_user          	txn_alert_log.tal_create_user%type)

  RETURN NUMBER IS
begin

  insert into txn_alert_log (
		tal_report_type,
		tal_txn_id,
		tal_alert_sent,
		tal_create_timestamp,
                tal_create_user,
                tal_update_timestamp,
                tal_update_user
		)
         values (
		in_report_type,
		in_txn_id,
		in_alert_sent,
		sysdate,
                in_create_user,
                sysdate,
                in_create_user
		);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end  sp_txn_alert_log_insert;
/
