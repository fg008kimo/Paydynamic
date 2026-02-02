load data
infile 'txn_engine_baid7.txt' 
append
into table ol_txn_engine_baid_nature
fields terminated by '|'
(OTE_ACTIVITY,
 OTE_BANK_STMT_TYPE,
 OTE_CHANNEL,
 OTE_TRIGGER_TYPE,
 OTE_BAID_NATURE,
 OTE_BAID_CATEGORY,
 ote_party_type,
 ote_create_timestamp SYSDATE,
 ote_update_timestamp SYSDATE,
 ote_create_user,
 ote_update_user
)
