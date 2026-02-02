CREATE OR REPLACE FUNCTION sp_payout_ret_batch_dt_insert(
	in_batch_id		payout_return_batch_dt.prd_batch_id%type,
	in_seq			payout_return_batch_dt.prd_seq%type,
	in_txn_id		payout_return_batch_dt.prd_txn_id%type,
	in_account_name		payout_return_batch_dt.prd_account_name%type,
	in_account_num		payout_return_batch_dt.prd_account_num%type,
	in_amount		payout_return_batch_dt.prd_amount%type,
	in_reason		payout_return_batch_dt.prd_reason%type,
	in_is_valid		payout_return_batch_dt.prd_is_valid%type,
	in_create_user		payout_return_batch_dt.prd_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO payout_return_batch_dt(
	prd_batch_id,
	prd_seq,
	prd_txn_id,
	prd_account_name,
	prd_account_num,
	prd_amount,
	prd_reason,
	prd_is_valid,
	prd_create_timestamp,
        prd_update_timestamp,
        prd_create_user,
        prd_update_user
	)

  VALUES(
	in_batch_id,
	in_seq,
	in_txn_id,
	in_account_name,
	in_account_num,
	in_amount,
	in_reason,
	in_is_valid,
	sysdate,
        sysdate,
        in_create_user,
        in_create_user
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_payout_ret_batch_dt_insert;
/
