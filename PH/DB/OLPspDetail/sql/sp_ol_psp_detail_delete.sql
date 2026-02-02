CREATE OR REPLACE FUNCTION sp_ol_psp_detail_delete(
	in_psp_id		ol_psp_detail.opd_psp_id%type,
	in_client_id		ol_psp_detail.opd_client_id%type
	)
RETURN NUMBER IS

BEGIN
	DELETE FROM ol_psp_detail
	WHERE opd_psp_id = in_psp_id
	AND opd_client_id = in_client_id;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_ol_psp_detail_delete;
/
