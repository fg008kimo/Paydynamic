create or replace function sp_non_postingdate_resp_insert(
	in_txn_id			non_postingdate_resp.txn_id%type,
	in_posting_date			non_postingdate_resp.posting_date%type,
	in_tm_date			non_postingdate_resp.tm_date%type,
	in_tm_time			non_postingdate_resp.tm_time%type,
	in_create_user			non_postingdate_resp.create_user%type,
	in_update_user			non_postingdate_resp.update_user%type)
  RETURN NUMBER IS
begin

  insert into non_postingdate_resp
	      (txn_id,
		posting_date,
		tm_date,
		tm_time,
		create_user,
		create_timestamp,
		update_user,
		update_timestamp)
	values(in_txn_id,
                in_posting_date,
                in_tm_date,
                in_tm_time,
		in_create_user,
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
end sp_non_postingdate_resp_insert;
/
