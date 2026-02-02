CREATE OR REPLACE FUNCTION sp_mms_txn_element_dt_insert (
	in_txn_id		mms_txn_element_detail.mtl_txn_id%TYPE,
	in_entity_id		mms_txn_element_detail.mtl_entity_id%TYPE,
	in_nature_id		mms_txn_element_detail.mtl_nature_id%TYPE,
	in_txn_element_type	mms_txn_element_detail.mtl_txn_element_type%TYPE,
	in_amount		mms_txn_element_detail.mtl_amount%TYPE,
	in_ccy			mms_txn_element_detail.mtl_ccy%TYPE,
	in_amt_type		mms_txn_element_detail.mtl_amt_type%TYPE,
	in_user			mms_txn_element_detail.mtl_create_user%TYPE
	)
  RETURN NUMBER IS
	iCnt integer := 0;

BEGIN
	SELECT nvl(max(mtl_exec_seq),0)
	  INTO iCnt
          FROM mms_txn_element_detail
         WHERE mtl_txn_id = in_txn_id;

	iCnt := iCnt + 1;

	        INSERT into mms_txn_element_detail
                       (mtl_txn_id,
			mtl_entity_id,
			mtl_nature_id,
			mtl_txn_element_type,
			mtl_exec_seq,
			mtl_amount,
			mtl_ccy,
			mtl_amt_type,
                        mtl_create_user,
                        mtl_create_timestamp,
                        mtl_update_user,
                        mtl_update_timestamp)
                 values(in_txn_id,
			in_entity_id,
			in_nature_id,
			in_txn_element_type,
			iCnt,
			in_amount,
			in_ccy,
			in_amt_type,
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
end sp_mms_txn_element_dt_insert;
/

