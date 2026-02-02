CREATE OR REPLACE FUNCTION sp_rule_disabled_bank_insert(
	in_int_bank_code	rule_disabled_bank.rb_int_bank_code%type,
	in_disabled_bank_type	rule_disabled_bank.rb_disabled_bank_type%type,
	in_channel_code		rule_disabled_bank.rb_channel_code%type,
	in_client_id		rule_disabled_bank.rb_client_id%type,
	in_psp_id		rule_disabled_bank.rb_psp_id%type,
	in_scheduler_id		rule_disabled_bank.rb_scheduler_id%type,
	in_disabled		rule_disabled_bank.rb_disabled%type,
	in_create_user		rule_disabled_bank.rb_create_user%type,
	out_rule_disabled_bank_id	OUT rule_disabled_bank.rb_rule_disabled_bank_id%type
	)
  RETURN NUMBEr IS


BEGIN

	select NVL(max(rb_rule_disabled_bank_id), 0)
	into out_rule_disabled_bank_id
	from rule_disabled_bank;

	out_rule_disabled_bank_id := out_rule_disabled_bank_id + 1;


	INSERT INTO rule_disabled_bank(
		rb_rule_disabled_bank_id,
		rb_int_bank_code,
		rb_disabled_bank_type,
		rb_channel_code,
		rb_client_id,
		rb_psp_id,
		rb_scheduler_id,
		rb_disabled,
		rb_create_user,
		rb_create_timestamp,
		rb_update_user,
		rb_update_timestamp
		)
	VALUES (	
		out_rule_disabled_bank_id,
		in_int_bank_code,
		in_disabled_bank_type,
		in_channel_code,
		in_client_id,
		in_psp_id,
		in_scheduler_id,
		in_disabled,
		in_create_user,
		sysdate,
		in_create_user,
		sysdate
		);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_rule_disabled_bank_insert;
/
