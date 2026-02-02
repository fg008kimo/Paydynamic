CREATE OR REPLACE FUNCTION sp_rule_outage_note_insert(
	in_language		rule_outage_note.ron_language%type,
	in_note			rule_outage_note.ron_note%type,
	in_create_user		rule_outage_note.ron_create_user%type,
	out_note_id	OUT 	rule_outage_note.ron_note_id%type
	)
  RETURN NUMBEr IS

BEGIN

	select NVL(max(ron_note_id), 0)
	into out_note_id 
	from rule_outage_note;

	out_note_id := out_note_id + 1;


	INSERT INTO rule_outage_note(
		ron_note_id,
		ron_language,
		ron_note,
		ron_create_user,
		ron_create_timestamp,
		ron_update_user,
		ron_update_timestamp
		)
	VALUES (	
		out_note_id,
		in_language,
		in_note,
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

END sp_rule_outage_note_insert;
/
