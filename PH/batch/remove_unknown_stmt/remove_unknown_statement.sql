set serveroutput on;
set verify off;

declare
    v_file_id ol_statement_header.olsh_file_id%type;

begin

    for i in (select olsh_file_id from ol_statement_header
              where olsh_create_timestamp >= to_date('20150709 103000','yyyymmdd hh24miss')
              and olsh_create_timestamp < to_date('20150710 000000','yyyymmdd hh24miss')
              and olsh_create_user = 'SYSTEM'
              and olsh_status = 'A'
              and olsh_bank_acct_num in (select bank_acct_num from ol_remove_mass_upd_stmt_list)
              and olsh_bank_acct_num not in ('6212261202021053872',
                                             '6212261202021785622',
                                             '6212262002007173408',
                                             '6212262002007173416',
                                             '6212262013009362576',
                                             '6217002000025577869',
                                             '6217002000025577877',
                                             '6217003110009875111',
                                             '6217711301050876',
                                             '6217711301051197',
                                             '6217711301051205',
                                             '6228480078096288671',
                                             '6228480119640867873',
                                             '6228480119640867972',
                                             '622908398060995315',
                                             '622908398061862217',
                                             '6236683090000154293',
                                             '6236683090000154327')) loop

        -- .... need to check before if any not unknown .... --
        v_file_id := i.olsh_file_id;

dbms_output.put_line('v_file_id [' || v_file_id);

        for j in (select olsd_stat_txn_id
                  from  ol_statement_detail
                  where olsd_file_id = v_file_id) loop

dbms_output.put_line('stat_txn_id [' || j.olsd_stat_txn_id);

--              select * from ol_statement_detail where olsd_stat_txn_id = j.olsd_stat_txn_id;
--            delete from ol_statement_detail where olsd_stat_txn_id = j.olsd_stat_txn_id;
--dbms_output.put_line('ol_statement_detail del [' || j.olsd_stat_txn_id || '] sql%rowcount [' || sql%rowcount || ']');

--              select * from ol_baid_txn where obt_stat_txn_id = j.olsd_stat_txn_id;
--            delete from ol_baid_txn where obt_stat_txn_id = j.olsd_stat_txn_id;
--dbms_output.put_line('ol_baid_txn del [' || j.olsd_stat_txn_id || '] sql%rowcount [' || sql%rowcount || ']');

        end loop;

--          select * from ol_statement_header where olsh_file_id = v_file_id;
--        delete from ol_statement_header where olsh_file_id = v_file_id;
--dbms_output.put_line('ol_statement_header del [' || v_file_id || '] [' || sql%rowcount || ']');

    end loop;

end;
/
