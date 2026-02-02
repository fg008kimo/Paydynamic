CREATE OR REPLACE FUNCTION sp_psp_url_delete(
	in_psp_id		psp_url.psp_id%type,
	in_url			psp_url.url%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM psp_url
	WHERE	psp_id=in_psp_id
	AND	url=in_url;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_psp_url_delete;
/
