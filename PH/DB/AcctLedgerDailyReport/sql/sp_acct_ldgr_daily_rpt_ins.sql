


CREATE OR REPLACE FUNCTION sp_acct_ldgr_daily_rpt_ins (
	in_merchant_id  acct_ledger_daily_report.aldr_merchant_id%TYPE,
	in_ccy          acct_ledger_daily_report.aldr_currency_id%TYPE,
	in_country      acct_ledger_daily_report.aldr_country_id%TYPE,
	in_service_code acct_ledger_daily_report.aldr_service_code%TYPE,
	in_ledger_type  acct_ledger_daily_report.aldr_ledger_type%TYPE,
	in_disabled     acct_ledger_daily_report.aldr_disabled%TYPE,
	in_report_date  acct_ledger_daily_report.aldr_report_date%TYPE,
	in_filename     acct_ledger_daily_report.aldr_filename%TYPE,
	in_status       acct_ledger_daily_report.aldr_status%TYPE,
	in_create_user  acct_ledger_daily_report.aldr_create_user%TYPE)
RETURN NUMBER
IS
BEGIN

 	INSERT INTO acct_ledger_daily_report (
		aldr_merchant_id,
		aldr_currency_id,
		aldr_country_id,
		aldr_service_code,
		aldr_ledger_type,
		aldr_report_date,
		aldr_filename,
		aldr_status,
		aldr_disabled,
		aldr_create_timestamp,
		aldr_create_user,
		aldr_update_timestamp,
		aldr_update_user)
	VALUES (in_merchant_id,
		in_ccy,
		in_country,
		in_service_code,
		in_ledger_type,
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
END sp_acct_ldgr_daily_rpt_ins;
/

