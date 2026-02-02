create or replace function sp_txn_set_contributors_insert(
       in_txn_id                        txn_set_contributors.ts_txn_id%type,
       in_from_ccy			txn_set_contributors.ts_from_ccy%type,
       in_ratio				txn_set_contributors.ts_ratio%type,
       in_rate				txn_set_contributors.ts_rate%type,
       in_amt				txn_set_contributors.ts_amt%type,
       in_create_user                   txn_set_contributors.create_user%type)
  RETURN NUMBER IS
begin

  insert into txn_set_contributors
              (ts_txn_id,
		ts_from_ccy,
		ts_ratio,
		ts_rate,
		ts_amt,
		create_user,
		create_timestamp,
		update_user,
		update_timestamp)
         values(in_txn_id,
		in_from_ccy,
		in_ratio,
		in_rate,
		in_amt,
                in_create_user,
                sysdate,
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
end sp_txn_set_contributors_insert;
/
