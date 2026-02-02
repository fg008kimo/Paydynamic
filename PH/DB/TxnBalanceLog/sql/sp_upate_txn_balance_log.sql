CREATE OR REPLACE FUNCTION PHUSER.sp_update_txn_balance_log(
	in_txn_aprv_date	txn_balance_log.tb_txn_aprv_date%type,
	in_party_type		txn_balance_log.tb_party_type%type,
	in_is_completed		txn_balance_log.tb_is_completed%type,
	in_update_user		txn_balance_log.tb_update_user%type
)
return number is
begin
	update txn_balance_log
	  set tb_is_completed = in_is_completed,
              tb_update_user = in_update_user,
	      tb_update_timestamp = sysdate
        where tb_txn_aprv_date = in_txn_aprv_date
	  and tb_party_type = in_party_type;

	if SQL%ROWCOUNT = 0 THEN
		insert into txn_balance_log
			(tb_txn_aprv_date,
			 tb_party_type,
			 tb_is_completed,
			 tb_create_user,
			 tb_update_user,
			 tb_create_timestamp,
			 tb_update_timestamp)
		values(in_txn_aprv_date,
		       in_party_type,
                       in_is_completed,
		       in_update_user,
                       in_update_user,
		       sysdate,
		       sysdate);
		if SQL%ROWCOUNT = 0 THEN
			return 1;

		else
			return 0;
		end if;
	else
		return 0;
	end if;

exception
  when others then
  return 9;
end sp_update_txn_balance_log;
/
