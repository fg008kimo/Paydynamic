CREATE OR REPLACE FUNCTION sp_merchant_bal_insert_fl_ret (
	in_merchant_id	IN	merchant_balance.m_merchant_id%TYPE, 
	in_country_id	IN	merchant_balance.m_country_id%TYPE, 
	in_currency_id	IN	merchant_balance.m_currency_id%TYPE, 
	in_service_code	IN	merchant_balance.m_service_code%TYPE, 
	in_net_amt	IN	merchant_balance.m_total_float%TYPE, 
	in_reserved_amt	IN	merchant_balance.m_total_reserved_amount%TYPE, 
	in_create_user	IN	merchant_balance.m_create_user%TYPE, 
	out_cursor	OUT	SYS_REFCURSOR)
RETURN NUMBER IS
	out_current_bal			merchant_balance.m_current_bal%TYPE			:= -1;
	out_current_bal_settlement	merchant_balance.m_current_bal_settlement%TYPE		:= -1;
	out_total_float			merchant_balance.m_total_float%TYPE			:= -1;
	out_total_float_after_payout	merchant_balance.m_total_float_after_payout%TYPE	:= -1;
	out_total_float_settlement	merchant_balance.m_total_float_settlement%TYPE		:= -1;
	out_total_reserved_amount	merchant_balance.m_total_reserved_amount%TYPE		:= -1;
	out_fundin_payout		merchant_balance.m_fundin_payout%TYPE			:= -1;
	out_reserved_payout		merchant_balance.m_reserved_payout%TYPE			:= -1;
	out_total_hold			merchant_balance.m_total_hold%TYPE			:= -1;
	out_total_hold_settlement	merchant_balance.m_total_hold_settlement%TYPE		:= -1;
BEGIN
	UPDATE merchant_balance 
	SET m_current_bal = m_current_bal + (in_net_amt - in_reserved_amt), 
		m_current_bal_settlement = m_current_bal_settlement + in_reserved_amt, 
		m_total_float = m_total_float + (in_net_amt - in_reserved_amt), 
		m_total_reserved_amount = m_total_reserved_amount + in_reserved_amt, 
		m_update_user = in_create_user, 
		m_update_timestamp = SYSDATE 
	WHERE	m_merchant_id = in_merchant_id AND 
		m_currency_id = in_currency_id AND 
		m_country_id = in_country_id AND 
		m_service_code = in_service_code 
	RETURNING	m_current_bal, 
			m_current_bal_settlement, 
			m_total_float, 
			m_total_float_after_payout, 
			m_total_float_settlement, 
			m_total_reserved_amount, 
			m_fundin_payout, 
			m_reserved_payout, 
			m_total_hold, 
			m_total_hold_settlement 
	INTO	out_current_bal, 
		out_current_bal_settlement, 
		out_total_float, 
		out_total_float_after_payout, 
		out_total_float_settlement, 
		out_total_reserved_amount, 
		out_fundin_payout, 
		out_reserved_payout, 
		out_total_hold, 
		out_total_hold_settlement;

	IF SQL%ROWCOUNT = 0 THEN
		INSERT INTO merchant_balance (
			m_merchant_id, 
			m_currency_id, 
			m_country_id, 
			m_service_code, 
			m_current_bal, 
			m_current_bal_settlement, 
			m_total_float, 
			m_total_reserved_amount, 
			m_create_user, 
			m_update_user, 
			m_create_timestamp, 
			m_update_timestamp)
		VALUES (
			in_merchant_id, 
			in_currency_id, 
			in_country_id, 
			in_service_code, 
			(in_net_amt - in_reserved_amt), 
			in_reserved_amt, 
			(in_net_amt - in_reserved_amt), 
			in_reserved_amt, 
			in_create_user, 
			in_create_user, 
			SYSDATE, 
			SYSDATE) 
		RETURNING	m_current_bal, 
				m_current_bal_settlement, 
				m_total_float, 
				m_total_float_after_payout, 
				m_total_float_settlement, 
				m_total_reserved_amount, 
				m_fundin_payout, 
				m_reserved_payout, 
				m_total_hold, 
				m_total_hold_settlement 
		INTO	out_current_bal, 
			out_current_bal_settlement, 
			out_total_float, 
			out_total_float_after_payout, 
			out_total_float_settlement, 
			out_total_reserved_amount, 
			out_fundin_payout, 
			out_reserved_payout, 
			out_total_hold, 
			out_total_hold_settlement;

		IF SQL%ROWCOUNT = 0 THEN
			RETURN 1;
		ELSE
			OPEN out_cursor FOR 
			SELECT	out_current_bal, 
				out_current_bal_settlement, 
				out_total_float, 
				out_total_float_after_payout, 
				out_total_float_settlement, 
				out_total_reserved_amount, 
				out_fundin_payout, 
				out_reserved_payout, 
				out_total_hold, 
				out_total_hold_settlement 
			FROM DUAL;

			RETURN 0;
		END IF;
	ELSE
		OPEN out_cursor FOR 
		SELECT	out_current_bal, 
			out_current_bal_settlement, 
			out_total_float, 
			out_total_float_after_payout, 
			out_total_float_settlement, 
			out_total_reserved_amount, 
			out_fundin_payout, 
			out_reserved_payout, 
			out_total_hold, 
			out_total_hold_settlement 
		FROM DUAL;

		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_merchant_bal_insert_fl_ret;
/
