create or replace function sp_ol_txn_browser_info_insert(
       in_txn_id                                ol_txn_browser_info.otb_txn_id%type,
       in_client_ip				ol_txn_browser_info.otb_client_ip%type,
       in_user_agent                         	ol_txn_browser_info.otb_user_agent%type,
       in_update_user                           ol_txn_browser_info.otb_update_user%type)

  RETURN NUMBER IS
	iCnt    integer := 0;
begin

  select count(otb_txn_id)
  into iCnt
  from ol_txn_browser_info
  where otb_txn_id = in_txn_id;

  if iCnt > 0 then

  	update	ol_txn_browser_info
  	set	otb_client_ip = in_client_ip,
		otb_update_timestamp = sysdate
  	where	otb_txn_id = in_txn_id
  	and	otb_client_ip is Null
  	and	in_client_ip is not null;
	

  	update	ol_txn_browser_info
  	set	otb_user_agent = in_user_agent,
		otb_update_timestamp = sysdate
  	where	otb_txn_id = in_txn_id
  	and	otb_user_agent is Null
  	and	in_user_agent is not null;

  	RETURN 0;
    else
  	insert into ol_txn_browser_info
              (otb_txn_id,
		otb_client_ip,
		otb_user_agent,
                otb_create_user,
                otb_create_timestamp,
                otb_update_user,
                otb_update_timestamp)
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
end sp_ol_txn_browser_info_insert;
/
