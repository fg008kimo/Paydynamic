CREATE OR REPLACE FUNCTION sp_maq_insert(
	in_approve_id		merchant_approve_queue_hd.qh_approve_id%type,
	in_posting_date		merchant_approve_queue_hd.qh_posting_date%type,
	in_merchant_id		merchant_approve_queue_hd.qh_merchant_id%type,
	in_client_id		merchant_approve_queue_hd.qh_client_id%type,
	in_service_code		merchant_approve_queue_hd.qh_service_code%type,
	in_country		merchant_approve_queue_hd.qh_country%type,
	in_currency		merchant_approve_queue_hd.qh_currency%type,
	in_txn_count		merchant_approve_queue_hd.qh_total_count%type,
	in_txn_amt		merchant_approve_queue_hd.qh_total_req_amt%type,
	in_status		merchant_approve_queue_hd.qh_status%type,
	in_add_user		merchant_approve_queue_hd.qh_create_user%type
)
  RETURN NUMBER IS

BEGIN
  INSERT INTO merchant_approve_queue_hd(
	qh_approve_id,
	qh_posting_date,
	qh_merchant_id,
	qh_client_id,
	qh_service_code,
	qh_country,
	qh_currency,
	qh_total_count,
	qh_total_req_amt,
	qh_status,
	qh_create_timestamp,
        qh_update_timestamp,
        qh_create_user,
        qh_update_user
	)

  VALUES(
	in_approve_id,
	in_posting_date,
	in_merchant_id,
	in_client_id,
	in_service_code,
	in_country,
	in_currency,
	in_txn_count,
	in_txn_amt,
	in_status,
	sysdate,
        sysdate,
        in_add_user,
        in_add_user
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_maq_insert;
/
