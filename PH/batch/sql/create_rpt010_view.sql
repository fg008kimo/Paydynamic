CREATE OR REPLACE VIEW REPORT_RPT010_VIEW AS
   SELECT TO_CHAR (th_approval_timestamp, 'YYYYMMDDHH24MISS') AS approval_date,
          th_txn_id,
          th_merchant_id,
          name AS merchant_name,
          at_desc AS transaction_type,
          dm_status_desc,
          ds_name AS sub_status_desc,
          th_transaction_amount,
          td_txn_ccy,
          te_amount,
          te_ccy
     FROM def_sub_status,
          def_txn_status_map,
          merch_detail,
          txn_detail,
          txn_elements,
          adjustment_type,
          txn_header
    WHERE     th_ar_ind = 'A'
          AND th_txn_code = at_code
          AND at_party_type = 'M'
          AND at_dc_ind = 'D'
          AND te_txn_id = th_txn_id
          AND te_txn_element_type = 'TFEE'
          AND te_party_type = 'M'
          AND dm_type = 'A'
          AND dm_status = th_status
          AND dm_ar_ind = NVL (th_ar_ind, ' ')
          AND dm_txn_code = th_txn_code
          AND ds_sub_status = th_sub_status
          AND td_txn_id = th_txn_id
          AND merchant_id = th_merchant_id
          AND ROWNUM = 1;
