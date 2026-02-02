CREATE OR REPLACE FUNCTION sp_ol_statement_tmp_delete(
	in_file_id              ol_statement_tmp.olst_file_id%type
        )
  RETURN NUMBER IS

BEGIN
  DELETE FROM ol_statement_tmp
        WHERE   file_id=in_file_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_statement_tmp_delete;
