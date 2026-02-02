create or replace view report_rpt003_view as 
	select th_host_posting_date,
		tc_desc,
		sc_desc,
		psp_name,
		tp_txn_ccy,
		tp_txn_amount as total_transaction_amount,
		1 as transaction_count,
		tp_txn_amount as average_transaction_amount
	from  def_service_code,
		txn_code,
		psp_detail,
		txn_psp_detail,
		txn_header 
	where th_ar_ind = 'A'
	and th_txn_code = 'DSI'
	and th_txn_id= tp_txn_id
	and sc_code = th_service_code
	and tc_code = th_txn_code
	and psp_id = tp_psp_id
	and rownum = 1
/
