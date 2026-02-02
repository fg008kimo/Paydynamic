CREATE OR REPLACE FUNCTION sp_deposit_request_log_delete(
	in_request_log_id		deposit_request_log.request_log_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM deposit_request_log
	WHERE	request_log_id=in_request_log_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_deposit_request_log_delete;
/
