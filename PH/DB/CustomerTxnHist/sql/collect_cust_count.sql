merge into customer_group_counters c
using (select th_host_posting_date, td_customer_group, sum(th_transaction_amount) amount,
              td_txn_country, th_input_channel, th_service_code, th_net_ccy
        from txn_header, txn_detail
        where th_txn_id = td_txn_id
        and th_txn_code = 'DSI'
        and th_ar_ind = 'A'
        and exists (select null from customer_group_merchant
                    where cgm_disabled = 0
                      AND   cgm_merchant_id = th_merchant_id)
        and th_host_posting_date > to_char(to_date(sysdate-30),'YYYYMMDD')
	and th_host_posting_date <= to_char(to_date(sysdate),'YYYYMMDD')
        group by th_host_posting_date, td_customer_group, td_txn_country, th_input_channel, th_service_code, th_net_ccy) t
on (      cgc_date = th_host_posting_date
     AND  cgc_country_id = td_txn_country
     AND  cgc_channel_code = th_input_channel
     AND  cgc_code = td_customer_group
     AND cgc_service_code = th_service_code
     AND cgc_currency_id = th_net_ccy)
WHEN MATCHED THEN
     update SET cgc_counter = amount,
            cgc_update_user = 'SYSTEM',
            cgc_update_timestamp = SYSDATE
  WHEN NOT MATCHED THEN
   INSERT (cgc_code,
           cgc_country_id,
           cgc_channel_code,
           cgc_service_code,
           cgc_currency_id,
           cgc_date,
           cgc_category,
           cgc_counter,
           cgc_create_user,
           cgc_create_timestamp,
           cgc_update_user,
           cgc_update_timestamp)
        VALUES (td_customer_group, td_txn_country, th_input_channel, th_service_code, th_net_ccy, th_host_posting_date, 'AMT',amount,
                'SYSTEM',
                SYSDATE,
                'SYSTEM',
                SYSDATE);
