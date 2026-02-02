CREATE OR REPLACE FUNCTION sp_mms_txn_element_insert (
	in_txn_id		mms_txn_element.mte_txn_id%TYPE,
	in_entity_id		mms_txn_element.mte_entity_id%TYPE,
	in_txn_element_type	mms_txn_element.mte_txn_element_type%TYPE,
	in_amount		mms_txn_element.mte_amount%TYPE,
	in_ccy			mms_txn_element.mte_ccy%TYPE,
	in_amt_type		mms_txn_element.mte_amt_type%TYPE,
	in_user			mms_txn_element.mte_create_user%TYPE
	)
  RETURN NUMBER IS
	iCnt integer := 0;

BEGIN
	SELECT nvl(max(mte_exec_seq),0)
	  INTO iCnt
          FROM mms_txn_element
         WHERE mte_txn_id = in_txn_id;

	iCnt := iCnt + 1;

	        INSERT into mms_txn_element
                       (mte_txn_id,
			mte_entity_id,
			mte_txn_element_type,
			mte_exec_seq,
			mte_amount,
			mte_ccy,
			mte_amt_type,
                        mte_create_user,
                        mte_create_timestamp,
                        mte_update_user,
                        mte_update_timestamp)
                 values(in_txn_id,
			in_entity_id,
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
end sp_mms_txn_element_insert;
/

