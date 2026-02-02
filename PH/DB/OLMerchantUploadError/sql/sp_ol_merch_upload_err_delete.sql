CREATE OR REPLACE FUNCTION sp_ol_merch_upload_err_delete(
	in_batch_id		ol_merchant_upload_error.oue_batch_id%type
	)
  RETURN NUMBER IS

  iCnt	INTEGER := 0;

BEGIN
  
  select count(*)
  into iCnt
  from ol_merchant_upload_error
  where oue_batch_id = in_batch_id;

  if iCnt > 0 
  then
  	DELETE	FROM ol_merchant_upload_error
		WHERE	oue_batch_id=in_batch_id;

  	IF SQL%ROWCOUNT = 0 THEN
   	  RETURN 1;
  	ELSE
   	  RETURN 0;
  	END IF;
   else
	return 0;
   end if;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_merch_upload_err_delete;
/
