load data
infile 'bank_name_mapping2.txt'
append
into table bank_name_mapping
fields terminated by '|'
(nm_psp_channel_id,
 nm_in_bank_name,
 nm_out_bank_name,
 nm_disabled,
 nm_create_timestamp SYSDATE,
 nm_update_timestamp SYSDATE,
 nm_create_user,
 nm_update_user
)
