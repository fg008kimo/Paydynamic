CREATE OR REPLACE FUNCTION sp_mms_acr_bal_update (
   in_entity_id      mms_acr_bal.mab_entity_id%TYPE,
   in_org_ccy        mms_acr_bal.mab_org_ccy%TYPE,
   in_ccy            mms_acr_bal.mab_ccy%TYPE,
   in_bal            mms_acr_bal.mab_bal%TYPE,
   in_rate           mms_acr_bal.mab_rate%TYPE,
   in_ratio          mms_acr_bal.mab_ratio%TYPE,
   in_update_user    mms_acr_bal.mab_update_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   UPDATE mms_acr_bal
      SET mab_bal = in_bal,
          mab_rate = in_rate,
          mab_ratio = in_ratio,
          mab_update_user = in_update_user,
          mab_update_timestamp = SYSDATE
    WHERE     mab_entity_id = in_entity_id
          AND mab_org_ccy = in_org_ccy
          AND mab_ccy = in_ccy;

   IF SQL%ROWCOUNT = 0
   THEN
      INSERT INTO mms_acr_bal (mab_entity_id,
                               mab_org_ccy,
                               mab_ccy,
                               mab_bal,
                               mab_rate,
                               mab_ratio,
                               mab_create_timestamp,
                               mab_create_user,
                               mab_update_timestamp,
                               mab_update_user)
           VALUES (in_entity_id,
                   in_org_ccy,
                   in_ccy,
                   in_bal,
                   in_rate,
                   in_ratio,
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
END sp_mms_acr_bal_update;
/
