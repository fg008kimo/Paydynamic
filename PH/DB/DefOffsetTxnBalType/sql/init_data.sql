


--------------------------------------------------
-- Add Data in the table "DEF_OFFSET_TXN_BAL_TYPE"
--------------------------------------------------
insert into def_offset_txn_bal_type (
        otbt_type, otbt_desc, otbt_party_type,
        otbt_create_timestamp, otbt_update_timestamp, otbt_create_user, otbt_update_user
)
values (
        'M', 'Merchant Balance', 'M', sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

insert into def_offset_txn_bal_type (
        otbt_type, otbt_desc, otbt_party_type,
        otbt_create_timestamp, otbt_update_timestamp, otbt_create_user, otbt_update_user
)
values (
        'S', 'Merchant Settlement Balance', 'M', sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

insert into def_offset_txn_bal_type (
	otbt_type, otbt_desc, otbt_party_type,
	otbt_create_timestamp, otbt_update_timestamp, otbt_create_user, otbt_update_user
)
values (
	'B', 'PSP Balance', 'P', sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

insert into def_offset_txn_bal_type (
        otbt_type, otbt_desc, otbt_party_type, 
        otbt_create_timestamp, otbt_update_timestamp, otbt_create_user, otbt_update_user
)
values (
        'F', 'PSP Float', 'P', sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

