CREATE OR REPLACE FUNCTION sp_mms_instant_txn_inq_hd_ins(
	in_inq_id		mms_instant_txn_inq_hd.mih_inq_id%type,
	in_txn_id		mms_instant_txn_inq_hd.mih_txn_id%type,
	in_req_txn_status	mms_instant_txn_inq_hd.mih_req_txn_status%type,
        in_status               mms_instant_txn_inq_hd.mih_status%type,
        in_create_user          mms_instant_pm_acct_hd.mia_create_user%type)
  RETURN NUMBEr IS
BEGIN

        INSERT INTO mms_instant_txn_inq_hd(
		mih_inq_id,
		mih_txn_id,
		mih_req_txn_status,
		mih_status,
		mih_create_user,
		mih_create_timestamp,
		mih_update_user,
		mih_update_timestamp
		)
        VALUES (
		in_inq_id,
                in_txn_id,
		in_req_txn_status,
		in_status,
                in_create_user,
                sysdate,
                in_create_user,
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

END sp_mms_instant_txn_inq_hd_ins;
/
