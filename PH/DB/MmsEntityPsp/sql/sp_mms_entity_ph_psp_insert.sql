CREATE OR REPLACE FUNCTION sp_mms_entity_psp_insert (
	in_node_id		mms_entity_psp.mep_node_id%TYPE,
	in_client_id		mms_entity_psp.mep_client_id%TYPE,
	in_psp_id		mms_entity_psp.mep_psp_Id%TYPE,
	in_baid			mms_entity_psp.mep_baid%TYPE,
	in_psp_name		mms_entity_psp.mep_psp_name%TYPE,
	in_baid_name		mms_entity_psp.mep_baid_name%TYPE,
	in_country		mms_entity_psp.mep_country%TYPE,
	in_entity_id		mms_entity_psp.mep_entity_id%TYPE,
	in_user			mms_entity_psp.mep_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO MMS_ENTITY_PSP (
	mep_node_id,
	mep_client_id,
	mep_psp_id,
	mep_baid,
	mep_psp_name,
	mep_baid_name,
	mep_country,
	mep_entity_id,
     	mep_create_timestamp,
     	mep_create_user,
     	mep_update_timestamp,
     	mep_update_user
	)

  VALUES (
	in_node_id,
	in_client_id,
	in_psp_id,
	in_baid,
	in_psp_name,
	in_baid_name,
	in_country,
	in_entity_id,
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

END sp_mms_entity_psp_insert;
/

