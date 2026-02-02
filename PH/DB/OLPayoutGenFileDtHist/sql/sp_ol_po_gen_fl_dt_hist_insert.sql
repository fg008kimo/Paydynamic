CREATE OR REPLACE FUNCTION sp_ol_po_gen_fl_dt_hist_insert (
   in_txn_id         ol_payout_gen_file_dt_hist.odh_txn_id%TYPE,
   in_init_txn_id    ol_payout_gen_file_dt_hist.odh_init_txn_id%TYPE,
   in_add_user       ol_payout_gen_file_dt_hist.odh_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   INSERT INTO ol_payout_gen_file_dt_hist (odh_txn_id,
                                           odh_init_txn_id,
                                           odh_create_user,
                                           odh_update_user,
                                           odh_create_timestamp,
                                           odh_update_timestamp)
        VALUES (in_txn_id,
                in_init_txn_id,
                in_add_user,
                in_add_user,
                SYSDATE,
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
END sp_ol_po_gen_fl_dt_hist_insert;
/

