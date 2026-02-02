-- Update Data from the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_ITM' and OLFK_INT_BANK_CODE = '086302'
UPDATE ol_stmt_format_keywords
SET olfk_format_col_name = '摘要'
WHERE olfk_int_bank_code = '086302'
AND olfk_format_type = 'TXN_CODE_ITM';
