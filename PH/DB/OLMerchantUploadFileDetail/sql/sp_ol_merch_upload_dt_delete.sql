CREATE OR REPLACE FUNCTION sp_ol_merch_upload_dt_delete(
	in_batch_id		ol_merchant_upload_file_detail.oud_batch_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM ol_merchant_upload_file_detail
	WHERE	oud_batch_id=in_batch_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_merch_upload_dt_delete;
/
