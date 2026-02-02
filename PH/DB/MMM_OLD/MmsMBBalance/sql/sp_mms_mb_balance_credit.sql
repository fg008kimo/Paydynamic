CREATE OR REPLACE FUNCTION PHUSER.sp_mms_mb_balance_credit(
	in_mb_id		mms_mb_balance.mb_id%type,
	in_currency_id		mms_mb_balance.mb_currency_id%type,
	in_bal			mms_mb_balance.mb_bal%type,
	in_create_user		mms_mb_balance.mb_create_user%type
)
return number is
begin
	update mms_mb_balance
	  set mb_bal = mb_bal + in_bal,
              mb_update_user = in_create_user,
	      mb_update_timestamp = sysdate
        where mb_id = in_mb_id
          and mb_currency_id = in_currency_id;

	if SQL%ROWCOUNT = 0 THEN
		insert into mms_mb_balance
			(mb_id,
			 mb_currency_id,
			 mb_bal,
			 mb_create_user,
			 mb_update_user,
			 mb_create_timestamp,
			 mb_update_timestamp)
		values(in_mb_id,
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
end sp_mms_mb_balance_credit;
/
