


insert all
into ol_def_trigger_status (dts_status, dts_desc, dts_create_timestamp, dts_create_user, dts_update_timestamp, dts_update_user)
values ('I', 'Initiated', sysdate, 'SYSTEM', sysdate, 'SYSTEM')
into ol_def_trigger_status (dts_status, dts_desc, dts_create_timestamp, dts_create_user, dts_update_timestamp, dts_update_user)
values ('P', 'Processing', sysdate, 'SYSTEM', sysdate, 'SYSTEM')
into ol_def_trigger_status (dts_status, dts_desc, dts_create_timestamp, dts_create_user, dts_update_timestamp, dts_update_user)
values ('C', 'Completed', sysdate, 'SYSTEM', sysdate, 'SYSTEM')
select * from dual;

