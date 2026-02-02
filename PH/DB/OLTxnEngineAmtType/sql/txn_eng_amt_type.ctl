load data
infile 'txn_eng_amt_type5.txt'
append
into table ol_txn_engine_amt_type
fields terminated by '|'
(OTAT_ACTIVITY,
 OTAT_BANK_STMT_TYPE,
 OTAT_CHANNEL,
 OTAT_TRIGGER_TYPE,
 OTAT_RECON_TYPE,
 OTAT_P1_AMT_TYPE,
 OTAT_P2_AMT_TYPE,
 otat_create_timestamp SYSDATE,
 otat_update_timestamp SYSDATE,
 otat_create_user,
 otat_update_user
)
