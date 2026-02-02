CREATE OR REPLACE FUNCTION sp_test_zale_update_return_c3 (
	in_txn_code	IN 	test_zale.tz_txn_code%type, 
	in_value	IN	test_zale.tz_value%type, 
	out_cursor	OUT	SYS_REFCURSOR)
RETURN NUMBER IS
	out_group	test_zale.tz_group%type := NULL;
	out_flag	test_zale.tz_flag%type := -1;
	out_value	test_zale.tz_value%type := -1;
	out_remark	test_zale.tz_remark%type := NULL;
BEGIN
	UPDATE test_zale 
	SET tz_flag = tz_flag + 1, 
	    tz_value = tz_value + in_value, 
	    tz_update_timestamp = sysdate 
	WHERE tz_txn_code = in_txn_code 
	RETURNING tz_group, 
		  tz_flag, 
		  tz_value, 
		  tz_remark 
	INTO out_group, 
	     out_flag, 
	     out_value, 
	     out_remark;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		OPEN out_cursor FOR 
		SELECT out_group, 
		       out_flag, 
		       out_value, 
		       out_remark 
		FROM DUAL;

		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_test_zale_update_return_c3;
/
