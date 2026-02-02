load data
infile 'txn_engine_spc_act_def.txt'
append
into table ol_txn_engine_spc_act_def
fields terminated by '|'
(ESAD_SPECIAL_ACTION_DETAIL_ID,
 ESAD_SPECIAL_ACTION_DESC,
 ESAD_RETURNED_TAG,
 ESAD_RETURNED_VALUE,
 ESAD_CREATE_TIMESTAMP SYSDATE,
 ESAD_UPDATE_TIMESTAMP SYSDATE,
 ESAD_CREATE_USER,
 ESAD_UPDATE_USER
)
