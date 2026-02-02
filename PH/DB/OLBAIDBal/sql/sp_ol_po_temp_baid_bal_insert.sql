CREATE OR REPLACE FUNCTION sp_ol_po_temp_baid_bal_insert (
   in_baid           ol_baid_bal.obab_baid%TYPE,
   in_country_id     ol_baid_bal.obab_country_id%TYPE,
   in_currency_id    ol_baid_bal.obab_currency_id%TYPE,
   in_bal            ol_baid_bal.obab_bal%TYPE,
   in_create_user    ol_baid_bal.obab_create_user%TYPE)
RETURN NUMBER IS
   iCnt              integer := 0;	
BEGIN
   SELECT count(*) 
   INTO iCnt
   FROM ol_bank_acct_id
   WHERE obai_baid = in_baid;

   IF iCnt = 0
   THEN
      INSERT INTO ol_baid_bal (obab_baid,
                               obab_country_id,
                               obab_currency_id,
                               obab_bal,
                               obab_create_user,
                               obab_update_user,
                               obab_create_timestamp,
                               obab_update_timestamp)
           VALUES (in_baid,
                   in_country_id,
                   in_currency_id,
                   in_bal,
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
END sp_ol_po_temp_baid_bal_insert;
/

