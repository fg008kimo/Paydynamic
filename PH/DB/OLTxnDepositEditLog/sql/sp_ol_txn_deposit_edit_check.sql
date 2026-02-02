CREATE OR REPLACE FUNCTION sp_ol_txn_deposit_edit_check (
   in_txn_id                   ol_txn_deposit_edit_log.otc_txn_id%TYPE,
   in_deposit_amount           ol_txn_deposit_edit_log.otc_amount%TYPE,
   in_cust_deposit_datetime    ol_txn_deposit_edit_log.otc_cust_deposit_datetime%TYPE,
   in_bank_code                ol_txn_deposit_edit_log.otc_bank_code%TYPE,
   in_bank_acct_num            ol_txn_deposit_edit_log.otc_bank_acct_num%TYPE,
   in_deposit_bank_code        ol_txn_deposit_edit_log.otc_deposit_bank_code%TYPE,
   in_deposit_bank             ol_txn_deposit_edit_log.otc_deposit_bank%TYPE,
   in_deposit_ref              ol_txn_deposit_edit_log.otc_deposit_ref%TYPE)
   RETURN NUMBER
IS
   iCnt   INTEGER;
BEGIN
   SELECT COUNT (1)
     INTO iCnt
     FROM ol_txn_header, ol_txn_detail
    WHERE     oth_txn_id = otd_txn_id
          AND oth_txn_id = in_txn_id
          AND oth_deposit_amount = in_deposit_amount
          AND otd_cust_deposit_datetime = in_cust_deposit_datetime
          AND otd_bank_code = in_bank_code
          AND otd_bank_acct_num = in_bank_acct_num
          AND otd_deposit_bank_code = in_deposit_bank_code
          AND (   (otd_deposit_bank = in_deposit_bank)
               OR (otd_deposit_bank IS NULL AND in_deposit_bank IS NULL))
          AND (   (otd_deposit_ref = in_deposit_ref)
               OR (otd_deposit_ref IS NULL AND in_deposit_ref IS NULL));

   RETURN iCnt;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 0;
END sp_ol_txn_deposit_edit_check;
/

