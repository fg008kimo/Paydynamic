CREATE OR REPLACE FUNCTION PHUSER.sp_crr_psp_product_code_ins(
        in_psp_id               crr_psp_product_code_map.pm_psp_id%type,
        in_business_type        crr_psp_product_code_map.pm_business_type%type,
        in_product_code         crr_psp_product_code_map.pm_product_code%type,
        in_disabled             crr_psp_product_code_map.pm_disabled%type,
        in_create_user          crr_psp_product_code_map.pm_create_user%type)
RETURN NUMBER IS

BEGIN

	INSERT INTO crr_psp_product_code_map(
		pm_psp_id,
		pm_business_type,
		pm_product_code,
		pm_disabled,
		pm_create_user,
		pm_create_timestamp,
		pm_update_user,
		pm_update_timestamp
	)
	VALUES(
		in_psp_id,
		in_business_type,
		in_product_code,
		in_disabled,
		in_create_user,
		sysdate,
		in_create_user,
		sysdate
	);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;



EXCEPTION
 WHEN OTHERS THEN
	RETURN 9;

END sp_crr_psp_product_code_ins;
/

