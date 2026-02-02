CREATE OR REPLACE FUNCTION sp_entity_fx_bal_hist_insert (
	in_fx_id		mms_entity_fx_bal_history.mbh_fx_id%TYPE,
	in_fx_seq		mms_entity_fx_bal_history.mbh_fx_seq%TYPE,
	in_funds_direction	mms_entity_fx_bal_history.mbh_funds_direction%TYPE,
	in_entity_id		mms_entity_fx_bal_history.mbh_entity_id%TYPE,
	in_org_ccy		mms_entity_fx_bal_history.mbh_org_ccy%TYPE,
	in_ccy			mms_entity_fx_bal_history.mbh_ccy%TYPE,
	in_acr_ind		mms_entity_fx_bal_history.mbh_acr_ind%TYPE,
	in_old_bal		mms_entity_fx_bal_history.mbh_old_bal%TYPE,
	in_new_bal		mms_entity_fx_bal_history.mbh_new_bal%TYPE,
	in_old_rate		mms_entity_fx_bal_history.mbh_old_rate%TYPE,
	in_new_rate		mms_entity_fx_bal_history.mbh_new_rate%TYPE,
	in_user			mms_entity_fx_bal_history.mbh_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO MMS_ENTITY_FX_BAL_HISTORY (
	mbh_fx_id,
	mbh_fx_seq,
	mbh_funds_direction,
	mbh_entity_id,
	mbh_org_ccy,
	mbh_ccy,
	mbh_acr_ind,
	mbh_old_bal,
	mbh_new_bal,
	mbh_old_rate,
	mbh_new_rate,
     	mbh_create_timestamp,
     	mbh_create_user,
       	mbh_update_timestamp,
       	mbh_update_user
	)

  VALUES (
	in_fx_id,
	in_fx_seq,
	in_funds_direction,
	in_entity_id,
	in_org_ccy,
	in_ccy,
	in_acr_ind,
	in_old_bal,
	in_new_bal,
	in_old_rate,
	in_new_rate,
       	SYSDATE,
       	in_user,
       	SYSDATE,
       	in_user
	);

  IF SQL%ROWCOUNT = 0
  THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;

END sp_entity_fx_bal_hist_insert;
/

