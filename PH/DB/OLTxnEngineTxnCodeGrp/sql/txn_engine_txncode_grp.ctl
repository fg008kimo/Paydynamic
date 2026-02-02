load data
infile 'txn_engine_txncode_grp7.txt'
append
into table ol_txn_engine_txncode_grp 
fields terminated by '|'
(etg_txn_grp,
 etg_txn_code,
 etg_create_timestamp SYSDATE,
 etg_update_timestamp SYSDATE,
 etg_create_user,
 etg_update_user
)
