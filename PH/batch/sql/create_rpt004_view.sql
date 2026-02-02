CREATE OR REPLACE VIEW REPORT_RPT004_VIEW AS
   SELECT th_merchant_id,
          name,
          sc_desc,
          te_ccy,
          te_amt_type,
          te_amount AS total_amount
     FROM txn_elements,
          (SELECT th_txn_id, th_merchant_id, th_service_code
             FROM txn_header
            WHERE th_ar_ind = 'A'),
          def_service_code,
          merch_detail
    WHERE     te_txn_id = th_txn_id
          AND te_txn_element_type = 'TFEE'
          AND te_party_type = 'M'
          AND merchant_id = th_merchant_id
          AND sc_code = th_service_code
          AND ROWNUM = 1;
