CREATE OR REPLACE FUNCTION sp_mms_acr_bal_history_insert (
   in_fx_id            mms_acr_bal_history.mah_fx_id%TYPE,
   in_fx_seq           mms_acr_bal_history.mah_fx_seq%TYPE,
   in_funds_direction    mms_acr_bal_history.mah_funds_direction%TYPE,
   in_entity_id         mms_acr_bal_history.mah_entity_id%TYPE,
   in_org_ccy           mms_acr_bal_history.mah_org_ccy%TYPE,
   in_ccy               mms_acr_bal_history.mah_ccy%TYPE,
   in_old_bal           mms_acr_bal_history.mah_old_bal%TYPE,
   in_new_bal           mms_acr_bal_history.mah_new_bal%TYPE,
   in_old_rate          mms_acr_bal_history.mah_old_rate%TYPE,
   in_new_rate          mms_acr_bal_history.mah_new_rate%TYPE,
   in_old_ratio         mms_acr_bal_history.mah_old_ratio%TYPE,
   in_new_ratio         mms_acr_bal_history.mah_new_ratio%TYPE,
   in_create_user       mms_acr_bal_history.mah_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   INSERT INTO mms_acr_bal_history (mah_fx_id,
				    mah_fx_seq,
                                    mah_funds_direction,
                                    mah_entity_id,
                                    mah_org_ccy,
                                    mah_ccy,
                                    mah_old_bal,
                                    mah_new_bal,
                                    mah_old_rate,
                                    mah_new_rate,
                                    mah_old_ratio,
                                    mah_new_ratio,
                                    mah_create_timestamp,
                                    mah_create_user,
                                    mah_update_timestamp,
                                    mah_update_user)
        VALUES (in_fx_id,
		in_fx_seq,
                in_funds_direction,
                in_entity_id,
                in_org_ccy,
                in_ccy,
                in_old_bal,
                in_new_bal,
                in_old_rate,
                in_new_rate,
                in_old_ratio,
                in_new_ratio,
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
END sp_mms_acr_bal_history_insert;
/
