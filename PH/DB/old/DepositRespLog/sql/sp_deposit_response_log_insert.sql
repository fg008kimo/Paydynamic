CREATE OR REPLACE FUNCTION sp_deposit_response_log_insert(
	in_response_log_id	deposit_response_log.response_log_id%type,
	in_request_log_id	deposit_response_log.request_log_id%type,
	in_process_code		deposit_response_log.process_code%type,
	in_process_type		deposit_response_log.process_type%type,
	in_txn_status_id	deposit_response_log.txn_status_id%type,
	in_txn_id		deposit_response_log.txn_id%type,
	in_pay_amt		deposit_response_log.pay_amt%type,
	in_currency		deposit_response_log.currency%type,
	in_reference		deposit_response_log.reference%type,
	in_request_time		deposit_response_log.request_time%type,
	in_merchant_id		deposit_response_log.merchant_id%type,
	in_response_time	deposit_response_log.response_time%type,
	in_post_date		deposit_response_log.post_date%type,
	in_country_id		deposit_response_log.country_id%type,
	in_channel_id		deposit_response_log.channel_id%type,
	in_bank_code		deposit_response_log.bank_code%type,
	in_service_fee		deposit_response_log.service_fee%type,
	in_service_curr		deposit_response_log.service_currency%type,
	in_remark		deposit_response_log.remark%type,
	in_checksum		deposit_response_log.checksum%type,
	in_algorithm		deposit_response_log.algorithm%type,
	in_disabled		deposit_response_log.disabled%type,
	in_created_by		deposit_response_log.created_by%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO deposit_response_log(
	response_log_id,
	request_log_id,
	process_code,
	process_type,
	txn_status_id,
	txn_id,
	pay_amt,
	currency,
	reference,
	request_time,
	merchant_id,
	response_time,
	post_date,
	country_id,
	channel_id,
	bank_code,
	service_fee,
	service_currency,
	remark,
	checksum,
	algorithm,
	create_date,
	update_date,
	disabled,
	created_by
	)

  VALUES(
	in_response_log_id,
	in_request_log_id,
	in_process_code,
	in_process_type,
	in_txn_status_id,
	in_txn_id,
	in_pay_amt,
	in_currency,
	in_reference,
	in_request_time,
	in_merchant_id,
	in_response_time,
	in_post_date,
	in_country_id,
	in_channel_id,
	in_bank_code,
	in_service_fee,
	in_service_curr,
	in_remark,
	in_checksum,
	in_algorithm,
	sysdate,
	sysdate,
	in_disabled,
	in_created_by
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_deposit_response_log_insert;
/
