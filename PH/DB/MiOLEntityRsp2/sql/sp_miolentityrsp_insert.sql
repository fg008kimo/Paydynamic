create or replace function sp_miolentityrsp_insert(
	in_entity_id			mi_ol_entity_rsp_2.er_entity_id%type,
	in_rsp_id			mi_ol_entity_rsp_2.er_rsp_id%type,
	in_rsp_name			mi_ol_entity_rsp_2.er_rsp_name%type,
	in_rsp_node_id			mi_ol_entity_rsp_2.er_rsp_node_id%type,
	in_rsp_status			mi_ol_entity_rsp_2.er_rsp_status%type,
	in_create_ts			varchar,
	in_update_ts			varchar,
	in_create_user			mi_ol_entity_rsp_2.er_create_user%type,
	in_update_user			mi_ol_entity_rsp_2.er_update_user%type)

  RETURN NUMBER IS
begin
  update mi_ol_entity_rsp_2
  set    er_rsp_name = in_rsp_name,
         er_rsp_node_id = in_rsp_node_id,
         er_rsp_status = in_rsp_status
  where  er_entity_id = in_entity_id;

  if SQL%ROWCOUNT = 0 THEN

    insert into mi_ol_entity_rsp_2
               (er_entity_id,
		er_rsp_id,
		er_rsp_name,
		er_rsp_node_id,
		er_rsp_status,
		er_create_timestamp,
		er_update_timestamp,
		er_create_user,
		er_update_user)
         values(in_entity_id,
		in_rsp_id,
		in_rsp_name,
		in_rsp_node_id,
		in_rsp_status,
		sysdate,
		sysdate,
		'SYSTEM',
		'SYSTEM');

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
end  sp_miolentityrsp_insert;
/
