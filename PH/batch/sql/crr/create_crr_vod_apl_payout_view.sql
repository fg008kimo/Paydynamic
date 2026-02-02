DROP VIEW CRR_VOD_APL_PAYOUT_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_VOD_APL_PAYOUT_VIEW
(
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
     SELECT TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TH_MERCHANT_ID,
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
            COUNT (DISTINCT TH_TXN_ID) TXN_COUNT,
            SUM (TE_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID, TH_APPROVAL_DATE, TH_MERCHANT_ID, TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('VOA', 'VRA')
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_AMOUNT,
                    TE_PARTY_TYPE
               FROM TXN_ELEMENTS
              WHERE     TE_PARTY_TYPE = 'M'
                    AND TE_TXN_ELEMENT_TYPE IN ('TAMT', 'MAPO', 'MAPF', 'TFEE')),
            (SELECT * FROM CRR_PRODUCT_CODE_MAP WHERE PM_DISABLED = 0),
            (SELECT CR_COUNTRY_ID,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID,
                    CR_CURRENCY_ID,
                    CR_PARTY_ID,
                    CR_PARTY_TYPE,
                    CR_PRODUCT_CODE
               FROM CRR_RULE_POSTING
              WHERE     CR_PARTY_TYPE = 'M'
                    AND CR_DISABLED = 0
                    AND CR_TXN_CODE = 'VOA'
                    AND CR_JNL_ENTRY_TYPE_ID = 'NET_AMT')
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
   GROUP BY TH_APPROVAL_DATE,
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
     SELECT TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            '' PARTY_ID,
            UD_PAYOUT_CURRENCY,
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
            COUNT (DISTINCT TH_TXN_ID) TXN_COUNT,
            SUM (UD_PAYOUT_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID, TH_APPROVAL_DATE, TH_MERCHANT_ID, TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('VOA', 'VRA')
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            (SELECT UD_AUX_TXN_ID, UD_PAYOUT_AMOUNT, UD_PAYOUT_CURRENCY
               FROM MERCHANT_UPLOAD_FILE_DETAIL),
            (SELECT * FROM CRR_PRODUCT_CODE_MAP WHERE PM_DISABLED = 0),
            (SELECT CR_COUNTRY_ID,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID,
                    CR_CURRENCY_ID,
                    CR_PARTY_ID,
                    CR_PARTY_TYPE,
                    CR_PRODUCT_CODE
               FROM CRR_RULE_POSTING CRP
              WHERE     CR_PARTY_TYPE = 'G'
                    AND CR_DISABLED = 0
                    AND CR_TXN_CODE = 'VOA'
                    AND CR_JNL_ENTRY_TYPE_ID = 'PSP_TEMP')
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = UD_AUX_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND PM_MERCHANT_ID = TH_MERCHANT_ID
            AND PM_SERVICE_CODE = TH_SERVICE_CODE
            AND PM_COUNTRY = TD_TXN_COUNTRY
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   GROUP BY TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            UD_PAYOUT_CURRENCY,
            CR_JNL_TYPE_ID,
            CR_JNL_ENTRY_TYPE_ID,
            CR_CREDIT_GL_ID,
            CR_DEBIT_GL_ID
   UNION ALL
     SELECT TH_APPROVAL_DATE,
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
            COUNT (DISTINCT TH_TXN_ID) TXN_COUNT,
            SUM (TE_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID, TH_APPROVAL_DATE, TH_MERCHANT_ID, TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('VOA', 'VRA')
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_AMOUNT,
                    TE_PARTY_TYPE
               FROM TXN_ELEMENTS
              WHERE TE_PARTY_TYPE = 'M' AND TE_TXN_ELEMENT_TYPE in ('MAPF','TFEE')),
            (SELECT * FROM CRR_PRODUCT_CODE_MAP WHERE PM_DISABLED = 0),
            (SELECT CR_COUNTRY_ID,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID,
                    CR_CURRENCY_ID,
                    CR_PARTY_ID,
                    CR_PARTY_TYPE,
                    CR_PRODUCT_CODE
               FROM CRR_RULE_POSTING
              WHERE     CR_PARTY_TYPE = 'G'
                    AND CR_DISABLED = 0
                    AND CR_TXN_CODE = 'VOA'
                    AND CR_JNL_ENTRY_TYPE_ID = 'M_FEE')
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TE_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND PM_MERCHANT_ID = TH_MERCHANT_ID
            AND PM_SERVICE_CODE = TH_SERVICE_CODE
            AND PM_COUNTRY = TD_TXN_COUNTRY
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   GROUP BY TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TE_CCY,
            CR_JNL_TYPE_ID,
            CR_JNL_ENTRY_TYPE_ID,
            CR_CREDIT_GL_ID,
            CR_DEBIT_GL_ID
   UNION ALL
     SELECT TH_APPROVAL_DATE,
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
            COUNT (DISTINCT TH_TXN_ID) TXN_COUNT,
            SUM (TE_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID, TH_APPROVAL_DATE, TH_MERCHANT_ID, TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('VOA', 'VRA')
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_AMOUNT,
                    TE_PARTY_TYPE
               FROM TXN_ELEMENTS
              WHERE TE_PARTY_TYPE = 'R' AND TE_TXN_ELEMENT_TYPE = 'MAMT'),
            (SELECT * FROM CRR_PRODUCT_CODE_MAP WHERE PM_DISABLED = 0),
            (SELECT CR_COUNTRY_ID,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID,
                    CR_CURRENCY_ID,
                    CR_PARTY_ID,
                    CR_PARTY_TYPE,
                    CR_PRODUCT_CODE
               FROM CRR_RULE_POSTING
              WHERE     CR_PARTY_TYPE = 'G'
                    AND CR_DISABLED = 0
                    AND CR_TXN_CODE = 'VOA'
                    AND CR_JNL_ENTRY_TYPE_ID = 'M_FXMU_FEE')
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TE_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND PM_MERCHANT_ID = TH_MERCHANT_ID
            AND PM_SERVICE_CODE = TH_SERVICE_CODE
            AND PM_COUNTRY = TD_TXN_COUNTRY
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   GROUP BY TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TE_CCY,
            CR_JNL_TYPE_ID,
            CR_JNL_ENTRY_TYPE_ID,
            CR_CREDIT_GL_ID,
            CR_DEBIT_GL_ID;

