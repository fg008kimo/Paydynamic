CREATE OR REPLACE FUNCTION sp_txn_mi_detail_upd_remark(
	in_txn_id		txn_mi_detail.tm_txn_id%type,
        in_remark		txn_mi_detail.tm_remark%type,
	in_update_user		txn_mi_detail.tm_update_user%type)
  RETURN NUMBER IS

BEGIN
  UPDATE txn_mi_detail
     SET tm_remark = in_remark,
         tm_update_user = in_update_user,
         tm_update_timestamp = sysdate
   WHERE tm_txn_id = in_txn_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_txn_mi_detail_upd_remark;
/
