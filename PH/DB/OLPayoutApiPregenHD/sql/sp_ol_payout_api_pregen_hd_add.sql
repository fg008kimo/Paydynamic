CREATE OR REPLACE FUNCTION sp_ol_payout_api_pregen_hd_add(
	in_action_id		ol_payout_api_pregen_hd.oap_action_id%type,
	in_batch_id		ol_payout_api_pregen_hd.oap_batch_id%type,
	in_payout_group		ol_payout_api_pregen_hd.oap_payout_group%type,
	in_status		ol_payout_api_pregen_hd.oap_status%type,
	in_pregen_ret_code	ol_payout_api_pregen_hd.oap_pregen_ret_code%type,
	in_gen_ret_code		ol_payout_api_pregen_hd.oap_gen_ret_code%type,
	in_add_user		ol_payout_api_pregen_hd.oap_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO ol_payout_api_pregen_hd(
	oap_action_id,
	oap_batch_id,
	oap_payout_group,
	oap_status,
	oap_pregen_ret_code,
	oap_gen_ret_code,
	oap_create_user,
	oap_update_user,
	oap_create_timestamp,
	oap_update_timestamp
	)

  VALUES(
	in_action_id,
	in_batch_id,
	in_payout_group,
	in_status,
	in_pregen_ret_code,
	in_gen_ret_code,
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

END sp_ol_payout_api_pregen_hd_add;
/
