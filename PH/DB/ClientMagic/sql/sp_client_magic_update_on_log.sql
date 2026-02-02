CREATE OR REPLACE FUNCTION sp_client_magic_update_on_log (
   in_client_id      client_magic.cm_client_id%TYPE,
   in_cust_id        client_magic.cm_cust_id%TYPE,
   in_num            client_magic.cm_num%TYPE,
   in_word           client_magic.cm_word%TYPE,
   in_disabled       client_magic.cm_disabled%TYPE,
   in_update_user    client_magic.cm_update_user%TYPE)
   RETURN NUMBER
IS
   action         client_magic_log.cml_action%TYPE;
   old_num        client_magic.cm_num%TYPE;
   old_word       client_magic.cm_word%TYPE;
   old_disabled   client_magic.cm_disabled%TYPE;
   num            client_magic.cm_num%TYPE;
   word           client_magic.cm_word%TYPE;
   disabled       client_magic.cm_disabled%TYPE;
   iCnt           INTEGER;
BEGIN
   num := in_num;
   word := in_word;
   disabled := in_disabled;

   SELECT COUNT (*)
     INTO iCnt
     FROM client_magic
    WHERE cm_client_id = in_client_id AND cm_cust_id = in_cust_id;

   IF iCnt > 0
   THEN
      action := 'U';

      SELECT cm_num, cm_word, cm_disabled
        INTO old_num, old_word, old_disabled
        FROM client_magic
       WHERE cm_client_id = in_client_id AND cm_cust_id = in_cust_id;

      INSERT INTO client_magic_log (cml_client_id,
                                    cml_cust_id,
                                    cml_action,
                                    cml_old_num,
                                    cml_old_word,
                                    cml_old_disabled,
                                    cml_new_num,
                                    cml_new_word,
                                    cml_new_disabled,
                                    cml_create_user,
                                    cml_update_user,
                                    cml_create_timestamp,
                                    cml_update_timestamp)
              VALUES (
                        in_client_id,
                        in_cust_id,
                        action,
                        old_num,
                        old_word,
                        old_disabled,
                        CASE WHEN num IS NULL THEN old_num ELSE num END,
                        CASE WHEN word IS NULL THEN old_word ELSE word END,
                        CASE
                           WHEN disabled IS NULL THEN old_disabled
                           ELSE disabled
                        END,
                        in_update_user,
                        in_update_user,
                        SYSDATE,
                        SYSDATE);

      IF SQL%ROWCOUNT = 0
      THEN
         RETURN 1;
      ELSE
         RETURN 0;
      END IF;
   END IF;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_client_magic_update_on_log;
/

