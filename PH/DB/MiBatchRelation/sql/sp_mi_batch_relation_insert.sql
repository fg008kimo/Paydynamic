create or replace function sp_mi_batch_relation_insert(
       in_batch_id                              mi_batch_relation.br_batch_id%type,
       in_org_batch_id                          mi_batch_relation.br_org_batch_id%type,
       in_relation_type                         mi_batch_relation.br_relation_type%type,
       in_user                                  mi_batch_relation.br_create_user%type)

  RETURN NUMBER IS
begin

  insert into mi_batch_relation
              (br_batch_id,
                br_org_batch_id,
                br_relation_type,
                br_create_user,
                br_create_timestamp,
                br_update_user,
                br_update_timestamp)
         values(in_batch_id,
                in_org_batch_id,
                in_relation_type,
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
end sp_mi_batch_relation_insert;
/
