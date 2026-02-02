
        
select tc_desc, dm_status_desc, count(*) as txn_count, markup_ccy, NVL(sum(te_amount), 0)
from txn_code,
        def_txn_status_map,
        (select  th_txn_id,
                     th_txn_code, 
                     th_status, 
                     th_ar_ind,
                     NVL(te_ccy, td_txn_ccy) as markup_ccy,
                     te_amount,
                     te_amt_type 
        from (select  th_txn_id,
                          th_txn_code, 
                             th_status, 
                            th_ar_ind,
                            td_txn_ccy
                    from txn_detail, txn_header
                    -- where th_host_posting_date = '20120710'
                    where th_txn_id = td_txn_id
                ) txn_header
        left join txn_elements
        on te_txn_id = th_txn_id
        and te_txn_element_type = 'MAMT'
        and te_party_type = 'R') markup_dtl
where dm_type = 'A'
and th_txn_code = dm_txn_code
and th_status = dm_status
and  NVL(th_ar_ind, ' ') = dm_ar_ind
and th_txn_code = tc_code
and tc_fe_display = 1
group by tc_desc, dm_status_desc, markup_ccy
order by tc_desc, dm_status_desc, markup_ccy

