CREATE OR REPLACE FUNCTION sp_service_psp_url_delete (
	in_psp_id	IN	service_psp_url.pu_psp_id%TYPE, 
	in_service_code	IN	service_psp_url.pu_service_code%TYPE)
RETURN NUMBER IS
BEGIN
	DELETE FROM	service_psp_url 
	WHERE		pu_psp_id = in_psp_id
			AND pu_service_code = in_service_code;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_service_psp_url_delete;
/
