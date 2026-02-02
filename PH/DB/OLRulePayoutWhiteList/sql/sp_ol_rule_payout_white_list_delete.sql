CREATE OR REPLACE FUNCTION sp_ol_rul_po_white_lis_del (
	in_merch_id		ol_rule_payout_white_list.orpwl_merch_id%TYPE,
	in_acct_name		ol_rule_payout_white_list.orpwl_acct_name%TYPE,
	in_user			ol_rule_payout_white_list.orpwl_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
	update ol_rule_payout_white_list
	set 	orpwl_disabled = 1,
		orpwl_update_user = in_user,
		orpwl_update_timestamp = sysdate
	where	orpwl_merch_id = in_merch_id
	and	orpwl_acct_name = in_acct_name;

	if SQL%ROWCOUNT = 0 THEN
		return 1;
	else
		return 0;
	end if;

exception
  when others then
  return 9;

END sp_ol_rul_po_white_lis_del;
/

