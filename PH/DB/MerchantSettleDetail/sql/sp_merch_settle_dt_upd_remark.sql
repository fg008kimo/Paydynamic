CREATE OR REPLACE FUNCTION sp_merch_settle_dt_upd_remark(
	in_txn_id		merchant_settlement_detail.sd_txn_id%type,
        in_remark		merchant_settlement_detail.sd_remark%type,
	in_update_user		merchant_settlement_detail.sd_update_user%type)
  RETURN NUMBER IS

BEGIN
  UPDATE merchant_settlement_detail
     SET sd_remark = in_remark,
         sd_update_user = in_update_user,
         sd_update_timestamp = sysdate
   WHERE sd_txn_id = in_txn_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_settle_dt_upd_remark;
/
