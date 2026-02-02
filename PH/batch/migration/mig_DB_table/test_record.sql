
insert into mig_txn_data(mtd_txn_seq, mtd_post_date, mtd_txn_date,
                         mtd_txn_merch_nmb, mtd_txn_nmb, mtd_merch_ref, mtd_txn_type, mtd_txn_status, mtd_txn_status_group,
                         mtd_to_ccy, mtd_to_amount, mtd_ccy, mtd_amount, mtd_fee, mtd_ex_rate, mtd_markup_amt
                         )
values (1234, to_date('2013-03-13 10:00:00', 'YYYY-MM-DD HH24:MI:SS'), to_timestamp('2013-03-13 10:00:00.123', 'YYYY-MM-DD HH24:MI:SS.FF3'),
           'aaaa', 'bbbb', 'cccc', 'dd', 'eee', 'fff',
           'RMB', 1234.4, 'RMB', 1234.4, 12.51, 1.23456, 10.888);
