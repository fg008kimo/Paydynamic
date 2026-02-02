CREATE OR REPLACE FUNCTION sp_rule_po_exclude_bkat_delete(
	in_client_id		rule_payout_exclude_bk_acct.re_psp_client_id%type,
	in_name			rule_payout_exclude_bk_acct.re_acct_name%type,
	in_num			rule_payout_exclude_bk_acct.re_acct_num%type,
	in_update_user		rule_payout_exclude_bk_acct.re_update_user%type
	)
  RETURN NUMBER IS

BEGIN
  	update	rule_payout_exclude_bk_acct
	set	re_disabled = 1,
		re_update_user = in_update_user,
		re_update_timestamp = sysdate
	where	re_psp_client_id = in_client_id
	and	re_acct_name = in_name
	and	re_acct_num = in_num
	and	re_disabled = 0;


	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_rule_po_exclude_bkat_delete;
/
