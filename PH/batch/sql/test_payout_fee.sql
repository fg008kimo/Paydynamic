select sum(record_cnt),
         member_amt_type,
         member_ccy,
         sum(member_amount),
         merch_amt_type,
         merch_ccy,
         sum(merch_amount)
from 
(
select th_txn_id,
         th_txn_code,
         th_status,
         th_ar_ind,
         member_amt_type,
         member_ccy,
         member_amount,
         merch_amt_type,
         merch_ccy,
         merch_amount,
         1 as record_cnt
from MERCHANT_UPLOAD_FILE_HEADER,
       MERCHANT_UPLOAD_FILE_DETAIL,
       (
select th_txn_id, 
        th_txn_code, 
        th_status, 
        th_ar_ind,  
        member_fee_element.te_amt_type as member_amt_type,
        member_fee_element.te_ccy as member_ccy,
        member_fee_element.te_amount as member_amount,
        merch_fee_element.te_amt_type as merch_amt_type,
        merch_fee_element.te_ccy as merch_ccy,
        merch_fee_element.te_amount as merch_amount
from ( 
    select th_txn_id,
             th_txn_code,
             th_status,
             th_ar_ind
    from txn_header
    where th_txn_code = 'POU'
    and th_ar_ind = 'A'
    ) txn_header
left join txn_elements member_fee_element
on member_fee_element.te_txn_id = th_txn_id
and member_fee_element.te_txn_element_type = 'TFEE'
and MEMBER_FEE_ELEMENT.TE_PARTY_TYPE = 'R'
left join txn_elements merch_fee_element
on merch_fee_element.te_txn_id = th_txn_id
and merch_fee_element.te_txn_element_type = 'TFEE'
and merch_fee_element.te_party_type = 'M'
)
where th_txn_id = uh_txn_id
and uh_batch_id = ud_batch_id
group by th_txn_id, th_txn_code, th_status, th_ar_ind, member_amt_type,
         member_ccy,
         member_amount,
         merch_amt_type,
         merch_ccy,
         merch_amount
)
group by 
         member_amt_type,
         member_ccy,
         merch_amt_type,
         merch_ccy;

