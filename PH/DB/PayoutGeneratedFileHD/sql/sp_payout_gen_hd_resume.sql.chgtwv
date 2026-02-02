CREATE OR REPLACE FUNCTION sp_payout_gen_hd_resume(
	in_file_id		payout_generated_file_hd.fh_file_id%type,
	in_status		payout_generated_file_hd.fh_status%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM payout_generated_file_hd
	WHERE	fh_file_id=in_file_id
	AND	fh_status=in_status;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_payout_gen_hd_resume;
/
