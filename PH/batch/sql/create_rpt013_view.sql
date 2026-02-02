CREATE OR REPLACE VIEW REPORT_RPT013_VIEW AS
   SELECT tc_desc,
          th_service_code,
          sc_desc AS service_desc,
          dm_status_desc AS status,
          1 AS transaction_count
     FROM def_service_code,
          def_txn_status_map,
          txn_code,
          txn_header
    WHERE     th_txn_code = tc_code
          AND tc_fe_display = 1
          AND dm_type = 'A'
          AND dm_status = th_status
          AND dm_ar_ind = NVL (th_ar_ind, ' ')
          AND dm_txn_code = th_txn_code
          AND sc_code = th_service_code
          AND ROWNUM = 1;
