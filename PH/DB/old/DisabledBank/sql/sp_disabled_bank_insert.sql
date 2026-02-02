create or replace function sp_disabled_bank_insert(
        in_psp_id                               disabled_bank.db_psp_id%type,
        in_country                              disabled_bank.db_country%type,
        in_int_bank_code                        disabled_bank.db_int_bank_code%type,
        in_create_user                          disabled_bank.db_create_user%type 
)

  RETURN NUMBER IS
begin
        insert into disabled_bank 
                 (db_psp_id, 
                  db_country,
                  db_int_bank_code,
                  db_create_timestamp,
                  db_update_timestamp,
                  db_create_user,
                  db_update_user)
        values (in_psp_id,
                in_country,
                in_int_bank_code,
                sysdate,
                sysdate,
                in_create_user,
                in_create_user); 
  

/*
  IF in_psp_id is not null THEN  
          insert into disabled_bank
                  (db_psp_id, 
                   db_country,
                   db_int_bank_code,
                   db_create_timestamp,
                   db_update_timestamp,
                   db_create_user,
                   db_update_user)
          select in_psp_id, 
                 country, 
                 in_int_bank_code, 
                 sysdate, 
                 sysdate, 
                 in_create_user, 
                 in_create_user
          from psp_country 
          where psp_id = in_psp_id;                                        
                  
  ELSIF in_country is not null THEN
          insert into disabled_bank 
                  (db_psp_id, 
                   db_country, 
                   db_int_bank_code,
                   db_create_timestamp, 
                   db_update_timestamp,
                   db_create_user, 
                   db_update_user)
          select psp_id, 
                 in_country, 
                 in_int_bank_code, 
                 sysdate, 
                 sysdate, 
                 in_create_user, 
                 in_create_user
          from psp_country 
          where country = in_country;

  END IF;
*/

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;


EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_disabled_bank_insert; 
/

