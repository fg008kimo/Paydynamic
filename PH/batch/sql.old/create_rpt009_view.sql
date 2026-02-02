create or replace view report_rpt009_view as
	select  merchant_id,
		name,
		sc_desc as service_code_desc,
		th_approval_timestamp,
		td_current_bal,
		td_total_float,
		td_total_reserved_amount,
		td_total_hold,
		td_settlement_in_transit,
		mb_ccy_id as currency,
		ds_desc as status
	from  def_service_code,
		def_status,
		merch_detail,
		merchant_bal_acct,
		(select th_merchant_id,
			th_approval_timestamp,
			td_current_bal,
			td_total_float,
			td_total_reserved_amount,
			td_total_hold,
			td_settlement_in_transit
			from  txn_detail,txn_header
			where td_txn_id = th_txn_id
			and th_ar_ind = 'A')
	where merchant_id =th_merchant_id
	and mb_merchant_id =merchant_id
	and mb_status = ds_type
	and sc_code= mb_service_code
	and rownum = 1
/
