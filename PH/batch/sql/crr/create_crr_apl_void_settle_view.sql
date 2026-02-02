DROP VIEW CRR_APL_VOID_SETTLE_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_APL_VOID_SETTLE_VIEW
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
            TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TH_MERCHANT_ID PARTY_ID,
            TE_CCY,
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
            SUM (TE_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID,
                    TH_TXN_CODE,
                    TH_MERCHANT_ID,
                    TH_APPROVAL_DATE,
                    TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('VST')),
            TXN_DETAIL,
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_PARTY_TYPE,
                    TE_AMOUNT
               FROM TXN_ELEMENTS
              WHERE TE_PARTY_TYPE = 'M' AND TE_TXN_ELEMENT_TYPE IN ('TAMT', 'TFEE')),
            (SELECT *
               FROM CRR_RULE_POSTING
              WHERE     CR_TXN_CODE = 'VST'
                    AND CR_PARTY_TYPE = 'M'
                    AND CR_JNL_ENTRY_TYPE_ID = 'C_TXN_AMT'
                    AND CR_DISABLED = 0),
            (SELECT * FROM CRR_PRODUCT_CODE_MAP WHERE PM_DISABLED = 0)
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TE_TXN_ID
            AND TH_MERCHANT_ID = CR_PARTY_ID
            AND TE_PARTY_TYPE = CR_PARTY_TYPE
            AND TE_CCY = CR_CURRENCY_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND PM_MERCHANT_ID = TH_MERCHANT_ID
            AND PM_SERVICE_CODE = TH_SERVICE_CODE
            AND PM_COUNTRY = TD_TXN_COUNTRY
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   GROUP BY TH_TXN_ID,
            TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TH_MERCHANT_ID,
            TE_CCY,
            CR_JNL_TYPE_ID,
            CR_JNL_ENTRY_TYPE_ID,
            CR_CREDIT_GL_ID,
            CR_DEBIT_GL_ID
   UNION ALL
     SELECT TH_TXN_ID,
            TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            '' PARTY_ID,
            TE_CCY CR_CURRENCY,
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
            TE_AMOUNT CR_AMOUNT
       FROM (SELECT TH_TXN_ID,
                    TH_TXN_CODE,
                    TH_MERCHANT_ID,
                    TH_APPROVAL_DATE,
                    TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('VST')),
            TXN_DETAIL,
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_PARTY_TYPE,
                    TE_AMOUNT
               FROM TXN_ELEMENTS
              WHERE TE_PARTY_TYPE = 'M' AND TE_TXN_ELEMENT_TYPE = 'TFEE'),
            (SELECT *
               FROM CRR_RULE_POSTING
              WHERE     CR_TXN_CODE = 'VST'
                    AND CR_PARTY_TYPE = 'G'
                    AND CR_JNL_ENTRY_TYPE_ID = 'FEE'
                    AND CR_DISABLED = 0),
            (SELECT * FROM CRR_PRODUCT_CODE_MAP WHERE PM_DISABLED = 0)
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TE_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND PM_MERCHANT_ID = TH_MERCHANT_ID
            AND PM_SERVICE_CODE = TH_SERVICE_CODE
            AND PM_COUNTRY = TD_TXN_COUNTRY
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   UNION ALL
     SELECT TH_TXN_ID,
            TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            '' PARTY_ID,
            TE_CCY CR_CURRENCY,
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
            TE_AMOUNT CR_AMOUNT
       FROM (SELECT TH_TXN_ID,
                    TH_TXN_CODE,
                    TH_MERCHANT_ID,
                    TH_APPROVAL_DATE,
                    TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('VST')),
            TXN_DETAIL,
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_PARTY_TYPE,
                    TE_AMOUNT
               FROM TXN_ELEMENTS
              WHERE TE_PARTY_TYPE in ('R', 'M') AND TE_TXN_ELEMENT_TYPE = 'MAMT'),
            (SELECT *
               FROM CRR_RULE_POSTING
              WHERE     CR_TXN_CODE = 'VST'
                    AND CR_PARTY_TYPE = 'G'
                    AND CR_JNL_ENTRY_TYPE_ID = 'MU_FEE'
                    AND CR_DISABLED = 0),
            (SELECT * FROM CRR_PRODUCT_CODE_MAP WHERE PM_DISABLED = 0)
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TE_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND PM_MERCHANT_ID = TH_MERCHANT_ID
            AND PM_SERVICE_CODE = TH_SERVICE_CODE
            AND PM_COUNTRY = TD_TXN_COUNTRY
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   UNION ALL
     SELECT TH_TXN_ID,
            TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            '' PARTY_ID,
            SD_DELIVER_CCY CR_CURRENCY,
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
       FROM (SELECT TH_TXN_ID,
                    TH_ORG_TXN_ID,
                    TH_TXN_CODE,
                    TH_MERCHANT_ID,
                    TH_APPROVAL_DATE,
                    TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('VST')),
            (SELECT SD_TXN_ID,
                    SD_COUNTRY_ID,
                    SD_DELIVER_CCY,
                    SD_DELIVER_AMT
               FROM MERCHANT_SETTLEMENT_DETAIL),
            (SELECT *
               FROM CRR_RULE_POSTING
              WHERE     CR_TXN_CODE = 'VST'
                    AND CR_PARTY_TYPE = 'G'
                    AND CR_JNL_ENTRY_TYPE_ID = 'G_TXN_AMT_DR'
                    AND CR_DISABLED = 0),
            (SELECT * FROM CRR_PRODUCT_CODE_MAP WHERE PM_DISABLED = 0)
      WHERE     TH_ORG_TXN_ID = SD_TXN_ID
            AND SD_COUNTRY_ID = CR_COUNTRY_ID
            AND PM_MERCHANT_ID = TH_MERCHANT_ID
            AND PM_SERVICE_CODE = TH_SERVICE_CODE
            AND PM_COUNTRY = SD_COUNTRY_ID
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE;

