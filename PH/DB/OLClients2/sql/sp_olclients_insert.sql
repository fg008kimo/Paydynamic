create or replace function sp_olclients_insert(
	in_client_id			ol_clients_2.client_id%type,
	in_create_ts			varchar,
	in_update_ts			varchar,
	in_create_user			ol_clients_2.create_user%type,
	in_update_user			ol_clients_2.update_user%type,
	in_client_name			ol_clients_2.client_name%type,
	in_status			ol_clients_2.status%type,
	in_business_type		ol_clients_2.business_type%type,
	in_company_name			ol_clients_2.company_name%type,
	in_company_addr			ol_clients_2.company_addr%type)

  RETURN NUMBER IS
begin
   update ol_clients_2
   set    client_name = in_client_name,
          status = in_status,
          business_type = in_business_type,
          company_name = in_company_name,
          company_addr = in_company_addr,
          update_timestamp = sysdate,
          update_user = in_update_user
   where  client_id = in_client_id;

   if SQL%ROWCOUNT = 0 THEN

     insert into ol_clients_2
                (client_id,
   		 create_timestamp,
		 update_timestamp,
		 create_user,
		 update_user,
		 client_name,
		 status,
		 business_type,
		 company_name,
		 company_addr)
         values (in_client_id,
		 sysdate,
		 sysdate,
		 'SYSTEM',
		 'SYSTEM',
		 in_client_name,
		 in_status,
		 in_business_type,
		 in_company_name,
		 in_company_addr);

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
end  sp_olclients_insert;
/
