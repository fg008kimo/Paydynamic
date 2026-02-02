CREATE OR REPLACE FUNCTION sp_entity_support_insert (
	in_from_entity_type	mms_entity_support.mes_from_entity_type%TYPE,
	in_to_entity_type	mms_entity_support.mes_to_entity_type%TYPE,
	in_support		mms_entity_support.mes_support%TYPE,
	in_user			mms_entity_support.mes_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO MMS_ENTITY_SUPPORT (
	mes_from_entity_type,
	mes_to_entity_type,
	mes_support,
     	mes_create_timestamp,
     	mes_create_user,
       	mes_update_timestamp,
       	mes_update_user
	)

  VALUES (
	in_from_entity_type,
	in_to_entity_type,
	in_support,
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

END sp_entity_support_insert;
/

