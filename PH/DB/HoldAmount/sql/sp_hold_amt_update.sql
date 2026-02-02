CREATE OR REPLACE FUNCTION sp_hold_amt_update(
	in_merchant_id          hold_amount.hv_merchant_id%type,
        in_country_id           hold_amount.hv_country_id%type,
        in_currency_id          hold_amount.hv_currency_id%type,
        in_service_code         hold_amount.hv_service_code%type,
	in_type			hold_amount.hv_type%type,
	in_amt			hold_amount.hv_holded_amt%type,
	in_create_user		hold_amount.hv_create_user%type
)
return number is
begin
	update	hold_amount
	  set	hv_holded_amt = hv_holded_amt + in_amt,
	  	hv_hold_remain = hv_hold_remain - in_amt,
	  	hv_update_user = in_create_user
	  where hv_type = in_type
	  and	hv_state != 'C'
	  and	hv_merchant_id = in_merchant_id
	  and	hv_currency_id = in_currency_id
	  and	hv_country_id = in_country_id
	  and	hv_service_code = in_service_code;

	if SQL%ROWCOUNT = 0 THEN
		return 1;

	else
		update	hold_amount
		set 	hv_state = 'C'
		where	hv_hold_remain = 0
		and	hv_type = in_type
		and	hv_state != 'C'
		and	hv_merchant_id = in_merchant_id
		and	hv_currency_id = in_currency_id
		and	hv_country_id = in_country_id
		and	hv_service_code = in_service_code;

		if SQL%ROWCOUNT = 0 THEN
			
			update  hold_amount
			set     hv_state = 'P'
			where   hv_hold_remain > 0
			and	hv_total_hold = hv_holded_amt + hv_hold_remain
			and	hv_type = in_type
			and	hv_state != 'P'
			and	hv_merchant_id = in_merchant_id
			and	hv_currency_id = in_currency_id
			and	hv_country_id = in_country_id
			and	hv_service_code = in_service_code;
			
			return 0;

		else
			return 0;
		end if;

	end if;

exception
  when others then
  return 9;
end sp_hold_amt_update;
/
