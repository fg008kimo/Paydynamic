set serveroutput on;
set verify off;

declare
    v_rec_cnt	NUMBER;

begin
    dbms_output.new_line(); 

    select count(*)
    into v_rec_cnt
    from ol_statement_detail
    where olsd_file_id in (
        select olsh_file_id 
        from ol_statement_header 
        where olsh_create_timestamp >= to_date('&&DateFrom', 'YYYYMMDD')
        and olsh_create_timestamp < to_date('&&DateTo', 'YYYYMMDD')
        and olsh_create_user = 'SYSTEM'
        and olsh_message_code = 0
    )
    and (exists (select 1
         from ol_baid_txn
         where obt_stat_txn_id = olsd_stat_txn_id
         and obt_status = 'C'
         and obt_ar_ind = 'A'
         and obt_txn_code not in ('UBD', 'UBC')
         )
        or
        exists (select 1
         from ol_baid_txn
         where obt_stat_txn_id = olsd_stat_txn_id
         and obt_status = 'R'
         and obt_ar_ind = 'A'
         and obt_txn_code not in ('UBD', 'UBC')
	)
    );

    dbms_output.new_line; 
    dbms_output.new_line; 
    dbms_output.put_line('rec_cnt = ' || v_rec_cnt );
    dbms_output.new_line; 
end;
/
