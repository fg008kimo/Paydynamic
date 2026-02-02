CREATE OR REPLACE FUNCTION sp_ol_merch_balance_add_fin_po(
	in_merchant_id		ol_merchant_balance.om_merchant_id%type,
	in_country_id		ol_merchant_balance.om_country_id%type,
	in_currency_id		ol_merchant_balance.om_currency_id%type,
	in_service_code		ol_merchant_balance.om_service_code%type,
	in_fundin		ol_merchant_balance.om_fundin_payout%type,
	in_create_user		ol_merchant_balance.om_create_user%type
)
return number is
begin
	update ol_merchant_balance
	  set om_fundin_payout = om_fundin_payout + in_fundin,
	      om_current_bal = om_current_bal + in_fundin,
              om_update_user = in_create_user,
	      om_update_timestamp = sysdate
        where om_merchant_id = in_merchant_id
          and om_currency_id = in_currency_id
	  and om_country_id = in_country_id
	  and om_service_code = in_service_code;

	if SQL%ROWCOUNT = 0 THEN
		insert into ol_merchant_balance (om_merchant_id, om_currency_id, om_country_id, om_service_code,
                                              om_current_bal, om_fundin_payout,
                                              om_create_user, om_update_user,
                                              om_create_timestamp, om_update_timestamp)
                values (in_merchant_id, in_currency_id, in_country_id, in_service_code,
                        in_fundin, in_fundin,
                        in_create_user, in_create_user,
                        sysdate, sysdate);

		if SQL%RoWCOUNT = 0 then
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
end sp_ol_merch_balance_add_fin_po;
/

