CREATE OR REPLACE FUNCTION sp_txn_remarks_update(
	in_txn_id		txn_remarks.tr_txn_id%type,
	in_exec_seq		txn_remarks.tr_exec_seq%type,
	in_remark		txn_remarks.tr_remark%type,
	in_update_user		txn_remarks.tr_update_user%type)
  RETURN NUMBER IS

BEGIN
  UPDATE txn_remarks
     SET tr_remark = in_remark,
         tr_update_user = in_update_user,
         tr_update_timestamp = sysdate
   WHERE tr_txn_id = in_txn_id
     AND tr_exec_seq = in_exec_seq;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_txn_remarks_update;
/
