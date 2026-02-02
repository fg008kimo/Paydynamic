CREATE OR REPLACE FUNCTION sp_eod_jobs_status_update (
  in_job_id                     eod_jobs_status.es_job_id%Type,
  in_status                     eod_jobs_status.es_status%Type,
  in_update_user                eod_jobs_status.es_update_user%Type
 )
  RETURN NUMBER Is

Begin

  Update eod_jobs_status t
       Set es_status = in_status,
             es_run_date= Null,
             es_run_timestamp = Null,
             es_run_completed_timestamp = Null,
             es_rerun_date = Null,
             es_rerun_timestamp = Null,
             es_rerun_completed_timestamp = Null,
             es_remarks = Null
   Where es_job_id = in_job_id;

   If Sql%Rowcount = 0 Then
            INSERT INTO eod_jobs_status(
                        es_job_id,
                        es_status,
                        es_create_user,
                        es_create_timestamp,
                        es_update_user,
                        es_update_timestamp)
             VALUES(
                        in_job_id,
                        in_status,
                        in_update_user,
                        sysdate,
                        in_update_user,
                        sysdate
                        );
            IF SQL%ROWCOUNT = 0 THEN
               RETURN 1;
            ELSE
              RETURN 0;
            END IF;
  Else
     Return 0;
  End If;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_eod_jobs_status_update;
/
