create or replace function sp_histbaidbaldetail_insert(
	in_batch_id			hist_baid_bal_detail_2.hd_batch_id%type,
	in_pid_id			hist_baid_bal_detail_2.hd_pid_id%type,
	in_baid				hist_baid_bal_detail_2.hd_baid%type,
	in_ccy				hist_baid_bal_detail_2.hd_ccy%type,
	in_txn_id			hist_baid_bal_detail_2.hd_txn_id%type,
	in_in_transit			hist_baid_bal_detail_2.hd_in_transit%type,
	in_lien				hist_baid_bal_detail_2.hd_lien%type,
	in_available_bal		hist_baid_bal_detail_2.hd_available_bal%type,
	in_bal				hist_baid_bal_detail_2.hd_bal%type,
	in_bal_hkd			hist_baid_bal_detail_2.hd_bal_hkd%type,
	in_bal_hkd_rate			hist_baid_bal_detail_2.hd_bal_hkd_rate%type,
	in_bal_usd			hist_baid_bal_detail_2.hd_bal_usd%type,
	in_bal_usd_rate			hist_baid_bal_detail_2.hd_bal_usd_rate%type,
	in_cat				hist_baid_bal_detail_2.hd_cat%type,
	in_cat_desc			hist_baid_bal_detail_2.hd_cat_desc%type,
	in_acct_type			hist_baid_bal_detail_2.hd_acct_type%type,
	in_in_balance			hist_baid_bal_detail_2.hd_in_balance%type)

  RETURN NUMBER IS
begin

  insert into hist_baid_bal_detail_2
               (hd_batch_id,
		hd_pid_id,
		hd_baid,
		hd_ccy,
		hd_txn_id,
		hd_in_transit,
		hd_lien,
		hd_available_bal,
		hd_bal,
		hd_bal_hkd,
		hd_bal_hkd_rate,
		hd_bal_usd,
		hd_bal_usd_rate,
		hd_cat,
		hd_cat_desc,
		hd_acct_type,
		hd_in_balance)
         values(in_batch_id,
		in_pid_id,
		in_baid,
		in_ccy,
		in_txn_id,
		in_in_transit,
		in_lien,
		in_available_bal,
		in_bal,
		in_bal_hkd,
		in_bal_hkd_rate,
		in_bal_usd,
		in_bal_usd_rate,
		in_cat,
		in_cat_desc,
		in_acct_type,
		in_in_balance);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end  sp_histbaidbaldetail_insert;
/
