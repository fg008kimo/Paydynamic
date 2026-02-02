CREATE OR REPLACE FUNCTION sp_test_zale_update_return (
	in_txn_code	IN 	test_zale.tz_txn_code%type, 
	in_value	IN	test_zale.tz_value%type, 
	out_group	OUT	test_zale.tz_group%type, 
	out_flag	OUT	test_zale.tz_flag%type, 
	out_value	OUT	test_zale.tz_value%type, 
	out_remark	OUT	test_zale.tz_remark%type)
RETURN NUMBER IS
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
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_test_zale_update_return;
/
