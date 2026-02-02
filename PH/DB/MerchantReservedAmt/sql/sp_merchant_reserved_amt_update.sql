CREATE OR REPLACE FUNCTION sp_merchant_res_amt_update(
	in_merchant_id		merchant_reserved_amt.mr_merchant_id%type,
	in_country_id		merchant_reserved_amt.mr_country_id%type,
	in_currency_id		merchant_reserved_amt.mr_currency_id%type,
	in_service_code		merchant_reserved_amt.mr_service_code%type,
	in_day_of_week		merchant_reserved_amt.mr_day_of_week%type,
        in_type		        merchant_reserved_amt.mr_type%type,
	in_reserved_amount      merchant_reserved_amt.mr_reserved_amount%type,
	in_status               merchant_reserved_amt.mr_status%type,
	in_effect_date          VARCHAR2, 
	in_create_user		merchant_reserved_amt.mr_create_user%type
)
return number is
begin

	if (in_status = 'A') then

		update merchant_reserved_amt
		set    mr_status = in_status,
                       mr_approve_user = in_create_user,
		       mr_approve_timestamp = sysdate,
                       mr_update_user = in_create_user,
                       mr_update_timestamp = sysdate
		where  mr_merchant_id = in_merchant_id
                and    mr_currency_id = in_currency_id
                and    mr_country_id  = in_country_id
                and    mr_day_of_week = in_day_of_week
                and    mr_type = in_type
                and    mr_status = 'P';
	else 		

		update merchant_reserved_amt
		set    mr_reserved_amount = in_reserved_amount,
                       mr_effect_date = NVL(to_date(in_effect_date, 'YYYYMMDDHH24MISS'), sysdate),
		       mr_update_user = in_create_user,
                       mr_update_timestamp = sysdate
                where  mr_merchant_id = in_merchant_id
                and    mr_currency_id = in_currency_id
                and    mr_country_id  = in_country_id
                and    mr_day_of_week = in_day_of_week
                and    mr_type = in_type
                and    mr_status = 'P';	
	
	end if;

	if SQL%ROWCOUNT = 0 then
		return 1;
	else 
		return 0;
	end if;	
	

exception
  when others then
  return 9;
end sp_merchant_res_amt_update;
/
