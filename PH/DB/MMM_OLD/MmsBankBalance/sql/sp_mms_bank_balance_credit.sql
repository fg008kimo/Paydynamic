CREATE OR REPLACE FUNCTION PHUSER.sp_mms_bank_balance_credit(
	in_bk_id		mms_bank_balance.bk_id%type,
	in_currency_id		mms_bank_balance.bk_currency_id%type,
	in_bal			mms_bank_balance.bk_bal%type,
	in_create_user		mms_bank_balance.bk_create_user%type
)
return number is
begin
	update mms_bank_balance
	  set bk_bal = bk_bal + in_bal,
              bk_update_user = in_create_user,
	      bk_update_timestamp = sysdate
        where bk_id = in_bk_id
          and bk_currency_id = in_currency_id;

	if SQL%ROWCOUNT = 0 THEN
		insert into mms_bank_balance
			(bk_id,
			 bk_currency_id,
			 bk_bal,
			 bk_create_user,
			 bk_update_user,
			 bk_create_timestamp,
			 bk_update_timestamp)
		values(in_bk_id,
                       in_currency_id,
		       in_bal,
		       in_create_user,
                       in_create_user,
		       sysdate,
		       sysdate);
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
end sp_mms_bank_balance_credit;
/
