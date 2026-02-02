CREATE OR REPLACE FUNCTION sp_merch_res_amt_value_for_upd(
	in_merchant_id		merchant_reserved_amt.mr_merchant_id%type,
	in_country_id		merchant_reserved_amt.mr_country_id%type,
	in_currency_id		merchant_reserved_amt.mr_currency_id%type,
	in_service_code		merchant_reserved_amt.mr_service_code%type,
	in_day_of_week		merchant_reserved_amt.mr_day_of_week%type,
        in_type		        merchant_reserved_amt.mr_type%type,
	in_status               merchant_reserved_amt.mr_status%type,
	out_reserved_amount    OUT  merchant_reserved_amt.mr_reserved_amount%type,
	out_remain_reserved_amount	OUT	merchant_reserved_amt.mr_remain_reserved_amount%type,
	out_effect_date			OUT	VARCHAR2
)
return number is
begin

	begin
		select mr_reserved_amount, mr_remain_reserved_amount, to_char(mr_effect_date, 'YYYYMMDDHH24MISS')
                  into out_reserved_amount, out_remain_reserved_amount, out_effect_date
		  from merchant_reserved_amt
                 where mr_merchant_id = in_merchant_id
                   and mr_currency_id = in_currency_id
                   and mr_country_id  = in_country_id 
                   and mr_service_code= in_service_code
                   and mr_day_of_week = in_day_of_week
                   and mr_type = in_type
                   and mr_status = in_status
                   and mr_effect_date = (select max(mr_effect_date)
                                           from merchant_reserved_amt
                                          where mr_merchant_id = in_merchant_id
                                            and mr_currency_id = in_currency_id
                                            and mr_country_id  = in_country_id 
                                            and mr_service_code= in_service_code
                                            and mr_day_of_week = in_day_of_week
                                            and mr_type = in_type
                                            and mr_status = in_status)
		for update;
 
	exception when no_data_found then
            out_reserved_amount := 0; 
            out_remain_reserved_amount := 0;	
	    out_effect_date := NULL;
	end;

	return 0;


exception
  when others then
  return 9;
end sp_merch_res_amt_value_for_upd;
/
