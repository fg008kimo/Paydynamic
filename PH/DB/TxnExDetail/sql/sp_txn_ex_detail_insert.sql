


CREATE OR REPLACE FUNCTION sp_txn_ex_detail_insert (
    in_txn_id              txn_ex_detail.tx_txn_id%TYPE,
    in_ref_ex_rate_type    txn_ex_detail.tx_ref_ex_rate_type%TYPE,
    in_ref_ex_rate         txn_ex_detail.tx_ref_ex_rate%TYPE,
    in_min_ref_tolerance   txn_ex_detail.tx_min_ref_tolerance%TYPE,
    in_max_ref_tolerance   txn_ex_detail.tx_max_ref_tolerance%TYPE,
    in_min_ref_ex_rate     txn_ex_detail.tx_min_ref_ex_rate%TYPE,
    in_max_ref_ex_rate     txn_ex_detail.tx_max_ref_ex_rate%TYPE,
    in_create_user         txn_ex_detail.tx_create_user%TYPE)
    RETURN NUMBER
IS
BEGIN
    INSERT INTO txn_ex_detail (tx_txn_id,
                               tx_ref_ex_rate_type,
                               tx_ref_ex_rate,
                               tx_min_ref_tolerance,
                               tx_max_ref_tolerance,
                               tx_min_ref_ex_rate,
                               tx_max_ref_ex_rate,
                               tx_create_user,
                               tx_create_timestamp,
                               tx_update_user,
                               tx_update_timestamp)
         VALUES (in_txn_id,
                 in_ref_ex_rate_type,
                 in_ref_ex_rate,
                 in_min_ref_tolerance,
                 in_max_ref_tolerance,
                 in_min_ref_ex_rate,
                 in_max_ref_ex_rate,
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
END sp_txn_ex_detail_insert;
/

