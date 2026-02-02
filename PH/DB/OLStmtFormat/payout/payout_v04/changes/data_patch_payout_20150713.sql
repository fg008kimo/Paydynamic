-- Update Data from the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_POA' and OLFK_INT_BANK_CODE = '086303'
UPDATE ol_stmt_format_keywords
SET olfk_format_template = '分行电子汇划费(对私)'
WHERE olfk_int_bank_code = '086303'
AND olfk_format_type = 'TXN_CODE_POA'
AND olfk_format_value = 8
AND olfk_format_txn_code = 'CGB'
AND olfk_display_order = 1;

-- Insert Data into the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_POA' and OLFK_INT_BANK_CODE = '086308'
INSERT INTO ol_stmt_format_keywords (olfk_int_bank_code, olfk_format_type,
olfk_format_value, olfk_format_txn_code, olfk_format_template,
olfk_format_col_name, olfk_display_order, olfk_disabled,
olfk_create_timestamp, olfk_create_user, olfk_update_timestamp,
olfk_update_user)
VALUES ('086308', 'TXN_CODE_POA', 40, 'SNP', '客户转账', '说明 (part 1)', 14, 0, 
sysdate, 'SYSTEM', sysdate , 'SYSTEM');

-- Insert Data into the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_POA' and OLFK_INT_BANK_CODE = '086308'
INSERT INTO ol_stmt_format_keywords (olfk_int_bank_code, olfk_format_type,
olfk_format_value, olfk_format_txn_code, olfk_format_template,
olfk_format_col_name, olfk_display_order, olfk_disabled,
olfk_create_timestamp, olfk_create_user, olfk_update_timestamp,
olfk_update_user)
VALUES ('086308', 'TXN_CODE_POA', 41, 'SUP', '本行ATM取款', '说明', 6, 0,
sysdate, 'SYSTEM', sysdate , 'SYSTEM');

-- Insert Data into the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_POA' and OLFK_INT_BANK_CODE = '086103'
INSERT INTO ol_stmt_format_keywords (olfk_int_bank_code, olfk_format_type,
olfk_format_value, olfk_format_txn_code, olfk_format_template,
olfk_format_col_name, olfk_display_order, olfk_disabled,
olfk_create_timestamp, olfk_create_user, olfk_update_timestamp,
olfk_update_user)
VALUES ('086103', 'TXN_CODE_POA', 45, 'SUP', '消费', '交易摘要', 6, 0,
sysdate, 'SYSTEM', sysdate , 'SYSTEM');

-- Insert Data into the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_POA' and OLFK_INT_BANK_CODE = '086301'
INSERT INTO ol_stmt_format_keywords (olfk_int_bank_code, olfk_format_type,
olfk_format_value, olfk_format_txn_code, olfk_format_template,
olfk_format_col_name, olfk_display_order, olfk_disabled,
olfk_create_timestamp, olfk_create_user, olfk_update_timestamp,
olfk_update_user)
VALUES ('086301', 'TXN_CODE_POA', 48, 'SUP', '网上银行卡转出', '交易方式', 7, 0,
sysdate, 'SYSTEM', sysdate , 'SYSTEM');

-- Insert Data into the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_POA' and OLFK_INT_BANK_CODE = '086301'
INSERT INTO ol_stmt_format_keywords (olfk_int_bank_code, olfk_format_type,
olfk_format_value, olfk_format_txn_code, olfk_format_template,
olfk_format_col_name, olfk_display_order, olfk_disabled,
olfk_create_timestamp, olfk_create_user, olfk_update_timestamp,
olfk_update_user)
VALUES ('086301', 'TXN_CODE_POA', 49, 'SUP', '同城跨行网银转账', '交易方式', 8, 0,
sysdate, 'SYSTEM', sysdate , 'SYSTEM');

-- Insert Data into the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_POA' and OLFK_INT_BANK_CODE = '086301'
INSERT INTO ol_stmt_format_keywords (olfk_int_bank_code, olfk_format_type,
olfk_format_value, olfk_format_txn_code, olfk_format_template,
olfk_format_col_name, olfk_display_order, olfk_disabled,
olfk_create_timestamp, olfk_create_user, olfk_update_timestamp,
olfk_update_user)
VALUES ('086301', 'TXN_CODE_POA', 50, 'SUP', '转账汇款', '交易方式', 9, 0,
sysdate, 'SYSTEM', sysdate , 'SYSTEM');

-- Insert Data into the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_POA' and OLFK_INT_BANK_CODE = '086301'
INSERT INTO ol_stmt_format_keywords (olfk_int_bank_code, olfk_format_type,
olfk_format_value, olfk_format_txn_code, olfk_format_template,
olfk_format_col_name, olfk_display_order, olfk_disabled,
olfk_create_timestamp, olfk_create_user, olfk_update_timestamp,
olfk_update_user)
VALUES ('086301', 'TXN_CODE_POA', 51, 'SUP', '同城跨行取现', '交易方式', 10, 0,
sysdate, 'SYSTEM', sysdate , 'SYSTEM');

-- Insert Data into the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_POA' and OLFK_INT_BANK_CODE = '086301'
INSERT INTO ol_stmt_format_keywords (olfk_int_bank_code, olfk_format_type,
olfk_format_value, olfk_format_txn_code, olfk_format_template,
olfk_format_col_name, olfk_display_order, olfk_disabled,
olfk_create_timestamp, olfk_create_user, olfk_update_timestamp,
olfk_update_user)
VALUES ('086301', 'TXN_CODE_POA', 52, 'SUP', '信用卡转账还款', '交易方式', 11, 0,
sysdate, 'SYSTEM', sysdate , 'SYSTEM');

