CREATE OR REPLACE FUNCTION sp_ol_bank_acct_id_delete(
	in_baid		ol_bank_acct_id.obai_baid%type
	)
RETURN NUMBER IS

BEGIN
	DELETE FROM ol_bank_acct_id
	WHERE obai_baid = in_baid;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_ol_bank_acct_id_delete;
/
