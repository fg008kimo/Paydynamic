CREATE OR REPLACE FUNCTION sp_txn_qr_request_log_insert(
	in_txn_id			txn_qr_request_log.tql_txn_id%type,
	in_expriy			txn_qr_request_log.tql_expiry%type,
	in_enable_button		txn_qr_request_log.tql_enable_button%type,
	in_auto_check_txn_status	txn_qr_request_log.tql_auto_check_txn_status%type,
	in_redirect			txn_qr_request_log.tql_redirect%type,
	in_create_user			txn_qr_request_log.tql_create_user%type
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO txn_qr_request_log(
	tql_txn_id,
	tql_qrcode_init_timestamp,
	tql_expiry,
	tql_enable_button,
	tql_auto_check_txn_status,
	tql_redirect,
	tql_create_user,
	tql_create_timestamp
	)

  VALUES(
	in_txn_id,
	sysdate,
	in_expriy,
	in_enable_button,
	in_auto_check_txn_status,
	in_redirect,
	in_create_user,
	sysdate
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_txn_qr_request_log_insert;
/


