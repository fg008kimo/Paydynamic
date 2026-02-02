insert into txn_code (tc_code, tc_process_type, tc_process_code, tc_desc, 
                        tc_create_user, tc_create_timestamp, tc_update_user, tc_update_timestamp,
                        tc_voidable, 
                        tc_fe_display, tc_merchant_fe_display, 
                        tc_merchant_txn_display, tc_psp_txn_display,
                        tc_ofl_fe_display, tc_ofl_merchant_fe_display, 
                        tc_ofl_merchant_txn_display, tc_ofl_provider_txn_display)
values ('OTF', '0000', '000000', 'Offline Balance Transfer Out - Intra Settlement', 
        'SYSTEM', sysdate, 'SYSTEM', sysdate, 
        0, 
        0, 0, 0, 0,
	1, 1, 1, 0);

insert into txn_code (tc_code, tc_process_type, tc_process_code, tc_desc, 
                        tc_create_user, tc_create_timestamp, tc_update_user, tc_update_timestamp,
                        tc_voidable, 
                        tc_fe_display, tc_merchant_fe_display, 
                        tc_merchant_txn_display, tc_psp_txn_display,
                        tc_ofl_fe_display, tc_ofl_merchant_fe_display, 
                        tc_ofl_merchant_txn_display, tc_ofl_provider_txn_display)
values ('OTT', '0000', '000000', 'Offline Balance Transfer In - Intra Settlement', 
        'SYSTEM', sysdate, 'SYSTEM', sysdate, 
        0, 
        0, 0, 0, 0,
	1, 1, 1, 0);

-----------------------------------------------------------------------------------------        
insert into txn_supported (ts_txn_code, ts_channel_code, ts_support,
                            ts_create_timestamp, ts_create_user, ts_update_timestamp, ts_update_user,
                            ts_do_logging, ts_to_mms_host, ts_init_txn)
values ('OTF', 'OMT', 1,
        sysdate, 'SYSTEM', sysdate, 'SYSTEM',
        1, 0, 0);
        
-----------------------------------------------------------------------------------------        

insert into channel_txn_map (ct_channel_code, ct_txn_code, ct_disabled,
                            ct_apply_fee, ct_apply_limit, ct_apply_reserve, ct_apply_ex_markup,
                            ct_create_user, ct_update_user, ct_create_timestamp, ct_update_timestamp)
values ('OMT', 'OTF', 0,
            1, 0, 0, 0, 
            'SYSTEM', 'SYSTEM', sysdate, sysdate);

insert into channel_txn_map (ct_channel_code, ct_txn_code, ct_disabled,
                            ct_apply_fee, ct_apply_limit, ct_apply_reserve, ct_apply_ex_markup,
                            ct_create_user, ct_update_user, ct_create_timestamp, ct_update_timestamp)
values ('OMT', 'OTT', 0,
            0, 0, 0, 1, 
            'SYSTEM', 'SYSTEM', sysdate, sysdate);


-----------------------------------------------------------------------------------------        

insert into def_txn_status_map (
	dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
	dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
	'A', 'C', 'A', 'OTF', 'Approved', 
	'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
	dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
	dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
	'A', 'C', 'R', 'OTF', 'Declined', 
	'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
	dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
	dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
	'A', 'P', ' ', 'OTF', 'Pending', 
	'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
	dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
	dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
	'A', 'R', 'A', 'OTF', 'Approved', 
	'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
	dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
	dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
	'A', 'W', ' ', 'OTF', 'Pending', 
	'SYSTEM', sysdate, 'SYSTEM', sysdate);
--------------

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'C', 'A', 'OTF', 'Approved',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'C', 'R', 'OTF', 'Declined',       
        'SYSTEM', sysdate, 'SYSTEM', sysdate);  

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'P', ' ', 'OTF', 'Pending',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'R', 'A', 'OTF', 'Approved',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'W', ' ', 'OTF', 'Pending',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

------------

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'A', 'C', 'A', 'OTT', 'Approved',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'A', 'C', 'R', 'OTT', 'Declined',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'A', 'P', ' ', 'OTT', 'Pending',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'A', 'R', 'A', 'OTT', 'Approved',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'A', 'W', ' ', 'OTT', 'Pending',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

--------------

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'C', 'A', 'OTT', 'Approved',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'C', 'R', 'OTT', 'Declined',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'P', ' ', 'OTT', 'Pending',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'R', 'A', 'OTT', 'Approved',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'W', ' ', 'OTT', 'Pending',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);



-----------------------------------------------------------------------------------------        


insert into system_ex_rules (
	sr_txn_code, sr_none_restricted, sr_restricted_1, sr_restricted_2, sr_res1_res2_opr, sr_markup_amt_opr,
        sr_create_timestamp, sr_update_timestamp, sr_create_user, sr_update_user)
select 'OTT', sr_none_restricted, sr_restricted_1, sr_restricted_2, sr_res1_res2_opr, sr_markup_amt_opr,
    sysdate, sysdate, 'SYSTEM', 'SYSTEM'
from system_ex_rules
where sr_txn_code = 'TFT';





