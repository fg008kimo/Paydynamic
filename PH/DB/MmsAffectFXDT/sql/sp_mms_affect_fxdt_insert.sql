CREATE OR REPLACE FUNCTION sp_mms_affect_fxdt_insert (
	in_fx_id		mms_affect_fx_dt.maf_fx_id%TYPE,
	in_fx_seq		mms_affect_fx_dt.maf_fx_seq%TYPE,
	in_direction		mms_affect_fx_dt.maf_direction%TYPE,
	in_entity_id		mms_affect_fx_dt.maf_entity_id%TYPE,
	in_acr_ind		mms_affect_fx_dt.maf_acr_ind%TYPE,
	in_org_ccy		mms_affect_fx_dt.maf_org_ccy%TYPE,
	in_org_amount		mms_affect_fx_dt.maf_org_amount%TYPE,
	in_ccy			mms_affect_fx_dt.maf_ccy%TYPE,
	in_amount		mms_affect_fx_dt.maf_amount%TYPE,
	in_calculate_ind	mms_affect_fx_dt.maf_calculate_ind%TYPE,
	in_user			mms_affect_fx_dt.maf_create_user%TYPE
	)
  RETURN NUMBER IS
BEGIN

  INSERT INTO MMS_AFFECT_FX_DT (
	maf_fx_id,
	maf_fx_seq,
	maf_direction,
	maf_entity_id,
	maf_acr_ind,
	maf_org_ccy,
	maf_org_amount,
	maf_ccy,
	maf_amount,
	maf_calculate_ind,
     	maf_create_timestamp,
     	maf_create_user,
       	maf_update_timestamp,
       	maf_update_user
	)

  VALUES (
	in_fx_id,
	in_fx_seq,
	in_direction,
	in_entity_id,
	in_acr_ind,
	in_org_ccy,
	in_org_amount,
	in_ccy,
	in_amount,
	in_calculate_ind,
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

END sp_mms_affect_fxdt_insert;
/

