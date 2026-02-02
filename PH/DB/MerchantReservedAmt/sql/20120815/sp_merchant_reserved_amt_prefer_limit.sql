CREATE OR REPLACE FUNCTION sp_merch_res_amt_prefer_limit(
	in_merchant_id		merchant_reserved_amt.mr_merchant_id%type,
	in_country_id		merchant_reserved_amt.mr_country_id%type,
	in_currency_id		merchant_reserved_amt.mr_currency_id%type,
	in_service_code		merchant_reserved_amt.mr_service_code%type,
	in_day_of_week		merchant_reserved_amt.mr_day_of_week%type,
	in_reserved		merchant_reserved_amt.mr_reserved_amount%type,
	in_prefer		merchant_reserved_amt.mr_merchant_prefer_limit%type,
	in_effect_date		varchar2(14),
	in_create_user		merchant_reserved_amt.mr_create_user%type
)
return number is
begin
		insert into merchant_reserved_amt
			(mr_merchant_id,
			 mr_currency_id,
			 mr_country_id,
			 mr_service_code,
			 mr_day_of_week,
			 mr_reserved_amount,
			 mr_merchant_prefer_limit,
			 mr_effect_date,
			 mr_status,
			 mr_create_user,
			 mr_update_user,
			 mr_create_timestamp,
			 mr_update_timestamp)
		values(in_merchant_id,
                       in_currency_id,
                       in_country_id,
		       in_service_code,
		       in_day_of_week,
		       in_reserved,
		       in_prefer,
		       to_date(in_effect_date,'YYYYMMDDHH24MISS'),
		       'W',
		       in_create_user,
                       in_create_user,
		       sysdate,
		       sysdate);
		if SQL%ROWCOUNT = 0 THEN
			return 1;

		else
			return 0;
		end if;

exception
  when others then
  return 9;
end sp_merch_res_amt_prefer_limit;
/
