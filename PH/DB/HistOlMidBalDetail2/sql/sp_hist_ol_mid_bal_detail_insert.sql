create or replace function sp_histolmidbaldetail_insert(
	in_batch_id			hist_ol_mid_bal_detail_2.hd_batch_id%type,
	in_client_id			hist_ol_mid_bal_detail_2.hd_client_id%type,
	in_mid_id			hist_ol_mid_bal_detail_2.hd_mid_id%type,
	in_service_code			hist_ol_mid_bal_detail_2.hd_service_code%type,
	in_ccy				hist_ol_mid_bal_detail_2.hd_ccy%type,
	in_country			hist_ol_mid_bal_detail_2.hd_country%type,
	in_txn_id			hist_ol_mid_bal_detail_2.hd_txn_id%type,
	in_current_bal			hist_ol_mid_bal_detail_2.hd_current_bal%type,
	in_hold_bal			hist_ol_mid_bal_detail_2.hd_hold_bal%type,
	in_lien				hist_ol_mid_bal_detail_2.hd_lien%type,
	in_merchant_bal			hist_ol_mid_bal_detail_2.hd_merchant_bal%type,
	in_bal				hist_ol_mid_bal_detail_2.hd_bal%type,
	in_bal_hkd			hist_ol_mid_bal_detail_2.hd_bal_hkd%type,
	in_bal_hkd_rate			hist_ol_mid_bal_detail_2.hd_bal_hkd_rate%type,
	in_bal_usd			hist_ol_mid_bal_detail_2.hd_bal_usd%type,
	in_bal_usd_rate			hist_ol_mid_bal_detail_2.hd_bal_usd_rate%type)

  RETURN NUMBER IS
begin

  insert into hist_ol_mid_bal_detail_2
               (hd_batch_id,
		hd_client_id,
		hd_mid_id,
		hd_service_code,
		hd_ccy,
		hd_country,
		hd_txn_id,
		hd_current_bal,
		hd_hold_bal,
		hd_lien,
		hd_merchant_bal,
		hd_bal,
		hd_bal_hkd,
		hd_bal_hkd_rate,
		hd_bal_usd,
		hd_bal_usd_rate)
         values(in_batch_id,
		in_client_id,
		in_mid_id,
		in_service_code,
		in_ccy,
		in_country,
		in_txn_id,
		in_current_bal,
		in_hold_bal,
		in_lien,
		in_merchant_bal,
		in_bal,
		in_bal_hkd,
		in_bal_hkd_rate,
		in_bal_usd,
		in_bal_usd_rate);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end  sp_histolmidbaldetail_insert;
/
