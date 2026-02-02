load data
infile 'txn_eng_act_list8.txt'
append
into table ol_txn_engine_action_list 
fields terminated by '|'
(eal_action_detail_id,
 eal_action_desc,
 eal_action_type,
 eal_action_level,
 eal_after_status_rule,
 eal_bal_rule,
 eal_txn_amt_tag,
 eal_create_timestamp SYSDATE,
 eal_update_timestamp SYSDATE,
 eal_create_user,
 eal_update_user
)
