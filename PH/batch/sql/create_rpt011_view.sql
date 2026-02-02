CREATE OR REPLACE VIEW REPORT_RPT011_VIEW AS
   SELECT th_txn_id,
          th_txn_code,
          tc_desc,
          tp_txn_date,
          tp_psp_id,
          psp_name,
          tp_txn_ccy,
          tp_txn_amount,
          tp_service_fee
     FROM txn_code,
          psp_detail,
          txn_psp_detail,
          txn_header
    WHERE     th_ar_ind = 'A'
          AND th_txn_id = tp_txn_id
          AND psp_id = tp_psp_id
          AND tc_code = th_txn_code
          AND ROWNUM = 1;
