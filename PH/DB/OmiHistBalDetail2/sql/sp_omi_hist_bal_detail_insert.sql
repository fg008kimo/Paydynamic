create or replace function sp_omihistbaldetail_insert(
	in_batch_id			omi_hist_bal_detail_2.omid_batch_id%type,
	in_mi_id			omi_hist_bal_detail_2.omid_mi_id%type,
	in_entity_type			omi_hist_bal_detail_2.omid_entity_type%type,
	in_ccy				omi_hist_bal_detail_2.omid_ccy%type,
	in_country			omi_hist_bal_detail_2.omid_country%type,
	in_txn_id			omi_hist_bal_detail_2.omid_txn_id%type,
	in_acct_bal			omi_hist_bal_detail_2.omid_acct_bal%type,
	in_intransit			omi_hist_bal_detail_2.omid_intransit%type,
	in_ar_bal			omi_hist_bal_detail_2.omid_ar_bal%type,
	in_bal				omi_hist_bal_detail_2.omid_bal%type,
	in_bal_hkd			omi_hist_bal_detail_2.omid_bal_hkd%type,
	in_bal_hkd_rate			omi_hist_bal_detail_2.omid_bal_hkd_rate%type,
	in_bal_usd			omi_hist_bal_detail_2.omid_bal_usd%type,
	in_bal_usd_rate			omi_hist_bal_detail_2.omid_bal_usd_rate%type)

  RETURN NUMBER IS
begin

  insert into omi_hist_bal_detail_2
               (omid_batch_id,
		omid_mi_id,
		omid_entity_type,
		omid_ccy,
		omid_country,
		omid_txn_id,
		omid_acct_bal,
		omid_intransit,
		omid_ar_bal,
		omid_bal,
		omid_bal_hkd,
		omid_bal_hkd_rate,
		omid_bal_usd,
		omid_bal_usd_rate)
         values(in_batch_id,
		in_mi_id,
		in_entity_type,
		in_ccy,
		in_country,
		in_txn_id,
		in_acct_bal,
		in_intransit,
		in_ar_bal,
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
end  sp_omihistbaldetail_insert;
/
