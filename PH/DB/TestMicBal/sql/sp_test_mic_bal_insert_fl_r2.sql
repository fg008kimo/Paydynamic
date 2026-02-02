CREATE OR REPLACE FUNCTION sp_test_mic_bal_insert_fl_r2(
	in_merchant_id		test_mic_bal.m_merchant_id%type,
	in_country_id		test_mic_bal.m_country_id%type,
	in_currency_id		test_mic_bal.m_currency_id%type,
	in_service_code		test_mic_bal.m_service_code%type,
	in_net_amt			test_mic_bal.m_total_float%type,
	in_reserved_amt		test_mic_bal.m_total_reserved_amount%type,
	in_create_user		test_mic_bal.m_create_user%type,
	out_cursor			SYS_REFCURSOR
)
return number is

out_total_float					test_mic_bal.m_total_float%type;
out_current_bal					test_mic_bal.m_current_bal%type;
out_current_bal_settlement		test_mic_bal.m_current_bal_settlement%type;
out_total_reserved_amount		test_mic_bal.m_total_reserved_amount%type;
result number(1);

begin
	update test_mic_bal
	  set m_total_float = m_total_float + (in_net_amt - in_reserved_amt),
	      m_current_bal = m_current_bal + (in_net_amt - in_reserved_amt),
	      m_current_bal_settlement = m_current_bal_settlement + in_reserved_amt,
	      m_total_reserved_amount = m_total_reserved_amount + in_reserved_amt,
		  m_update_user = in_create_user,
	      m_update_timestamp = sysdate
        where m_merchant_id = in_merchant_id
          and m_currency_id = in_currency_id
	  and m_country_id = in_country_id
	  and m_service_code = in_service_code
      returning m_total_float, m_current_bal, m_current_bal_settlement, m_total_reserved_amount 
      into out_total_float, out_current_bal, out_current_bal_settlement, out_total_reserved_amount;

	if SQL%ROWCOUNT = 0 THEN
		insert into test_mic_bal
			(m_merchant_id,
			 m_currency_id,
			 m_country_id,
			 m_service_code,
			 m_total_float,
			 m_current_bal,
			 m_total_reserved_amount,
			 m_current_bal_settlement,
			 m_create_user,
			 m_update_user,
			 m_create_timestamp,
			 m_update_timestamp)
		values(in_merchant_id,
				in_currency_id,
				in_country_id,
				in_service_code,
		       (in_net_amt - in_reserved_amt),
			   (in_net_amt - in_reserved_amt),
				in_reserved_amt,
				in_reserved_amt,
				in_create_user,
				in_create_user,
		       sysdate,
		       sysdate)
		returning m_total_float, m_current_bal, m_current_bal_settlement, m_total_reserved_amount 
		into out_total_float, out_current_bal, out_current_bal_settlement, out_total_reserved_amount;
		if SQL%ROWCOUNT = 0 THEN
			result := 1;
		else
			result := 0;
		end if;
	else
		result := 0;
	end if;

	if result = 0 then
		OPEN out_cursor for 
		select
		out_total_float,
		out_current_bal,
		out_current_bal_settlement,
		out_total_reserved_amount from dual;
	end if;
	
	return result;
	
exception
  when others then
  return 9;
end sp_test_mic_bal_insert_fl_r2;
/
