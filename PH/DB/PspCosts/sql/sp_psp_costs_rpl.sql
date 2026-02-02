CREATE OR REPLACE FUNCTION sp_psp_costs_rpl(
		in_replicate_psp_id          psp_costs.pc_psp_id%type,
		in_create_psp_id             psp_costs.pc_psp_id%type,
		in_create_user               psp_costs.pc_create_user%type
)
  RETURN NUMBER IS
  
  iRecCnt		      	  INTEGER := 0;
  
BEGIN

	select count(1)
	into iRecCnt
	from psp_costs
	where pc_psp_id = in_replicate_psp_id;

	IF iRecCnt = 0
	THEN
		return 0;
	END IF;
	
	INSERT INTO psp_costs(
		pc_psp_id,
		pc_effect_date,
		pc_precal_type,
		pc_precal_value,
		pc_precal_additional_value,
		pc_precal_min_value,
		pc_precal_max_value,
		pc_value_type,
		pc_scale,
		pc_disabled,
		pc_create_timestamp,
		pc_create_user,
		pc_update_timestamp,
		pc_update_user,
		pc_txn_type,
		pc_cost_type,
		pc_cost_charging_method
		)
	SELECT in_create_psp_id, 
			pc_effect_date,
			pc_precal_type,
			pc_precal_value,
			pc_precal_additional_value,
			pc_precal_min_value,
			pc_precal_max_value,
			pc_value_type,
			pc_scale,
			pc_disabled,
			sysdate,
			in_create_user,
			sysdate,			
			in_create_user,			
			pc_txn_type,			
			pc_cost_type,			
			pc_cost_charging_method		
	from psp_costs
	where pc_psp_id = in_replicate_psp_id;
		

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_psp_costs_rpl;
/
