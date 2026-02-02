CREATE OR REPLACE FUNCTION sp_dsp_mismatch_markdelete_ref(
	in_merchant_ref		deposit_mismatch.dm_merchant_ref%type,
	in_party_type		deposit_mismatch.dm_party_type%type,
	in_match_date		deposit_mismatch.dm_match_date%type
	)
  RETURN NUMBER IS

BEGIN
  	UPDATE	deposit_mismatch
	SET	dm_match_ind = 1,
		dm_match_date=in_match_date
	WHERE	dm_merchant_ref=in_merchant_ref
	AND	dm_party_type=in_party_type;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_dsp_mismatch_markdelete_ref;
/
