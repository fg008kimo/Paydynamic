DROP VIEW PSP_SETTLEMENT_PREVIEW_VIEW;

CREATE OR REPLACE FORCE VIEW PSP_SETTLEMENT_PREVIEW_VIEW
(
   MB_POSTING_DATE,
   MB_MERCHANT_ID,
   MB_COUNTRY_ID,
   MB_CURRENCY_ID,
   MB_SERVICE_CODE,
   MB_PSP_ID,
   MBP_BAL
)
AS
     SELECT mb_posting_date,
            mb_merchant_id,
            mb_country_id,
            mb_currency_id,
            mb_service_code,
            mb_psp_id,
            SUM (mbp_bal) AS mbp_bal
       FROM (  SELECT mb_posting_date,
                      mb_merchant_id,
                      mb_country_id,
                      mb_currency_id,
                      mb_service_code,
                      mb_psp_id,
                      SUM (mb_bal) AS mbp_bal
                 FROM rule_service_release_period, merchant_bucket
                WHERE     mb_bucket_type = 'AF'
                      AND mb_released_date IS NULL
                      AND rs_release_type = 'SETTFT'
                      AND rs_service_code = mb_service_code
                      AND rs_disabled = 0
                      AND mb_posting_date <= release_pkg.find_release_date (
                                                (SELECT sys_val
                                                   FROM system_control
                                                  WHERE sys_code = 'CTPHDATE'),
                                                mb_country_id,
                                                mb_service_code,
                                                rs_release_period)
             GROUP BY mb_posting_date,
                      mb_merchant_id,
                      mb_country_id,
                      mb_currency_id,
                      mb_service_code,
                      mb_psp_id
             UNION ALL
               SELECT mbp_posting_date,
                      mbp_merchant_id,
                      mbp_country_id,
                      mbp_currency_id,
                      mbp_service_code,
                      mbp_psp_id,
                      SUM (mbp_bal) AS mbp_bal
                 FROM rule_service_release_period, merchant_bucket_preview
                WHERE     mbp_bucket_type = 'AF'
                      AND rs_release_type = 'SETTFT'
                      AND rs_service_code = mbp_service_code
                      AND rs_disabled = 0
                      AND mbp_posting_date <= release_pkg.find_release_date (
                                                 (SELECT sys_val
                                                    FROM system_control
                                                   WHERE sys_code = 'CTPHDATE'),
                                                 mbp_country_id,
                                                 mbp_service_code,
                                                 rs_release_period)
             GROUP BY mbp_posting_date,
                      mbp_merchant_id,
                      mbp_country_id,
                      mbp_currency_id,
                      mbp_service_code,
                      mbp_psp_id)
   GROUP BY mb_posting_date,
            mb_merchant_id,
            mb_country_id,
            mb_currency_id,
            mb_service_code,
            mb_psp_id;

