CREATE OR REPLACE FUNCTION sp_mms_instant_pmacct_hd_ins(
	in_party_type		mms_instant_pm_acct_hd.mia_party_type%type,
	in_business_type        mms_instant_pm_acct_hd.mia_business_type%type,
	in_status		mms_instant_pm_acct_hd.mia_status%type,
	in_create_user		mms_instant_pm_acct_hd.mia_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO mms_instant_pm_acct_hd(
		mia_party_type,
		mia_business_type,
		mia_lastupdate_datetime,
		mia_status,
		mia_status_update_datetime,
		mia_create_user,
		mia_update_user,
		mia_create_timestamp,
		mia_update_timestamp
		)
	VALUES (	
		in_party_type,
		in_business_type,
		sysdate,
		in_status,
		sysdate,
		in_create_user,
		in_create_user,
		sysdate,
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

END sp_mms_instant_pmacct_hd_ins;
/
