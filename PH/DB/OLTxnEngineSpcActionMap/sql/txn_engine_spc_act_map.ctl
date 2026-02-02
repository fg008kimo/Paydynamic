load data
infile 'txn_engine_spc_act_map5.txt'
append
into table ol_txn_engine_spc_act_map 
fields terminated by '|'
(esam_special_action_id,
 esam_seq,
 esam_special_action_detail_id,
 esam_create_timestamp SYSDATE,
 esam_update_timestamp SYSDATE,
 esam_create_user,
 esam_update_user
)
