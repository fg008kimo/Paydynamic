insert into def_balance_type (
bt_type, bt_desc, bt_party_type, bt_allow_adj, 
bt_create_timestamp, bt_update_timestamp, bt_create_user, bt_update_user
)
values (
'A', 'Available', 'P', 1, sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

insert into def_balance_type (
bt_type, bt_desc, bt_party_type, bt_allow_adj, 
bt_create_timestamp, bt_update_timestamp, bt_create_user, bt_update_user
)
values (
'P', 'Available for Payout', 'M', 1, sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

insert into def_balance_type (
bt_type, bt_desc, bt_party_type, bt_allow_adj, 
bt_create_timestamp, bt_update_timestamp, bt_create_user, bt_update_user
)
values (
'S', 'Available for Settlement', 'M', 1, sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);
