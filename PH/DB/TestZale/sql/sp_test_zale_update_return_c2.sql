CREATE OR REPLACE FUNCTION sp_test_zale_update_return_c2 (
	in_txn_code	IN 	test_zale.tz_txn_code%type, 
	in_value	IN	test_zale.tz_value%type, 
	out_cursor	OUT	SYS_REFCURSOR)
RETURN NUMBER IS
	recResult	TEST_ZALE_RES_TAB;
BEGIN
	UPDATE test_zale 
	SET tz_flag = tz_flag + 1, 
	    tz_value = tz_value + in_value, 
	    tz_update_timestamp = sysdate 
	WHERE tz_txn_code = in_txn_code 
	RETURNING TEST_ZALE_REC_OBJ(tz_group, 
				    tz_flag, 
				    tz_value, 
				    tz_remark) 
	BULK COLLECT INTO recResult;

--	SELECT TEST_ZALE_REC_OBJ(t.tz_group, t.tz_flag, t.tz_value, t.tz_remark) 
--	BULK COLLECT INTO recResult
--	FROM test_zale t 
--	WHERE t.tz_txn_code = in_txn_code;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		OPEN out_cursor FOR SELECT * FROM TABLE(recResult);

		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_test_zale_update_return_c2;
/
