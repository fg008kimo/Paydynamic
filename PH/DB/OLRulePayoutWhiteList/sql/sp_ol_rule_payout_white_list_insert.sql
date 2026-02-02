CREATE OR REPLACE FUNCTION sp_ol_rul_po_white_lis_ins (
	in_merch_id		ol_rule_payout_white_list.orpwl_merch_id%TYPE,
	in_acct_name		ol_rule_payout_white_list.orpwl_acct_name%TYPE,
	in_disabled		ol_rule_payout_white_list.orpwl_disabled%TYPE,
	in_create_user		ol_rule_payout_white_list.orpwl_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
	update ol_rule_payout_white_list
	set 	orpwl_disabled = 0,
		orpwl_update_user = in_create_user,
		orpwl_update_timestamp = sysdate
	where	orpwl_merch_id = in_merch_id
	and	orpwl_acct_name = in_acct_name;

	if SQL%ROWCOUNT = 0 THEN
		insert into ol_rule_payout_white_list
		(
			orpwl_merch_id,
			orpwl_acct_name,
			orpwl_disabled,
			orpwl_create_user,
			orpwl_update_user,
			orpwl_create_timestamp,
			orpwl_update_timestamp)
		values
		(
			in_merch_id,
			in_acct_name,
			in_disabled,
			in_create_user,
			in_create_user,
			sysdate,
			sysdate
		);

		if SQL%ROWCOUNT = 0 THEN
			return 1;
		else
			return 0;
		end if;
	else
		return 0;
	end if;

exception
  when others then
  return 9;

END sp_ol_rul_po_white_lis_ins;
/

