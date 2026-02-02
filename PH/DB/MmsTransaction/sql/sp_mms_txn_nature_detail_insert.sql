create or replace function sp_mms_txn_nature_dt_insert(
       in_txn_id                                mms_txn_nature_detail.mtn_txn_id%type,
       in_entity_id                             mms_txn_nature_detail.mtn_entity_id%type,
       in_nature_id                             mms_txn_nature_detail.mtn_nature_id%type,
       in_txn_amount                            mms_txn_nature_detail.mtn_txn_amount%type,
       in_txn_ccy                               mms_txn_nature_detail.mtn_txn_ccy%type,
       in_net_amount                            mms_txn_nature_detail.mtn_net_amount%type,
       in_net_ccy                               mms_txn_nature_detail.mtn_net_ccy%type,
       in_create_user                           mms_txn_nature_detail.mtn_create_user%type
	
)
  RETURN NUMBER IS
Begin
        insert into mms_txn_nature_detail
                     (mtn_txn_id,
		      mtn_entity_id,
		      mtn_nature_id,
		      mtn_txn_amount,
		      mtn_txn_ccy,
		      mtn_net_amount,
		      mtn_net_ccy,
                      mtn_create_user,
                      mtn_create_timestamp,
                      mtn_update_user,
                      mtn_update_timestamp)
          values(in_txn_id,
		     in_entity_id,
		     in_nature_id,
		     in_txn_amount,
		     in_txn_ccy,
		     in_net_amount,
		     in_net_ccy,
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
end sp_mms_txn_nature_dt_insert;
/
