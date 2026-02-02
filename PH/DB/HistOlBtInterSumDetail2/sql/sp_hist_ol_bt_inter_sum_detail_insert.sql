create or replace function sp_hobis_detail_insert(
	in_batch_id			hist_ol_bt_inter_sum_detail_2.hd_batch_id%type,
	in_ccy				hist_ol_bt_inter_sum_detail_2.hd_ccy%type,
	in_product			hist_ol_bt_inter_sum_detail_2.hd_product%type,
	in_count			hist_ol_bt_inter_sum_detail_2.hd_count%type,
	in_accum_req_amt		hist_ol_bt_inter_sum_detail_2.hd_accum_req_amt%type,
	in_accum_void_amt		hist_ol_bt_inter_sum_detail_2.hd_accum_void_amt%type,
	in_accum_net_hkd		hist_ol_bt_inter_sum_detail_2.hd_accum_net_amt%type,
	in_accum_net_amt_hkd		hist_ol_bt_inter_sum_detail_2.hd_accum_net_amt_hkd%type,
	in_hkd_rate			hist_ol_bt_inter_sum_detail_2.hd_hkd_rate%type,
	in_accum_net_amt_usd		hist_ol_bt_inter_sum_detail_2.hd_accum_net_amt_usd%type,
	in_usd_rate			hist_ol_bt_inter_sum_detail_2.hd_usd_rate%type)

  RETURN NUMBER IS
begin

  insert into hist_ol_bt_inter_sum_detail_2
               (hd_batch_id,
		hd_ccy,
		hd_product,
		hd_count,
		hd_accum_req_amt,
		hd_accum_void_amt,
		hd_accum_net_amt,
		hd_accum_net_amt_hkd,
		hd_hkd_rate,
		hd_accum_net_amt_usd,
		hd_usd_rate)
         values(in_batch_id,
		in_ccy,
		in_product,
		in_count,
		in_accum_req_amt,
		in_accum_void_amt,
		in_accum_net_hkd,
		in_accum_net_amt_hkd,
		in_hkd_rate,
		in_accum_net_amt_usd,
		in_usd_rate);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end  sp_hobis_detail_insert;
/
