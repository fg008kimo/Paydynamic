create or replace function sp_crr_ofl_psp_map_insert(
       in_psp_id                                crr_ofl_psp_product_code_map.oppm_psp_id%type,
       in_business_type                         crr_ofl_psp_product_code_map.oppm_business_type%type,
       in_effective_date                        crr_ofl_psp_product_code_map.oppm_effective_date%type,
       in_product_code                          crr_ofl_psp_product_code_map.oppm_product_code%type,
       in_create_user				crr_ofl_psp_product_code_map.oppm_create_user%type)

  RETURN NUMBER IS
begin

  insert into crr_ofl_psp_product_code_map
               (oppm_psp_id,
		oppm_business_type,
		oppm_effective_date,
		oppm_product_code,
		oppm_create_timestamp,
		oppm_update_timestamp,
		oppm_create_user,
		oppm_update_user)
         values(in_psp_id,
		in_business_type,
		in_effective_date,
		in_product_code,
		sysdate,
		sysdate,
		in_create_user,
		in_create_user);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_crr_ofl_psp_map_insert;
/
