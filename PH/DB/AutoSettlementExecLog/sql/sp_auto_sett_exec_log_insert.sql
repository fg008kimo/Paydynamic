CREATE OR REPLACE FUNCTION sp_auto_sett_exec_log_insert (
        in_merchant_id        auto_settlement_exec_log.al_merchant_id%type,
        in_country            auto_settlement_exec_log.al_country%type,
        in_ccy_id             auto_settlement_exec_log.al_ccy_id%type,
        in_service_code       auto_settlement_exec_log.al_service_code%type,
        in_rule_type          auto_settlement_exec_log.al_rule_type%type,
        in_settlement_date    auto_settlement_exec_log.al_last_settlement_date%type,
        in_status             auto_settlement_exec_log.al_status%type, 
        in_txn_id             auto_settlement_exec_log.al_txn_id%type,
        in_create_user        auto_settlement_exec_log.al_create_user%type)
  RETURN NUMBER IS

BEGIN

    INSERT INTO auto_settlement_exec_log(
        al_merchant_id,
        al_country,
        al_ccy_id,
        al_service_code,
        al_rule_type,
        al_last_settlement_date,
        al_status,
        al_txn_id, 
        al_create_user,
        al_update_user,
        al_create_timestamp, 
        al_update_timestamp
    )
  VALUES(
        in_merchant_id,
        in_country,
        in_ccy_id,
        in_service_code,
        in_rule_type,
        in_settlement_date,
        in_status,
        in_txn_id,
        in_create_user,
        in_create_user,
        sysdate,
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

END sp_auto_sett_exec_log_insert;
/
