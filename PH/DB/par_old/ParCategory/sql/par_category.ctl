load data
infile "par_category.txt"
append
into table par_category
fields terminated by '|'
(pc_sequence_type_name,
 pc_category,
 pc_txn_code,
 pc_reversal_txn_code,
 pc_create_timestamp SYSDATE,
 pc_create_user constant 'SYSTEM',
 pc_update_timestamp SYSDATE,
 pc_update_user constant 'SYSTEM'
)
