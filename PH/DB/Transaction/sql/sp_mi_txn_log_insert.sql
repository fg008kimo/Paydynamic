CREATE OR REPLACE FUNCTION sp_mi_txn_log_insert (
   in_txn_id    mi_txn_log.tl_txn_id%TYPE,
   in_user      mi_txn_log.tl_create_user%TYPE)
   RETURN NUMBER
IS
   iCnt   INTEGER := 0;
BEGIN
   SELECT COUNT (1)
     INTO iCnt
     FROM MI_TXN_LOG
    WHERE tl_txn_id = in_txn_id;

   IF iCnt > 0
   THEN
      RETURN 0;
   ELSE
      INSERT INTO MI_TXN_LOG (tl_txn_id,
                              tl_create_timestamp,
                              tl_create_user,
                              tl_update_timestamp,
                              tl_update_user)
           VALUES (in_txn_id,
                   SYSDATE,
                   in_user,
                   SYSDATE,
                   in_user);

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
END sp_mi_txn_log_insert;
/
