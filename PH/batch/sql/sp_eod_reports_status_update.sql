CREATE OR REPLACE FUNCTION sp_eod_reports_status_update (
  in_report_id                  eod_reports_status.ers_report_id%Type,
  in_status                     eod_reports_status.ers_status%Type,
  in_update_user                eod_reports_status.ers_update_user%Type
 )
  RETURN NUMBER Is

Begin

  Update eod_reports_status t
       Set ers_status = in_status,
             ers_run_date= Null,
             ers_run_timestamp = Null,
             ers_run_completed_timestamp = Null,
             ers_rerun_date = Null,
             ers_rerun_timestamp = Null,
             ers_rerun_completed_timestamp = Null,
             ers_remarks = Null
   Where ers_report_id = in_report_id;

   If Sql%Rowcount = 0 Then
            INSERT INTO eod_reports_status(
                        ers_report_id,
                        ers_status,
                        ers_create_user,
                        ers_create_timestamp,
                        ers_update_user,
                        ers_update_timestamp)
             VALUES(
                        in_report_id,
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

END sp_eod_reports_status_update;
/

