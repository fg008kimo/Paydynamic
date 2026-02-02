CREATE OR REPLACE FUNCTION sp_ol_merchant_bal_upd_shold(
	in_merchant_id		ol_merchant_balance.om_merchant_id%type,
	in_country_id		ol_merchant_balance.om_country_id%type,
	in_currency_id		ol_merchant_balance.om_currency_id%type,
	in_service_code		ol_merchant_balance.om_service_code%type,
	in_shold		ol_merchant_balance.om_total_hold_settlement%type,
	in_create_user		ol_merchant_balance.om_create_user%type
)
return number is
begin
	update ol_merchant_balance
	  set om_total_hold_settlement = om_total_hold_settlement + in_shold,
              om_update_user = in_create_user,
	      om_update_timestamp = sysdate
        where om_merchant_id = in_merchant_id
          and om_currency_id = in_currency_id
	  and om_country_id = in_country_id
	  and om_service_code = in_service_code;

	if SQL%ROWCOUNT = 0 THEN
		return 1;
	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_ol_merchant_bal_upd_shold;
/
