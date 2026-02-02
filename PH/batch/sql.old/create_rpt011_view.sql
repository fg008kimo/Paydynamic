create or replace view report_rpt011_view as
	select  th_txn_id,
		th_txn_code,
		tc_desc,
		tp_txn_date,
		tp_psp_id,
		psp_name,
		tp_txn_ccy,
		tp_txn_amount,
		tp_service_fee
	from txn_code, psp_detail, txn_psp_detail, txn_header
	where th_ar_ind = 'A'
	and th_txn_id = tp_txn_id
	and psp_id = tp_psp_id
	and tc_code = th_txn_code
	and rownum = 1
/
