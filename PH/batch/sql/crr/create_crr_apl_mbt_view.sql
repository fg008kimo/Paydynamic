DROP VIEW CRR_APL_MBT_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_APL_MBT_VIEW
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
       FROM (SELECT *
               FROM TXN_HEADER
              WHERE     TH_TXN_CODE IN ('RTF', 'TFF')
                    AND TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            (SELECT *
               FROM TXN_ELEMENTS
              WHERE     TE_AMT_TYPE IS NOT NULL
                    AND TE_PARTY_TYPE = 'M'
                    AND TE_TXN_ELEMENT_TYPE IN
                           ('TAMT', 'MFIN', 'MFLT', 'MPOR', 'TFEE')),
            (SELECT *
               FROM CRR_PRODUCT_CODE_MAP
              WHERE PM_DISABLED = 0),
            (SELECT *
               FROM CRR_RULE_POSTING
              WHERE     CR_DISABLED = 0
                    AND CR_TXN_CODE = 'TFR'
                    AND CR_PARTY_TYPE = 'M'
                    AND CR_JNL_ENTRY_TYPE_ID = 'S_NET_AMT')
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
     SELECT TH_ORG_TXN_ID,
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
            SUM (
               CASE
                  WHEN TE_TXN_ELEMENT_TYPE IN ('TAMT', 'MFIN', 'MFLT', 'MPOR')
                  THEN
                     TE_AMOUNT
                  WHEN TE_TXN_ELEMENT_TYPE = 'TFEE'
                  THEN
                     -1 * TE_AMOUNT
                  ELSE
                     0
               END)
               CR_AMOUNT
       FROM (SELECT *
               FROM TXN_HEADER
              WHERE     TH_TXN_CODE IN ('RTT', 'TFT')
                    AND TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            (SELECT *
               FROM TXN_ELEMENTS
              WHERE     TE_AMT_TYPE IS NOT NULL
                    AND TE_PARTY_TYPE = 'M'
                    AND TE_TXN_ELEMENT_TYPE IN
                           ('TAMT', 'MFIN', 'MFLT', 'MPOR', 'TFEE')),
            (SELECT *
               FROM CRR_PRODUCT_CODE_MAP
              WHERE PM_DISABLED = 0),
            (SELECT *
               FROM CRR_RULE_POSTING
              WHERE     CR_DISABLED = 0
                    AND CR_TXN_CODE = 'TFR'
                    AND CR_PARTY_TYPE = 'M'
                    AND CR_JNL_ENTRY_TYPE_ID = 'D_NET_AMT')
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
   GROUP BY TH_ORG_TXN_ID,
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
          TE_AMOUNT CR_AMOUNT
     FROM (SELECT *
             FROM TXN_HEADER
            WHERE     TH_TXN_CODE IN ('RTF', 'TFF')
                  AND TH_STATUS IN ('C', 'R')
                  AND TH_AR_IND = 'A'
                  AND TH_APPROVAL_DATE IS NOT NULL),
          TXN_DETAIL,
          (SELECT *
             FROM TXN_ELEMENTS
            WHERE     TE_AMT_TYPE IS NOT NULL
                  AND TE_PARTY_TYPE = 'M'
                  AND TE_TXN_ELEMENT_TYPE = 'TFEE'),
          (SELECT *
             FROM CRR_PRODUCT_CODE_MAP
            WHERE PM_DISABLED = 0),
          (SELECT *
             FROM CRR_RULE_POSTING
            WHERE     CR_DISABLED = 0
                  AND CR_TXN_CODE = 'TFR'
                  AND CR_PARTY_TYPE = 'G'
                  AND CR_JNL_ENTRY_TYPE_ID = 'S_M_FEE')
    WHERE     TH_TXN_ID = TD_TXN_ID
          AND TH_TXN_ID = TE_TXN_ID
          AND TD_TXN_COUNTRY = CR_COUNTRY_ID
          AND PM_MERCHANT_ID = TH_MERCHANT_ID
          AND PM_SERVICE_CODE = TH_SERVICE_CODE
          AND PM_COUNTRY = TD_TXN_COUNTRY
          AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   UNION ALL
   SELECT TH_ORG_TXN_ID,
          TH_APPROVAL_DATE,
          CR_COUNTRY_ID,
          CR_PRODUCT_CODE,
          CR_PARTY_TYPE,
          '' PARTY_ID,
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
          TE_AMOUNT CR_AMOUNT
     FROM (SELECT *
             FROM TXN_HEADER
            WHERE     TH_TXN_CODE IN ('RTT', 'TFT')
                  AND TH_STATUS IN ('C', 'R')
                  AND TH_AR_IND = 'A'
                  AND TH_APPROVAL_DATE IS NOT NULL),
          TXN_DETAIL,
          (SELECT *
             FROM TXN_ELEMENTS
            WHERE     TE_AMT_TYPE IS NOT NULL
                  AND TE_PARTY_TYPE = 'M'
                  AND TE_TXN_ELEMENT_TYPE = 'TFEE'),
          (SELECT *
             FROM CRR_PRODUCT_CODE_MAP
            WHERE PM_DISABLED = 0),
          (SELECT *
             FROM CRR_RULE_POSTING
            WHERE     CR_DISABLED = 0
                  AND CR_TXN_CODE = 'TFR'
                  AND CR_PARTY_TYPE = 'G'
                  AND CR_JNL_ENTRY_TYPE_ID = 'D_M_FEE')
    WHERE     TH_TXN_ID = TD_TXN_ID
          AND TH_TXN_ID = TE_TXN_ID
          AND TD_TXN_COUNTRY = CR_COUNTRY_ID
          AND PM_MERCHANT_ID = TH_MERCHANT_ID
          AND PM_SERVICE_CODE = TH_SERVICE_CODE
          AND PM_COUNTRY = TD_TXN_COUNTRY
          AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   UNION ALL
   SELECT TH_ORG_TXN_ID,
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
     FROM (SELECT *
             FROM TXN_HEADER
            WHERE     TH_TXN_CODE IN ('RTT', 'TFT')
                  AND TH_STATUS IN ('C', 'R')
                  AND TH_AR_IND = 'A'
                  AND TH_APPROVAL_DATE IS NOT NULL),
          TXN_DETAIL,
          (SELECT *
             FROM TXN_ELEMENTS
            WHERE     TE_AMT_TYPE IS NOT NULL
                  AND TE_PARTY_TYPE in ('R', 'M')
                  AND TE_TXN_ELEMENT_TYPE = 'MAMT'),
          (SELECT *
             FROM CRR_PRODUCT_CODE_MAP
            WHERE PM_DISABLED = 0),
          (SELECT *
             FROM CRR_RULE_POSTING
            WHERE     CR_DISABLED = 0
                  AND CR_TXN_CODE = 'TFR'
                  AND CR_PARTY_TYPE = 'G'
                  AND CR_JNL_ENTRY_TYPE_ID = 'D_M_FXMU_FEE')
    WHERE     TH_TXN_ID = TD_TXN_ID
          AND TH_TXN_ID = TE_TXN_ID
          AND TD_TXN_COUNTRY = CR_COUNTRY_ID
          AND PM_MERCHANT_ID = TH_MERCHANT_ID
          AND PM_SERVICE_CODE = TH_SERVICE_CODE
          AND PM_COUNTRY = TD_TXN_COUNTRY
          AND PM_PRODUCT_CODE = CR_PRODUCT_CODE;

