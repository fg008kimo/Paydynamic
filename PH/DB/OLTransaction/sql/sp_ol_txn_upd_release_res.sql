CREATE OR REPLACE FUNCTION sp_ol_txn_upd_release_res(
        in_txn_id          ol_txn_header.oth_txn_id%type,
        in_release_date    ol_txn_header.oth_reserved_release_date%type,
        in_create_user     ol_txn_header.oth_create_user%type
)
return number is
begin
        update ol_txn_header
          set oth_reserved_release_date = in_release_date,
              oth_update_user  = in_create_user,
              oth_update_timestamp = sysdate
        where oth_txn_id = in_txn_id;

        if SQL%ROWCOUNT = 0 THEN
                return 1;
        else
                return 0;
        end if;

exception
  when others then
  return 9;
end sp_ol_txn_upd_release_res;
/
