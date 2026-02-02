CREATE OR REPLACE FUNCTION sp_deposit_response_log_delete(
	in_response_log_id		deposit_response_log.response_log_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM deposit_response_log
	WHERE	response_log_id=in_response_log_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_deposit_response_log_delete;
/
