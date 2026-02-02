


CREATE OR REPLACE FUNCTION sp_ol_pregen_daily_report_ins (
	in_report_code  ol_pregen_daily_report.opdr_report_code%TYPE,
	in_merchant_id  ol_pregen_daily_report.opdr_merchant_id%TYPE,
	in_country      ol_pregen_daily_report.opdr_country_id%TYPE,
	in_ccy          ol_pregen_daily_report.opdr_currency_id%TYPE,
	in_service_code ol_pregen_daily_report.opdr_service_code%TYPE,
	in_report_date  ol_pregen_daily_report.opdr_report_date%TYPE,
	in_filename     ol_pregen_daily_report.opdr_filename%TYPE,
	in_status       ol_pregen_daily_report.opdr_status%TYPE,
	in_disabled     ol_pregen_daily_report.opdr_disabled%TYPE,
	in_create_user  ol_pregen_daily_report.opdr_create_user%TYPE)
RETURN NUMBER
IS
BEGIN

 	INSERT INTO ol_pregen_daily_report (
		opdr_id,
		opdr_report_code,
		opdr_merchant_id,
		opdr_country_id,
		opdr_currency_id,
		opdr_service_code,
		opdr_report_date,
		opdr_filename,
		opdr_status,
		opdr_disabled,
		opdr_create_timestamp,
		opdr_create_user,
		opdr_update_timestamp,
		opdr_update_user)
	VALUES ((select NVL(max(opdr_id),0)+1 from ol_pregen_daily_report),
		in_report_code,
		in_merchant_id,
		in_country,
		in_ccy,
		in_service_code,
		in_report_date,
		in_filename,
		in_status,
		in_disabled,
		SYSDATE,
		in_create_user,
		SYSDATE,
		in_create_user);

   	IF SQL%ROWCOUNT = 0 THEN
   		RETURN 1;
	ELSE
   		RETURN 0;
    END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_ol_pregen_daily_report_ins;
/
