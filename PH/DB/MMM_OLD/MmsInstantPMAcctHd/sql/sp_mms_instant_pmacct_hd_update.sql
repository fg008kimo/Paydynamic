CREATE OR REPLACE FUNCTION sp_mms_instant_pmacct_hd_upd(
	in_party_type		mms_instant_pm_acct_hd.mia_party_type%type,
	--in_lastupdate_datetime  varchar2, --mms_instant_pm_acct_hd.mia_lastupdate_datetime%type,
	in_business_type        mms_instant_pm_acct_hd.mia_business_type%type,
	in_status		mms_instant_pm_acct_hd.mia_status%type,
	in_update_user          mms_instant_pm_acct_hd.mia_update_user%type)
  RETURN NUMBEr IS
BEGIN

	UPDATE	mms_instant_pm_acct_hd
	   SET	mia_lastupdate_datetime = sysdate, --to_date(in_lastupdate_datetime, 'YYYYMMDDHH24MISS'),
		mia_status = in_status,
		mia_update_user = in_update_user,
		mia_status_update_datetime = sysdate,
		mia_update_timestamp = sysdate
	 WHERE  mia_party_type = in_party_type
	   AND  mia_business_type = in_business_type;
	

	IF SQL%ROWCOUNT = 0 THEN
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
					sysdate, --to_date(in_lastupdate_datetime, 'YYYYMMDDHH24MISS'),
					in_status,
					sysdate,
					in_update_user,
					in_update_user,
					sysdate,
					sysdate
					);
		IF SQL%ROWCOUNT = 0 THEN
			RETURN 1;
		ELSE
			RETURN 0;
		END IF;
	ELSE
		RETURN 0;

	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_mms_instant_pmacct_hd_upd;
/
