CREATE OR REPLACE FUNCTION sp_deposit_response_log_update(
	in_response_log_id      deposit_response_log.response_log_id%type,
        in_request_log_id       deposit_response_log.request_log_id%type,
        in_process_code         deposit_response_log.process_code%type,
        in_process_type         deposit_response_log.process_type%type,
        in_txn_status_id        deposit_response_log.txn_status_id%type,
        in_txn_id               deposit_response_log.txn_id%type,
        in_pay_amt              deposit_response_log.pay_amt%type,
        in_currency             deposit_response_log.currency%type,
        in_reference            deposit_response_log.reference%type,
        in_request_time         deposit_response_log.request_time%type,
        in_merchant_id          deposit_response_log.merchant_id%type,
        in_response_time        deposit_response_log.response_time%type,
        in_post_date            deposit_response_log.post_date%type,
        in_country_id           deposit_response_log.country_id%type,
        in_channel_id           deposit_response_log.channel_id%type,
        in_bank_code            deposit_response_log.bank_code%type,
        in_service_fee          deposit_response_log.service_fee%type,
        in_service_curr         deposit_response_log.service_currency%type,
        in_remark               deposit_response_log.remark%type,
        in_checksum             deposit_response_log.checksum%type,
        in_algorithm            deposit_response_log.algorithm%type,
        in_disabled             deposit_response_log.disabled%type)

RETURN NUMBER IS

BEGIN
  UPDATE deposit_response_log
	SET	request_log_id=in_request_log_id,
		process_code=in_process_code,
		process_type=in_process_type,
		txn_status_id=in_txn_status_id,
		txn_id=in_txn_id,
		pay_amt=in_pay_amt,
		currency=in_currency,
		reference=in_reference,
		request_time=in_request_time,
		merchant_id=in_merchant_id,
		response_time=in_response_time,
		post_date=in_post_date,
		country_id=in_country_id,
		channel_id=in_channel_id,
		bank_code=in_bank_code,
		service_fee=in_service_fee,
		service_currency=in_service_curr,
		remark=in_remark,
		checksum=in_checksum,
		algorithm=in_algorithm,
		update_date=sysdate,
		disabled=in_disabled

 	WHERE	response_log_id=in_response_log_id;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_deposit_response_log_update;
/
