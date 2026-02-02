CREATE OR REPLACE FUNCTION sp_merch_login_policy_insert(
	in_client_id		merchant_login_policy.mp_client_id%type,
	in_login_policy_type	merchant_login_policy.mp_login_policy_type%type,
	in_value		merchant_login_policy.mp_val%type,
	in_create_user		merchant_login_policy.mp_create_user%type)
  RETURN NUMBER IS

BEGIN
    INSERT INTO merchant_login_policy (
	mp_client_id,
	mp_login_policy_type,
	mp_val,
	mp_create_timestamp,
	mp_create_user,
	mp_update_timestamp,
	mp_update_user
	)

    VALUES(
	in_client_id,
	in_login_policy_type,
	in_value,
	sysdate,
	in_create_user,
	sysdate,
	in_create_user
	);

    IF SQL%ROWCOUNT = 0 THEN
       RETURN 1;
    ELSE
       RETURN 0;
    END IF;


EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_login_policy_insert;
/
