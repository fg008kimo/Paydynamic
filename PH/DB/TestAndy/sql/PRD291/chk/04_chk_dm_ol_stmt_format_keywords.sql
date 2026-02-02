


select olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled
from ol_stmt_format_keywords
where olfk_int_bank_code = '086309'
and olfk_format_type = 'TXN_CODE_DSI'
order by olfk_int_bank_code, olfk_format_type, olfk_format_value;

