create or replace function sp_mi_batch_detail_insert(
       in_batch_id                              mi_batch_detail.bd_batch_id%type,
       in_seq                          		mi_batch_detail.bd_seq%type,
       in_entity_id                           	mi_batch_detail.bd_entity_id%type,
       in_party_type                           	mi_batch_detail.bd_party_type%type,
       in_party_id                            	mi_batch_detail.bd_party_id%type,
       in_txn_id                                mi_batch_detail.bd_txn_id%type,
       in_txn_oper_ind                         	mi_batch_detail.bd_txn_oper_ind%type,
       in_user                                  mi_batch_detail.bd_create_user%type)

  RETURN NUMBER IS
begin

  insert into mi_batch_detail
              (bd_batch_id,
                bd_seq,
                bd_entity_id,
		bd_party_type,
		bd_party_id,
		bd_txn_id,
		bd_txn_oper_ind,
                bd_create_user,
                bd_create_timestamp,
                bd_update_user,
                bd_update_timestamp)
         values(in_batch_id,
                in_seq,
                in_entity_id,
		in_party_type,
		in_party_id,
		in_txn_id,
		in_txn_oper_ind,
                in_user,
                sysdate,
                in_user,
                sysdate);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mi_batch_detail_insert;
/
