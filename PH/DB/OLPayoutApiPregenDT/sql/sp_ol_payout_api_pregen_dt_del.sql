CREATE OR REPLACE FUNCTION sp_ol_payout_api_pregen_dt_del(
	in_batch_id		ol_payout_api_pregen_dt.oag_batch_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM ol_payout_api_pregen_dt
	WHERE	oag_batch_id=in_batch_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_payout_api_pregen_dt_del;
/
