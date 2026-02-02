CREATE OR REPLACE FUNCTION sp_eod_jobs_status_run (
  in_job_id                     eod_jobs_status.es_job_id%Type,
  in_status                     eod_jobs_status.es_status%Type,
  in_lms_date                   eod_jobs_status.es_run_date%Type,
  in_update_user                eod_jobs_status.es_update_user%Type
 )
  RETURN NUMBER Is

Begin

  If in_status ='P' Then
     Update eod_jobs_status t
            Set es_status = in_status,
                es_run_date= in_lms_date,
                es_run_timestamp =Sysdate,
                es_update_user = in_update_user,
                es_update_timestamp = Sysdate
                Where es_job_id = in_job_id;
  Else   
         Update eod_jobs_status t
       Set es_status = in_status,
             t.es_run_completed_timestamp = Sysdate,
             es_update_user = in_update_user,
             es_update_timestamp = Sysdate
   Where es_job_id = in_job_id;
  End If;

   If Sql%Rowcount = 0 Then
      Return 1;
   Else
       Return 0;
    End If;
EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_eod_jobs_status_run;
/
