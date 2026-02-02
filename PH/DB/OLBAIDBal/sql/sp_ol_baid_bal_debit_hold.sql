CREATE OR REPLACE FUNCTION sp_ol_baid_bal_debit_hold (
   in_baid           ol_baid_bal.obab_baid%TYPE,
   in_country_id     ol_baid_bal.obab_country_id%TYPE,
   in_currency_id    ol_baid_bal.obab_currency_id%TYPE,
   in_hold           ol_baid_bal.obab_total_hold%TYPE,
   in_create_user    ol_baid_bal.obab_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   UPDATE ol_baid_bal
      SET obab_total_hold = obab_total_hold - in_hold,
          obab_update_user = in_create_user,
          obab_update_timestamp = SYSDATE
    WHERE     obab_baid = in_baid
          AND obab_country_id = in_country_id
          AND obab_currency_id = in_currency_id;

   IF SQL%ROWCOUNT = 0
   THEN
      INSERT INTO ol_baid_bal (obab_baid,
                               obab_country_id,
                               obab_currency_id,
                               obab_total_hold,
                               obab_create_user,
                               obab_update_user,
                               obab_create_timestamp,
                               obab_update_timestamp)
           VALUES (in_baid,
                   in_country_id,
                   in_currency_id,
                   in_hold,
                   in_create_user,
                   in_create_user,
                   SYSDATE,
                   SYSDATE);

      IF SQL%ROWCOUNT = 0
      THEN
         RETURN 1;
      ELSE
         RETURN 0;
      END IF;
   ELSE
      RETURN 0;
   END IF;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_ol_baid_bal_debit_hold;
/