insert into txn_code (tc_code, tc_process_type, tc_process_code, tc_desc,
                        tc_create_user, tc_create_timestamp, tc_update_user, tc_update_timestamp,
                        tc_voidable, tc_fe_display)
values ('BTV', '0000', '000000', 'Balance Transfer Detail Preview',
        'SYSTEM', sysdate, 'SYSTEM', sysdate,
        0, 0);
        
insert into txn_supported (ts_txn_code, ts_channel_code, ts_support,
                            ts_create_timestamp, ts_create_user, ts_update_timestamp, ts_update_user,
                            ts_do_logging, ts_to_mms_host, ts_init_txn)
values ('BTV', 'MGT', 1,
        sysdate, 'SYSTEM', sysdate, 'SYSTEM',
        0, 0, 0);
