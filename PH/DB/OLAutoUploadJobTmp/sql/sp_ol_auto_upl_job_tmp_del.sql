CREATE OR REPLACE FUNCTION sp_ol_auto_upl_job_tmp_del(
	in_job_seq			ol_auto_upload_job_tmp.oaujt_job_seq%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM ol_auto_upload_job_tmp
	WHERE oaujt_job_seq = in_job_seq;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_auto_upl_job_tmp_del;
/
