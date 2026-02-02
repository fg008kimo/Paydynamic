load data
infile *
append
into table ol_def_unknown_txncode 
fields terminated by '|'
(ouc_code,
 ouc_create_timestamp SYSDATE,
 ouc_update_timestamp SYSDATE,
 ouc_create_user,
 ouc_update_user
)
BEGINDATA
UBC|SYSTEM|SYSTEM
UBD|SYSTEM|SYSTEM
USI|SYSTEM|SYSTEM
USO|SYSTEM|SYSTEM
