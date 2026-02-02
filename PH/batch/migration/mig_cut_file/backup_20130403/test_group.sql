set serveroutput on;
set feedback off;
set verify off;

declare
    v_date	VARCHAR2(8) := '&1';

    cursor c1 (v_req_date IN VARCHAR2) is
        select mp_mig_group, mn_username
        from par_def_merch_mig_period, par_def_merch_nmb_map
        where mn_mig_group = mp_mig_group
        and v_req_date between mp_start_date and mp_end_date
         order by mp_mig_group, mn_username;

begin

    for i in c1 (v_date) loop
        dbms_output.put_line(i.mp_mig_group || ' ' || i.mn_username);

    end loop;
exception
    when others then
	dbms_output.put_line('ERROR...');
end;
/
