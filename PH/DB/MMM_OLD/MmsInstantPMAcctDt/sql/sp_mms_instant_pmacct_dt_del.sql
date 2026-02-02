CREATE OR REPLACE FUNCTION sp_mms_instant_pmacct_dt_del(
	in_party_type		mms_instant_pm_acct_dt.mid_party_type%type,
	in_business_type	mms_instant_pm_acct_dt.mid_business_type%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM mms_instant_pm_acct_dt
	WHERE	mid_party_type = in_party_type
	AND	mid_business_type = in_business_type;

--  IF SQL%ROWCOUNT = 0 THEN
--     RETURN 1;
--  ELSE
     RETURN 0;
--  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_mms_instant_pmacct_dt_del;
/
