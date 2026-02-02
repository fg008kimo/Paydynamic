CREATE OR REPLACE FUNCTION sp_rule_auto_sett_insert(
	in_rule_id	 	rule_auto_settlement.rs_id%type,
	in_rs_type		rule_auto_settlement.rs_type%type,
	in_rs_value		rule_auto_settlement.rs_value%type,
	in_rs_min_amount	rule_auto_settlement.rs_min_amount%type,
	in_rs_desc		rule_auto_settlement.rs_desc%type,
	in_rs_disabled		rule_auto_settlement.rs_disabled%type,
	in_create_user		rule_auto_settlement.rs_create_user%type)
  RETURN NUMBER IS
	
BEGIN

  INSERT INTO rule_auto_settlement(
	rs_id,
	rs_type,
	rs_value,
	rs_min_amount,
	rs_desc,
	rs_disabled,
	rs_create_timestamp,
	rs_create_user,
        rs_update_timestamp,
        rs_update_user
	)

  VALUES(
	in_rule_id,
	in_rs_type,
	in_rs_value,
	in_rs_min_amount,
	in_rs_desc,
        in_rs_disabled,
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

END sp_rule_auto_sett_insert;
/
