CREATE OR REPLACE FUNCTION sp_test_create_insert(
	in_key		test_create.tc_key%type,
	in_field		test_create.tc_field%type,
	in_amount		test_create.tc_amount%type,
	in_disabled		test_create.tc_disabled%type,
	in_user		test_create.tc_create_user%type,
	in_currency_id  test_create.tc_ccy%type
)
RETURN NUMBER IS
BEGIN
  INSERT INTO test_create(
	tc_key,
	tc_field,
	tc_amount,
	tc_disabled,
	tc_create_timestamp,
    tc_update_timestamp,
    tc_create_user,
    tc_update_user,
    tc_ccy
	)

  VALUES(
	in_key,
	in_field,
	in_amount,
	in_disabled,
	sysdate,
    sysdate,
    in_user,
    in_user,
    in_currency_id
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_test_create_insert;
/


