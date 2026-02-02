CREATE OR REPLACE FUNCTION sp_merch_upload_error_delete(
	in_batch_id		merchant_upload_error.ue_batch_id%type
	)
  RETURN NUMBER IS

  iCnt	INTEGER := 0;

BEGIN
  
  select count(*)
  into iCnt
  from merchant_upload_error
  where ue_batch_id = in_batch_id;

  if iCnt > 0 
  then
  	DELETE	FROM merchant_upload_error
		WHERE	ue_batch_id=in_batch_id;

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

END sp_merch_upload_error_delete;
/
