CREATE OR REPLACE FUNCTION sp_ol_payout_gen_hd_insert(
	in_file_id		ol_payout_generated_file_hd.ofh_file_id%type,
	in_file_date		ol_payout_generated_file_hd.ofh_file_date%type,
	in_file_pid		ol_payout_generated_file_hd.ofh_file_pid%type,
	in_file_bank		ol_payout_generated_file_hd.ofh_file_bank_code%type,
	in_seq_num		ol_payout_generated_file_hd.ofh_seq_num%type,
	in_filename		ol_payout_generated_file_hd.ofh_filename%type,
	in_ccy_id		ol_payout_generated_file_hd.ofh_ccy_id%type,
	in_txn_cnt              ol_payout_generated_file_hd.ofh_txn_count%type,
        in_status               ol_payout_generated_file_hd.ofh_status%type,
	in_add_user		ol_payout_generated_file_hd.ofh_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO ol_payout_generated_file_hd(
	ofh_file_id,
	ofh_file_date,
	ofh_file_pid,
	ofh_file_bank_code,
	ofh_seq_num,
	ofh_filename,
	ofh_ccy_id,
	ofh_txn_count,
        ofh_status,
	ofh_create_user,
	ofh_update_user,
	ofh_create_timestamp,
	ofh_update_timestamp
	)

  VALUES(
	in_file_id,
	in_file_date,
	in_file_pid,
	in_file_bank,
	in_seq_num,
	in_filename,
	in_ccy_id,
	in_txn_cnt,
	in_status,
	in_add_user,
	in_add_user,
	sysdate,
	sysdate
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_payout_gen_hd_insert;
/
