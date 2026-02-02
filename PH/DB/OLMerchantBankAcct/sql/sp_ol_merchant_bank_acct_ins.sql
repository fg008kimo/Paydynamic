CREATE OR REPLACE FUNCTION sp_ol_merchant_bank_acct_ins(
    in_merchant_id          ol_merchant_bank_acct.omb_merchant_id%type,
    in_int_bank_code        ol_merchant_bank_acct.omb_int_bank_code%type,
    in_bank_acct_num        ol_merchant_bank_acct.omb_bank_acct_num%type,
    in_type        	    ol_merchant_bank_acct.omb_txn_type%type,
    in_disabled             ol_merchant_bank_acct.omb_disabled%type,
    in_service_code         ol_merchant_bank_acct.omb_service_code%type,
    in_status               ol_merchant_bank_acct.omb_status%type,
    in_create_user          ol_merchant_bank_acct.omb_create_user%type)
  RETURN NUMBER IS
BEGIN

  INSERT INTO ol_merchant_bank_acct(
    omb_merchant_id,
    omb_int_bank_code,
    omb_bank_acct_num,
    omb_txn_type,
    omb_disabled,
    omb_service_code,
    omb_status,
    omb_update_timestamp,
    omb_create_timestamp,
    omb_update_user,
    omb_create_user
    )
  VALUES(
    in_merchant_id,
    in_int_bank_code,
    in_bank_acct_num,
    in_type,
    in_disabled,
    in_service_code,
    in_status,
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

END sp_ol_merchant_bank_acct_ins;
/

