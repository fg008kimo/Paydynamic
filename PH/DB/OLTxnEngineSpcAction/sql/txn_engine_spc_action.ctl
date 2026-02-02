load data
infile 'txn_engine_spc_action.txt'
append
into table ol_txn_engine_spc_action
fields terminated by '|'
(esa_special_action_detail_id,
 esa_seq,
 ESA_P1_CHECK_TAG,
 ESA_P2_CHECK_TAG,
 ESA_COMPARE_OPERATOR,
 ESA_EXPECTED_VALUE,
 ESA_CHECK_TYPE,
 ESA_RETURNED_TAG,
 ESA_RETURNED_VALUE,
 ESA_RETURNED_FUNCT,
 ESA_RETURNED_TYPE,
 ESA_TERMINATE_WHEN_ERROR,
 esa_create_timestamp SYSDATE,
 esa_update_timestamp SYSDATE,
 esa_create_user,
 esa_update_user
)
