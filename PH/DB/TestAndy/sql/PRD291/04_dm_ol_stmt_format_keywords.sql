


insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'OTC', '汇款汇入', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'OTC'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'OTC', '转账', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'OTC'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'OTC', '转账转入', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'OTC'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'OTD', '汇款汇出', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'OTD'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'CGB', '转账手续费', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'CGB'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'CGB', '收费', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'CGB'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'CGB', '精灵信使服务费', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'CGB'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'OBI', '存息', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'OBI'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'OBI', '存款利息', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'OBI'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'SUD', '汇款汇出', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'SUD'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'VUD', '调整', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'VUD'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'VCB', '当日冲账', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'VCB'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'OBD', '汇款汇入', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'OBD'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'OBD', '转账', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'OBD'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

insert into ol_stmt_format_keywords(olfk_int_bank_code, olfk_format_type, olfk_format_value, olfk_format_txn_code, olfk_format_template, olfk_format_col_name, olfk_display_order, olfk_disabled, olfk_create_timestamp, olfk_create_user, olfk_update_timestamp, olfk_update_user)
values ('086309', 'TXN_CODE_DSI',
(select nvl(max(olfk_format_value), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI'),
'OBD', '转账转入', '摘要',
(select nvl(max(olfk_display_order), 0) + 1 from ol_stmt_format_keywords where olfk_int_bank_code = '086309' and olfk_format_type = 'TXN_CODE_DSI' and olfk_format_txn_code = 'OBD'),
0, sysdate, 'SYSTEM', sysdate, 'SYSTEM'
);

