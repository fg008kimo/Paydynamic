CREATE OR REPLACE FUNCTION sp_ol_payout_gen_hd_delete(
	in_file_id		ol_payout_generated_file_hd.ofh_file_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM ol_payout_generated_file_hd
	WHERE	ofh_file_id=in_file_id
	AND	ofh_status = 8;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_payout_gen_hd_delete;
/
