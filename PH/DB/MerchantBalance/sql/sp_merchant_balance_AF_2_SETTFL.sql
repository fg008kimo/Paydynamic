CREATE OR REPLACE FUNCTION sp_merchant_balance_AF_2_SFL(
	in_merchant_id		merchant_balance.m_merchant_id%type,
	in_country_id		merchant_balance.m_country_id%type,
	in_currency_id		merchant_balance.m_currency_id%type,
	in_service_code		merchant_balance.m_service_code%type,
	in_float		merchant_balance.m_total_float%type,
	in_create_user		merchant_balance.m_create_user%type
)
return number is
begin
	update merchant_balance
	  set m_current_bal = m_current_bal - in_float,
              m_total_float_after_payout = m_total_float_after_payout - in_float,	 
	      m_current_bal_settlement = m_current_bal_settlement + in_float,
              m_total_float_settlement = m_total_float_settlement + in_float,
              m_update_user = in_create_user,
	      m_update_timestamp = sysdate
        where m_merchant_id = in_merchant_id
          and m_currency_id = in_currency_id
	  and m_country_id = in_country_id
	  and m_service_code = in_service_code;

	if SQL%ROWCOUNT = 0 THEN
		return 1;

	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_merchant_balance_AF_2_SFL;
/
