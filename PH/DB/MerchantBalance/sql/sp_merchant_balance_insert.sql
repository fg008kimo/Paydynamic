CREATE OR REPLACE FUNCTION sp_merchant_balance_insert(
	in_merchant_id		merchant_balance.m_merchant_id%type,
	in_currency_id		merchant_balance.m_currency_id%type,
	in_country_id		merchant_balance.m_country_id%type,
	in_service_code		merchant_balance.m_service_code%type,
	in_create_user		merchant_balance.m_create_user%type
)
return number is
begin
		insert into merchant_balance
			(m_merchant_id,
			 m_currency_id,
			 m_country_id,
			 m_service_code,
			 m_create_user,
			 m_update_user,
			 m_create_timestamp,
			 m_update_timestamp)
		values(in_merchant_id,
                       in_currency_id,
                       in_country_id,
		       in_service_code,
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
end sp_merchant_balance_insert;
/
