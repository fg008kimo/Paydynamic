CREATE OR REPLACE FUNCTION sp_deposit_request_log_update(
	in_request_log_id	deposit_request_log.request_log_id%type,
	in_process_code		deposit_request_log.process_code%type,
	in_process_type		deposit_request_log.process_type%type,
	in_pay_amt		deposit_request_log.pay_amt%type,
	in_currency		deposit_request_log.currency%type,
	in_reference		deposit_request_log.reference%type,
	in_request_time		deposit_request_log.request_time%type,
	in_merchant_id		deposit_request_log.merchant_id%type,
	in_country_id		deposit_request_log.country_id%type,
	in_channel_id		deposit_request_log.channel_id%type,
	in_bank_code		deposit_request_log.bank_code%type,
	in_show_paypage		deposit_request_log.show_paypage%type,
	in_language_id		deposit_request_log.language_id%type,
	in_success_url		deposit_request_log.success_url%type,
	in_failure_url		deposit_request_log.failure_url%type,
	in_succ_cb_url		deposit_request_log.success_callback_url%type,
	in_fail_cb_url		deposit_request_log.failure_callback_url%type,
	in_remark		deposit_request_log.remark%type,
	in_mac			deposit_request_log.mac%type,
	in_disabled		deposit_request_log.disabled%type)
  RETURN NUMBER IS

BEGIN
  UPDATE deposit_request_log
	SET	process_code=in_process_code,
		process_type=in_process_type,
		pay_amt=in_pay_amt,
		currency=in_currency,
		reference=in_reference,
		request_time=in_request_time,
		merchant_id=in_merchant_id,
		country_id=in_country_id,
		channel_id=in_channel_id,
		bank_code=in_bank_code,
		show_paypage=in_show_paypage,
		language_id=in_language_id,
		success_url=in_success_url,
		failure_url=in_failure_url,
		success_callback_url=in_succ_cb_url,
		failure_callback_url=in_fail_cb_url,
		remark=in_remark,
		mac=in_mac,
		update_date=sysdate,
		disabled=in_disabled

 	WHERE	request_log_id=in_request_log_id;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_deposit_request_log_update;
/
