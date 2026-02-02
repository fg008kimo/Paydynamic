CREATE OR REPLACE FUNCTION sp_test_nini_insert(
	in_txn_code		test_nini.tn_txn_code%type,
	in_service_code		test_nini.tn_service_code%type,
	in_daily_limit		test_nini.tn_daily_limit%type,
	in_sys_support		test_nini.tn_sys_support%type,
	in_desc			test_nini.tn_desc%type,
	in_user			test_nini.tn_create_user%type
)
RETURN NUMBER IS
BEGIN
  INSERT INTO test_nini(
	tn_txn_code,
	tn_service_code,
	tn_daily_limit,
	tn_sys_support,
	tn_desc,
	tn_create_timestamp,
	tn_create_user,
 	tn_update_timestamp,
 	tn_update_user
	)

  VALUES(
	in_txn_code,
	in_service_code,
	in_daily_limit,
	in_sys_support,
	in_desc,
	sysdate,
	in_user,
 	sysdate,
	in_user
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_test_nini_insert;
/


