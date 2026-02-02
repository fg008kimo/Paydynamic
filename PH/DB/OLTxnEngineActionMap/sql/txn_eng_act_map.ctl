load data
infile 'txn_eng_act_map15.txt'
append
into table ol_txn_engine_action_map
fields terminated by '|'
(eam_action_id,
 eam_action_desc,
 eam_action_seq,
 eam_action_detail_id,
 eam_spc_action,
 eam_before_status_rule,
 eam_linkage,
 eam_create_timestamp SYSDATE,
 eam_update_timestamp SYSDATE,
 eam_create_user,
 eam_update_user
)
