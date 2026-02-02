CREATE OR REPLACE FUNCTION sp_rule_outage_note_update(
	in_note_id		rule_outage_note.ron_note_id%type,
	in_language		rule_outage_note.ron_language%type,
	in_note 		rule_outage_note.ron_note%type,
	in_update_user		rule_outage_note.ron_update_user%type
	)
  RETURN NUMBER IS

BEGIN

  UPDATE rule_outage_note
     SET ron_language = NVL(in_language, ron_language),
	 ron_note = NVL(in_note, ron_note),
         ron_update_user = in_update_user,
         ron_update_timestamp = sysdate
   WHERE ron_note_id = in_note_id;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_rule_outage_note_update;
/
