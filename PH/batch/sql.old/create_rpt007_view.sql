create or replace view report_rpt007_view as
	select th_create_timestamp,
		th_update_timestamp,
		th_approval_timestamp,
		th_txn_id,
		psp_name,
		th_merchant_ref,
		th_merchant_id,
		name as merchant_name,
		dm_status_desc,
		ds_name as sub_status_desc,
		tp_txn_amount,
		tp_txn_ccy,
		th_net_amount,
		th_ex_rate,
		te_amount as fee,
		te_ccy as fee_ccy,
		th_transaction_amount as requested_amount,
		td_txn_ccy
	from def_sub_status,
		def_txn_status_map,
		merch_detail,
		psp_detail,
		txn_psp_detail, 
		txn_detail,
		txn_header,
		txn_elements
	where th_txn_code = 'DSI' 
	and te_txn_id = th_txn_id
	and tp_txn_id = th_txn_id
	and th_txn_id = td_txn_id
	and tp_psp_id = psp_id
	and th_merchant_id = merchant_id
	and dm_type = 'A'
	and th_txn_code = dm_txn_code
	and th_status = dm_status
	and NVL(th_ar_ind, ' ') = dm_ar_ind
	and th_sub_status = ds_sub_status
	and rownum = 1
/
