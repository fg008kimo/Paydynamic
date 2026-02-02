
update psp_param_check
set pc_init_req = 1,
    pc_update_timestamp = sysdate
where pc_psp_channel in (
	'TWV',
	'FEP',
	'TPM',
	'PGN',
	'XJP',
	'CPE',
	'GPV'
);


update psp_param_check
set pc_qr_code = 1,
    pc_init_req = 1,
    pc_update_timestamp = sysdate
where pc_psp_channel in (
	'WCP',
	'AWC',
	'NTW',
	'XJW',
	'UNW',
	'XJQ',
	'DPQ',
	'SKQ',
	'HXQ',
	'RFQ',
	'SFQ',
	'BFQ',
	'COQ',
	'ESQ',
	'TTQ',
	'ZPQ',
	'SPQ',
	'DFQ',
	'XDQ',
	'XJR',
	'NEQ',
	'XPQ',
	'UNQ',
	'TPQ',
	'XYQ',
	'OUQ'
);
