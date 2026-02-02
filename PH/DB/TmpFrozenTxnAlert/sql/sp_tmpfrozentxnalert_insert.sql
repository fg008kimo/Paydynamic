create or replace function sp_tmpfrozentxnalert_insert(
       in_txn_id				tmp_frozen_txn_alert.tfa_txn_id%type)

  RETURN NUMBER IS
begin

  insert into tmp_frozen_txn_alert
               (tfa_txn_id)
         values(in_txn_id);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end  sp_tmpfrozentxnalert_insert;
/
