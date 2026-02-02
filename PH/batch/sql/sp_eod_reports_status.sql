CREATE OR REPLACE FUNCTION sp_eod_reports_status (
  in_report_id                  eod_reports_status.ers_report_id%Type
 )
  RETURN CHAR Is
	cStatus char := ' ';
Begin

   select ers_status
     into cStatus
     FROM eod_reports_status
    WHERE ers_report_id = in_report_id;

   If Sql%Rowcount = 0 Then
      Return ' ';
   Else
       Return cStatus;
   End If;
EXCEPTION
  WHEN OTHERS THEN
     RETURN ' ';

END sp_eod_reports_status;
/
