CREATE OR REPLACE FUNCTION sp_rule_txn_res_insert(
	in_party_type		rule_txn_reserve.rs_party_type%type,
	in_party_id		rule_txn_reserve.rs_party_id%type,
	in_amount_id		rule_txn_reserve.rs_amount_id%type,
	in_disabled		rule_txn_reserve.rs_disabled%type,
	in_create_user		rule_txn_reserve.rs_create_user%type
)
return number is
begin
		insert into rule_txn_reserve
			(rs_party_type,
			 rs_party_id,
			 rs_amount_id,
			 rs_disabled,
			 rs_create_timestamp,
			 rs_create_user,
			 rs_update_timestamp,
			 rs_update_user)
		values(in_party_type,
			in_party_id,
			in_amount_id,
			in_disabled,
			sysdate,
			in_create_user,
			sysdate,
			in_create_user);
		if SQL%ROWCOUNT = 0 THEN
			return 1;
		else
			return 0;
		end if;

exception
 when others then
 return 9;
end sp_rule_txn_res_insert;
/
