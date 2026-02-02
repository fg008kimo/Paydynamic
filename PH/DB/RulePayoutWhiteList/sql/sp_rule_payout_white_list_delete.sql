CREATE OR REPLACE FUNCTION sp_rpwl_delete (
	in_merch_id		rule_payout_white_list.rpwl_merch_id%TYPE,
	in_acct_name		rule_payout_white_list.rpwl_acct_name%TYPE,
	in_user			rule_payout_white_list.rpwl_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
	update rule_payout_white_list
	set 	rpwl_disabled = 1,
		rpwl_update_user = in_user,
		rpwl_update_timestamp = sysdate
	where	rpwl_merch_id = in_merch_id
	and	rpwl_acct_name = in_acct_name;

	if SQL%ROWCOUNT = 0 THEN
		return 1;
	else
		return 0;
	end if;

exception
  when others then
  return 9;

END sp_rpwl_delete;
/

