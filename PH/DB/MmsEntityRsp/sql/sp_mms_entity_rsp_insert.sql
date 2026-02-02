CREATE OR REPLACE FUNCTION sp_mms_entity_rsp_insert (
	in_entity_id		mms_entity_rsp.mer_entity_id%TYPE,
	in_rsp_id		mms_entity_rsp.mer_rsp_id%TYPE,
	in_desc			mms_entity_rsp.mer_desc%TYPE,
	in_status_ref		mms_entity_rsp.mer_status_ref%TYPE,
	in_node_id		mms_entity_rsp.mer_node_id%TYPE,
	in_acct_type		mms_entity_rsp.mer_acct_type%TYPE,
	in_relate_grp		mms_entity_rsp.mer_relate_grp%TYPE,
	in_user			mms_entity_rsp.mer_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO MMS_ENTITY_RSP (
	mer_entity_id,
	mer_rsp_id,
	mer_desc,
	mer_status_ref,
	mer_node_id,
	mer_acct_type,
	mer_relate_grp,
     	mer_create_timestamp,
     	mer_create_user,
     	mer_update_timestamp,
     	mer_update_user
	)

  VALUES (
	in_entity_id,
	in_rsp_id,
	in_desc,
	in_status_ref,
	in_node_id,
	in_acct_type,
	in_relate_grp,
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

END sp_mms_entity_rsp_insert;
/

