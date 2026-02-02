load data
infile  *
append
into table ol_pf_txn_init_code
fields terminated by '|'
(opic_txn_code,
 opic_amt_type,
 opic_create_timestamp SYSDATE,
 opic_update_timestamp SYSDATE,
 opic_create_user,
 opic_update_user
)
BEGINDATA
OSF|DR|SYSTEM|SYSTEM
APF|DR|SYSTEM|SYSTEM
MRO|CR|SYSTEM|SYSTEM
MWO|DR|SYSTEM|SYSTEM
MWI|CR|SYSTEM|SYSTEM
MIO|CR|SYSTEM|SYSTEM
MPA|DR|SYSTEM|SYSTEM
MPC|DR|SYSTEM|SYSTEM
