create or replace view REPORT_RPT001_view as 
select th_txn_id,
         th_merchant_ref,
         th_txn_code,
         tc_desc as txn_code_desc,
         td_open_bal,
         td_current_bal,
         te_txn_element_type,
         dt_desc as txn_element_type_desc,
         te_exec_seq,
         te_amount,
         te_ccy,
         te_amt_type,
         td_current_bal as bal,
         th_approval_timestamp
  from txn_header,
          txn_code,
          txn_detail,
          txn_elements,
          def_element_type
where th_txn_code  = tc_code
    and th_txn_id = td_txn_id
    and th_txn_id = te_txn_id
    and te_txn_element_type = dt_type
    and rownum = 1

/
