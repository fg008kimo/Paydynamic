


CREATE OR REPLACE FUNCTION sp_ol_acct_ldgr_daily_rpt_ins (
	in_merchant_id  ol_acct_ledger_daily_report.oaldr_merchant_id%TYPE,
	in_ccy          ol_acct_ledger_daily_report.oaldr_currency_id%TYPE,
	in_country      ol_acct_ledger_daily_report.oaldr_country_id%TYPE,
	in_service_code ol_acct_ledger_daily_report.oaldr_service_code%TYPE,
	in_ledger_type  ol_acct_ledger_daily_report.oaldr_ledger_type%TYPE,
	in_disabled     ol_acct_ledger_daily_report.oaldr_disabled%TYPE,
	in_report_date  ol_acct_ledger_daily_report.oaldr_report_date%TYPE,
	in_filename     ol_acct_ledger_daily_report.oaldr_filename%TYPE,
	in_status       ol_acct_ledger_daily_report.oaldr_status%TYPE,
	in_create_user  ol_acct_ledger_daily_report.oaldr_create_user%TYPE)
RETURN NUMBER
IS
BEGIN

 	INSERT INTO ol_acct_ledger_daily_report (
		oaldr_merchant_id,
		oaldr_currency_id,
		oaldr_country_id,
		oaldr_service_code,
		oaldr_ledger_type,
		oaldr_report_date,
		oaldr_filename,
		oaldr_status,
		oaldr_disabled,
		oaldr_create_timestamp,
		oaldr_create_user,
		oaldr_update_timestamp,
		oaldr_update_user)
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
END sp_ol_acct_ldgr_daily_rpt_ins;
/

