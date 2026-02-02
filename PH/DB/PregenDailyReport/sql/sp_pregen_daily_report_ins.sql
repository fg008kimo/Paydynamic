


CREATE OR REPLACE FUNCTION sp_pregen_daily_report_ins (
	in_report_code  pregen_daily_report.pdr_report_code%TYPE,
	in_merchant_id  pregen_daily_report.pdr_merchant_id%TYPE,
	in_country      pregen_daily_report.pdr_country_id%TYPE,
	in_ccy          pregen_daily_report.pdr_currency_id%TYPE,
	in_service_code pregen_daily_report.pdr_service_code%TYPE,
	in_report_date  pregen_daily_report.pdr_report_date%TYPE,
	in_filename     pregen_daily_report.pdr_filename%TYPE,
	in_status       pregen_daily_report.pdr_status%TYPE,
	in_disabled     pregen_daily_report.pdr_disabled%TYPE,
	in_create_user  pregen_daily_report.pdr_create_user%TYPE)
RETURN NUMBER
IS
BEGIN

 	INSERT INTO pregen_daily_report (
		pdr_id,
		pdr_report_code,
		pdr_merchant_id,
		pdr_country_id,
		pdr_currency_id,
		pdr_service_code,
		pdr_report_date,
		pdr_filename,
		pdr_status,
		pdr_disabled,
		pdr_create_timestamp,
		pdr_create_user,
		pdr_update_timestamp,
		pdr_update_user)
	VALUES ((select NVL(max(pdr_id),0)+1 from pregen_daily_report),
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
END sp_pregen_daily_report_ins;
/

