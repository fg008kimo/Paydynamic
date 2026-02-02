CREATE OR REPLACE FUNCTION sp_rule_disabled_bank_insert(
	in_bank_code		rule_disabled_bank.rb_bank_code%type,
	in_party_type 		rule_disabled_bank.rb_type%type,
	in_channel_code		rule_disabled_bank.rb_channel_code%type,
	in_party_id		rule_disabled_bank.rb_party_id%type,
	in_scheduler_id		rule_disabled_bank.rb_scheduler_id%type,
	in_note_id 		rule_disabled_bank.rb_note_id%type,
	in_disabled		rule_disabled_bank.rb_disabled%type,
	in_create_user		rule_disabled_bank.rb_create_user%type
	)
  RETURN NUMBEr IS


BEGIN


	INSERT INTO rule_disabled_bank(
		rb_bank_code,
		rb_type,
		rb_channel_code,
		rb_party_id,
		rb_scheduler_id,
		rb_note_id,
		rb_disabled,
		rb_create_user,
		rb_create_timestamp,
		rb_update_user,
		rb_update_timestamp
		)
	VALUES (	
		in_bank_code,
		in_party_type,
		in_channel_code,
		in_party_id,
		in_scheduler_id,
		in_note_id,
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
