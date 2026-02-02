CREATE OR REPLACE FUNCTION sp_ol_merchant_res_amt_get(
	in_merchant_id		ol_merchant_reserved_amt.omr_merchant_id%type,
	in_country_id		ol_merchant_reserved_amt.omr_country_id%type,
	in_currency_id		ol_merchant_reserved_amt.omr_currency_id%type,
	in_service_code		ol_merchant_reserved_amt.omr_service_code%type,
	in_day_of_week		ol_merchant_reserved_amt.omr_day_of_week%type,
	in_status               ol_merchant_reserved_amt.omr_status%type,
	out_cursor	    OUT sys_refcursor

)
return number is
begin

	OPEN out_cursor for
		SELECT  /*omr_merchant_id, 
			omr_currency_id, 
			omr_country_id, 
			omr_service_code, 
			omr_day_of_week,
			*/
	                --daily_cap_type, 
			max(daily_cap_amount) as daily_cap_amount, 
			--reserved_amount_type, 
			max(reserved_amount) as reserved_amount,
			max(omr_status) as omr_status, 
			to_char(max(omr_effect_date), 'YYYYMMDDHH24MISS') as omr_effect_date,
			count(1) as rec_cnt
		FROM (
			SELECT	omr_merchant_id, 
				omr_currency_id, 
				omr_country_id, 
				omr_service_code, 
				omr_day_of_week,
				'D' as daily_cap_type, 
				omr_reserved_amount as daily_cap_amount,
				'R' as reserved_amount_type, 
				NULL as reserved_amount,
				to_char(NULL) as omr_status, 
				to_date(NULL) as omr_effect_date
			FROM ol_merchant_reserved_amt
			WHERE omr_merchant_id = in_merchant_id
			AND   omr_currency_id = in_currency_id
			AND   omr_country_id = in_country_id
			AND   omr_service_code = in_service_code
			AND   omr_day_of_week = in_day_of_week
			AND   omr_type = 'D'
			AND   omr_status = 'A'
			AND   omr_effect_date = (select max(omr_effect_date)
                                 		from   ol_merchant_reserved_amt
		                                where  omr_merchant_id = in_merchant_id
						and    omr_currency_id = in_currency_id
						and    omr_country_id = in_country_id
						and    omr_service_code = in_service_code
						and    omr_day_of_week = in_day_of_week
						and    omr_type = 'D'
						and    omr_status = 'A'
						)
			union 
			SELECT	omr_merchant_id, 
				omr_currency_id, 
				omr_country_id, 
				omr_service_code, 
				omr_day_of_week,
				'D' as daily_cap_type,  
				NULL as daily_cap_amount,
				'R' as reserved_amount_type, 
				omr_reserved_amount as reserved_amount,
				omr_status, 
				omr_effect_date
			FROM ol_merchant_reserved_amt
			WHERE omr_merchant_id = in_merchant_id
			AND   omr_currency_id = in_currency_id
			AND   omr_country_id = in_country_id
			AND   omr_service_code = in_service_code
			AND   omr_day_of_week = in_day_of_week
			AND   omr_type = 'R'
			AND   omr_status = in_status
			AND   omr_effect_date = (select max(omr_effect_date)
		                                from   ol_merchant_reserved_amt
						where  omr_merchant_id = in_merchant_id
						and    omr_currency_id = in_currency_id
						and    omr_country_id = in_country_id
						and    omr_service_code = in_service_code
						and    omr_day_of_week = in_day_of_week
						and    omr_type = 'R'
						and    omr_status = in_status
						)
		)
		/*
		group by omr_merchant_id, 
			 omr_currency_id, 
			 omr_country_id, 
			 omr_service_code, 
			 omr_day_of_week,
			 daily_cap_type, 
			 reserved_amount_type*/
		;
	return 0;

exception
  when others then
  return 9;
end sp_ol_merchant_res_amt_get;
/
