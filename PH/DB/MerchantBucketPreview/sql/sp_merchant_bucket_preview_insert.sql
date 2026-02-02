CREATE OR REPLACE FUNCTION sp_merchant_bucket_pre_insert (
   in_posting_date    merchant_bucket_preview.mbp_posting_date%TYPE,
   in_merchant_id     merchant_bucket_preview.mbp_merchant_id%TYPE,
   in_country_id      merchant_bucket_preview.mbp_country_id%TYPE,
   in_currency_id     merchant_bucket_preview.mbp_currency_id%TYPE,
   in_service_code    merchant_bucket_preview.mbp_service_code%TYPE,
   in_psp_id          merchant_bucket_preview.mbp_psp_id%TYPE,
   in_bucket_type     merchant_bucket_preview.mbp_bucket_type%TYPE,
   in_bal             merchant_bucket_preview.mbp_bal%TYPE,
   in_create_user     merchant_bucket_preview.mbp_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   UPDATE merchant_bucket_preview
      SET mbp_bal = in_bal,
          mbp_update_user = in_create_user,
          mbp_update_timestamp = sysdate
    WHERE     mbp_posting_date = in_posting_date
          AND mbp_merchant_id = in_merchant_id
          AND mbp_country_id = in_country_id
          AND mbp_currency_id = in_currency_id
          AND mbp_service_code = in_service_code
          AND mbp_psp_id = in_psp_id
          AND mbp_bucket_type = in_bucket_type;

   IF SQL%ROWCOUNT = 0
   THEN
      INSERT INTO merchant_bucket_preview (mbp_posting_date,
                                           mbp_merchant_id,
                                           mbp_country_id,
                                           mbp_currency_id,
                                           mbp_service_code,
                                           mbp_psp_id,
                                           mbp_bucket_type,
                                           mbp_bal,
                                           mbp_create_user,
                                           mbp_update_user,
                                           mbp_create_timestamp,
                                           mbp_update_timestamp)
           VALUES (in_posting_date,
                   in_merchant_id,
                   in_country_id,
                   in_currency_id,
                   in_service_code,
                   in_psp_id,
                   in_bucket_type,
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
END sp_merchant_bucket_pre_insert;
/

