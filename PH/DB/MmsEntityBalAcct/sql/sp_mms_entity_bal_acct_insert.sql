CREATE OR REPLACE FUNCTION sp_mms_entity_bal_acct_insert (
   in_entity_id           mms_entity_bal_acct.mba_entity_id%TYPE,
   in_ccy                 mms_entity_bal_acct.mba_ccy%TYPE,
   in_status_ref          mms_entity_bal_acct.mba_status_ref%TYPE,
   in_is_user_editable    mms_entity_bal_acct.mba_is_user_editable%TYPE,
   in_disabled            mms_entity_bal_acct.mba_disabled%TYPE,
   in_create_user         mms_entity_bal_acct.mba_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   INSERT INTO mms_entity_bal_acct (mba_entity_id,
                                    mba_ccy,
                                    mba_status_ref,
                                    mba_is_user_editable,
                                    mba_disabled,
                                    mba_create_timestamp,
                                    mba_create_user,
                                    mba_update_timestamp,
                                    mba_update_user)
        VALUES (in_entity_id,
                in_ccy,
                in_status_ref,
                in_is_user_editable,
                in_disabled,
                SYSDATE,
                in_create_user,
                SYSDATE,
                in_create_user);

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
END sp_mms_entity_bal_acct_insert;
/
