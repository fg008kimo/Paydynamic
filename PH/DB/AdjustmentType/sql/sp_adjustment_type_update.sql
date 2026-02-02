CREATE OR REPLACE FUNCTION sp_adjustment_type_update(
	in_party_type		adjustment_type.at_party_type%type,
	in_code			adjustment_type.at_code%type,
	in_dc_ind		adjustment_type.at_dc_ind%type,
	in_desc			adjustment_type.at_desc%type,
	in_dual_control		adjustment_type.at_dual_control%type,
	in_fee_type		adjustment_type.at_fee_type%type,
	in_disabled		adjustment_type.at_disabled%type,
	in_update_user		adjustment_type.at_update_user%type
	)
  RETURN NUMBER IS

BEGIN

  UPDATE adjustment_type 
     SET at_dc_ind = in_dc_ind,
	 at_desc = in_desc,
	 at_dual_control = NVL(in_dual_control, at_dual_control),
	 at_fee_type = NVL(in_fee_type, at_fee_type),
	 at_disabled = in_disabled,
         at_update_user = in_update_user,
         at_update_timestamp = sysdate
   WHERE at_party_type = in_party_type
     AND at_code = in_code;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_adjustment_type_update;
/
