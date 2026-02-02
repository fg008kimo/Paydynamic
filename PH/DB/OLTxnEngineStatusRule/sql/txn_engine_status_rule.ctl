load data
infile 'txn_engine_status_rule.txt'
append
into table ol_txn_engine_status_rule
fields terminated by '|'
(ESR_RULE_ID,
 ESR_STATUS,
 ESR_AR_IND,
 ESR_SUB_STATUS,
 ESR_RECON_STATUS,
 ESR_CLASSIFIED_STATUS,
 ESR_CREATE_USER,
 ESR_CREATE_TIMESTAMP SYSDATE,
 ESR_UPDATE_TIMESTAMP SYSDATE,
 ESR_UPDATE_USER
)
