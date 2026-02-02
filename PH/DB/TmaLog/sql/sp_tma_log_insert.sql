create or replace function sp_tma_log_insert(
       in_txn_id                                tma_log.t_txn_id%type,
       in_ip_address				tma_log.t_ip_address%type,
       in_create_user                           tma_log.t_create_user%type)

  RETURN NUMBER IS
begin

  insert into tma_log
              (t_txn_id,
		t_ip_address,
                t_create_user,
		t_create_timestamp)

         values(in_txn_id,
		in_ip_address,
		in_create_user,
		sysdate);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_tma_log_insert;
/
