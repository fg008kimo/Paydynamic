create or replace function sp_mms_manual_void_log_insert (
       in_txn_id                                mms_manual_void_log.mvt_txn_id%type,
       in_void_txn_id                           mms_manual_void_log.mvt_txn_id%type,
       in_void_dtl_txn_id                       mms_manual_void_log.mvt_void_dtl_txn_id%type,
       in_update_user				mms_manual_void_log.mvt_update_user%type
)
  RETURN NUMBER IS

	iCnt 		integer := 0;
Begin

	select count(1)
	into iCnt
	from mms_manual_void_log
	where mvt_txn_id = in_txn_id
	and mvt_void_txn_id = in_void_txn_id
	and mvt_void_dtl_txn_id = in_void_dtl_txn_id;

	if iCnt = 0 then
		insert into mms_manual_void_log
                     (mvt_txn_id,
		      mvt_void_txn_id,
		      mvt_void_dtl_txn_id,
                      mvt_create_user,
                      mvt_create_timestamp,
                      mvt_update_user,
                      mvt_update_timestamp
                      )
		values(in_txn_id,
			in_void_txn_id, 
			in_void_dtl_txn_id,
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
	else 
		return 0;
	end if;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_mms_manual_void_log_insert;
/
