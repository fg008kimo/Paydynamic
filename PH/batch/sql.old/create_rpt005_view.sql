create or replace view report_rpt005_view as
	select tc_desc,
		dm_status_desc,
		1 as transaction_count,
		te_amt_type,
		te_ccy,
		te_amount as markup_amount 
	from txn_code,
		def_txn_status_map,
		txn_elements,
		txn_header
	where te_txn_element_type = 'MAMT'
	and te_party_type = 'R' 
	and te_txn_id = th_txn_id
	and tc_code = th_txn_code
	and dm_type = 'A'
	and dm_status = th_status
	and dm_ar_ind = 'A'
	and dm_txn_code= th_txn_code
	and rownum = 1 
/
