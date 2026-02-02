CREATE OR REPLACE FUNCTION sp_ol_merchant_res_amt_update(
	in_merchant_id		ol_merchant_reserved_amt.omr_merchant_id%type,
	in_country_id		ol_merchant_reserved_amt.omr_country_id%type,
	in_currency_id		ol_merchant_reserved_amt.omr_currency_id%type,
	in_service_code		ol_merchant_reserved_amt.omr_service_code%type,
	in_day_of_week		ol_merchant_reserved_amt.omr_day_of_week%type,
        in_type		        ol_merchant_reserved_amt.omr_type%type,
	in_reserved_amount      ol_merchant_reserved_amt.omr_reserved_amount%type,
	in_status               ol_merchant_reserved_amt.omr_status%type,
	in_effect_date          VARCHAR2, 
	in_create_user		ol_merchant_reserved_amt.omr_create_user%type
)
return number is
begin

	if (in_status = 'A') then

		update ol_merchant_reserved_amt
		set    omr_status = in_status,
                       omr_approve_user = in_create_user,
		       omr_approve_timestamp = sysdate,
                       omr_update_user = in_create_user,
                       omr_update_timestamp = sysdate
		where  omr_merchant_id = in_merchant_id
                and    omr_currency_id = in_currency_id
                and    omr_country_id  = in_country_id
                and    omr_day_of_week = in_day_of_week
                and    omr_type = in_type
                and    omr_status = 'P';
	else 		

		update ol_merchant_reserved_amt
		set    omr_reserved_amount = in_reserved_amount,
                       omr_effect_date = NVL(to_date(in_effect_date, 'YYYYMMDDHH24MISS'), sysdate),
		       omr_update_user = in_create_user,
                       omr_update_timestamp = sysdate
                where  omr_merchant_id = in_merchant_id
                and    omr_currency_id = in_currency_id
                and    omr_country_id  = in_country_id
                and    omr_day_of_week = in_day_of_week
                and    omr_type = in_type
                and    omr_status = 'P';	
	
	end if;

	if SQL%ROWCOUNT = 0 then
		return 1;
	else 
		return 0;
	end if;	
	

exception
  when others then
  return 9;
end sp_ol_merchant_res_amt_update;
/
