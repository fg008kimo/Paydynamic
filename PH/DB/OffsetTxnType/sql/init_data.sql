


------------------------------------------
-- Add Data in the table "OFFSET_TXN_TYPE"
------------------------------------------
insert into offset_txn_type (
	ott_party_type, ott_txn_code, ott_desc, ott_amt_type, ott_bal_type, 
	ott_allow_modify, ott_allow_bal_negative, ott_nature,
	ott_disabled,
	ott_create_timestamp, ott_update_timestamp, ott_create_user, ott_update_user
)
values (
	'P', 'OFP', 'PSP Offset Frozen Processor Balance (-)', 'DR', 'B', 
	1, 1, 'V',
	0,
	sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

insert into offset_txn_type (
        ott_party_type, ott_txn_code, ott_desc, ott_amt_type, ott_bal_type, 
	ott_allow_modify, ott_allow_bal_negative, ott_nature,
	ott_disabled,
        ott_create_timestamp, ott_update_timestamp, ott_create_user, ott_update_user
)
values (
        'P', 'BDP', 'PSP Bad Debt (-)', 'DR', 'B', 
	1, 1, 'C',
	0,
        sysdate, sysdate, 'SYSTEM', 'SYSTEM'
);

