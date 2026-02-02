CREATE OR REPLACE FUNCTION sp_mms_adj_type_entity_insert (
        in_code                    	mms_adjustment_type_entity.mae_code%TYPE,
        in_entity_type             	mms_adjustment_type_entity.mae_entity_type%TYPE,
        in_disabled               	mms_adjustment_type_entity.mae_disabled%TYPE,
        in_user                         mms_adjustment_type_entity.mae_create_user%TYPE
        )
  RETURN NUMBER IS

BEGIN
  INSERT INTO MMS_ADJUSTMENT_TYPE_ENTITY (
        mae_code,
        mae_entity_type,
        mae_disabled,
        mae_create_timestamp,
        mae_create_user,
	mae_update_timestamp,
        mae_update_user
        )

  VALUES (
        in_code,
        in_entity_type,
        in_disabled,
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

END sp_mms_adj_type_entity_insert;
/
