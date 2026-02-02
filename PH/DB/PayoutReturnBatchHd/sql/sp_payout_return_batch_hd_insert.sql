CREATE OR REPLACE FUNCTION sp_payout_ret_batch_hd_insert(
	in_batch_id		payout_return_batch_hd.prh_batch_id%type,
	in_filename		payout_return_batch_hd.prh_filename%type,
	in_record_count		payout_return_batch_hd.prh_record_count%type,
	in_status		payout_return_batch_hd.prh_status%type,
	in_add_user		payout_return_batch_hd.prh_create_user%type)
  RETURN NUMBER IS

BEGIN

  INSERT INTO payout_return_batch_hd(
	prh_batch_id,
	prh_filename,
	prh_record_count,
	prh_status,
	prh_create_timestamp,
	prh_update_timestamp,
	prh_create_user,
	prh_update_user
	)
  VALUES(
	in_batch_id,
	in_filename,
	in_record_count,
	in_status,
	sysdate,
	sysdate,
	in_add_user,
	in_add_user
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_payout_ret_batch_hd_insert;
/
