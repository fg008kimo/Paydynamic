insert into txn_supported (ts_txn_code, ts_channel_code, ts_support, 
                            ts_create_timestamp, ts_create_user, 
                            ts_update_timestamp, ts_update_user,
                            ts_do_logging, ts_to_mms_host, ts_init_txn)
values ('CTF', 'MGT', 1, 
            sysdate, 'SYSTEM',
            sysdate, 'SYSTEM',
            2, 0, 0);
