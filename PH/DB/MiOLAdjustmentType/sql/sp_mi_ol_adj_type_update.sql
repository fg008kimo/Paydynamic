CREATE OR REPLACE FUNCTION sp_mi_ol_adj_type_update(
	in_entity_type		mi_ol_adjustment_type.moat_entity_type%type,
	in_code			mi_ol_adjustment_type.moat_code%type,
	in_desc			mi_ol_adjustment_type.moat_desc%type,
	in_amt_type		mi_ol_adjustment_type.moat_amt_type%type,
	in_bal_type		mi_ol_adjustment_type.moat_bal_type%type,
	in_nature		mi_ol_adjustment_type.moat_nature%type,
	in_is_prorata		mi_ol_adjustment_type.moat_is_prorata%type,
	in_disabled		mi_ol_adjustment_type.moat_disabled%type,
	in_update_user		mi_ol_adjustment_type.moat_update_user%type
	)
  RETURN NUMBER IS

BEGIN

  UPDATE mi_ol_adjustment_type 
     SET moat_desc = in_desc,
	 moat_amt_type = NVL(in_amt_type, moat_amt_type),
	 moat_bal_type = NVL(in_bal_type, moat_bal_type),
	 moat_nature = NVL(in_nature, moat_nature),
	 moat_is_prorata = in_is_prorata,
	 moat_disabled = in_disabled,
         moat_update_user = in_update_user,
         moat_update_timestamp = sysdate
   WHERE moat_entity_type = in_entity_type
     AND moat_code = in_code;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_mi_ol_adj_type_update;
/
