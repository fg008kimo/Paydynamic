CREATE OR REPLACE FUNCTION sp_mms_instant_pmacct_dt_ins(
	in_party_type		mms_instant_pm_acct_dt.mid_party_type%type,
	in_business_type        mms_instant_pm_acct_dt.mid_business_type%type,
	in_party_id		mms_instant_pm_acct_dt.mid_party_id%type,
	in_party_name		mms_instant_pm_acct_dt.mid_party_name%type,
	in_mms_node_id		mms_instant_pm_acct_dt.mid_mms_node_id%type,
	in_create_user		mms_instant_pm_acct_dt.mid_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO mms_instant_pm_acct_dt(
		mid_party_type,
		mid_business_type,
		mid_party_id,
		mid_party_name,
		mid_mms_node_id,
		mid_create_user,
		mid_update_user,
		mid_create_timestamp,
		mid_update_timestamp
		)
	VALUES (	
		in_party_type,
		in_business_type,
		in_party_id,
		in_party_name,
		in_mms_node_id,
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

END sp_mms_instant_pmacct_dt_ins;
/
