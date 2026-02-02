CREATE OR REPLACE FUNCTION sp_merch_detail_delete(
	in_merchant_id		merch_detail.merchant_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM merch_detail
	WHERE	merchant_id=in_merchant_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_detail_delete;
/
