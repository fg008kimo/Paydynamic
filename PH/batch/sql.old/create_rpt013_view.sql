create or replace view report_rpt013_view as
	select  tc_desc,
		th_service_code,
		sc_desc as service_desc,
		dm_status_desc as status,
		1 as transaction_count
	from def_service_code,
		def_txn_status_map,
		txn_code,
		txn_header
	where th_txn_code = tc_code
	and tc_fe_display = 1
	and dm_type = 'A'
	and dm_status = th_status
	and dm_ar_ind = NVL(th_ar_ind, ' ')
	and dm_txn_code = th_txn_code
	and sc_code = th_service_code
	and rownum = 1
/
