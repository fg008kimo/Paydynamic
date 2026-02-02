create or replace function sp_ol_txn_web_log_insert(
    in_txn_id              ol_txn_web_log.otw_txn_id%type,
    in_bank_code           ol_txn_web_log.otw_bank_code%type,
    in_logmsg              ol_txn_web_log.otw_logmsg%type,
    in_session_id          ol_txn_web_log.otw_session_id%type,
    in_update_user         ol_txn_web_log.otw_update_user%type)
RETURN NUMBER IS
    iCnt    integer := 0;
begin

    insert into ol_txn_web_log (
            otw_txn_id,
            otw_bank_code,
            otw_logmsg,
            otw_session_id,
            otw_create_user,
            otw_create_timestamp,
            otw_update_user,
            otw_update_timestamp
    )
    values(
            in_txn_id,
            in_bank_code,
            in_logmsg,
            in_session_id,
            in_update_user,
            sysdate,
            in_update_user,
            sysdate
    );

    IF SQL%ROWCOUNT = 0 THEN
        RETURN 1;
    ELSE
        RETURN 0;
    END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_ol_txn_web_log_insert;
/
