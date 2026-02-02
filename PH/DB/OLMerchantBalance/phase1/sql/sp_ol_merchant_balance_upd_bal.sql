CREATE OR REPLACE FUNCTION sp_ol_merchant_bal_upd_bal(
	in_merchant_id		ol_merchant_balance.om_merchant_id%type,
	in_country_id		ol_merchant_balance.om_country_id%type,
	in_currency_id		ol_merchant_balance.om_currency_id%type,
	in_service_code		ol_merchant_balance.om_service_code%type,
	in_bal			ol_merchant_balance.om_current_bal%type,
	in_create_user		ol_merchant_balance.om_create_user%type
)
return number is
begin
	update ol_merchant_balance
	  set om_current_bal = om_current_bal + in_bal,
              om_update_user = in_create_user,
	      om_update_timestamp = sysdate
        where om_merchant_id = in_merchant_id
          and om_currency_id = in_currency_id
	  and om_country_id = in_country_id
	  and om_service_code = in_service_code;

	if SQL%ROWCOUNT = 0 THEN
		insert into ol_merchant_balance
                        (om_merchant_id,
                         om_currency_id,
                         om_country_id,
                         om_service_code,
                         om_current_bal,
                         om_create_user,
                         om_update_user,
                         om_create_timestamp,
                         om_update_timestamp)
                values(in_merchant_id,
                       in_currency_id,
                       in_country_id,
                       in_service_code,
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
end sp_ol_merchant_bal_upd_bal;
/
