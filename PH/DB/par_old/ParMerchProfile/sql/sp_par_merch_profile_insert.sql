CREATE OR REPLACE FUNCTION sp_par_merch_profile_insert(
	in_merch_account_nmb	par_merch_profile.pmp_merch_account_nmb%type,
	in_company_name         par_merch_profile.pmp_company_name%type,
	in_username		par_merch_profile.pmp_username%type,
	in_api_merch_id		par_merch_profile.pmp_api_merch_id%type,
	in_ack_url		par_merch_profile.pmp_ack_url%type,
	in_payout_enable        par_merch_profile.pmp_payout_enable%type,
	in_service		par_merch_profile.pmp_service%type,
	in_merchant_id		par_merch_profile.pmp_ph_merch_id%type,
	in_create_user		par_merch_profile.pmp_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO par_merch_profile(
	pmp_merch_account_nmb,
	pmp_company_name,
	pmp_username,
	pmp_api_merch_id,
	pmp_ack_url,
	pmp_payout_enable,
	pmp_service,
	pmp_ph_merch_id,
	pmp_create_timestamp,
	pmp_create_user,
	pmp_update_timestamp,
	pmp_update_user
	)
  VALUES(
	in_merch_account_nmb,
	in_company_name,
	in_username,
	in_api_merch_id,
	in_ack_url,
	in_payout_enable,
	in_service,
	in_merchant_id,
	sysdate,
	in_create_user,
	sysdate,
	in_create_user
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_par_merch_profile_insert;
/

