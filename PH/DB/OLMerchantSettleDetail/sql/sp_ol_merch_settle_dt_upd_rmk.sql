CREATE OR REPLACE FUNCTION sp_ol_merch_settle_dt_upd_rmk(
	in_txn_id		ol_merchant_settlement_detail.osd_txn_id%type,
        in_remark		ol_merchant_settlement_detail.osd_remark%type,
	in_update_user		ol_merchant_settlement_detail.osd_update_user%type)
  RETURN NUMBER IS

BEGIN
  UPDATE ol_merchant_settlement_detail
     SET osd_remark = in_remark,
         osd_update_user = in_update_user,
         osd_update_timestamp = sysdate
   WHERE osd_txn_id = in_txn_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_merch_settle_dt_upd_rmk;
/
