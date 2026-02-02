create or replace function sp_txn_web_log_insert(
       in_txn_id                                txn_web_log.tw_txn_id%type,
       in_logmsg				txn_web_log.tw_logmsg%type,
       in_update_user                           txn_web_log.tw_update_user%type)

  RETURN NUMBER IS
	iCnt    integer := 0;
begin

  	insert into txn_web_log
              (tw_txn_id,
		tw_logmsg,
                tw_create_user,
                tw_create_timestamp,
                tw_update_user,
                tw_update_timestamp)
         values(in_txn_id,
		in_logmsg,
                in_update_user,
                sysdate,
                in_update_user,
                sysdate);


 	 IF SQL%ROWCOUNT = 0 THEN
     		RETURN 1;
  	ELSE
  		RETURN 0;
  	END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_txn_web_log_insert;
/
