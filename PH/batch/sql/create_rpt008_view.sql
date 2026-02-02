CREATE OR REPLACE VIEW REPORT_RPT008_VIEW AS
   SELECT TO_CHAR (th_create_timestamp, 'YYYYMMDDHH24MISS') AS create_date,
          TO_CHAR (th_update_timestamp, 'YYYYMMDDHH24MISS') AS update_date,
          TO_CHAR (th_approval_timestamp, 'YYYYMMDDHH24MISS') AS approval_date,
          th_txn_id,
          th_merchant_ref,
          tc_desc,
          th_merchant_id,
          name AS merchant_name,
          dm_status_desc,
          ds_name AS sub_status_desc,
          tp_txn_amount,
          tp_txn_ccy,
          th_net_amount,
          th_ex_rate,
          fee,
          fee_ccy,
          th_transaction_amount,
          td_txn_ccy
     FROM def_sub_status,
          def_txn_status_map,
          merch_detail,
          txn_detail,
          (SELECT th_create_timestamp,
                  th_update_timestamp,
                  th_approval_timestamp,
                  th_txn_id,
                  th_merchant_ref,
                  th_merchant_id,
                  th_status,
                  th_ar_ind,
                  th_sub_status,
                  th_transaction_amount,
                  th_net_amount,
                  th_ex_rate,
                  NVL (te_amount, 0) AS fee,
                  te_ccy AS fee_ccy,
                  th_txn_code,
                  tp_txn_amount,
                  tp_txn_ccy,
                  tc_desc
             FROM (SELECT th_create_timestamp,
                          th_update_timestamp,
                          th_approval_timestamp,
                          th_txn_id,
                          th_merchant_ref,
                          th_merchant_id,
                          th_status,
                          th_ar_ind,
                          th_sub_status,
                          th_transaction_amount,
                          th_net_amount,
                          th_ex_rate,
                          th_txn_code,
                          tc_desc
                     FROM txn_header, txn_code
                    WHERE tc_code = th_txn_code AND tc_fe_display = 1) txn_header
                  LEFT JOIN txn_elements
                     ON     te_txn_id = th_txn_id
                        AND TE_TXN_ELEMENT_TYPE = 'TFEE'
                        AND te_party_type = 'M'
                  LEFT JOIN txn_psp_detail
                     ON tp_txn_id = th_txn_id)
    WHERE     th_txn_id = td_txn_id
          AND th_merchant_id = merchant_id
          AND dm_type = 'A'
          AND th_txn_code = dm_txn_code
          AND th_status = dm_status
          AND NVL (th_ar_ind, ' ') = dm_ar_ind
          AND th_sub_status = ds_sub_status
          AND ROWNUM = 1;
