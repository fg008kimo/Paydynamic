CREATE OR REPLACE FUNCTION sp_ol_payout_api_batch_sup_add(
	in_txn_code			ol_payout_api_batch_support.oau_txn_code%type,
	in_support			ol_payout_api_batch_support.oau_support%type,
	in_support_batch_ret_code	ol_payout_api_batch_support.oau_support_batch_ret_code%type,
	in_support_multi_ret_code	ol_payout_api_batch_support.oau_support_multi_ret_code%type,
	in_add_user			ol_payout_api_batch_support.oau_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO ol_payout_api_batch_support(
	oau_txn_code,
	oau_support,
	oau_support_batch_ret_code,
	oau_support_multi_ret_code,
	oau_create_user,
	oau_update_user,
	oau_create_timestamp,
	oau_update_timestamp
	)

  VALUES(
	in_txn_code,
	in_support,
	in_support_batch_ret_code,
	in_support_multi_ret_code,
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

END sp_ol_payout_api_batch_sup_add;
/
