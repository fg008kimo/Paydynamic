


CREATE OR REPLACE FUNCTION sp_txn_supp_info_insert (
    in_txn_id         txn_supp_info.ts_txn_id%TYPE,
    in_info_type      txn_supp_info.ts_info_type%TYPE,
    in_info_value     txn_supp_info.ts_info_value%TYPE,
    in_create_user    txn_supp_info.ts_create_user%TYPE)
    RETURN NUMBER
IS
    iCnt   INTEGER := 0;
BEGIN
    SELECT NVL (MAX (ts_exec_seq), 0) + 1
      INTO iCnt
      FROM txn_supp_info
     WHERE ts_txn_id = in_txn_id AND ts_info_type = in_info_type;

    INSERT INTO txn_supp_info (ts_txn_id,
                               ts_info_type,
                               ts_exec_seq,
                               ts_info_value,
                               ts_create_user,
                               ts_create_timestamp,
                               ts_update_user,
                               ts_update_timestamp)
         VALUES (in_txn_id,
                 in_info_type,
                 iCnt,
                 in_info_value,
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
END sp_txn_supp_info_insert;
/

