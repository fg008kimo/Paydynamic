CREATE OR REPLACE FUNCTION sp_system_control_update (
       in_code             system_control.sys_code%type,
       in_val              system_control.sys_val%type,
       in_update_user      system_control.sys_update_user%type)
  RETURN NUMBER IS

BEGIN

   UPDATE system_control
      SET sys_val = in_val,
          sys_update_user = in_update_user,
	  sys_update_timestamp = sysdate
    WHERE sys_code = in_code;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_system_control_update;
/
