CREATE OR REPLACE FUNCTION sp_rule_txn_bk_chr_find (
   in_bank_code          rule_txn_bank_charge.rtbc_bank_code%TYPE,
   in_country            rule_txn_bank_charge.rtbc_country%TYPE,
   in_ccy                rule_txn_bank_charge.rtbc_ccy%TYPE,
   in_channel_code       rule_txn_bank_charge.rtbc_channel_code%TYPE,
   in_txn_code           rule_txn_bank_charge.rtbc_txn_code%TYPE,
   out_cursor        OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
   iCnt   INTEGER := 0;
BEGIN
   SELECT COUNT (*)
     INTO iCnt
     FROM rule_txn_bank_charge, rule_amount
    WHERE     rtbc_amount_id = ra_id
          AND rtbc_bank_code = in_bank_code
          AND rtbc_country = in_country
          AND rtbc_ccy = in_ccy
          AND rtbc_channel_code = in_channel_code
          AND rtbc_txn_code = in_txn_code
          AND rtbc_disabled = 0
          AND rtbc_effect_date =
                 (SELECT MAX (rtbc_effect_date)
                    FROM rule_txn_bank_charge
                   WHERE     rtbc_bank_code = in_bank_code
                         AND rtbc_country = in_country
                         AND rtbc_ccy = in_ccy
                         AND rtbc_channel_code = in_channel_code
                         AND rtbc_txn_code = in_txn_code
                         AND rtbc_disabled = 0
                         AND rtbc_effect_date < SYSDATE);

   IF iCnt > 0
   THEN
      OPEN out_cursor FOR
         SELECT rtbc_min_value,
                rtbc_max_value,
                rtbc_amount_id,
                ra_type,
                ra_value,
                ra_add_value,
                ra_min_value,
                ra_max_value
           FROM rule_txn_bank_charge, rule_amount
          WHERE     rtbc_amount_id = ra_id
                AND rtbc_bank_code = in_bank_code
                AND rtbc_country = in_country
                AND rtbc_ccy = in_ccy
                AND rtbc_channel_code = in_channel_code
                AND rtbc_txn_code = in_txn_code
                AND rtbc_disabled = 0
                AND rtbc_effect_date =
                       (SELECT MAX (rtbc_effect_date)
                          FROM rule_txn_bank_charge
                         WHERE     rtbc_bank_code = in_bank_code
                               AND rtbc_country = in_country
                               AND rtbc_ccy = in_ccy
                               AND rtbc_channel_code = in_channel_code
                               AND rtbc_txn_code = in_txn_code
                               AND rtbc_disabled = 0
                               AND rtbc_effect_date < SYSDATE);


      RETURN 1;
   ELSE
      RETURN 0;
   END IF;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_rule_txn_bk_chr_find;
/

