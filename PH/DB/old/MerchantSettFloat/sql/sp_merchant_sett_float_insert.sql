CREATE OR REPLACE FUNCTION sp_merchant_sett_float_insert (
   in_id                        merchant_sett_float.sf_id%TYPE,
   in_merchant_id               merchant_sett_float.sf_merchant_id%TYPE,
   in_country                   merchant_sett_float.sf_country%TYPE,
   in_ccy                       merchant_sett_float.sf_ccy%TYPE,
   in_service_code              merchant_sett_float.sf_service_code%TYPE,
   in_org_available_payout      merchant_sett_float.sf_org_available_payout%TYPE,
   in_after_available_payout    merchant_sett_float.sf_after_available_payout%TYPE,
   in_org_settlement_float      merchant_sett_float.sf_org_settlement_float%TYPE,
   in_after_settlement_float    merchant_sett_float.sf_after_settlement_float%TYPE,
   in_add_user                  merchant_sett_float.sf_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   INSERT INTO merchant_sett_float (sf_id,
                                    sf_merchant_id,
                                    sf_country,
                                    sf_ccy,
                                    sf_service_code,
                                    sf_org_available_payout,
                                    sf_after_available_payout,
                                    sf_org_settlement_float,
                                    sf_after_settlement_float,
                                    sf_create_user,
                                    sf_update_user,
                                    sf_create_timestamp,
                                    sf_update_timestamp)
        VALUES (in_id,
                in_merchant_id,
                in_country,
                in_ccy,
                in_service_code,
                in_org_available_payout,
                in_after_available_payout,
                in_org_settlement_float,
                in_after_settlement_float,
                in_add_user,
                in_add_user,
                SYSDATE,
                SYSDATE);

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
END sp_merchant_sett_float_insert;
/
