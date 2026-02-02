load data
infile 'bank_name_mapping_new.txt'
append
into table bank_name_mapping
fields terminated by '|'
(nm_in_bank_name,
 nm_out_bank_name,
 nm_out_bank_code,
 nm_disabled,
 nm_psp_channel_id,
 nm_create_timestamp SYSDATE,
 nm_update_timestamp SYSDATE,
 nm_create_user,
 nm_update_user
)
