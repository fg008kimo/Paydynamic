CREATE OR REPLACE FUNCTION sp_merchant_bal_snap_insert(
	in_create_user		merchant_balance_snap.mbs_create_user%type)
  RETURN NUMBER IS

BEGIN

  INSERT INTO merchant_balance_snap(
	mbs_snapshot_timestamp        ,
	mbs_merchant_id               ,
	mbs_currency_id               ,
	mbs_country_id                ,
	mbs_service_code              ,
	mbs_current_bal               ,
	mbs_current_bal_settlement    ,
	mbs_total_float               ,
	mbs_total_float_after_payout  ,
	mbs_total_float_settlement    ,
	mbs_total_reserved_amount     ,
	mbs_fundin_payout             ,
	mbs_reserved_payout           ,
	mbs_total_hold                ,
	mbs_total_hold_settlement     ,
	mbs_settlement_in_transit     ,
	mbs_create_timestamp          ,
	mbs_create_user               
	)
  SELECT 
	sysdate                     ,
	m_merchant_id               ,
	m_currency_id               ,
	m_country_id                ,
	m_service_code              ,
	m_current_bal               ,
	m_current_bal_settlement    ,
	m_total_float               ,
	m_total_float_after_payout  ,
	m_total_float_settlement    ,
	m_total_reserved_amount     ,
	m_fundin_payout             ,
	m_reserved_payout           ,
	m_total_hold                ,
	m_total_hold_settlement     ,
	m_settlement_in_transit     ,
        sysdate                     ,
	in_create_user
  FROM merchant_balance;

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merchant_bal_snap_insert;
/

