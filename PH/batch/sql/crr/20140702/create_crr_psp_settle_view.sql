CREATE OR REPLACE FORCE VIEW CRR_PSP_SETTLE_VIEW
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
       FROM (SELECT TH_TXN_ID,
                    TH_TXN_CODE,
                    TH_APPROVAL_DATE,
                    TH_MERCHANT_ID,
                    TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('PST')
                    AND TH_APPROVAL_DATE IS NOT NULL) TH,
            TXN_DETAIL,
            TXN_PSP_DETAIL,
            (SELECT TE_TXN_ID,
                    TE_TXN_ELEMENT_TYPE,
                    TE_CCY,
                    TE_AMOUNT
               FROM TXN_ELEMENTS
              WHERE TE_TXN_ELEMENT_TYPE = 'TFEE' AND TE_PARTY_TYPE = 'P'),
            (SELECT *
               FROM CRR_PSP_PRODUCT_CODE_MAP
              WHERE PM_DISABLED = 0),
            (SELECT CR_COUNTRY_ID,
                    CR_PARTY_TYPE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_TXN_CODE,
                    CR_PRODUCT_CODE,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
               FROM CRR_RULE_POSTING
              WHERE     CR_PARTY_TYPE = 'G'
                    AND CR_JNL_ENTRY_TYPE_ID = 'PSP_COST'
                    AND CR_TXN_CODE = 'PSR'
                    AND CR_DISABLED = 0)
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TE_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND TP_PSP_ID = PSP_ID
            AND PM_PSP_ID = PSP_ID
            AND PM_BUSINESS_TYPE = PSP_TYPE
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
   UNION
     SELECT TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TP_PSP_ID PARTY_ID,
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
       FROM (SELECT TH_TXN_ID,
                    TH_TXN_CODE,
                    TH_APPROVAL_DATE,
                    TH_MERCHANT_ID,
                    TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('PST')
                    AND TH_APPROVAL_DATE IS NOT NULL) TH,
            TXN_DETAIL,
            TXN_PSP_DETAIL,
            (SELECT TE_TXN_ID,
                    TE_TXN_ELEMENT_TYPE,
                    TE_CCY,
                    TE_AMOUNT
               FROM TXN_ELEMENTS
              WHERE TE_TXN_ELEMENT_TYPE = 'TFEE' AND TE_PARTY_TYPE = 'P'),
            (SELECT *
               FROM CRR_PSP_PRODUCT_CODE_MAP
              WHERE PM_DISABLED = 0),
            (SELECT CR_COUNTRY_ID,
                    CR_PARTY_TYPE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_TXN_CODE,
                    CR_PRODUCT_CODE,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
               FROM CRR_RULE_POSTING
              WHERE     CR_PARTY_TYPE = 'G'
                    AND CR_JNL_ENTRY_TYPE_ID = 'PSP_COST'
                    AND CR_TXN_CODE = 'PSR'
                    AND CR_DISABLED = 0)
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TE_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND TP_PSP_ID = PSP_ID
            AND PM_PSP_ID = PSP_ID
            AND PM_BUSINESS_TYPE = PSP_TYPE
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   GROUP BY TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TP_PSP_ID
            TE_CCY,
            CR_JNL_TYPE_ID,
            CR_JNL_ENTRY_TYPE_ID,
            CR_CREDIT_GL_ID,
            CR_DEBIT_GL_ID;

