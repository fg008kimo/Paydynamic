CREATE OR REPLACE FUNCTION sp_psp_restrict_ip_region_upd (
	in_psp_id	IN	psp_restrict_ip_region.pir_psp_id%TYPE, 
	in_region_code	IN	psp_restrict_ip_region.pir_region_code%TYPE, 
	in_disabled	IN	psp_restrict_ip_region.pir_disabled%TYPE, 
	in_create_user	IN	psp_restrict_ip_region.pir_create_user%TYPE)
RETURN NUMBER IS
BEGIN
	UPDATE	psp_restrict_ip_region 
	SET	pir_disabled = in_disabled, 
		pir_update_user = in_create_user, 
		pir_update_timestamp = sysdate 
	WHERE	pir_psp_id = in_psp_id 
		AND pir_region_code = in_region_code;
		

	IF SQL%ROWCOUNT = 0 THEN
		INSERT INTO psp_restrict_ip_region (
			pir_psp_id, 
			pir_region_code, 
			pir_disabled, 
			pir_create_user, 
			pir_update_user) 
		VALUES (
			in_psp_id, 
			in_region_code, 
			in_disabled, 
			in_create_user, 
			in_create_user);

		IF SQL%ROWCOUNT = 0 THEN
			RETURN 1;
		ELSE
			RETURN 0;
		END IF;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_psp_restrict_ip_region_upd;
/
