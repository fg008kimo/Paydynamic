CREATE OR REPLACE FUNCTION sp_mms_adj_type_delete(
        in_code                   	mms_adjustment_type.mat_code%type
        )
  RETURN NUMBER IS

BEGIN
  DELETE FROM mms_adjustment_type
        WHERE   mat_code = in_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_mms_adj_type_delete;
/
