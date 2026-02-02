CREATE OR REPLACE FUNCTION sp_psp_response_txn_url_delete(
	in_psp_id		psp_response_txn_url.psp_id%type,
	in_txn_code		psp_response_txn_url.txn_code%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM psp_response_txn_url
	WHERE	psp_id=in_psp_id
	AND	txn_code = in_txn_code;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_psp_response_txn_url_delete;
/
