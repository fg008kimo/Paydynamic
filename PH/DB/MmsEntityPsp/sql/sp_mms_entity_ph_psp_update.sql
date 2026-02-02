CREATE OR REPLACE FUNCTION sp_mms_entity_psp_update (
	in_node_id		mms_entity_psp.mep_node_id%TYPE,
	in_client_id		mms_entity_psp.mep_client_id%TYPE,
	in_psp_id		mms_entity_psp.mep_psp_Id%TYPE,
	in_baid			mms_entity_psp.mep_baid%TYPE,
	in_psp_name		mms_entity_psp.mep_psp_name%TYPE,
	in_baid_name		mms_entity_psp.mep_baid_name%TYPE,
	in_country		mms_entity_psp.mep_country%TYPE,
	in_user			mms_entity_psp.mep_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
	UPDATE MMS_ENTITY_PSP
	   set MEP_PSP_NAME = in_psp_name,
               MEP_BAID_NAME = in_baid_name,
               MEP_COUNTRY = in_country,
	       MEP_UPDATE_USER = in_user,
	       MEP_UPDATE_TIMESTAMP = sysdate
         WHERE MEP_NODE_ID = in_node_id 
           AND MEP_CLIENT_ID = in_client_id
           AND MEP_PSP_ID = in_psp_id
           AND MEP_BAID = in_baid;
	

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

END sp_mms_entity_psp_update;
/

