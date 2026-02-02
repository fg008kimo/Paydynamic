CREATE OR REPLACE FUNCTION sp_client_magic_delete (
   in_client_id      client_magic.cm_client_id%TYPE,
   in_cust_id        client_magic.cm_cust_id%TYPE,
   in_create_user    client_magic.cm_create_user%TYPE)
   RETURN NUMBER
IS
   action     client_magic_log.cml_action%TYPE;
   num        client_magic.cm_num%TYPE;
   word       client_magic.cm_word%TYPE;
   disabled   client_magic.cm_disabled%TYPE;

   v_txn_gp_id  client_magic.cm_txn_gp_id%TYPE;
BEGIN
   action := 'D';

   SELECT cm_num, cm_word, cm_disabled, cm_txn_gp_id
     INTO num, word, disabled, v_txn_gp_id
     FROM client_magic
    WHERE cm_client_id = in_client_id AND cm_cust_id = in_cust_id;

   UPDATE client_magic
      SET cm_disabled = 1,
          cm_update_user = in_create_user,
          cm_update_timestamp = SYSDATE
    WHERE cm_client_id = in_client_id AND cm_cust_id = in_cust_id;

   IF SQL%ROWCOUNT = 0
   THEN
      RETURN 1;
   END IF;

   INSERT INTO client_magic_log (cml_client_id,
                                 cml_cust_id,
                                 cml_action,
                                 cml_old_num,
                                 cml_old_word,
                                 cml_old_txn_gp_id, 
                                 cml_old_disabled,
                                 cml_new_num,
                                 cml_new_word, 
                                 cml_new_txn_gp_id,
                                 cml_new_disabled,
                                 cml_create_user,
                                 cml_update_user,
                                 cml_create_timestamp,
                                 cml_update_timestamp)
        VALUES (in_client_id,
                in_cust_id,
                action,
                num,
                word,
                v_txn_gp_id,
                disabled,
                num,
                word,
                v_txn_gp_id,
                1,
                in_create_user,
                in_create_user,
                SYSDATE,
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
END sp_client_magic_delete;
/

