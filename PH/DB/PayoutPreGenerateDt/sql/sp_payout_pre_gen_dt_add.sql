CREATE OR REPLACE FUNCTION sp_payout_pre_gen_dt_add(
	in_file_id		payout_pre_generate_dt.pg_file_id%type,
	in_txn_id		payout_pre_generate_dt.pg_txn_id%type,
	in_payout_amount	payout_pre_generate_dt.pg_payout_amt%type,
	in_multiple_ind		payout_pre_generate_dt.pg_multiple_ind%type,
	in_psp_id		payout_pre_generate_dt.pg_psp_id%type,
	in_add_user		payout_pre_generate_dt.pg_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO payout_pre_generate_dt(
	pg_file_id,
	pg_txn_id,
	pg_payout_amt,
	pg_multiple_ind,
	pg_psp_id,
	pg_create_user,
	pg_update_user,
	pg_create_timestamp,
	pg_update_timestamp
	)

  VALUES(
	in_file_id,
	in_txn_id,
	in_payout_amount,
	in_multiple_ind,
	in_psp_id,
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

END sp_payout_pre_gen_dt_add;
/
