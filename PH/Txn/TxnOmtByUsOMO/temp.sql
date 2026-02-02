insert into txn_code (tc_code, tc_process_type, tc_process_code, tc_desc, 
                        tc_create_user, tc_create_timestamp, tc_update_user, tc_update_timestamp,
                        tc_voidable, 
                        tc_fe_display, tc_merchant_fe_display, 
                        tc_merchant_txn_display, tc_psp_txn_display,
                        tc_ofl_fe_display, tc_ofl_merchant_fe_display, 
                        tc_ofl_merchant_txn_display, tc_ofl_provider_txn_display)
values ('OMO', '0000', '000000', 'Offline Balance Transfer Out - Inter Settlement', 
        'SYSTEM', sysdate, 'SYSTEM', sysdate, 
        0, 
        0, 0, 0, 0,
	1, 1, 1, 1);


        
insert into txn_supported (ts_txn_code, ts_channel_code, ts_support,
                            ts_create_timestamp, ts_create_user, ts_update_timestamp, ts_update_user,
                            ts_do_logging, ts_to_mms_host, ts_init_txn)
values ('OMO', 'OMT', 1,
        sysdate, 'SYSTEM', sysdate, 'SYSTEM',
        1, 0, 0);
        

insert into channel_txn_map (ct_channel_code, ct_txn_code, ct_disabled,
                            ct_apply_fee, ct_apply_limit, ct_apply_reserve, ct_apply_ex_markup,
                            ct_create_user, ct_update_user, ct_create_timestamp, ct_update_timestamp)
values ('OMT', 'OMO', 0,
            1, 0, 0, 0, 
            'SYSTEM', 'SYSTEM', sysdate, sysdate);


insert into def_txn_status_map (
	dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
	dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
	'A', 'C', 'A', 'OMO', 'Approved', 
	'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
	dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
	dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
	'A', 'C', 'R', 'OMO', 'Declined', 
	'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
	dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
	dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
	'A', 'P', ' ', 'OMO', 'Pending', 
	'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
	dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
	dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
	'A', 'R', 'A', 'OMO', 'Approved', 
	'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
	dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
	dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
	'A', 'W', ' ', 'OMO', 'Pending', 
	'SYSTEM', sysdate, 'SYSTEM', sysdate);
--------------

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc, 
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'C', 'A', 'OMO', 'Approved',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'C', 'R', 'OMO', 'Declined',       
        'SYSTEM', sysdate, 'SYSTEM', sysdate);  

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'P', ' ', 'OMO', 'Pending',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'R', 'A', 'OMO', 'Approved',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

insert into def_txn_status_map (
        dm_type, dm_status, dm_ar_ind, dm_txn_code, dm_status_desc,
        dm_create_user, dm_create_timestamp, dm_update_user, dm_update_timestamp)
values (
        'M', 'W', ' ', 'OMO', 'Pending',
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

------------

insert into system_parameter (sp_code, sp_desc, sp_val, sp_deletable, 
	sp_create_user, sp_create_timestamp, sp_update_user, sp_update_timestamp)
values ('OFL_BAL_TRF_AVAI_SETT', 'Offline Balance Transfer Out - Inter Settlement by Available Settlement', 'N', 0, 
        'SYSTEM', sysdate, 'SYSTEM', sysdate);

