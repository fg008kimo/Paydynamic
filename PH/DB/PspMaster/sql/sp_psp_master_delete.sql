CREATE OR REPLACE FUNCTION sp_psp_master_delete(
	in_client_id		psp_master.pm_client_id%type
)
RETURN NUMBER IS

BEGIN
	DELETE FROM psp_master
	WHERE	pm_client_id=in_client_id;


	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
 WHEN OTHERS THEN
	RETURN 9;

END sp_psp_master_delete;
/
