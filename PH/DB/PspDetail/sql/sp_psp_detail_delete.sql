CREATE OR REPLACE FUNCTION sp_psp_detail_delete(
	in_psp_id		psp_detail.psp_id%type,
	in_client_id		psp_detail.client_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM psp_detail
	WHERE	psp_id=in_psp_id
	AND	client_id=in_client_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_psp_detail_delete;
/
