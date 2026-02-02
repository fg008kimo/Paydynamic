load data
infile 'txn_engine_txncode_map11.txt'
append
into table ol_txn_engine_txncode_map 
fields terminated by '|'
(etm_action_detail_id,
 etm_fr_acct_type,
 etm_to_acct_type,
 etm_org_txn_code,
 etm_new_txn_code,
 etm_create_timestamp SYSDATE,
 etm_update_timestamp SYSDATE,
 etm_create_user,
 etm_update_user
)
