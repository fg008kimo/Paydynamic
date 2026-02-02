create or replace view report_rpt010_view as
	select  to_char(th_approval_timestamp, 'YYYY-MM-DD HH24:MI:SS:FF6') approval_timestamp,
		th_txn_id,
		th_merchant_id,
		name as merchant_name,
		at_desc transaction_type,
		dm_status_desc,
		ds_name sub_status_desc,
		th_transaction_amount,
		td_txn_ccy,
		te_amount,
		te_ccy
	from
		def_sub_status,
		def_txn_status_map,
		merch_detail,
		txn_detail,
		txn_elements,
		adjustment_type,
		txn_header
	where  th_ar_ind = 'A'
	and th_txn_code = at_code
	and at_party_type = 'M'
	and at_dc_ind = 'D' 
	and te_txn_id = th_txn_id
	and te_txn_element_type = 'TFEE'
	and te_party_type = 'M'
	and dm_type ='A'
	and dm_status = th_status
	and dm_ar_ind = NVL(th_ar_ind, ' ')
	and dm_txn_code = th_txn_code
	and ds_sub_status =  th_sub_status
	and td_txn_id = th_txn_id
	and merchant_id = th_merchant_id
	and rownum = 1
/
