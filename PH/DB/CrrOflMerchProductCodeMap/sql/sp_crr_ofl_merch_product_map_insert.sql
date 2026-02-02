create or replace function sp_crr_ofl_merch_map_insert(
       in_merch_id                              crr_ofl_merch_product_code_map.ompm_merch_id%type,
       in_service_code                          crr_ofl_merch_product_code_map.ompm_service_code%type,
       in_country	                        crr_ofl_merch_product_code_map.ompm_country%type,
       in_effective_date                        crr_ofl_merch_product_code_map.ompm_effective_date%type,
       in_product_code                          crr_ofl_merch_product_code_map.ompm_product_code%type,
       in_create_user				crr_ofl_merch_product_code_map.ompm_create_user%type)

  RETURN NUMBER IS
begin

  insert into crr_ofl_merch_product_code_map
               (ompm_merch_id,
		ompm_service_code,
		ompm_country,
		ompm_effective_date,
		ompm_product_code,
		ompm_create_timestamp,
		ompm_update_timestamp,
		ompm_create_user,
		ompm_update_user)
         values(in_merch_id,
		in_service_code,
		in_country,
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
end sp_crr_ofl_merch_map_insert;
/
