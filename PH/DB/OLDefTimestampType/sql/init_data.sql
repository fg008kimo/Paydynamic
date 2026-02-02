


insert all
into ol_def_timestamp_type (dtt_type, dtt_desc, dtt_create_timestamp, dtt_create_user, dtt_update_timestamp, dtt_update_user)
values ('CREATE', 'Create Timestamp', sysdate, 'SYSTEM', sysdate, 'SYSTEM')
into ol_def_timestamp_type (dtt_type, dtt_desc, dtt_create_timestamp, dtt_create_user, dtt_update_timestamp, dtt_update_user)
values ('STMT', 'Bank Statement Timestamp', sysdate, 'SYSTEM', sysdate, 'SYSTEM')
select * from dual;

