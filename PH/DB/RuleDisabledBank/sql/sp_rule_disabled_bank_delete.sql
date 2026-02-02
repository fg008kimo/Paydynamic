CREATE OR REPLACE FUNCTION sp_rule_disabled_bank_delete(
	in_bank_code		rule_disabled_bank.rb_bank_code%type,
	in_party_type		rule_disabled_bank.rb_type%type,
	in_channel_code		rule_disabled_bank.rb_channel_code%type,
	in_party_id		rule_disabled_bank.rb_party_id%type,
	in_scheduler_id		rule_disabled_bank.rb_scheduler_id%type,
	in_disabled		rule_disabled_bank.rb_disabled%type
	)
  RETURN NUMBER IS

BEGIN

  IF in_party_type = 'G' then
  	DELETE FROM rule_disabled_bank
	WHERE rb_bank_code = in_bank_code
	AND   rb_type = in_party_type
	AND   rb_channel_code = in_channel_code
	AND   rb_scheduler_id = in_scheduler_id
	/*AND   rb_disabled = in_disabled*/
	;

  ELSE
  	DELETE FROM rule_disabled_bank
	WHERE rb_bank_code = in_bank_code
	AND   rb_type = in_party_type
	AND   rb_party_id = in_party_id 
	AND   rb_scheduler_id = in_scheduler_id
 	/*AND   rb_disabled = in_disabled*/
	;

  END IF;


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
