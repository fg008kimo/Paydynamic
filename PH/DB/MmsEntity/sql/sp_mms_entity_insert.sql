CREATE OR REPLACE FUNCTION sp_mms_entity_insert (
	in_id			mms_entity.me_id%TYPE,
	in_desc			mms_entity.me_desc%TYPE,
	in_entity_type		mms_entity.me_entity_type%TYPE,
	in_mms_client_id	mms_entity.me_mms_client_id%TYPE,
	in_user			mms_entity.me_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO MMS_ENTITY (
	me_id,
	me_desc,
	me_entity_type,
	me_mms_client_id,
     	me_create_timestamp,
     	me_create_user,
     	me_update_timestamp,
     	me_update_user
	)

  VALUES (
	in_id,
	in_desc,
	in_entity_type,
	in_mms_client_id,
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

END sp_mms_entity_insert;
/

