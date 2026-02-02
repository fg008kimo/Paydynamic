-- 1)
insert into tmp_ol_odi_edit_final (rec_date, rec_no, rec_time,txn_id, deposit_amt, cust_deposit_datetime, bank_code, bank_acct_num, deposit_ref, deposit_bank)
select rec_date, rec_no, rec_time,txn_id, deposit_amt, cust_deposit_datetime, bank_code, bank_acct_num, deposit_ref, deposit_bank 
from tmp_ol_odi_edit_req
--where rec_date = 20150615
;

-- 2)
update tmp_ol_odi_edit_final a
set a.merch_ref = (select merch_ref
                  from tmp_ol_odi_edit_mer_ref b 
                  where a.txn_id = b.txn_id
                  and rownum = 1)
--where rec_date = 20150615
;


-- 3)
update tmp_ol_odi_edit_final a
set a.bank_desc = (select b.bank_name
                   from  bank_desc b
                   where b.internal_bank_code = a.bank_code)
--where rec_date = 20150615
;

--4)
update tmp_ol_odi_edit_final a
set a.error_code = (select b.error_code
                    from tmp_ol_odi_edit_rpy b
                    where a.rec_date = b.rec_date
                    and a.txn_id = b.txn_id
                    and a.rec_no = b.rec_no
                    )
--where rec_date = 20150615
;

--5)
update tmp_ol_odi_edit_final a
set a.new_txn_id = (select oth_txn_id
                    from ol_txn_header
                    where oth_txn_code = 'ODI'
                    and oth_merchant_ref = a.merch_ref
                    )
--where a.rec_date = '20150615'
;
