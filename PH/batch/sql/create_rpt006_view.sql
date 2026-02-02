CREATE OR REPLACE VIEW REPORT_RPT006_VIEW AS
   SELECT 1 AS transaction_count,
          te_amt_type AS member_amt_type,
          te_ccy AS member_ccy,
          te_amount AS member_fee,
          te_amt_type AS merchant_amt_type,
          te_ccy AS merchant_ccy,
          te_amount AS merchant_fee
     FROM txn_elements,
	  txn_header
    WHERE     th_txn_code = 'POU'
          AND th_ar_ind = 'A'
          AND te_txn_id = th_txn_id
          AND te_txn_element_type = 'TFEE'
          AND TE_PARTY_TYPE = 'M'
          AND ROWNUM = 1;
