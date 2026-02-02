CREATE OR REPLACE FUNCTION sp_rule_outage_note_delete(
	in_note_id		rule_outage_note.ron_note_id%type
	)
  RETURN NUMBER IS

BEGIN

  DELETE FROM rule_outage_note
  WHERE ron_note_id = in_note_id;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_rule_outage_note_delete;
/
