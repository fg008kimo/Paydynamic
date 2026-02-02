CREATE OR REPLACE FUNCTION sp_rule_disabled_bank_delete(
	in_rule_disabled_bank_id	rule_disabled_bank.rb_rule_disabled_bank_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM rule_disabled_bank
	WHERE	rb_rule_disabled_bank_id = in_rule_disabled_bank_id;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_rule_disabled_bank_delete;
/
