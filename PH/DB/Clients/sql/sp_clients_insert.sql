CREATE OR REPLACE FUNCTION sp_clients_insert(
	in_client_id		clients.client_id%type,
	in_client_name		clients.client_name%type,
	in_type			clients.business_type%type,
	in_status		clients.status%type,
	in_company_name		clients.company_name%type,
	in_company_addr		clients.company_addr%type,
	in_create_user		clients.create_user%type)
  RETURN NUMBER IS

BEGIN
  UPDATE clients
  set    client_name = in_client_name,
	 status = in_status,
	 business_type = in_type,
	 company_name = in_company_name,
	 company_addr = in_company_addr,
         update_timestamp = sysdate,
         update_user = in_create_user
  where  client_id = in_client_id;

  if SQL%ROWCOUNT = 0 THEN

    INSERT INTO clients(
	client_id,
	client_name,
	business_type,
	status,
	company_name,
	company_addr,
	create_timestamp,
	create_user,
	update_timestamp,
	update_user
	)

    VALUES(
	in_client_id,
	in_client_name,
	in_type,
	in_status,
	in_company_name,
	in_company_addr,
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

  else
     return 0;
  end if;


EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_clients_insert;
/
