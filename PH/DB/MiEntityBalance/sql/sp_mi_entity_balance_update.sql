CREATE OR REPLACE FUNCTION sp_mi_entity_balance_update (
   in_entity_id      mi_entity_balance.eb_entity_id%TYPE,
   in_ccy            mi_entity_balance.eb_currency%TYPE,
   in_country	     mi_entity_balance.eb_country%TYPE,
   in_bal_type       mi_def_balance_type.bt_type%TYPE,
   in_amount         mi_entity_balance.eb_acct_bal%TYPE,
   in_update_user    mi_entity_balance.eb_update_user%TYPE)
   RETURN NUMBER
IS
   acct_bal	number := 0.0;
   intransit	number := 0.0;
   ar_bal	number := 0.0;

BEGIN

   if in_bal_type = 'A'
   then  acct_bal := in_amount;

   elsif in_bal_type = 'I'
   then  intransit := in_amount;

   elsif in_bal_type = 'D'
   then  ar_bal := in_amount;

   else
	RETURN 1;
   end if;

   UPDATE mi_entity_balance
   SET eb_acct_bal = eb_acct_bal + acct_bal,
       eb_intransit = eb_intransit + intransit,
       eb_ar_bal = eb_ar_bal + ar_bal,
       eb_update_user = in_update_user,
       eb_update_timestamp = SYSDATE
   WHERE eb_entity_id = in_entity_id
   AND   eb_currency = in_ccy
   AND   eb_country = in_country;
  

   IF SQL%ROWCOUNT = 0
   THEN
      INSERT INTO mi_entity_balance (eb_entity_id,
                                      eb_currency,
                                      eb_country,
                                      eb_acct_bal,
                                      eb_intransit,
                                      eb_ar_bal,
                                      eb_create_timestamp,
                                      eb_create_user,
                                      eb_update_timestamp,
                                      eb_update_user)
           VALUES (in_entity_id,
                   in_ccy,
                   in_country,
		   acct_bal,
		   intransit,
		   ar_bal,
                   SYSDATE,
                   in_update_user,
                   SYSDATE,
                   in_update_user);

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
END sp_mi_entity_balance_update;
/
