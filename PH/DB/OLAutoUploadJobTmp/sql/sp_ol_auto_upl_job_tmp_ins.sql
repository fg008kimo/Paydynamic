CREATE OR REPLACE FUNCTION sp_ol_auto_upl_job_tmp_ins (
   in_job_seq			ol_auto_upload_job_tmp.oaujt_job_seq%TYPE,
   in_status             	ol_auto_upload_job_tmp.oaujt_status%TYPE,
   in_create_user             	ol_auto_upload_job_tmp.oaujt_create_user%TYPE)
   RETURN NUMBER 
IS
BEGIN

   INSERT INTO ol_auto_upload_job_tmp (oaujt_job_seq,
				       oaujt_status,
                              	       oaujt_create_timestamp,
                               	       oaujt_create_user)
   VALUES (in_job_seq,
	   in_status,
           SYSDATE,
           in_create_user);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
   WHEN OTHERS THEN
      	RETURN 9;
END sp_ol_auto_upl_job_tmp_ins;
/
