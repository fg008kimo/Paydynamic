CREATE OR REPLACE FUNCTION sp_txn_snapshot_insert (
   in_host_posting_date    eod_status_snapshot.es_process_date%TYPE,
   in_txn_id               eod_status_snapshot.es_txn_id%TYPE,
   in_mid                  eod_status_snapshot.es_mid%TYPE,
   in_pid                  eod_status_snapshot.es_pid%TYPE,
   in_txn_code             eod_status_snapshot.es_txn_code%TYPE,
   in_status               eod_status_snapshot.es_status%TYPE,
   in_ar_ind               eod_status_snapshot.es_ar_ind%TYPE,
   in_sub_status           eod_status_snapshot.es_sub_status%TYPE,
   in_create_user          eod_status_snapshot.es_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   INSERT INTO eod_status_snapshot (es_process_date,
                                    es_txn_id,
                                    es_mid,
                                    es_pid,
                                    es_txn_code,
                                    es_status,
                                    es_ar_ind,
                                    es_sub_status,
                                    es_create_user,
                                    es_create_timestamp,
                                    es_update_user,
                                    es_update_timestamp)
        VALUES (in_host_posting_date,
                in_txn_id,
                in_mid,
                in_pid,
                in_txn_code,
                in_status,
                in_ar_ind,
                in_sub_status,
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
END sp_txn_snapshot_insert;
/
