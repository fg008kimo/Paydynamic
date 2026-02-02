CREATE OR REPLACE FUNCTION sp_mms_entity_master_insert (
	in_client_id		mms_entity_master.mem_client_id%TYPE,
	in_client_name		mms_entity_master.mem_client_name%TYPE,
	in_user			mms_entity_master.mem_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
	UPDATE MMS_ENTITY_MASTER
	   SET mem_client_name = in_client_name,
               mem_update_user = in_user,
               mem_update_timestamp = sysdate
         WHERE mem_client_id = in_client_id;


	if SQL%ROWCOUNT = 0 THEN
  		INSERT INTO MMS_ENTITY_MASTER (
			mem_client_id,
			mem_client_name,
     			mem_create_timestamp,
     			mem_create_user
			)

  		VALUES (
			in_client_id,
			in_client_name,
       			SYSDATE,
       			in_user
			);

  		IF SQL%ROWCOUNT = 0 THEN
     			RETURN 1;
  		ELSE
     			RETURN 0;
  		END IF;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;

END sp_mms_entity_master_insert;
/

