


--------------------------------------------------------
-- Add Data into the table "PSP_TXN_CHECK_RPT_PARAMETER"
--------------------------------------------------------
--Report Type: Psp Performance
insert into psp_txn_check_rpt_parameter (
        pc_rpt_type, pc_code, 
	pc_desc, pc_val,
        pc_create_user, pc_create_timestamp, pc_update_user, pc_update_timestamp
)
values (
	'PSP_PERFORMANCE', 'SHOW',
	'Show this section', '1',
        'SYSTEM', sysdate, 'SYSTEM', sysdate
);

insert into psp_txn_check_rpt_parameter (
        pc_rpt_type, pc_code, 
        pc_desc, pc_val,
        pc_create_user, pc_create_timestamp, pc_update_user, pc_update_timestamp
)
values (
        'PSP_PERFORMANCE', 'EXACT_CNT_VALUE',
        'Exact Counter Value', '1',
        'SYSTEM', sysdate, 'SYSTEM', sysdate
);

--Report Type: Psp Performance By Bank
insert into psp_txn_check_rpt_parameter (
        pc_rpt_type, pc_code, 
        pc_desc, pc_val,
        pc_create_user, pc_create_timestamp, pc_update_user, pc_update_timestamp
)
values (
        'PSP_PERFORMANCE_BY_BANK', 'SHOW',
        'Show this section', '1',
        'SYSTEM', sysdate, 'SYSTEM', sysdate
);

insert into psp_txn_check_rpt_parameter (
        pc_rpt_type, pc_code,
        pc_desc, pc_val,
        pc_create_user, pc_create_timestamp, pc_update_user, pc_update_timestamp
)
values (
        'PSP_PERFORMANCE_BY_BANK', 'EXACT_CNT_VALUE',
        'Exact Counter Value', '1',
        'SYSTEM', sysdate, 'SYSTEM', sysdate
);

