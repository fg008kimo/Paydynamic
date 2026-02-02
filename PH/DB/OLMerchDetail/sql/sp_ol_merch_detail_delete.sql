CREATE OR REPLACE FUNCTION sp_ol_merch_detail_delete(
	in_merchant_id		ol_merch_detail.md_merchant_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM ol_merch_detail
	WHERE	md_merchant_id=in_merchant_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_merch_detail_delete;
/
