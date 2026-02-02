-----------------------------------------------
--Add Data into the table "MI_DEF_BALANCE_TYPE"
-----------------------------------------------
--Balance Type: Available
insert into mi_def_balance_type (
mbt_type, mbt_desc, mbt_allow_adj, 
mbt_create_timestamp, mbt_update_timestamp, mbt_create_user, mbt_update_user
)
values (
'A', 'Available', 1, sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

--Balance Type: Intransit
insert into mi_def_balance_type (
mbt_type, mbt_desc, mbt_allow_adj, 
mbt_create_timestamp, mbt_update_timestamp, mbt_create_user, mbt_update_user
)
values (
'I', 'Intransit', 1, sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

--Balance Type: Overpaid/Underpaid
insert into mi_def_balance_type (
mbt_type, mbt_desc, mbt_allow_adj, 
mbt_create_timestamp, mbt_update_timestamp, mbt_create_user, mbt_update_user
)
values (
'D', 'Overpaid/Underpaid', 1, sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);
