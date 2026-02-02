CREATE OR REPLACE FUNCTION sp_eod_reports_status_run (
  in_report_id                  eod_reports_status.ers_report_id%Type,
  in_status                     eod_reports_status.ers_status%Type,
  in_date                       eod_reports_status.ers_run_date%Type,
  in_update_user                eod_reports_status.ers_update_user%Type
 )
  RETURN NUMBER Is

	iCnt    integer := 0;
	cStatus char := ' ';
Begin

  select count(*)
    INTO iCnt
  FROM eod_reports_status
   WHERE ers_report_id = in_report_id;

   if (iCnt = 0 ) then
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
   else 
	select ers_status
          INTO cStatus
          FROM eod_reports_status
         WHERE ers_report_id = in_report_id;
   end if;



  If in_status ='P' Then
     if (cStatus <> 'C') then
         Update eod_reports_status t
            Set ers_status = in_status,
                ers_run_date= in_date,
                ers_run_timestamp =Sysdate,
		ers_run_completed_timestamp = NULL,
                ers_update_user = in_update_user,
                ers_update_timestamp = Sysdate
                Where ers_report_id = in_report_id;
     else 
         Update eod_reports_status t
            Set ers_status = in_status,
                ers_rerun_date= in_date,
                ers_rerun_timestamp =Sysdate,
		ers_rerun_completed_timestamp = NULL,
                ers_update_user = in_update_user,
                ers_update_timestamp = Sysdate
                Where ers_report_id = in_report_id;
     end if;


  Elsif in_status = 'C' then

	if (cStatus <> 'C') then
		Update eod_reports_status t
                   Set ers_status = in_status,
                       t.ers_run_completed_timestamp = Sysdate,
                       ers_update_user = in_update_user,
                       ers_update_timestamp = Sysdate
                 WHERE ers_report_id = in_report_id;
	else
		Update eod_reports_status t
                   Set ers_status = in_status,
                       t.ers_rerun_completed_timestamp = Sysdate,
                       ers_update_user = in_update_user,
                       ers_update_timestamp = Sysdate
                 WHERE ers_report_id = in_report_id;
	end if;
  End If;

   If Sql%Rowcount = 0 Then
      Return 1;
   Else
       Return 0;
    End If;
EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_eod_reports_status_run;
/
