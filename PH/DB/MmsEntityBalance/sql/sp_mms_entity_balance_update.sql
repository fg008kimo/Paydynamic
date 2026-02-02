CREATE OR REPLACE FUNCTION sp_mms_entity_balance_update (
   in_entity_id      mms_entity_balance.meb_entity_id%TYPE,
   in_ccy            mms_entity_balance.meb_ccy%TYPE,
   in_nature_id      mms_entity_balance.meb_nature_id%TYPE,
   in_acct_bal       mms_entity_balance.meb_acct_bal%TYPE,
   in_prepaid        mms_entity_balance.meb_prepaid%TYPE,
   in_intransit      mms_entity_balance.meb_intransit%TYPE,
   in_lien           mms_entity_balance.meb_lien%TYPE,
   in_update_user    mms_entity_balance.meb_update_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   UPDATE mms_entity_balance
      SET meb_acct_bal = meb_acct_bal + nvl(in_acct_bal,0),
          meb_prepaid = meb_prepaid + nvl(in_prepaid,0),
          meb_intransit = meb_intransit + nvl(in_intransit,0),
          meb_lien = meb_lien + nvl(in_lien,0),
          meb_update_user = in_update_user,
          meb_update_timestamp = SYSDATE
    WHERE     meb_entity_id = in_entity_id
          AND meb_ccy = in_ccy
          AND meb_nature_id = in_nature_id;

   IF SQL%ROWCOUNT = 0
   THEN
      INSERT INTO mms_entity_balance (meb_entity_id,
                                      meb_ccy,
                                      meb_nature_id,
                                      meb_acct_bal,
                                      meb_prepaid,
                                      meb_intransit,
                                      meb_lien,
                                      meb_create_timestamp,
                                      meb_create_user,
                                      meb_update_timestamp,
                                      meb_update_user)
           VALUES (in_entity_id,
                   in_ccy,
                   in_nature_id,
                   nvl(in_acct_bal,0),
                   nvl(in_prepaid,0),
                   nvl(in_intransit,0),
                   nvl(in_lien,0),
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
END sp_mms_entity_balance_update;
/
