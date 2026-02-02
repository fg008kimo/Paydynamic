-- Update Data from the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_ITM' and OLFK_INT_BANK_CODE = '086303'
UPDATE ol_stmt_format_keywords
SET olfk_format_template = '分行电子汇划费(对私)'
WHERE olfk_int_bank_code = '086303'
AND olfk_format_type = 'TXN_CODE_ITM'
AND olfk_format_value = 6
AND olfk_format_txn_code = 'CGB'
AND olfk_display_order = 1;

-- Insert Data into the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_ITM' and OLFK_INT_BANK_CODE = '086308'
INSERT INTO ol_stmt_format_keywords (olfk_int_bank_code, olfk_format_type,
olfk_format_value, olfk_format_txn_code, olfk_format_template,
olfk_format_col_name, olfk_display_order, olfk_disabled,
olfk_create_timestamp, olfk_create_user, olfk_update_timestamp,
olfk_update_user)
VALUES ('086308', 'TXN_CODE_ITM', 41, 'SNI', '客户转账', '说明 (part 1)', 20, 0, 
sysdate, 'SYSTEM', sysdate , 'SYSTEM');

