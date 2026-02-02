CREATE OR REPLACE FUNCTION sp_test_zale_update_return_c (
	in_txn_code	IN 	test_zale.tz_txn_code%type, 
	in_value	IN	test_zale.tz_value%type, 
	out_cursor	OUT	SYS_REFCURSOR)
RETURN NUMBER IS
BEGIN
	UPDATE test_zale 
	SET tz_flag = tz_flag + 1, 
	    tz_value = tz_value + in_value, 
	    tz_update_timestamp = sysdate 
	WHERE tz_txn_code = in_txn_code;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		OPEN out_cursor FOR 
		SELECT tz_group, 
		       tz_flag, 
		       tz_value, 
		       tz_remark 
		FROM test_zale 
		WHERE tz_txn_code = in_txn_code;

		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_test_zale_update_return_c;
/
