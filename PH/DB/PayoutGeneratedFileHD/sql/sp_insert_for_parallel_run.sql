CREATE OR REPLACE FUNCTION sp_insert_for_parallel_run(
	in_file_id		payout_generated_file_hd.fh_file_id%type,
	in_file_date		payout_generated_file_hd.fh_file_date%type,
	in_file_pid		payout_generated_file_hd.fh_file_pid%type,
	in_seq_num		payout_generated_file_hd.fh_seq_num%type,
	in_filename		payout_generated_file_hd.fh_filename%type,
	in_txn_cnt		payout_generated_file_hd.fh_txn_count%type,
	in_total_txn_amt	payout_generated_file_hd.fh_total_txn_amt%type,
	in_ccy			payout_generated_file_hd.fh_ccy_id%type,
	in_status		payout_generated_file_hd.fh_status%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO payout_generated_file_hd(
	fh_file_id,
	fh_file_date,
	fh_file_pid,
	fh_seq_num,
	fh_filename,
	fh_txn_count,	
	fh_total_txn_amt,
	fh_ccy_id,
	fh_status,	
	fh_create_user,
	fh_update_user,
	fh_create_timestamp,
	fh_update_timestamp
	)

  VALUES(
	in_file_id,
	in_file_date,
	in_file_pid,
	in_seq_num,
	in_filename,
	in_txn_cnt,
	in_total_txn_amt,
	in_ccy,
	in_status,
	'SYSTEM',
	'SYSTEM',
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

END sp_insert_for_parallel_run;
/
