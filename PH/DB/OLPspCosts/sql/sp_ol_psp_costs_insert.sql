CREATE OR REPLACE FUNCTION sp_ol_psp_costs_insert(
	in_rule_id		ol_psp_costs.opc_rule_id%type,
	in_party_type		ol_psp_costs.opc_party_type%type,
	in_party_id		ol_psp_costs.opc_party_id%type,
	in_cat_id		ol_psp_costs.opc_cat_id%type,
	in_effect_date		ol_psp_costs.opc_effect_date%type,
	in_cal_method		ol_psp_costs.opc_cal_method%type,
	in_charge_period_type	ol_psp_costs.opc_charge_period_type%type,
	in_grouping_type	ol_psp_costs.opc_grouping_type%type,
	in_costing_method	ol_psp_costs.opc_costing_method%type,
	in_value		ol_psp_costs.opc_value%type,
	in_additional_value	ol_psp_costs.opc_additional_value%type,
	in_min_value		ol_psp_costs.opc_min_value%type,
	in_max_value		ol_psp_costs.opc_max_value%type,
	in_value_type		ol_psp_costs.opc_value_type%type,
	in_scale		ol_psp_costs.opc_scale%type,
	in_disabled		ol_psp_costs.opc_disabled%type,
	in_create_user		ol_psp_costs.opc_create_user%type)
  RETURN NUMBER IS
BEGIN
	INSERT INTO OL_PSP_COSTS(
		opc_rule_id,
		opc_party_type,
		opc_party_id,
		opc_cat_id,
		opc_effect_date,
		opc_cal_method,
		opc_charge_period_type,
		opc_grouping_type,
		opc_costing_method,
		opc_value,
		opc_additional_value,
		opc_min_value,
		opc_max_value,
		opc_value_type,
		opc_scale,
		opc_disabled,
		opc_create_timestamp,
		opc_create_user,
		opc_update_timestamp,
		opc_update_user
		)
	VALUES (
		in_rule_id,
		in_party_type,
		in_party_id,
		in_cat_id,
		to_date(in_effect_date,'YYYYMMDDHH24MISS'),
		in_cal_method,
		in_charge_period_type,
		in_grouping_type,
		in_costing_method,
		in_value ,
		in_additional_value,
		in_min_value,
		in_max_value,
		in_value_type,
		in_scale,
		in_disabled,
		sysdate,
		in_create_user,
		sysdate,
		in_create_user
		);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_ol_psp_costs_insert;
/
