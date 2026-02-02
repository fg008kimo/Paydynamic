-- Insert txn_code into the table "TXN_CODE"
-- txn_code = 'VCB'
insert into txn_code (tc_code, tc_process_type, tc_process_code,
tc_desc, tc_create_user, tc_create_timestamp, tc_update_user,
tc_update_timestamp, tc_voidable, tc_fe_display, tc_merchant_fe_display,
tc_merchant_txn_display, tc_psp_txn_display, tc_ofl_fe_display,
tc_ofl_merchant_fe_display, tc_ofl_merchant_txn_display, tc_ofl_provider_txn_display,
tc_ofl_is_offset, tc_ofl_void_code, tc_ofl_is_void, tc_ofl_allow_cancel, tc_ofl_allow_fe_init)
values ('VCB', '0000', '000000', 'Returned Offline Bank Charges', 'SYSTEM',
sysdate, 'SYSTEM', sysdate, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 'XCB', 0, 1, 0);

-- txn_code = 'XCB'
insert into txn_code (tc_code, tc_process_type, tc_process_code,
tc_desc, tc_create_user, tc_create_timestamp, tc_update_user,
tc_update_timestamp, tc_voidable, tc_fe_display, tc_merchant_fe_display,
tc_merchant_txn_display, tc_psp_txn_display, tc_ofl_fe_display,
tc_ofl_merchant_fe_display, tc_ofl_merchant_txn_display, tc_ofl_provider_txn_display,
tc_ofl_is_offset, tc_ofl_void_code, tc_ofl_is_void, tc_ofl_allow_cancel, tc_ofl_allow_fe_init)
values ('XCB', '0000', '000000', 'Void Returned Offline Bank Charges', 'SYSTEM',
sysdate, 'SYSTEM', sysdate, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, '', 1, 0, 0);

-- Insert txn_code into the table "OL_BAID_TXN_CODE"
-- txn_code = 'VCB'
insert into ol_baid_txn_code (obtc_code, obtc_desc, obtc_voidable,
obtc_amt_type, obtc_void_code, obtc_create_timestamp, obtc_create_user,
obtc_update_timestamp, obtc_update_user)
values ('VCB', 'Returned Bank Charges', 1, 'CR', 'XCB', sysdate,
'SYSTEM', sysdate , 'SYSTEM');

-- txn_code = 'XCB'
insert into ol_baid_txn_code (obtc_code, obtc_desc, obtc_voidable,
obtc_amt_type, obtc_void_code, obtc_create_timestamp, obtc_create_user,
obtc_update_timestamp, obtc_update_user)
values ('XCB', 'Void - Returned Bank Charges', 0, 'DR', '', sysdate,
'SYSTEM', sysdate , 'SYSTEM');

-- Insert Data into the table "OL_BAID_TXN_CODE_MAPPING"
insert into ol_baid_txn_code_mapping (obtm_bank_acct_type, obtm_code,
obtm_range, obtm_keywords, obtm_default, obtm_priority, obtm_full_match,
obtm_hold_credit_side, obtm_real_time_post, obtm_update_bal,
obtm_create_timestamp, obtm_create_user, obtm_update_timestamp,
obtm_update_user)
values ('ITM', 'VCB', 0, 1, 0, 2, 1, 0, 1, 0, sysdate, 'SYSTEM',
sysdate , 'SYSTEM');

-- Insert txn_code into the table "DEF_TXN_SUB_STATUS_MAP"
-- txn_code = 'VCB'
insert into def_txn_sub_status_map (dsm_txn_code, dsm_sub_status,
dsm_create_user, dsm_create_timestamp, dsm_update_user, dsm_update_timestamp)
values ('VCB', '130', 'SYSTEM', sysdate, 'SYSTEM', sysdate);

-- txn_code = 'XCB'
insert into def_txn_sub_status_map (dsm_txn_code, dsm_sub_status,
dsm_create_user, dsm_create_timestamp, dsm_update_user, dsm_update_timestamp)
values ('XCB', '118', 'SYSTEM', sysdate, 'SYSTEM', sysdate);

