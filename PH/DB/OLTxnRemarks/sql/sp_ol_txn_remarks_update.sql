CREATE OR REPLACE FUNCTION sp_ol_txn_remarks_update(
	in_txn_id		ol_txn_remarks.otr_txn_id%type,
	in_exec_seq		ol_txn_remarks.otr_exec_seq%type,
	in_remark		ol_txn_remarks.otr_remark%type,
	in_update_user		ol_txn_remarks.otr_update_user%type)
  RETURN NUMBER IS

BEGIN
  UPDATE ol_txn_remarks
     SET otr_remark = in_remark,
         otr_update_user = in_update_user,
         otr_update_timestamp = sysdate
   WHERE otr_txn_id = in_txn_id
     AND otr_exec_seq = in_exec_seq;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_txn_remarks_update;
/
