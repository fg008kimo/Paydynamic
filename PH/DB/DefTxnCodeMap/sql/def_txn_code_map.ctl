load data
infile *
append
into table def_txn_code_map
fields terminated by '|'
(tcm_from_code,
 tcm_to_code,
 tcm_create_timestamp SYSDATE,
 tcm_update_timestamp SYSDATE,
 tcm_create_user,
 tcm_update_user
)
BEGINDATA
ODI|ODI|SYSTEM|SYSTEM|
ODT|ODI|SYSTEM|SYSTEM|
