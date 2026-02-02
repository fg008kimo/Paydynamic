CREATE OR REPLACE FUNCTION sp_service_psp_url_insert (
	in_psp_id		IN	service_psp_url.pu_psp_id%TYPE, 
	in_service_code		IN	service_psp_url.pu_service_code%TYPE, 
	in_service_psp_url	IN	service_psp_url.pu_url%TYPE, 
	in_create_user		IN	service_psp_url.pu_create_user%TYPE)
RETURN NUMBER IS
BEGIN
	INSERT INTO service_psp_url (
		pu_psp_id, 
		pu_service_code, 
		pu_url, 
		pu_create_user, 
		pu_update_user)
	VALUES (
		in_psp_id, 
		in_service_code, 
		in_service_psp_url, 
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
END sp_service_psp_url_insert;
/
