CREATE OR REPLACE FUNCTION sp_txn_detail_upd_remark(
	in_txn_id		txn_detail.td_txn_id%type,
        in_remark		txn_detail.td_remark%type,
	in_update_user		txn_detail.td_update_user%type)
  RETURN NUMBER IS

BEGIN
  UPDATE txn_detail
     SET td_remark = in_remark,
         td_update_user = in_update_user,
         td_update_timestamp = sysdate
   WHERE td_txn_id = in_txn_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_txn_detail_upd_remark;
/
