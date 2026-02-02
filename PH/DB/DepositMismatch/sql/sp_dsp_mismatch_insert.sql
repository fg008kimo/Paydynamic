create or replace function sp_dsp_mismatch_insert(
       in_txn_id                        deposit_mismatch.dm_txn_id%type,
       in_party_type			deposit_mismatch.dm_party_type%type,
       in_party_id			deposit_mismatch.dm_party_id%type,
       in_tid				deposit_mismatch.dm_psp_tid%type,
       in_merchant_ref			deposit_mismatch.dm_merchant_ref%type,
       in_txn_date			deposit_mismatch.dm_txn_date%type,
       in_absent			deposit_mismatch.dm_absent%type,
       in_create_user                   deposit_mismatch.dm_create_user%type)
  RETURN NUMBER IS
begin

  insert into deposit_mismatch
              (dm_txn_id,
		dm_party_type,
		dm_party_id,
		dm_psp_tid,
		dm_merchant_ref,
		dm_txn_date,
		dm_absent,
		dm_create_user,
		dm_create_timestamp,
		dm_update_user,
		dm_update_timestamp)
         values(in_txn_id,
		in_party_type,
		in_party_id,
		in_tid,
		in_merchant_ref,
		in_txn_date,
		in_absent,
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
end sp_dsp_mismatch_insert;
/
