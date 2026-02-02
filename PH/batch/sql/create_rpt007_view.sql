CREATE OR REPLACE VIEW REPORT_RPT007_VIEW AS
   SELECT TO_CHAR (th_create_timestamp, 'YYYYMMDDHH24MISS') AS create_date,
          TO_CHAR (th_update_timestamp, 'YYYYMMDDHH24MISS') AS update_date,
          TO_CHAR (th_approval_timestamp, 'YYYYMMDDHH24MISS') AS approval_date,
          th_txn_id,
          psp_name,
          tp_tid,
          th_merchant_ref,
          th_merchant_id,
          name AS merchant_name,
          dm_status_desc,
          ds_name AS sub_status_desc,
          tp_txn_amount,
          tp_txn_ccy,
          th_net_amount,
          th_ex_rate,
          te_amount AS fee,
          te_ccy AS fee_ccy,
          th_transaction_amount AS requested_amount,
          td_txn_ccy,
          te_amount AS markup,
          te_ccy AS  markup_ccy
     FROM def_sub_status,
          def_txn_status_map,
          merch_detail,
          psp_detail,
          txn_psp_detail,
          txn_detail,
          txn_header,
          txn_elements
    WHERE     th_txn_code = 'DSI'
          AND te_txn_id = th_txn_id
          AND tp_txn_id = th_txn_id
          AND th_txn_id = td_txn_id
          AND tp_psp_id = psp_id
          AND th_merchant_id = merchant_id
          AND dm_type = 'A'
          AND th_txn_code = dm_txn_code
          AND th_status = dm_status
          AND NVL (th_ar_ind, ' ') = dm_ar_ind
          AND th_sub_status = ds_sub_status
          AND ROWNUM = 1;
