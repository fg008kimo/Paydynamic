merge into customer_txn_hist c
using (select th_host_posting_date, th_merchant_id,td_customer_tag, td_customer_group,
	      sum(th_transaction_amount) amount, count(th_transaction_amount) cust_cnt
        from txn_header, txn_detail
        where th_txn_id = td_txn_id
        and th_txn_code = 'DSI'
        and th_ar_ind = 'A'
        and exists (select null from customer_group_merchant
                    where cgm_disabled = 0
                      AND   cgm_merchant_id = th_merchant_id)
        and th_host_posting_date > to_char(to_date(sysdate-30),'YYYYMMDD')
	and th_host_posting_date <= to_char(to_date(sysdate),'YYYYMMDD')
        group by th_host_posting_date, th_merchant_id,td_customer_tag, td_customer_group) t
on (      cth_date = th_host_posting_date
     AND  cth_merchant_id = th_merchant_id
     AND  cth_cust_id = td_customer_tag
     AND  cth_code = td_customer_group)
WHEN MATCHED THEN
     update SET cth_counter = cust_cnt,
            cth_amount = amount,
            cth_update_user = 'SYSTEM',
            cth_update_timestamp = SYSDATE
  WHEN NOT MATCHED THEN
   INSERT (cth_date,
           cth_merchant_id,
           cth_cust_id,
           cth_code,
           cth_amount,
           cth_counter,
           cth_create_user,
           cth_create_timestamp,
           cth_update_user,
           cth_update_timestamp)
        VALUES (th_host_posting_date, th_merchant_id,td_customer_tag, td_customer_group, amount,cust_cnt,
                'SYSTEM',
                SYSDATE,
                'SYSTEM',
                SYSDATE);
