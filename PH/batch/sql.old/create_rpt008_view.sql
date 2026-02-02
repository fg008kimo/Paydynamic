create or replace view report_rpt008_view as
	select th_create_timestamp,
		th_update_timestamp,
		th_approval_timestamp,
		th_txn_id,
		th_merchant_ref,
		tc_desc,
		th_merchant_id,
		name as merchant_name,
		dm_status_desc,
		ds_name as sub_status_desc,
		tp_txn_amount,
		tp_txn_ccy,
		th_net_amount,
		th_ex_rate,
		fee,
		fee_ccy,
		th_transaction_amount,
		td_txn_ccy
	from def_sub_status,
		def_txn_status_map,
		merch_detail,
		txn_detail,
		(select th_create_timestamp, th_update_timestamp, th_approval_timestamp,
			th_txn_id,  th_merchant_ref, th_merchant_id, th_status, th_ar_ind,
			th_sub_status, th_transaction_amount, th_net_amount, th_ex_rate,
			NVL(te_amount, 0) as fee, te_ccy as fee_ccy, th_txn_code,
			tp_txn_amount, tp_txn_ccy, tc_desc
		from (select  th_create_timestamp, th_update_timestamp, th_approval_timestamp,
				th_txn_id,  th_merchant_ref, th_merchant_id, th_status, th_ar_ind,
				th_sub_status, th_transaction_amount, th_net_amount, th_ex_rate,
				th_txn_code, tc_desc
			from txn_header, txn_code
			where tc_code = th_txn_code
			and tc_fe_display =1 ) txn_header
		left join txn_elements
		on te_txn_id = th_txn_id
		and TE_TXN_ELEMENT_TYPE = 'TFEE'
		and te_party_type = 'M'
		left join txn_psp_detail
		on tp_txn_id = th_txn_id)
	where th_txn_id = td_txn_id
	and th_merchant_id = merchant_id
	and dm_type = 'A'
	and th_txn_code = dm_txn_code
	and th_status = dm_status
	and NVL(th_ar_ind, ' ') = dm_ar_ind
	and th_sub_status = ds_sub_status
	and rownum =1
/
