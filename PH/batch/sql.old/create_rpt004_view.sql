create or replace view report_rpt004_view as
	select th_merchant_id,
		name,
		sc_desc,
		te_ccy,
		te_amt_type,
		te_amount as total_amount
	from 	txn_elements,
		(select th_txn_id, th_merchant_id, th_service_code
		from txn_header
		where th_ar_ind = 'A'),
		def_service_code,
		merch_detail
	where te_txn_id = th_txn_id 
	and te_txn_element_type = 'TFEE'
	and te_party_type = 'M'
	and merchant_id = th_merchant_id
	and sc_code = th_service_code
	and rownum =1
/
