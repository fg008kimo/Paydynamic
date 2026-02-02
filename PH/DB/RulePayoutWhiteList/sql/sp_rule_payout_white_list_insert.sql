CREATE OR REPLACE FUNCTION sp_rpwl_insert (
	in_merch_id		rule_payout_white_list.rpwl_merch_id%TYPE,
	in_acct_name		rule_payout_white_list.rpwl_acct_name%TYPE,
	in_disabled		rule_payout_white_list.rpwl_disabled%TYPE,
	in_create_user		rule_payout_white_list.rpwl_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
	update rule_payout_white_list
	set 	rpwl_disabled = 0,
		rpwl_update_user = in_create_user,
		rpwl_update_timestamp = sysdate
	where	rpwl_merch_id = in_merch_id
	and	rpwl_acct_name = in_acct_name;

	if SQL%ROWCOUNT = 0 THEN
		insert into rule_payout_white_list
		(
			rpwl_merch_id,
			rpwl_acct_name,
			rpwl_disabled,
			rpwl_create_user,
			rpwl_update_user,
			rpwl_create_timestamp,
			rpwl_update_timestamp)
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

END sp_rpwl_insert;
/

