DROP VIEW PSP_SETTLEMENT_VIEW;

/* Formatted on 8/29/2012 11:00:41 AM (QP5 v5.185.11230.41888) */
CREATE OR REPLACE FORCE VIEW PSP_SETTLEMENT_VIEW
(
   MB_POSTING_DATE,
   MB_MERCHANT_ID,
   MB_COUNTRY_ID,
   MB_CURRENCY_ID,
   MB_SERVICE_CODE,
   MB_PSP_ID,
   MB_BUCKET_TYPE,
   MB_BAL,
   MB_CREATE_USER,
   MB_UPDATE_USER,
   MB_CREATE_TIMESTAMP,
   MB_UPDATE_TIMESTAMP,
   MB_RELEASED_DATE,
   MB_RELEASED_AMT,
   MB_RELEASED_TO_AF
)
AS
   SELECT "MB_POSTING_DATE",
          "MB_MERCHANT_ID",
          "MB_COUNTRY_ID",
          "MB_CURRENCY_ID",
          "MB_SERVICE_CODE",
          "MB_PSP_ID",
          "MB_BUCKET_TYPE",
          "MB_BAL",
          "MB_CREATE_USER",
          "MB_UPDATE_USER",
          "MB_CREATE_TIMESTAMP",
          "MB_UPDATE_TIMESTAMP",
          "MB_RELEASED_DATE",
          "MB_RELEASED_AMT",
          "MB_RELEASED_TO_AF"
     FROM merchant_bucket
    WHERE     mb_bucket_type = 'AF'
          AND mb_released_date IS NULL
          AND mb_posting_date <= (SELECT sys_val
                                    FROM system_control
                                   WHERE sys_code = 'CTPHDATE');

