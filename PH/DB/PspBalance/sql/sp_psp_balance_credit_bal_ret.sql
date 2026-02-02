CREATE OR REPLACE FUNCTION sp_psp_balance_credit_bal_ret (
	in_psp_id	IN	psp_balance.pb_psp_id%TYPE, 
	in_country_id	IN	psp_balance.pb_country_id%TYPE, 
	in_currency_id	IN	psp_balance.pb_currency_id%TYPE, 
	in_bal		IN	psp_balance.pb_bal%TYPE, 
	in_create_user	IN	psp_balance.pb_create_user%TYPE, 
	out_cursor	OUT	SYS_REFCURSOR)
RETURN NUMBER IS
	out_psp_bal	psp_balance.pb_bal%TYPE		:= -1;
	out_total_float	psp_balance.pb_total_float%TYPE	:= -1;
	out_total_hold	psp_balance.pb_total_hold%TYPE	:= -1;
BEGIN
	UPDATE psp_balance 
	SET	pb_bal = pb_bal + in_bal, 
		pb_update_user = in_create_user, 
		pb_update_timestamp = sysdate 
	WHERE	pb_psp_id = in_psp_id AND 
		pb_country_id = in_country_id AND 
		pb_currency_id = in_currency_id 
	RETURNING	pb_bal, 
			pb_total_float, 
			pb_total_hold 
	INTO	out_psp_bal, 
		out_total_float, 
		out_total_hold;

	IF SQL%ROWCOUNT = 0 THEN
		INSERT INTO psp_balance (
			pb_psp_id, 
			pb_country_id, 
			pb_currency_id, 
			pb_bal, 
			pb_create_user, 
			pb_update_user, 
			pb_create_timestamp, 
			pb_update_timestamp)
		VALUES (
			in_psp_id, 
			in_country_id, 
			in_currency_id, 
			in_bal, 
			in_create_user, 
			in_create_user, 
			sysdate, 
			sysdate)
		RETURNING	pb_bal, 
				pb_total_float, 
				pb_total_hold 
		INTO	out_psp_bal, 
			out_total_float, 
			out_total_hold;

		IF SQL%ROWCOUNT = 0 THEN
			RETURN 1;
		ELSE
			OPEN out_cursor FOR 
			SELECT	out_psp_bal, 
				out_total_float, 
				out_total_hold 
			FROM DUAL;

			RETURN 0;
		END IF;
	ELSE
		OPEN out_cursor FOR 
		SELECT	out_psp_bal, 
			out_total_float, 
			out_total_hold 
		FROM DUAL;

		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_psp_balance_credit_bal_ret;
/

