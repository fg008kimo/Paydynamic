CREATE OR REPLACE FUNCTION sp_email_notify_list_insert (
	in_email_id             email_notify_list.el_id%TYPE,
	in_email_addr        	email_notify_list.el_email%TYPE,
	in_create_user         	email_notify_list.el_create_user%TYPE
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO email_notify_list (
	el_id,
     	el_email,
     	el_create_user,
       	el_update_user,
     	el_create_timestamp,
       	el_update_timestamp
	)

  VALUES (
	in_email_id,
       	in_email_addr,
       	in_create_user,
       	in_create_user,
       	SYSDATE,
       	SYSDATE
	);

  IF SQL%ROWCOUNT = 0
  THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;

END sp_email_notify_list_insert;
/

