CREATE OR REPLACE FUNCTION sp_merch_upload_hd_delete(
	in_batch_id		merchant_upload_file_header.uh_batch_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM merchant_upload_file_header
	WHERE	uh_batch_id=in_batch_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_upload_hd_delete;
/
