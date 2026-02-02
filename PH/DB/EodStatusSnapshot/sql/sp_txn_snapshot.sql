CREATE OR REPLACE FUNCTION sp_txn_snapshot (
   in_host_posting_date   IN     txn_header.th_host_posting_date%TYPE,
   out_cursor             IN OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
BEGIN
   OPEN out_cursor FOR
        SELECT th_host_posting_date,
               th_txn_id,
               th_merchant_id,
               tp_psp_id,
               th_txn_code,
               th_status,
               th_ar_ind,
               th_sub_status
          FROM txn_code,
                  (SELECT th_txn_id,
                          th_merchant_id,
                          th_txn_code,
                          th_status,
                          th_ar_ind,
                          th_sub_status,
                          th_host_posting_date,
                          th_create_timestamp
                     FROM txn_header
                    WHERE     th_update_timestamp >=
                                 TO_DATE (in_host_posting_date, 'YYYYMMDD')
                          AND th_update_timestamp <
                                 TO_DATE (in_host_posting_date, 'YYYYMMDD') + 1)
               LEFT JOIN
                  txn_psp_detail
               ON tp_txn_id = th_txn_id
         WHERE tc_code = th_txn_code AND tc_fe_display = 1
      ORDER BY th_host_posting_date,
               th_txn_id;

   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_txn_snapshot;
/
