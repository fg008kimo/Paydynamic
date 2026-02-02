CREATE OR REPLACE FUNCTION sp_payout_gen_dt_delete(
	in_file_id		payout_generated_file_dt.fd_file_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM payout_generated_file_dt
	WHERE	fd_file_id=in_file_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_payout_gen_dt_delete;
/
