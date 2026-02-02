CREATE OR REPLACE FUNCTION sp_psp_master_insert(
	in_client_id		psp_master.pm_client_id%type,
	in_client_name		psp_master.pm_client_name%type,
	in_status		psp_master.pm_status%type,
	in_mode_type		psp_master.pm_mode_type%type,
	in_code			psp_master.pm_code%type,
	in_code_in_num		psp_master.pm_code_in_num%type,
	in_create_user		psp_master.pm_create_user%type)
RETURN NUMBER IS

BEGIN
	UPDATE psp_master
	set	pm_client_name = in_client_name,
		pm_status = in_status,
		pm_mode_type = in_mode_type,
		pm_code	= in_code,
		pm_code_in_num = in_code_in_num,
		pm_update_timestamp = sysdate,
		pm_update_user = in_create_user
		 where pm_client_id = in_client_id;

	if SQL%ROWCOUNT = 0 THEN

	INSERT INTO psp_master(
		pm_client_id,
		pm_client_name,
		pm_status,
		pm_create_timestamp,
		pm_create_user,
		pm_update_timestamp,
		pm_update_user,
		pm_mode_type,
		pm_code,
		pm_code_in_num
	)

	VALUES(
		in_client_id,
		in_client_name,
		in_status,
		sysdate,
		in_create_user,
		sysdate,
		in_create_user,
		in_mode_type,
		in_code,
		in_code_in_num
	);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

	else
		return 0;
	end if;


EXCEPTION
 WHEN OTHERS THEN
	RETURN 9;

END sp_psp_master_insert;
/
