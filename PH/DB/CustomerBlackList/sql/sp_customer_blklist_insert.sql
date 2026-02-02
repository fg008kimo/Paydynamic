CREATE OR REPLACE FUNCTION sp_customer_blklist_insert(
	in_merchant_id		CUSTOMER_BLACK_LIST.cbl_merchant_id%type,
	in_cust_id		CUSTOMER_BLACK_LIST.cbl_cust_id%type,
	in_disabled		CUSTOMER_BLACK_LIST.cbl_disabled%type,
	in_create_user		CUSTOMER_BLACK_LIST.cbl_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO CUSTOMER_BLACK_LIST(
	cbl_merchant_id,
    cbl_cust_id,
    cbl_disabled,
	cbl_create_timestamp,
	cbl_create_user,
	cbl_update_timestamp,
	cbl_update_user
	)

  VALUES(
	in_merchant_id,
	in_cust_id,
	in_disabled,
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

END sp_customer_blklist_insert;
/
