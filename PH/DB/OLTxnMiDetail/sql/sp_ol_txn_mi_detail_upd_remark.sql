CREATE OR REPLACE FUNCTION sp_ol_txn_mi_detail_upd_remark(
	in_txn_id		ol_txn_mi_detail.otm_txn_id%type,
        in_remark		ol_txn_mi_detail.otm_remark%type,
	in_update_user		ol_txn_mi_detail.otm_update_user%type)
  RETURN NUMBER IS

BEGIN
  UPDATE ol_txn_mi_detail
     SET otm_remark = in_remark,
         otm_update_user = in_update_user,
         otm_update_timestamp = sysdate
   WHERE otm_txn_id = in_txn_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_txn_mi_detail_upd_remark;
/
