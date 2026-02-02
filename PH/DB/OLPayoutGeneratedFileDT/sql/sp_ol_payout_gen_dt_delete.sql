CREATE OR REPLACE FUNCTION sp_ol_payout_gen_dt_delete(
	in_file_id		ol_payout_generated_file_dt.ofd_file_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM ol_payout_generated_file_dt
	WHERE	ofd_file_id=in_file_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_payout_gen_dt_delete;
/
