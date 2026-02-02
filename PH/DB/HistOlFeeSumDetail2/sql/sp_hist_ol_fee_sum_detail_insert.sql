create or replace function sp_histolfeesumdetail_insert(
	in_batch_id			hist_ol_fee_sum_detail_2.hd_batch_id%type,
	in_client_id			hist_ol_fee_sum_detail_2.hd_client_id%type,
	in_client_name			hist_ol_fee_sum_detail_2.hd_client_name%type,
	in_merchant_id			hist_ol_fee_sum_detail_2.hd_merchant_id%type,
	in_merchant_name		hist_ol_fee_sum_detail_2.hd_merchant_name%type,
	in_country			hist_ol_fee_sum_detail_2.hd_country%type,
	in_service_code			hist_ol_fee_sum_detail_2.hd_service_code%type,
	in_ccy				hist_ol_fee_sum_detail_2.hd_ccy%type,
	in_txn_code			hist_ol_fee_sum_detail_2.hd_txn_code%type,
	in_amt				hist_ol_fee_sum_detail_2.hd_amt%type,
	in_amt_hkd			hist_ol_fee_sum_detail_2.hd_amt_hkd%type,
	in_amt_hkd_rate			hist_ol_fee_sum_detail_2.hd_amt_hkd_rate%type,
	in_amt_usd			hist_ol_fee_sum_detail_2.hd_amt_usd%type,
	in_amt_usd_rate			hist_ol_fee_sum_detail_2.hd_amt_usd_rate%type,
	in_txn_count			hist_ol_fee_sum_detail_2.hd_txn_count%type,
	in_is_fee			hist_ol_fee_sum_detail_2.hd_is_fee%type,
	in_is_markup			hist_ol_fee_sum_detail_2.hd_is_markup%type)

  RETURN NUMBER IS
begin

  insert into hist_ol_fee_sum_detail_2
               (hd_batch_id,
		hd_client_id,
		hd_client_name,
		hd_merchant_id,
		hd_merchant_name,
		hd_country,
		hd_service_code,
		hd_ccy,
		hd_txn_code,
		hd_amt,
		hd_amt_hkd,
		hd_amt_hkd_rate,
		hd_amt_usd,
		hd_amt_usd_rate,
		hd_txn_count,
		hd_is_fee,
		hd_is_markup)
         values(in_batch_id,
		in_client_id,
		in_client_name,
		in_merchant_id,
		in_merchant_name,
		in_country,
		in_service_code,
		in_ccy,
		in_txn_code,
		in_amt,
		in_amt_hkd,
		in_amt_hkd_rate,
		in_amt_usd,
		in_amt_usd_rate,
		in_txn_count,
		in_is_fee,
		in_is_markup);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end  sp_histolfeesumdetail_insert;
/
