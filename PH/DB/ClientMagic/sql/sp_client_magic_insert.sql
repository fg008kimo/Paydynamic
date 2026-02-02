CREATE OR REPLACE FUNCTION sp_client_magic_insert (
   in_client_id      client_magic.cm_client_id%TYPE,
   in_cust_id        client_magic.cm_cust_id%TYPE,
   in_num            client_magic.cm_num%TYPE,
   in_word           client_magic.cm_word%TYPE,
   in_txn_gp_id      client_magic.cm_txn_gp_id%TYPE,
   in_disabled       client_magic.cm_disabled%TYPE,
   in_create_user    client_magic.cm_create_user%TYPE)
   RETURN NUMBER
IS
   action     client_magic_log.cml_action%TYPE;
   num        client_magic.cm_num%TYPE;
   word       client_magic.cm_word%TYPE;
   disabled   client_magic.cm_disabled%TYPE;
   iCnt       INTEGER;

   v_old_txn_gp_id   client_magic.cm_txn_gp_id%TYPE;
   
BEGIN
   SELECT COUNT (*)
     INTO iCnt
     FROM client_magic
    WHERE cm_client_id = in_client_id AND cm_cust_id = in_cust_id;

   IF iCnt > 0
   THEN
      action := 'U';

      SELECT cm_num, cm_word, cm_disabled, cm_txn_gp_id
        INTO num, word, disabled, v_old_txn_gp_id
        FROM client_magic
       WHERE cm_client_id = in_client_id AND cm_cust_id = in_cust_id;


      UPDATE client_magic
         SET cm_disabled = in_disabled,
             cm_num = in_num,
             cm_word = in_word,
             cm_txn_gp_id = in_txn_gp_id,
             cm_update_user = in_create_user,
             cm_update_timestamp = SYSDATE
       WHERE cm_client_id = in_client_id AND cm_cust_id = in_cust_id;
   ELSE
      action := 'A';

      INSERT INTO client_magic (cm_client_id,
                                cm_cust_id,
                                cm_num,
                                cm_word,
                                cm_txn_gp_id,
                                cm_disabled,
                                cm_create_user,
                                cm_update_user,
                                cm_create_timestamp,
                                cm_update_timestamp)
           VALUES (in_client_id,
                   in_cust_id,
                   in_num,
                   in_word,
                   in_txn_gp_id,
                   in_disabled,
                   in_create_user,
                   in_create_user,
                   SYSDATE,
                   SYSDATE);
   END IF;

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
                v_old_txn_gp_id,
                disabled,
                in_num,
                in_word,
                in_txn_gp_id,
                in_disabled,
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
END sp_client_magic_insert;
/

