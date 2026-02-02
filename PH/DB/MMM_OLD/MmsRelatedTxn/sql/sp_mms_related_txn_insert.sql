create or replace function sp_mms_related_txn_insert(
       in_txn_id                                mms_related_txn.mrt_txn_id%type,
       in_dtl_txn_id                            mms_related_txn.mrt_dtl_txn_id%type,
       in_prev_txn_id                           mms_related_txn.mrt_prev_txn_id%type,
       in_prev_dtl_txn_id                       mms_related_txn.mrt_prev_dtl_txn_id%type,
       in_update_user				mms_related_txn.mrt_update_user%type
)
  RETURN NUMBER IS

	iCnt 		integer := 0;
Begin

        insert into mms_related_txn
                     (mrt_txn_id,
		      mrt_dtl_txn_id,
		      mrt_prev_txn_id,
		      mrt_prev_dtl_txn_id,
                      mrt_create_user,
                      mrt_create_timestamp,
                      mrt_update_user,
                      mrt_update_timestamp
                      )
          values(in_txn_id,
                 in_dtl_txn_id,
                 in_prev_txn_id,
                 in_prev_dtl_txn_id,
                 in_update_user,
                 sysdate,
                 in_update_user,
                 sysdate
                 );
		
          IF SQL%ROWCOUNT = 0 THEN
             RETURN 1;
          ELSE
             RETURN 0;
          END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mms_related_txn_insert;
/
