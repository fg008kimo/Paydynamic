CREATE OR REPLACE FUNCTION sp_system_control_chg_eoddate (
       in_lasthostdate_code          		system_control.sys_code%Type,
       in_curr_code                             system_control.sys_code%type,
       in_last_code                             system_control.sys_code%Type,
       in_update_user                           system_control.sys_update_user%type)
  RETURN NUMBER IS
       last_host_date                            system_control.sys_val%Type;
       current_eod_date                         system_control.sys_val%Type;
BEGIN

     Select  sys_val
        Into last_host_date
      From system_control
   Where sys_code = in_lasthostdate_code;
   
   select  sys_val
        Into current_eod_date
      From system_control
   Where sys_code = in_curr_code;
   
   
   If (last_host_date > current_eod_date) Then
      Update system_control 
                  Set sys_val = last_host_date,
                      sys_update_user = in_update_user,
                      sys_update_timestamp = Sysdate
                 Where sys_code = in_curr_code;
   End If;

  If (SQL%ROWCOUNT = 0 ) THEN
     RETURN 1;
  Else
        If (last_host_date > current_eod_date) Then
         Update system_control 
                  Set sys_val = current_eod_date,
                      sys_update_user = in_update_user,
                      sys_update_timestamp = Sysdate
                 Where sys_code = in_last_code;
            
            If Sql%Rowcount = 0 Then
                      return 1;
            Else      
                      Return 0;
            End If;
       Else
           Return 10;
       End If ;
       
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_system_control_chg_eoddate;
/
