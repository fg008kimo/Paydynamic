CREATE OR REPLACE FUNCTION sp_system_control_hostcutoff (
       in_curr_code                                    system_control.sys_code%Type,
       in_last_code                                    system_control.sys_code%Type,
       in_update_user                                system_control.sys_update_user%type)
  RETURN NUMBER IS

BEGIN

   UPDATE system_control
      SET sys_val = (Select  sys_val
                              From system_control
                            Where sys_code = in_curr_code),
          sys_update_user = in_update_user,
	  sys_update_timestamp = sysdate
    WHERE sys_code = in_last_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
            Update system_control 
                  Set sys_val = to_char(to_date(sys_val,'yyyymmdd') + 1,'yyyymmdd'),
                      sys_update_user = in_update_user,
                      sys_update_timestamp = Sysdate
                 Where sys_code = in_curr_code;
            
            If Sql%Rowcount = 0 Then
                      return 1;
            Else      
                      Return 0;
            End If;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_system_control_hostcutoff;

/
