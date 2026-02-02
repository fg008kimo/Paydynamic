select distinct(obt_bank_acct_num) from ol_baid_txn where obt_stat_txn_id in (
    select olsd_stat_txn_id from ol_statement_detail where olsd_file_id in ( 
        select olsh_file_id from ol_statement_header
        where olsh_create_timestamp >= to_date('20150709 103000','yyyymmdd hh24miss')
        and olsh_create_timestamp < to_date('20150710 000000','yyyymmdd hh24miss')
        and olsh_create_user = 'SYSTEM'
        and olsh_status = 'A'
    )
) and obt_txn_code not in ('UBC','UBD','USI','USO');
