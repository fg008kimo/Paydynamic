


CREATE OR REPLACE FUNCTION sp_ol_sar_trigger_log_upd (
    in_trigger_seq       ol_semi_auto_recon_trigger_log.otl_trigger_seq%TYPE,
    in_trigger_status    ol_semi_auto_recon_trigger_log.otl_trigger_status%TYPE,
    in_update_user       ol_semi_auto_recon_trigger_log.otl_update_user%TYPE)
    RETURN NUMBER
IS
BEGIN
    UPDATE ol_semi_auto_recon_trigger_log
       SET otl_trigger_status = in_trigger_status,
           otl_update_timestamp = SYSDATE,
           otl_update_user = in_update_user
     WHERE otl_trigger_seq = in_trigger_seq;

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
END sp_ol_sar_trigger_log_upd;
/

