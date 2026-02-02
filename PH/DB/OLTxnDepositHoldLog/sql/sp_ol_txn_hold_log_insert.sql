CREATE OR REPLACE FUNCTION sp_ol_txn_hold_log_insert (
   in_txn_id          ol_txn_deposit_hold_log.otdh_txn_id%TYPE,
   in_txn_hold_ind    ol_txn_deposit_hold_log.otdh_txn_hold_ind%TYPE,
   in_stat_txn_id     ol_txn_deposit_hold_log.otdh_stat_txn_id%TYPE,
   in_remark          ol_txn_deposit_hold_log.otdh_remark%TYPE,
   in_user            ol_txn_deposit_hold_log.otdh_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   INSERT INTO ol_txn_deposit_hold_log (otdh_txn_id,
                                        otdh_exec_seq,
                                        otdh_txn_hold_ind,
                                        otdh_stat_txn_id,
                                        otdh_remark,
                                        otdh_create_user,
                                        otdh_create_timestamp)
        VALUES (in_txn_id,
                (SELECT NVL (MAX (otdh_exec_seq), 0) + 1
                   FROM ol_txn_deposit_hold_log
                  WHERE otdh_txn_id = in_txn_id),
                in_txn_hold_ind,
                in_stat_txn_id,
                in_remark,
                in_user,
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
END sp_ol_txn_hold_log_insert;
/

