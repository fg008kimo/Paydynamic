create or replace view REPORT_RPT001_view as 
SELECT th_txn_id,
       th_merchant_ref,
       th_txn_code,
       tc_desc AS txn_code_desc,
       td_open_bal,
       td_current_bal,
       te_txn_element_type,
       dt_desc AS txn_element_type_desc,
       te_exec_seq,
       te_amount,
       te_ccy,
       te_amt_type,
       td_current_bal AS bal,
       th_approval_timestamp,
       th_org_txn_id AS void_txn_id
 FROM txn_header,
      txn_code,
      txn_detail,
      txn_elements,
      def_element_type
WHERE   th_txn_code = tc_code
    AND th_txn_id = td_txn_id
    AND th_txn_id = te_txn_id
    AND te_txn_element_type = dt_type
    AND ROWNUM = 1
/
