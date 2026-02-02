CREATE OR REPLACE FUNCTION sp_payout_gen_hd_delete(
	in_file_id		payout_generated_file_hd.fh_file_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM payout_generated_file_hd
	WHERE	fh_file_id=in_file_id
	AND	fh_status = 8;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_payout_gen_hd_delete;
/
