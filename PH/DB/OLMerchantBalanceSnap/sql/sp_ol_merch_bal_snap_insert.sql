CREATE OR REPLACE FUNCTION sp_ol_merch_bal_snap_insert(
        in_create_user          ol_merchant_balance_snap.ombs_create_user%type)
  RETURN NUMBER IS

BEGIN

  INSERT INTO ol_merchant_balance_snap(
        ombs_snapshot_timestamp        ,
        ombs_merchant_id               ,
        ombs_currency_id               ,
        ombs_country_id                ,
        ombs_service_code              ,
        ombs_current_bal               ,
        ombs_current_bal_settlement    ,
        ombs_total_float_after_payout  ,
        ombs_total_float_settlement    ,
        ombs_total_reserved_amount     ,
        ombs_fundin_payout             ,
        ombs_reserved_payout           ,
        ombs_total_hold                ,
        ombs_total_hold_settlement     ,
        ombs_settlement_in_transit     ,
        ombs_create_timestamp          ,
        ombs_create_user
        )
  SELECT
        sysdate                      ,
        om_merchant_id               ,
        om_currency_id               ,
        om_country_id                ,
        om_service_code              ,
        om_current_bal               ,
        om_current_bal_settlement    ,
        om_total_float_after_payout  ,
        om_total_float_settlement    ,
        om_total_reserved_amount     ,
        om_fundin_payout             ,
        om_reserved_payout           ,
        om_total_hold                ,
        om_total_hold_settlement     ,
        om_settlement_in_transit     ,
        sysdate                      ,
        in_create_user
  FROM ol_merchant_balance;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_merch_bal_snap_insert;
/




