CREATE OR REPLACE FUNCTION sp_payout_gen_tmp_insert(
	in_gen_id		payout_generated_tmp.pt_id%type,
	in_txn_id		payout_generated_tmp.pt_txn_id%type,
	in_psp_id		payout_generated_tmp.pt_psp_id%type,
	in_add_user		payout_generated_tmp.pt_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO payout_generated_tmp(
	pt_id,
	pt_txn_id,
	pt_psp_id,
	pt_create_user,
	pt_update_user,
	pt_create_timestamp,
	pt_update_timestamp
	)

  VALUES(
	in_gen_id,
	in_txn_id,
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

END sp_payout_gen_tmp_insert;
/
