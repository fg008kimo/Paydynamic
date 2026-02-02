DROP VIEW CRR_DEL_SETTLE_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_DEL_SETTLE_VIEW
(
   TH_TXN_ID,
   CR_TXN_DATE,
   CR_COUNTRY,
   CR_PRODUCT,
   TE_PARTY_TYPE,
   PARTY_ID,
   CR_CURRENCY,
   CR_JNL_TYPE_ID,
   CR_JNL_ENTRY_TYPE_ID,
   CR_IND,
   CR_GL_ID,
   TXN_COUNT,
   CR_AMOUNT
)
AS
   SELECT TH_TXN_ID,
          SD_DELIVER_DATE,
          CR_COUNTRY_ID,
          CR_PRODUCT_CODE,
          CR_PARTY_TYPE,
          '' PARTY_ID,
          SD_DELIVER_CCY,
          CR_JNL_TYPE_ID,
          CR_JNL_ENTRY_TYPE_ID,
          CASE
             WHEN CR_CREDIT_GL_ID <> 0 THEN 'C'
             WHEN CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
             ELSE ''
          END
             CR_IND,
          CASE
             WHEN CR_CREDIT_GL_ID <> 0 THEN CR_CREDIT_GL_ID
             WHEN CR_DEBIT_GL_ID IS NOT NULL THEN CR_DEBIT_GL_ID
             ELSE 0
          END
             CR_GL_ID,
          1 TXN_COUNT,
          SD_DELIVER_AMT CR_AMOUNT
     FROM (SELECT TH_TXN_ID, TH_MERCHANT_ID, TH_SERVICE_CODE
             FROM TXN_HEADER
            WHERE     TH_STATUS IN ('C', 'R')
                  AND TH_AR_IND = 'A'
                  AND TH_TXN_CODE IN ('STR')),
          (SELECT SD_DELIVER_DATE,
                  SD_DELIVER_CCY,
                  SD_DELIVER_AMT,
                  SD_COUNTRY_ID,
                  SD_TXN_ID
             FROM MERCHANT_SETTLEMENT_DETAIL
            WHERE SD_DELIVER_DATE IS NOT NULL AND SD_STATUS = 'C'),
          (SELECT CR_COUNTRY_ID,
                  CR_PRODUCT_CODE,
                  CR_PARTY_TYPE,
                  CR_PARTY_ID,
                  CR_DEBIT_GL_ID,
                  CR_CREDIT_GL_ID,
                  CR_JNL_TYPE_ID,
                  CR_JNL_ENTRY_TYPE_ID
             FROM CRR_RULE_POSTING
            WHERE     CR_PARTY_TYPE = 'G'
                  AND CR_JNL_ENTRY_TYPE_ID = 'S_DELI_AMT'
                  AND CR_DISABLED = 0
                  AND CR_TXN_CODE = 'STD'),
          (SELECT PM_MERCHANT_ID,
                  PM_SERVICE_CODE,
                  PM_COUNTRY,
                  PM_PRODUCT_CODE
             FROM CRR_PRODUCT_CODE_MAP
            WHERE PM_DISABLED = 0)
    WHERE     TH_TXN_ID = SD_TXN_ID
          AND SD_COUNTRY_ID = CR_COUNTRY_ID
          AND PM_MERCHANT_ID = TH_MERCHANT_ID
          AND PM_SERVICE_CODE = TH_SERVICE_CODE
          AND PM_COUNTRY = SD_COUNTRY_ID
          AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   UNION ALL
   SELECT TH_TXN_ID,
          SD_DELIVER_DATE,
          CR_COUNTRY_ID,
          CR_PRODUCT_CODE,
          CR_PARTY_TYPE,
          '' PARTY_ID,
          SD_DELIVER_CCY,
          CR_JNL_TYPE_ID,
          CR_JNL_ENTRY_TYPE_ID,
          CASE
             WHEN CR_CREDIT_GL_ID <> 0 THEN 'C'
             WHEN CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
             ELSE ''
          END
             CR_IND,
          CASE
             WHEN CR_CREDIT_GL_ID <> 0 THEN CR_CREDIT_GL_ID
             WHEN CR_DEBIT_GL_ID IS NOT NULL THEN CR_DEBIT_GL_ID
             ELSE 0
          END
             CR_GL_ID,
          1 TXN_COUNT,
          SD_DELIVER_AMT CR_AMOUNT
     FROM (SELECT TH_TXN_ID, TH_MERCHANT_ID, TH_SERVICE_CODE
             FROM TXN_HEADER TH
            WHERE     TH_STATUS IN ('C', 'R')
                  AND TH_AR_IND = 'A'
                  AND TH_TXN_CODE IN ('STR')),
          (SELECT SD_DELIVER_DATE,
                  SD_DELIVER_CCY,
                  SD_DELIVER_AMT,
                  SD_COUNTRY_ID,
                  SD_TXN_ID
             FROM MERCHANT_SETTLEMENT_DETAIL
            WHERE SD_DELIVER_DATE IS NOT NULL AND SD_STATUS = 'C'),
          (SELECT CR_COUNTRY_ID,
                  CR_PRODUCT_CODE,
                  CR_PARTY_TYPE,
                  CR_PARTY_ID,
                  CR_DEBIT_GL_ID,
                  CR_CREDIT_GL_ID,
                  CR_JNL_TYPE_ID,
                  CR_JNL_ENTRY_TYPE_ID,
                  CR_CURRENCY_ID
             FROM CRR_RULE_POSTING
            WHERE     CR_PARTY_TYPE = 'G'
                  AND CR_JNL_ENTRY_TYPE_ID = 'D_DELI_AMT'
                  AND CR_DISABLED = 0
                  AND CR_TXN_CODE = 'STD'),
          (SELECT PM_MERCHANT_ID,
                  PM_SERVICE_CODE,
                  PM_COUNTRY,
                  PM_PRODUCT_CODE
             FROM CRR_PRODUCT_CODE_MAP
            WHERE PM_DISABLED = 0)
    WHERE     TH_TXN_ID = SD_TXN_ID
          AND SD_COUNTRY_ID = CR_COUNTRY_ID
          AND SD_DELIVER_CCY = CR_CURRENCY_ID
          AND PM_MERCHANT_ID = TH_MERCHANT_ID
          AND PM_SERVICE_CODE = TH_SERVICE_CODE
          AND PM_COUNTRY = SD_COUNTRY_ID
          AND PM_PRODUCT_CODE = CR_PRODUCT_CODE;

