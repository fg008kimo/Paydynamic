create or replace view report_rpt002_view as 
	select th_txn_id,
		th_ar_ind,
		th_status,
		th_internal_code,
		th_response_code,
		th_merchant_id,
		th_merchant_ref,
		psp_name,
		tp_tid,
		tp_txn_ccy,
		th_transaction_amount,
		tp_service_fee,
		th_transmission_datetime,
		th_local_tm_date,
		th_local_tm_time,
		tp_txn_date,
		th_host_posting_date,
		tc_desc,
		th_txn_code,
		to_char(th_update_timestamp,'yyyymmddhh24miss') as th_update_timestamp,
		client_name,
		tp_bank_bill_no
	from txn_header,
		txn_detail,
		txn_psp_detail,
		txn_code,
		psp_detail,
		clients
	where txn_header.th_txn_id = txn_detail.td_txn_id
	and txn_header.th_txn_id = txn_psp_detail.tp_txn_id
	and txn_header.th_txn_code = txn_code.tc_code
	and psp_detail.psp_id = txn_psp_detail.tp_psp_id
	and txn_header.th_client_id = clients.client_id
	and rownum = 1
/
