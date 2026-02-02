CREATE OR REPLACE FUNCTION sp_mms_entity_nature_insert (
	in_id			mms_entity_nature.men_nature_id%TYPE,
	in_desc			mms_entity_nature.men_desc%TYPE,
	in_user			mms_entity_nature.men_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO MMS_ENTITY_NATURE (
	men_nature_id,
	men_desc,
     	men_create_timestamp,
     	men_create_user,
     	men_update_timestamp,
     	men_update_user
	)

  VALUES (
	in_id,
	in_desc,
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

END sp_mms_entity_nature_insert;
/

