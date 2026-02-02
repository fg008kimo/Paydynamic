CREATE OR REPLACE FUNCTION PHUSER.sp_payout_record_delete(
	in_batch_id		payout_record.batch_id%type,
	in_merchant_ref		payout_record.merchant_ref%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM payout_record
	WHERE	batch_id=in_batch_id
	AND	merchant_ref=in_merchant_ref;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_payout_record_delete;
/
