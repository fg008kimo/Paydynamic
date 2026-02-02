CREATE OR REPLACE FUNCTION sp_merchant_pay_method_insert(
	in_merchant_id		merchant_pay_method.pm_merchant_id%type,
	in_pay_method		merchant_pay_method.pm_pay_method%type,
	in_disabled		merchant_pay_method.pm_disabled%type,
	in_create_user		merchant_pay_method.pm_create_user%type)
RETURN NUMBER IS
	iCnt		INTEGER := 0;
BEGIN

	SELECT	count(*)
	INTO	iCnt
	FROM	merchant_pay_method
	WHERE	pm_merchant_id = in_merchant_id
	AND	pm_pay_method = in_pay_method;

	if iCnt = 0 then
		insert into merchant_pay_method 
			(pm_merchant_id,
			 pm_pay_method,
			 pm_disabled,
			 pm_create_timestamp,
			 pm_create_user,
			 pm_update_timestamp,
			 pm_update_user)
		values (in_merchant_id,
			in_pay_method,
			in_disabled,
			sysdate,
			in_create_user,
			sysdate,
			in_create_user);
	end if;
	
	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_merchant_pay_method_insert;
/
	
