CREATE OR REPLACE FUNCTION sp_dsp_mismatch_markdelete(
	in_txn_id		deposit_mismatch.dm_txn_id%type,
	in_party_type		deposit_mismatch.dm_party_type%type,
	in_match_date		deposit_mismatch.dm_match_date%type
	)
  RETURN NUMBER IS

BEGIN
  	UPDATE	deposit_mismatch
	SET	dm_match_ind = 1,
		dm_match_date=in_match_date,
		dm_update_timestamp = sysdate
	WHERE	dm_txn_id=in_txn_id
	AND	dm_party_type=in_party_type;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_dsp_mismatch_markdelete;
/
