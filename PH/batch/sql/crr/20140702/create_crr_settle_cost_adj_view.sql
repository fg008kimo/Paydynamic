CREATE OR REPLACE FORCE VIEW CRR_SETTLE_COST_ADJ_VIEW
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
            TD_TXN_CCY,
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
            SUM (TH_NET_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID,
                    TH_TXN_CODE,
                    TH_APPROVAL_DATE,
                    TH_MERCHANT_ID,
                    TH_NET_AMOUNT,
                    TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE = (SELECT SP_VAL
                                         FROM SYSTEM_PARAMETER
                                        WHERE SP_CODE = 'CREDIT_ADJ_FOR_SETTLE')
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            TXN_PSP_DETAIL,
            PSP_DETAIL,
            (SELECT *
               FROM CRR_PSP_PRODUCT_CODE_MAP
              WHERE PM_DISABLED = 0),
            (SELECT CR_COUNTRY_ID,
                    CR_PRODUCT_CODE,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    CR_CURRENCY_ID,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
               FROM CRR_RULE_POSTING
              WHERE     CR_PARTY_TYPE = 'G'
                    AND CR_JNL_ENTRY_TYPE_ID = 'ADJ_CR_PSP_COST'
                    AND CR_TXN_CODE = 'ASC'
                    AND CR_DISABLED = 0)
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TP_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND TP_PSP_ID = PSP_ID
            AND PM_PSP_ID = PSP_ID
            AND PM_BUSINESS_TYPE = PSP_TYPE
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   GROUP BY TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TD_TXN_CCY,
            CR_JNL_TYPE_ID,
            CR_JNL_ENTRY_TYPE_ID,
            CR_CREDIT_GL_ID,
            CR_DEBIT_GL_ID
   UNION ALL
     SELECT TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TP_PSP_ID PARTY_ID,
            TD_TXN_CCY,
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
            SUM (TH_NET_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID,
                    TH_TXN_CODE,
                    TH_APPROVAL_DATE,
                    TH_MERCHANT_ID,
                    TH_NET_AMOUNT,
                    TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE = (SELECT SP_VAL
                                         FROM SYSTEM_PARAMETER
                                        WHERE SP_CODE = 'CREDIT_ADJ_FOR_SETTLE')
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            TXN_PSP_DETAIL,
            PSP_DETAIL,
            (SELECT *
               FROM CRR_PSP_PRODUCT_CODE_MAP
              WHERE PM_DISABLED = 0),
            (SELECT CR_COUNTRY_ID,
                    CR_PRODUCT_CODE,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    CR_CURRENCY_ID,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
               FROM CRR_RULE_POSTING
              WHERE     CR_PARTY_TYPE = 'P'
                    AND CR_JNL_ENTRY_TYPE_ID = 'D_ADJ_CR_PSP_COST'
                    AND CR_TXN_CODE = 'ASC'
                    AND CR_DISABLED = 0)
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TP_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND TP_PSP_ID = CR_PARTY_ID
            AND TP_PSP_ID = PSP_ID
            AND PM_PSP_ID = PSP_ID
            AND PM_BUSINESS_TYPE = PSP_TYPE
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   GROUP BY TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TP_PSP_ID,
            TD_TXN_CCY,
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
            TD_TXN_CCY,
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
            SUM (TH_NET_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID,
                    TH_TXN_CODE,
                    TH_APPROVAL_DATE,
                    TH_MERCHANT_ID,
                    TH_NET_AMOUNT,
                    TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE = (SELECT SP_VAL
                                         FROM SYSTEM_PARAMETER
                                        WHERE SP_CODE = 'DEBIT_ADJ_FOR_SETTLE')
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            TXN_PSP_DETAIL,
            PSP_DETAIL,
            (SELECT *
               FROM CRR_PSP_PRODUCT_CODE_MAP
              WHERE PM_DISABLED = 0),
            (SELECT CR_COUNTRY_ID,
                    CR_PRODUCT_CODE,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    CR_CURRENCY_ID,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
               FROM CRR_RULE_POSTING
              WHERE     CR_PARTY_TYPE = 'G'
                    AND CR_JNL_ENTRY_TYPE_ID = 'ADJ_DR_PSP_COST'
                    AND CR_TXN_CODE = 'ASC'
                    AND CR_DISABLED = 0)
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TP_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND TP_PSP_ID = PSP_ID
            AND PM_PSP_ID = PSP_ID
            AND PM_BUSINESS_TYPE = PSP_TYPE
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   GROUP BY TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TD_TXN_CCY,
            CR_JNL_TYPE_ID,
            CR_JNL_ENTRY_TYPE_ID,
            CR_CREDIT_GL_ID,
            CR_DEBIT_GL_ID
   UNION ALL
     SELECT TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TP_PSP_ID PARTY_ID,
            TD_TXN_CCY,
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
            SUM (TH_NET_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID,
                    TH_TXN_CODE,
                    TH_APPROVAL_DATE,
                    TH_MERCHANT_ID,
                    TH_NET_AMOUNT,
                    TH_SERVICE_CODE
               FROM TXN_HEADER
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE = (SELECT SP_VAL
                                         FROM SYSTEM_PARAMETER
                                        WHERE SP_CODE = 'DEBIT_ADJ_FOR_SETTLE')
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            TXN_PSP_DETAIL,
            PSP_DETAIL,
            (SELECT *
               FROM CRR_PSP_PRODUCT_CODE_MAP
              WHERE PM_DISABLED = 0),
            (SELECT CR_COUNTRY_ID,
                    CR_PRODUCT_CODE,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    CR_CURRENCY_ID,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
               FROM CRR_RULE_POSTING
              WHERE     CR_PARTY_TYPE = 'P'
                    AND CR_JNL_ENTRY_TYPE_ID = 'D_ADJ_DR_PSP_COST'
                    AND CR_TXN_CODE = 'ASC'
                    AND CR_DISABLED = 0)
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TP_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND TP_PSP_ID = CR_PARTY_ID
            AND TP_PSP_ID = PSP_ID
            AND PM_PSP_ID = PSP_ID
            AND PM_BUSINESS_TYPE = PSP_TYPE
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   GROUP BY TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TP_PSP_ID,
            TD_TXN_CCY,
            CR_JNL_TYPE_ID,
            CR_JNL_ENTRY_TYPE_ID,
            CR_CREDIT_GL_ID,
            CR_DEBIT_GL_ID;


