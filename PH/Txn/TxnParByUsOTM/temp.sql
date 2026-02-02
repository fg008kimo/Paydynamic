select * from txn_code where tc_code = 'MTO'

insert into txn_code (tc_code, tc_process_type, tc_process_code, tc_desc, 
                        tc_create_user, tc_create_timestamp, tc_update_user, tc_update_timestamp,
                        tc_voidable, tc_fe_display)
values ('OTM', '0000', '000000', 'Other System to Merchant Balance Transfer', 
        'SYSTEM', sysdate, 'SYSTEM', sysdate, 
        0, 1);
        
select * from txn_supported where ts_txn_code = 'MTO'

insert into txn_supported (ts_txn_code, ts_channel_code, ts_support,
                            ts_create_timestamp, ts_create_user, ts_update_timestamp, ts_update_user,
                            ts_do_logging, ts_to_mms_host, ts_init_txn)
values ('OTM', 'MGT', 1,
        sysdate, 'SYSTEM', sysdate, 'SYSTEM',
        1, 0, 0);
        
select * from channel_txn_map where ct_txn_code = 'MTO'

insert into channel_txn_map (ct_channel_code, ct_txn_code, ct_disabled,
                            ct_apply_fee, ct_apply_limit, ct_apply_reserve, ct_apply_ex_markup,
                            ct_create_user, ct_update_user, ct_create_timestamp, ct_update_timestamp)
values ('MGT', 'OTM', 0,
            1, 0, 0, 1, 
            'SYSTEM', 'SYSTEM', sysdate, sysdate);


select * from def_txn_status_map where dm_txn_code = 'MTO';

insert into def_txn_status_map (dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
select dm_type, dm_status, dm_ar_ind, 'OTM', dm_status_desc, 'SYSTEM', sysdate, 'SYSTEM', sysdate
from   def_txn_status_map where dm_txn_code = 'MTO';
