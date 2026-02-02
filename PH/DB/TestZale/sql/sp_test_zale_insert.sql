CREATE OR REPLACE FUNCTION sp_test_zale_insert (
	in_txn_code		test_zale.tz_txn_code%type,
	in_group		test_zale.tz_group%type,
	in_flag			test_zale.tz_flag%type,
	in_value		test_zale.tz_value%type,
	in_remark		test_zale.tz_remark%type,
	in_create_user	test_zale.tz_create_user%type)
RETURN NUMBER IS
BEGIN
	INSERT INTO test_zale (
		tz_txn_code,
		tz_group,
		tz_flag,
		tz_value,
		tz_remark,
		tz_create_user,
		tz_update_user) 
	VALUES (
		in_txn_code,
		in_group,
		in_flag,
		in_value,
		in_remark,
		in_create_user,
		in_create_user);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_test_zale_insert;
/
