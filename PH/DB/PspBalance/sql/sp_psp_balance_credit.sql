CREATE OR REPLACE FUNCTION PHUSER.sp_psp_balance_credit(
	in_psp_id		psp_balance.pb_psp_id%type,
	in_country_id		psp_balance.pb_country_id%type,
	in_currency_id		psp_balance.pb_currency_id%type,
	in_bal			psp_balance.pb_bal%type,
	in_create_user		psp_balance.pb_create_user%type
)
return number is
begin
	update psp_balance
	  set pb_total_float = pb_total_float + in_bal,
              pb_update_user = in_create_user,
	      pb_update_timestamp = sysdate
        where pb_psp_id = in_psp_id
	  and pb_country_id = in_country_id
          and pb_currency_id = in_currency_id;

	if SQL%ROWCOUNT = 0 THEN
		insert into psp_balance
			(pb_psp_id,
			 pb_country_id,
			 pb_currency_id,
			 pb_total_float,
			 pb_create_user,
			 pb_update_user,
			 pb_create_timestamp,
			 pb_update_timestamp)
		values(in_psp_id,
		       in_country_id,
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
end sp_psp_balance_credit;
/
