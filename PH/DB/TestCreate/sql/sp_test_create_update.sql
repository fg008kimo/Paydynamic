CREATE OR REPLACE FUNCTION sp_test_create_update (
	in_key		test_create.tc_key%type,
    in_field		test_create.tc_field%type,
   	in_amount		test_create.tc_amount%type,
   	in_disabled		test_create.tc_disabled%type,
   	in_user		test_create.tc_create_user%type,
   	in_ccy  test_create.tc_ccy%type)
RETURN NUMBER IS
BEGIN
	UPDATE test_create
	SET tc_field = in_field,
		tc_amount = in_amount,
		tc_disabled = in_disabled,
		tc_ccy = in_ccy,
		tc_update_user = in_user,
		tc_update_timestamp = sysdate
	WHERE tc_key = in_key;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_test_create_update;
/
