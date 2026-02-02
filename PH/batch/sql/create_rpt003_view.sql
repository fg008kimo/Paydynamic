CREATE OR REPLACE VIEW REPORT_RPT003_VIEW AS
   SELECT th_approval_date,
          tc_desc,
          sc_desc,
          psp_name,
          tp_txn_ccy,
          tp_txn_amount AS total_transaction_amount,
          1 AS transaction_count,
          tp_txn_amount AS average_transaction_amount
     FROM def_service_code,
          txn_code,
          psp_detail,
          txn_psp_detail,
          txn_header
    WHERE     th_ar_ind = 'A'
          AND th_txn_code = 'DSI'
          AND th_txn_id = tp_txn_id
          AND sc_code = th_service_code
          AND tc_code = th_txn_code
          AND psp_id = tp_psp_id
          AND ROWNUM = 1;
