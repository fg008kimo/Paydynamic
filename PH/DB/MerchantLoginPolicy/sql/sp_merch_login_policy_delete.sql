CREATE OR REPLACE FUNCTION sp_merch_login_policy_delete(
	in_client_id		clients.client_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM merchant_login_policy
	WHERE mp_client_id = in_client_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_login_policy_delete;
/
