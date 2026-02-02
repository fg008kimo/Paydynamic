create or replace view report_rpt006_view as
	select 1 as transaction_count,
		te_amt_type as member_amt_type,
		te_ccy as member_ccy,
		te_amount as member_fee,
		te_amt_type as merchant_amt_type,
		te_ccy as merchant_ccy,
		te_amount as merchant_fee
	from txn_elements,
		txn_header
	where th_txn_code = 'POU'
	and th_ar_ind = 'A'
	and te_txn_id = th_txn_id
	and te_txn_element_type = 'TFEE'
	and TE_PARTY_TYPE = 'M' 
	and rownum = 1
/
