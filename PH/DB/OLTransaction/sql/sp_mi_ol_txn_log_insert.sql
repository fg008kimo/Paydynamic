CREATE OR REPLACE FUNCTION sp_mi_ol_txn_log_insert (
        in_txn_id                     mi_ol_txn_log.otl_txn_id%TYPE,
        in_user                       mi_ol_txn_log.otl_create_user%TYPE
        )
  RETURN NUMBER IS
  iCnt INTEGER := 0;
BEGIN
  SELECT COUNT(1)
  INTO iCnt
  FROM MI_OL_TXN_LOG
  WHERE otl_txn_id = in_txn_id;

  IF iCnt > 0
  THEN
     RETURN 0;
  ELSE

  INSERT INTO MI_OL_TXN_LOG (
        otl_txn_id,
        otl_create_timestamp,
        otl_create_user,
        otl_update_timestamp,
        otl_update_user
        )

  VALUES (
        in_txn_id,
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

  END IF;

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;

END sp_mi_ol_txn_log_insert;
/
