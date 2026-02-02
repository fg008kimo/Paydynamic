----------------------------------------------
--Add Data into the table "MI_DEF_ENTITY_TYPE"
----------------------------------------------
--Entity Type: RSP
insert into mi_def_entity_type (
et_type_code, et_type_desc, et_adj_bal_pool_option, 
et_create_timestamp, et_update_timestamp, et_create_user, et_update_user
)
values (
'RSP', 'RSP', 1, sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

--Entity Type: OPB
insert into mi_def_entity_type (
et_type_code, et_type_desc, et_adj_bal_pool_option,
et_create_timestamp, et_update_timestamp, et_create_user, et_update_user
)
values (
'OPB', 'OP Bank', 0, sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

--Entity Type: PIT
insert into mi_def_entity_type (
et_type_code, et_type_desc, et_adj_bal_pool_option,
et_create_timestamp, et_update_timestamp, et_create_user, et_update_user
)
values (
'PIT', 'PSP In-transit', 0, sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);
