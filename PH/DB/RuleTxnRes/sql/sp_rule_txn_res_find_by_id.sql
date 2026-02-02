CREATE OR REPLACE FUNCTION sp_rule_txn_res_find_by_id(
	in_party_type			rule_txn_reserve.rs_party_type%Type,
	in_party_id			rule_txn_reserve.rs_party_id%Type,
	out_amount_id		out	rule_txn_reserve.rs_amount_id%type
)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	out_amount_id := -1;
	
	select count(*)
	 into iCnt
	 from rule_txn_reserve
	where rs_party_type = in_party_type
	and rs_party_id = in_party_id
	and rs_disabled = 0;

	if iCnt = 0 THEN

		return 0;

	elsif iCnt = 1 THEN

		select rs_amount_id
		 into out_amount_id
		 from rule_txn_reserve
		where rs_party_type = in_party_type
		and rs_party_id = in_party_id
		and rs_disabled = 0;

		return 1;

	else

		return 9;

	end if;

exception
 WHEN OTHERS THEN
	RETURN 9;
END sp_rule_txn_res_find_by_id;
/
