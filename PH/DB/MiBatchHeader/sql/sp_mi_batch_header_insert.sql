create or replace function sp_mi_batch_header_insert(
       in_batch_id                             	mi_batch_header.bh_batch_id%type,
       in_process_type                      	mi_batch_header.bh_process_type%type,
       in_status                      		mi_batch_header.bh_status%type,
       in_user                           	mi_batch_header.bh_create_user%type)

  RETURN NUMBER IS
begin

  insert into mi_batch_header
              (bh_batch_id,
                bh_process_type,
                bh_status,
                bh_create_user,
                bh_create_timestamp,
                bh_update_user,
                bh_update_timestamp)
         values(in_batch_id,
                in_process_type,
                in_status,
                in_user,
                sysdate,
                in_user,
                sysdate);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mi_batch_header_insert;
/
