CREATE OR REPLACE FUNCTION sp_mms_entity_opb_insert (
	in_entity_id		mms_entity_opb.meob_entity_id%TYPE,
	in_opb_id		mms_entity_opb.meob_opb_id%TYPE,
	in_desc			mms_entity_opb.meob_desc%TYPE,
	in_status_ref		mms_entity_opb.meob_status_ref%TYPE,
	in_acct_name		mms_entity_opb.meob_acct_name%TYPE,
	in_acct_num		mms_entity_opb.meob_acct_num%TYPE,
	in_acct_holder		mms_entity_opb.meob_acct_holder%TYPE,
	in_base_ccy		mms_entity_opb.meob_base_ccy%TYPE,
	in_user			mms_entity_opb.meob_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO MMS_ENTITY_OPB (
	meob_entity_id,
	meob_opb_id,
	meob_desc,
	meob_status_ref,
	meob_acct_name,
	meob_acct_num,
     	meob_acct_holder,
     	meob_base_ccy,
     	meob_create_timestamp,
     	meob_create_user,
     	meob_update_timestamp,
     	meob_update_user
	)

  VALUES (
	in_entity_id,
	in_opb_id,
	in_desc,
	in_status_ref,
	in_acct_name,
	in_acct_num,
	in_acct_holder,
	in_base_ccy,
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

END sp_mms_entity_opb_insert;
/

