create or replace function sp_histolcostsumdetail_insert(
	in_batch_id			hist_ol_cost_sum_detail_2.hd_batch_id%type,
	in_party_type			hist_ol_cost_sum_detail_2.hd_party_type%type,
	in_entity_id			hist_ol_cost_sum_detail_2.hd_entity_id%type,
	in_entity_name			hist_ol_cost_sum_detail_2.hd_entity_name%type,
	in_client_name			hist_ol_cost_sum_detail_2.hd_client_name%type,
	in_ccy				hist_ol_cost_sum_detail_2.hd_ccy%type,
	in_country			hist_ol_cost_sum_detail_2.hd_country%type,
	in_product			hist_ol_cost_sum_detail_2.hd_product%type,
	in_txn_type			hist_ol_cost_sum_detail_2.hd_txn_type%type,
	in_count			hist_ol_cost_sum_detail_2.hd_count%type,
	in_accum_cost_amt		hist_ol_cost_sum_detail_2.hd_accum_cost_amt%type,
	in_accum_refund_amt		hist_ol_cost_sum_detail_2.hd_accum_refund_amt%type,
	in_accum_void_amt		hist_ol_cost_sum_detail_2.hd_accum_void_amt%type,
	in_accum_total_amt		hist_ol_cost_sum_detail_2.hd_accum_total_amt%type,
	in_accum_cost_amt_hkd		hist_ol_cost_sum_detail_2.hd_accum_cost_amt_hkd%type,
	in_accum_refund_amt_hkd		hist_ol_cost_sum_detail_2.hd_accum_refund_amt_hkd%type,
	in_accum_void_amt_hkd		hist_ol_cost_sum_detail_2.hd_accum_void_amt_hkd%type,
	in_accum_total_amt_hkd		hist_ol_cost_sum_detail_2.hd_accum_total_amt_hkd%type,
	in_accum_cost_amt_hkd_rate	hist_ol_cost_sum_detail_2.hd_accum_cost_amt_hkd_rate%type,
	in_accum_cost_amt_usd		hist_ol_cost_sum_detail_2.hd_accum_cost_amt_usd%type,
	in_accum_refund_amt_usd		hist_ol_cost_sum_detail_2.hd_accum_refund_amt_usd%type,
	in_accum_void_amt_usd		hist_ol_cost_sum_detail_2.hd_accum_void_amt_usd%type,
	in_accum_total_amt_usd		hist_ol_cost_sum_detail_2.hd_accum_total_amt_usd%type,
	in_accum_cost_amt_usd_rate	hist_ol_cost_sum_detail_2.hd_accum_cost_amt_usd_rate%type)

  RETURN NUMBER IS
begin

  insert into hist_ol_cost_sum_detail_2
               (hd_batch_id,
		hd_party_type,
		hd_entity_id,
		hd_entity_name,
		hd_client_name,
		hd_ccy,
		hd_country,
		hd_product,
		hd_txn_type,
		hd_count,
		hd_accum_cost_amt,
		hd_accum_refund_amt,
		hd_accum_void_amt,
		hd_accum_total_amt,
		hd_accum_cost_amt_hkd,
		hd_accum_refund_amt_hkd,
		hd_accum_void_amt_hkd,
		hd_accum_total_amt_hkd,
		hd_accum_cost_amt_hkd_rate,
		hd_accum_cost_amt_usd,
		hd_accum_refund_amt_usd,
		hd_accum_void_amt_usd,
		hd_accum_total_amt_usd,
		hd_accum_cost_amt_usd_rate)
         values(in_batch_id,
		in_party_type,
		in_entity_id,
		in_entity_name,
		in_client_name,
		in_ccy,
		in_country,
		in_product,
		in_txn_type,
		in_count,
		in_accum_cost_amt,
		in_accum_refund_amt,
		in_accum_void_amt,
		in_accum_total_amt,
		in_accum_cost_amt_hkd,
		in_accum_refund_amt_hkd,
		in_accum_void_amt_hkd,
		in_accum_total_amt_hkd,
		in_accum_cost_amt_hkd_rate,
		in_accum_cost_amt_usd,
		in_accum_refund_amt_usd,
		in_accum_void_amt_usd,
		in_accum_total_amt_usd,
		in_accum_cost_amt_usd_rate);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end  sp_histolcostsumdetail_insert;
/
