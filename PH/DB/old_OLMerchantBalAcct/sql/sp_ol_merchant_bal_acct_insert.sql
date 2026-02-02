CREATE OR REPLACE FUNCTION sp_ol_merchant_bal_acct_insert(
    in_merchant_id          ol_merchant_bal_acct.omb_merchant_id%type,
    in_int_bank_code        ol_merchant_bal_acct.omb_int_bank_code%type,
    in_bank_acct_num        ol_merchant_bal_acct.omb_bank_acct_num%type,
    in_disabled             ol_merchant_bal_acct.omb_disabled%type,
    in_service_code         ol_merchant_bal_acct.omb_service_code%type,
    in_status               ol_merchant_bal_acct.omb_status%type,
    in_preferred_settle_ccy ol_merchant_bal_acct.omb_preferred_settle_ccy%type,
    in_support_auto_sett    ol_merchant_bal_acct.omb_support_auto_sett%type,
    in_auto_sett_id         ol_merchant_bal_acct.omb_auto_sett_id%type,
    in_create_user          ol_merchant_bal_acct.omb_create_user%type)
  RETURN NUMBER IS
BEGIN

  INSERT INTO ol_merchant_bal_acct(
    omb_merchant_id,
    omb_int_bank_code,
    omb_bank_acct_num,
    omb_disabled,
    omb_service_code,
    omb_status,
    omb_preferred_settle_ccy,
    omb_support_auto_sett,
    omb_auto_sett_id,
    omb_update_timestamp,
    omb_create_timestamp,
    omb_update_user,
    omb_create_user
    )
  VALUES(
    in_merchant_id,
    in_int_bank_code,
    in_bank_acct_num,
    in_disabled,
    in_service_code,
    in_status,
    in_preferred_settle_ccy,
    in_support_auto_sett,
    in_auto_sett_id,
    sysdate,
    sysdate,
    in_create_user,
    in_create_user
    );

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_merchant_bal_acct_insert;
/

