CREATE OR REPLACE FUNCTION sp_mms_entity_balance_init (
   in_entity_id      mms_entity_balance.meb_entity_id%TYPE,
   in_ccy            mms_entity_balance.meb_ccy%TYPE,
   in_nature_id      mms_entity_balance.meb_nature_id%TYPE,
   in_update_user    mms_entity_balance.meb_update_user%TYPE)
   RETURN NUMBER
IS
BEGIN
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
                   0,
                   0,
                   0,
                   0,
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
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_mms_entity_balance_init;
/
