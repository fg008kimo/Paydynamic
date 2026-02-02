CREATE OR REPLACE FUNCTION sp_par_clients_insert(
	in_company_name         par_clients.pc_company_name%type,
	in_client_id		par_clients.pc_client_id%type,
	in_client_group		par_clients.pc_def_client_group%type,
	in_create_user		par_clients.pc_create_user%type)
  RETURN NUMBER IS

BEGIN

  INSERT INTO par_clients(
	pc_company_name,
	pc_client_id,
        pc_def_client_group,	
	pc_create_timestamp,
	pc_create_user,
	pc_update_timestamp,
	pc_update_user
	)
  VALUES(
	in_company_name,
	in_client_id,
	in_client_group,
	sysdate,
	in_create_user,
	sysdate,
	in_create_user
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_par_clients_insert;
/

