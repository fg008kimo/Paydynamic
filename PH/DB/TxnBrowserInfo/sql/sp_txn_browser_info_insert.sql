create or replace function sp_txn_browser_info_insert(
       in_txn_id                                txn_browser_info.tb_txn_id%type,
       in_client_ip				txn_browser_info.tb_client_ip%type,
       in_user_agent                         	txn_browser_info.tb_user_agent%type,
       in_update_user                           txn_browser_info.tb_update_user%type)

  RETURN NUMBER IS
	iCnt    integer := 0;
begin

  select count(tb_txn_id)
  into iCnt
  from txn_browser_info
  where tb_txn_id = in_txn_id;

  if iCnt > 0 then

  	update	txn_browser_info
  	set	tb_client_ip = in_client_ip,
		tb_update_timestamp = sysdate
  	where	tb_txn_id = in_txn_id
  	and	tb_client_ip is Null
  	and	in_client_ip is not null;
	

  	update	txn_browser_info
  	set	tb_user_agent = in_user_agent,
		tb_update_timestamp = sysdate
  	where	tb_txn_id = in_txn_id
  	and	tb_user_agent is Null
  	and	in_user_agent is not null;

  	RETURN 0;
    else
  	insert into txn_browser_info
              (tb_txn_id,
		tb_client_ip,
		tb_user_agent,
                tb_create_user,
                tb_create_timestamp,
                tb_update_user,
                tb_update_timestamp)
         values(in_txn_id,
		in_client_ip,
		in_user_agent,
                in_update_user,
                sysdate,
                in_update_user,
                sysdate);


 	 IF SQL%ROWCOUNT = 0 THEN
     		RETURN 1;
  	ELSE
  		RETURN 0;
  	END IF;
    END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_txn_browser_info_insert;
/
