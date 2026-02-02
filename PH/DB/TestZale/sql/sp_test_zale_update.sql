CREATE OR REPLACE FUNCTION sp_test_zale_update (
	in_txn_code	test_zale.tz_txn_code%type,
	in_group	test_zale.tz_group%type,
	in_flag		test_zale.tz_flag%type,
	in_value	test_zale.tz_value%type,
	in_remark	test_zale.tz_remark%type,
	in_update_user	test_zale.tz_update_user%type)
RETURN NUMBER IS
BEGIN
	UPDATE test_zale 
	SET tz_group = in_group,
		tz_flag = in_flag,
		tz_value = in_value,
		tz_remark = in_remark,
		tz_update_user = in_update_user,
		tz_update_timestamp = sysdate
	WHERE tz_txn_code = in_txn_code;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_test_zale_update;
/
