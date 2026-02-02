-- Delete Data from the table "OL_STMT_FORMAT_KEYWORDS"
-- OLFK_FORMAT_TYPE = 'TXN_CODE_ITM' and OLFK_INT_BANK_CODE = '086502'
DELETE FROM ol_stmt_format_keywords
WHERE olfk_int_bank_code = '086502'
AND olfk_format_type = 'TXN_CODE_ITM';
