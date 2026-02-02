CREATE OR REPLACE FUNCTION sp_merch_balance_update_aval(
	in_merchant_id		merchant_balance.m_merchant_id%type,
	in_country_id		merchant_balance.m_country_id%type,
	in_currency_id		merchant_balance.m_currency_id%type,
	in_service_code		merchant_balance.m_service_code%type,
	in_bal			merchant_balance.m_current_bal%type,
	in_create_user		merchant_balance.m_create_user%type,
	out_openbal	    out merchant_balance.m_current_bal%type
)
return number is
	dOpenBalance number := 0.0;
begin

	BEGIN
		select m_current_bal
          	  into dOpenBalance
          	  from merchant_balance
	  	 where m_merchant_id = in_merchant_id
           	   and m_currency_id = in_currency_id
           	   and m_country_id = in_country_id
           	   and m_service_code = in_service_code
	  	   for update;
	EXCEPTION
		when no_data_found then
			dOpenBalance := 0.0;
	END;
		
	--if SQL%ROWCOUNT = 0 THEN
 	--	dOpenBalance := 0.0;
	--end if;
	
	out_openbal := dOpenBalance;
 

	update merchant_balance
	  set m_current_bal = m_current_bal + in_bal,
              m_update_user = in_create_user,
	      m_update_timestamp = sysdate
        where m_merchant_id = in_merchant_id
          and m_currency_id = in_currency_id
	  and m_country_id = in_country_id
	  and m_service_code = in_service_code;

	if SQL%ROWCOUNT = 0 THEN
		insert into merchant_balance
                        (m_merchant_id,
                         m_currency_id,
                         m_country_id,
                         m_service_code,
                         m_current_bal,
                         m_create_user,
                         m_update_user,
                         m_create_timestamp,
                         m_update_timestamp)
                values(in_merchant_id,
                       in_currency_id,
                       in_country_id,
                       in_service_code,
                       in_bal,
                       in_create_user,
                       in_create_user,
                       sysdate,
                       sysdate);
                if SQL%ROWCOUNT = 0 THEN
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
end sp_merch_balance_update_aval;
/
