CREATE OR REPLACE VIEW REPORT_RPT005_VIEW AS
   SELECT tc_desc,
          dm_status_desc,
          1 AS transaction_count,
          te_amt_type,
          te_ccy,
          te_amount AS markup_amount
     FROM txn_code,
          def_txn_status_map,
          txn_elements,
          txn_header
    WHERE     te_txn_element_type = 'MAMT'
          AND te_party_type = 'R'
          AND te_txn_id = th_txn_id
          AND tc_code = th_txn_code
          AND dm_type = 'A'
          AND dm_status = th_status
          AND dm_ar_ind = 'A'
          AND dm_txn_code = th_txn_code
          AND ROWNUM = 1;
