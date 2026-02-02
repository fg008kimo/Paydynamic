CREATE OR REPLACE FUNCTION sp_txn_upd_release_res(
        in_txn_id          txn_header.th_txn_id%type,
        in_release_date    txn_header.th_reserved_release_date%type,
        in_sub_status	   txn_header.th_sub_status%type,
        in_create_user     txn_header.th_create_user%type
)
return number is
begin
        update txn_header
          set th_reserved_release_date = in_release_date,
	      th_sub_status = in_sub_status,
              th_update_user  = in_create_user,
              th_update_timestamp = sysdate
        where th_txn_id = in_txn_id;

        if SQL%ROWCOUNT = 0 THEN
                return 1;
        else
                return 0;
        end if;

exception
  when others then
  return 9;
end sp_txn_upd_release_res;
/
