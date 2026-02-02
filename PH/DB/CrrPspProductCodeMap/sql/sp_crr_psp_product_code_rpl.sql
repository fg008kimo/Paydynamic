CREATE OR REPLACE FUNCTION sp_crr_psp_product_code_rpl (
	in_replicate_psp_id          IN		 crr_psp_product_code_map.pm_psp_id%TYPE,
	in_create_psp_id             IN	         crr_psp_product_code_map.pm_psp_id%TYPE,
	in_create_user               IN          crr_psp_product_code_map.pm_create_user%TYPE
)
RETURN NUMBER IS
	iRecCnt		      	  INTEGER := 0;
	
BEGIN

	SELECT COUNT(1)
	INTO iRecCnt
	FROM crr_psp_product_code_map
	WHERE pm_psp_id = in_replicate_psp_id;

	IF iRecCnt > 1 or iRecCnt = 0
	THEN
		RETURN 2;
	END IF;
  
  
	INSERT INTO crr_psp_product_code_map (
		pm_psp_id,
		pm_business_type,
		pm_product_code,
		pm_disabled,
		pm_create_user,
		pm_create_timestamp,
		pm_update_user,
		pm_update_timestamp
	)
	SELECT  in_create_psp_id, 
			pm_business_type,
			pm_product_code,
			0,
			in_create_user,
			sysdate,
			in_create_user,
			sysdate
	from crr_psp_product_code_map
	where pm_psp_id = in_replicate_psp_id;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_crr_psp_product_code_rpl;
/
