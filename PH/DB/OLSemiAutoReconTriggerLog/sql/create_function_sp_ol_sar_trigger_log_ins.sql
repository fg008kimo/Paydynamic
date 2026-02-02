


CREATE OR REPLACE FUNCTION sp_ol_sar_trigger_log_ins (
    in_ts_type           ol_semi_auto_recon_trigger_log.otl_ts_type%TYPE,
    in_s_ts_from         ol_semi_auto_recon_trigger_log.otl_s_ts_from%TYPE,
    in_s_ts_to           ol_semi_auto_recon_trigger_log.otl_s_ts_to%TYPE,
    in_s_provider_id     ol_semi_auto_recon_trigger_log.otl_s_provider_id%TYPE,
    in_s_pid             ol_semi_auto_recon_trigger_log.otl_s_pid%TYPE,
    in_s_txn_amt         ol_semi_auto_recon_trigger_log.otl_s_txn_amt%TYPE,
    in_r_ts_from         ol_semi_auto_recon_trigger_log.otl_r_ts_from%TYPE,
    in_r_ts_to           ol_semi_auto_recon_trigger_log.otl_r_ts_to%TYPE,
    in_r_provider_id     ol_semi_auto_recon_trigger_log.otl_r_provider_id%TYPE,
    in_r_pid             ol_semi_auto_recon_trigger_log.otl_r_pid%TYPE,
    in_r_txn_amt         ol_semi_auto_recon_trigger_log.otl_r_txn_amt%TYPE,
    in_trigger_status    ol_semi_auto_recon_trigger_log.otl_trigger_status%TYPE,
    in_create_user       ol_semi_auto_recon_trigger_log.otl_create_user%TYPE)
    RETURN NUMBER
IS
    iSeq   INTEGER := 0;
BEGIN
    SELECT NVL (MAX (otl_trigger_seq), 0) + 1
      INTO iSeq
      FROM ol_semi_auto_recon_trigger_log;

    INSERT INTO ol_semi_auto_recon_trigger_log (otl_trigger_seq,
                                                otl_ts_type,
                                                otl_s_ts_from,
                                                otl_s_ts_to,
                                                otl_s_provider_id,
                                                otl_s_pid,
                                                otl_s_txn_amt,
                                                otl_r_ts_from,
                                                otl_r_ts_to,
                                                otl_r_provider_id,
                                                otl_r_pid,
                                                otl_r_txn_amt,
                                                otl_trigger_status,
                                                otl_create_timestamp,
                                                otl_create_user,
                                                otl_update_timestamp,
                                                otl_update_user)
         VALUES (iSeq,
                 in_ts_type,
                 in_s_ts_from,
                 in_s_ts_to,
                 in_s_provider_id,
                 in_s_pid,
                 in_s_txn_amt,
                 in_r_ts_from,
                 in_r_ts_to,
                 in_r_provider_id,
                 in_r_pid,
                 in_r_txn_amt,
                 in_trigger_status,
                 SYSDATE,
                 in_create_user,
                 SYSDATE,
                 in_create_user);

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
END sp_ol_sar_trigger_log_ins;
/

