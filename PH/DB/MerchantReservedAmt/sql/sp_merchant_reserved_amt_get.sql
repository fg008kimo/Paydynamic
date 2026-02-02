CREATE OR REPLACE FUNCTION sp_merchant_res_amt_get(
	in_merchant_id		merchant_reserved_amt.mr_merchant_id%type,
	in_country_id		merchant_reserved_amt.mr_country_id%type,
	in_currency_id		merchant_reserved_amt.mr_currency_id%type,
	in_service_code		merchant_reserved_amt.mr_service_code%type,
	in_day_of_week		merchant_reserved_amt.mr_day_of_week%type,
	in_status               merchant_reserved_amt.mr_status%type,
	out_cursor	    OUT sys_refcursor

)
return number is
begin

	OPEN out_cursor for
		SELECT  /*mr_merchant_id, 
			mr_currency_id, 
			mr_country_id, 
			mr_service_code, 
			mr_day_of_week,
			*/
	                --daily_cap_type, 
			max(daily_cap_amount) as daily_cap_amount, 
			--reserved_amount_type, 
			max(reserved_amount) as reserved_amount,
			max(mr_status) as mr_status, 
			to_char(max(mr_effect_date), 'YYYYMMDDHH24MISS') as mr_effect_date,
			count(1) as rec_cnt
		FROM (
			SELECT	mr_merchant_id, 
				mr_currency_id, 
				mr_country_id, 
				mr_service_code, 
				mr_day_of_week,
				'D' as daily_cap_type, 
				mr_reserved_amount as daily_cap_amount,
				'R' as reserved_amount_type, 
				NULL as reserved_amount,
				to_char(NULL) as mr_status, 
				to_date(NULL) as mr_effect_date
			FROM merchant_reserved_amt
			WHERE mr_merchant_id = in_merchant_id
			AND   mr_currency_id = in_currency_id
			AND   mr_country_id = in_country_id
			AND   mr_service_code = in_service_code
			AND   mr_day_of_week = in_day_of_week
			AND   mr_type = 'D'
			AND   mr_status = 'A'
			AND   mr_effect_date = (select max(mr_effect_date)
                                 		from   merchant_reserved_amt
		                                where  mr_merchant_id = in_merchant_id
						and    mr_currency_id = in_currency_id
						and    mr_country_id = in_country_id
						and    mr_service_code = in_service_code
						and    mr_day_of_week = in_day_of_week
						and    mr_type = 'D'
						and    mr_status = 'A'
						)
			union 
			SELECT	mr_merchant_id, 
				mr_currency_id, 
				mr_country_id, 
				mr_service_code, 
				mr_day_of_week,
				'D' as daily_cap_type,  
				NULL as daily_cap_amount,
				'R' as reserved_amount_type, 
				mr_reserved_amount as reserved_amount,
				mr_status, 
				mr_effect_date
			FROM merchant_reserved_amt
			WHERE mr_merchant_id = in_merchant_id
			AND   mr_currency_id = in_currency_id
			AND   mr_country_id = in_country_id
			AND   mr_service_code = in_service_code
			AND   mr_day_of_week = in_day_of_week
			AND   mr_type = 'R'
			AND   mr_status = in_status
			AND   mr_effect_date = (select max(mr_effect_date)
		                                from   merchant_reserved_amt
						where  mr_merchant_id = in_merchant_id
						and    mr_currency_id = in_currency_id
						and    mr_country_id = in_country_id
						and    mr_service_code = in_service_code
						and    mr_day_of_week = in_day_of_week
						and    mr_type = 'R'
						and    mr_status = in_status
						)
		)
		/*
		group by mr_merchant_id, 
			 mr_currency_id, 
			 mr_country_id, 
			 mr_service_code, 
			 mr_day_of_week,
			 daily_cap_type, 
			 reserved_amount_type*/
		;
	return 0;

exception
  when others then
  return 9;
end sp_merchant_res_amt_get;
/
