CREATE OR REPLACE FUNCTION sp_ol_merch_res_amt_for_upd(
	in_merchant_id		ol_merchant_reserved_amt.omr_merchant_id%type,
	in_country_id		ol_merchant_reserved_amt.omr_country_id%type,
	in_currency_id		ol_merchant_reserved_amt.omr_currency_id%type,
	in_service_code		ol_merchant_reserved_amt.omr_service_code%type,
	in_day_of_week		ol_merchant_reserved_amt.omr_day_of_week%type,
        in_type		        ol_merchant_reserved_amt.omr_type%type,
	in_status               ol_merchant_reserved_amt.omr_status%type,
	out_reserved_amount    OUT  ol_merchant_reserved_amt.omr_reserved_amount%type,
	out_remain_reserved_amount	OUT	ol_merchant_reserved_amt.omr_remain_reserved_amount%type,
	out_effect_date			OUT	VARCHAR2
)
return number is
begin

	begin
		select omr_reserved_amount, omr_remain_reserved_amount, to_char(omr_effect_date, 'YYYYMMDDHH24MISS')
                  into out_reserved_amount, out_remain_reserved_amount, out_effect_date
		  from ol_merchant_reserved_amt
                 where omr_merchant_id = in_merchant_id
                   and omr_currency_id = in_currency_id
                   and omr_country_id  = in_country_id 
                   and omr_service_code= in_service_code
                   and omr_day_of_week = in_day_of_week
                   and omr_type = in_type
                   and omr_status = in_status
                   and omr_effect_date = (select max(omr_effect_date)
                                           from ol_merchant_reserved_amt
                                          where omr_merchant_id = in_merchant_id
                                            and omr_currency_id = in_currency_id
                                            and omr_country_id  = in_country_id 
                                            and omr_service_code= in_service_code
                                            and omr_day_of_week = in_day_of_week
                                            and omr_type = in_type
                                            and omr_status = in_status)
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
end sp_ol_merch_res_amt_for_upd;
/
