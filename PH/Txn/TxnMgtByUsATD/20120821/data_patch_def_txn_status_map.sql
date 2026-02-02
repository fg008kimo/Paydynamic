declare

    cursor cur_code_list is 
        select at_code
        from adjustment_type
        where not exists (select 1
                          from def_txn_status_map
                          where dm_txn_code = at_code
                         )
        order by at_code;

    v_void_code  adjustment_type.at_code%type;

begin

    for i in cur_code_list loop
        v_void_code := NULL;

	select decode(substr(i.at_code, 1, 1), 'm', 'y', 'p', 'x', NULL) || substr(i.at_code, 2)
        into v_void_code
        from dual;
    
        dbms_output.put_line('i.at_code = [' || i.at_code || '] void_code = [' || v_void_code || ']');
       
        ----------
        insert into def_txn_status_map(DM_TYPE, DM_STATUS, DM_AR_IND, DM_TXN_CODE, DM_STATUS_DESC, 
                                       DM_CREATE_USER,  DM_CREATE_TIMESTAMP,  DM_UPDATE_USER, DM_UPDATE_TIMESTAMP)
        values ('A', 'C', 'A', i.at_code, 'Approved', 'SYSTEM', sysdate, 'SYSTEM', sysdate);

        insert into def_txn_status_map(DM_TYPE, DM_STATUS, DM_AR_IND, DM_TXN_CODE, DM_STATUS_DESC, 
                                       DM_CREATE_USER,  DM_CREATE_TIMESTAMP,  DM_UPDATE_USER, DM_UPDATE_TIMESTAMP)
        values ('M', 'C', 'A', i.at_code, 'Approved', 'SYSTEM', sysdate, 'SYSTEM', sysdate);

        insert into def_txn_status_map(DM_TYPE, DM_STATUS, DM_AR_IND, DM_TXN_CODE, DM_STATUS_DESC, 
                                       DM_CREATE_USER,  DM_CREATE_TIMESTAMP,  DM_UPDATE_USER, DM_UPDATE_TIMESTAMP)
        values ('A', 'C', 'A', v_void_code, 'Approved', 'SYSTEM', sysdate, 'SYSTEM', sysdate);

        insert into def_txn_status_map(DM_TYPE, DM_STATUS, DM_AR_IND, DM_TXN_CODE, DM_STATUS_DESC, 
                                       DM_CREATE_USER,  DM_CREATE_TIMESTAMP,  DM_UPDATE_USER, DM_UPDATE_TIMESTAMP)
        values ('M', 'C', 'A', v_void_code, 'Approved', 'SYSTEM', sysdate, 'SYSTEM', sysdate);
        ----------
        insert into def_txn_status_map(DM_TYPE, DM_STATUS, DM_AR_IND, DM_TXN_CODE, DM_STATUS_DESC, 
                                       DM_CREATE_USER,  DM_CREATE_TIMESTAMP,  DM_UPDATE_USER, DM_UPDATE_TIMESTAMP)
        values ('A', 'C', 'R', i.at_code, 'Declined', 'SYSTEM', sysdate, 'SYSTEM', sysdate);

        insert into def_txn_status_map(DM_TYPE, DM_STATUS, DM_AR_IND, DM_TXN_CODE, DM_STATUS_DESC, 
                                       DM_CREATE_USER,  DM_CREATE_TIMESTAMP,  DM_UPDATE_USER, DM_UPDATE_TIMESTAMP)
        values ('M', 'C', 'R', i.at_code, 'Declined', 'SYSTEM', sysdate, 'SYSTEM', sysdate);

        insert into def_txn_status_map(DM_TYPE, DM_STATUS, DM_AR_IND, DM_TXN_CODE, DM_STATUS_DESC, 
                                       DM_CREATE_USER,  DM_CREATE_TIMESTAMP,  DM_UPDATE_USER, DM_UPDATE_TIMESTAMP)
        values ('A', 'C', 'R', v_void_code, 'Declined', 'SYSTEM', sysdate, 'SYSTEM', sysdate);

        insert into def_txn_status_map(DM_TYPE, DM_STATUS, DM_AR_IND, DM_TXN_CODE, DM_STATUS_DESC, 
                                       DM_CREATE_USER,  DM_CREATE_TIMESTAMP,  DM_UPDATE_USER, DM_UPDATE_TIMESTAMP)
        values ('M', 'C', 'R', v_void_code, 'Declined', 'SYSTEM', sysdate, 'SYSTEM', sysdate);
        ----------

        insert into def_txn_status_map(DM_TYPE, DM_STATUS, DM_AR_IND, DM_TXN_CODE, DM_STATUS_DESC, 
                                       DM_CREATE_USER,  DM_CREATE_TIMESTAMP,  DM_UPDATE_USER, DM_UPDATE_TIMESTAMP)
        values ('A', 'R', 'A', i.at_code, 'Approved', 'SYSTEM', sysdate, 'SYSTEM', sysdate);

        insert into def_txn_status_map(DM_TYPE, DM_STATUS, DM_AR_IND, DM_TXN_CODE, DM_STATUS_DESC, 
                                       DM_CREATE_USER,  DM_CREATE_TIMESTAMP,  DM_UPDATE_USER, DM_UPDATE_TIMESTAMP)
        values ('M', 'R', 'A', i.at_code, 'Approved', 'SYSTEM', sysdate, 'SYSTEM', sysdate);
	

    
    end loop;

end;


