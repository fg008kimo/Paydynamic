CREATE OR REPLACE FUNCTION sp_ol_payout_gen_tmp_insert(
	in_gen_id		ol_payout_generated_tmp.opt_id%type,
	in_txn_id		ol_payout_generated_tmp.opt_txn_id%type,
	in_psp_id		ol_payout_generated_tmp.opt_psp_id%type,
	in_bank_code		ol_payout_generated_tmp.opt_bank_code%type,
	in_add_user		ol_payout_generated_tmp.opt_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO ol_payout_generated_tmp(
	opt_id,
	opt_txn_id,
	opt_psp_id,
	opt_bank_code,
	opt_create_user,
	opt_update_user,
	opt_create_timestamp,
	opt_update_timestamp
	)

  VALUES(
	in_gen_id,
	in_txn_id,
	in_psp_id,
	in_bank_code,
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

END sp_ol_payout_gen_tmp_insert;
/
