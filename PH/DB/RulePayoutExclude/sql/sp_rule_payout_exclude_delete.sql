CREATE OR REPLACE FUNCTION sp_rule_payout_exclude_delete(
	in_client_id		rule_payout_exclude.re_psp_client_id%type,
	in_name			rule_payout_exclude.re_bank_name%type,
	in_update_user		rule_payout_exclude.re_update_user%type
	)
  RETURN NUMBER IS

BEGIN
  	update	rule_payout_exclude
	set	re_disabled = 1,
		re_update_user = in_update_user,
		re_update_timestamp = sysdate
	where	re_psp_client_id = in_client_id
	and	re_bank_name = in_name
	and	re_disabled = 0;


	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_rule_payout_exclude_delete;
/
