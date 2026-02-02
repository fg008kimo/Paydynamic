CREATE OR REPLACE FUNCTION sp_mi_adjustment_type_update(
	in_entity_type		mi_adjustment_type.mat_entity_type%type,
	in_code			mi_adjustment_type.mat_code%type,
	in_desc			mi_adjustment_type.mat_desc%type,
	in_amt_type		mi_adjustment_type.mat_amt_type%type,
	in_bal_type		mi_adjustment_type.mat_bal_type%type,
	in_nature		mi_adjustment_type.mat_nature%type,
	in_is_prorata		mi_adjustment_type.mat_is_prorata%type,
	in_disabled		mi_adjustment_type.mat_disabled%type,
	in_update_user		mi_adjustment_type.mat_update_user%type
	)
  RETURN NUMBER IS

BEGIN

  UPDATE mi_adjustment_type 
     SET mat_desc = in_desc,
	 mat_amt_type = NVL(in_amt_type, mat_amt_type),
	 mat_bal_type = NVL(in_bal_type, mat_bal_type),
	 mat_nature = NVL(in_nature, mat_nature),
	 mat_is_prorata = in_is_prorata,
	 mat_disabled = in_disabled,
         mat_update_user = in_update_user,
         mat_update_timestamp = sysdate
   WHERE mat_entity_type = in_entity_type
     AND mat_code = in_code;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_mi_adjustment_type_update;
/
