CREATE OR REPLACE FUNCTION sp_client_magic_gp_status_ins(
   in_client_id      client_magic_gp_status.gs_client_id%TYPE,
   in_txn_gp_id      client_magic_gp_status.gs_txn_gp_id%TYPE,
   in_status         client_magic_gp_status.gs_status%TYPE,
   in_create_user    client_magic_gp_status.gs_create_user%TYPE)
   RETURN NUMBER
IS
   iCnt	         INTEGER;
   v_old_status  client_magic_gp_status.gs_status%TYPE;
   
BEGIN

  SELECT COUNT (1)
  INTO iCnt
  FROM client_magic_gp_status
  WHERE gs_client_id = in_client_id 
  AND gs_txn_gp_id = in_txn_gp_id;

  if iCnt > 0 then
    -- Update

    SELECT gs_status
    INTO v_old_status
    FROM client_magic_gp_status
    WHERE gs_client_id = in_client_id 
    AND gs_txn_gp_id = in_txn_gp_id;

    UPDATE client_magic_gp_status
    SET gs_status = in_status
    WHERE gs_client_id = in_client_id 
    AND gs_txn_gp_id = in_txn_gp_id;

  else
    -- Add
    insert into client_magic_gp_status (gs_client_id,
                                        gs_txn_gp_id,
                                        gs_status,
                                        gs_create_user,
                                        gs_create_timestamp, 
                                        gs_update_user,
                                        gs_update_timestamp)
    values (in_client_id, 
            in_txn_gp_id,
            in_status,
            in_create_user,
            sysdate,
            in_create_user,
            sysdate);
   
  end if;

  IF SQL%ROWCOUNT = 0 THEN
    return 1;
  END IF;


  INSERT INTO client_magic_gp_status_log (gsl_client_id,
                                          gsl_txn_gp_id,
                                          gsl_old_status,
                                          gsl_new_status,
                                          gsl_create_user,
                                          gsl_create_timestamp,
                                          gsl_update_user,
                                          gsl_update_timestamp)
        VALUES (in_client_id,
                in_txn_gp_id,
                v_Old_status,
                in_status,
                in_create_user, 
                SYSDATE,
                in_create_user, 
                SYSDATE);

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
END sp_client_magic_gp_status_ins;
/

