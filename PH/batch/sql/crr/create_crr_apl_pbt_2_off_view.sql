
DROP VIEW CRR_APL_PBT_2_OFF_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_APL_PBT_2_OFF_VIEW
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
          TP_PSP_ID,
          TP_TXN_CCY,
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
          TP_TXN_AMOUNT CR_AMOUNT
     FROM (SELECT *
             FROM TXN_HEADER
            WHERE     TH_TXN_CODE = 'PTO' 
                  AND TH_STATUS IN ('C', 'R')
                  AND TH_AR_IND = 'A'
                  AND TH_APPROVAL_DATE IS NOT NULL),
          TXN_DETAIL,
          TXN_PSP_DETAIL,
          PSP_DETAIL,
          (SELECT *
             FROM CRR_PSP_PRODUCT_CODE_MAP
            WHERE PM_DISABLED = 0),
          (SELECT *
             FROM CRR_RULE_POSTING
            WHERE     CR_DISABLED = 0
                  AND CR_TXN_CODE = 'PTO'
                  AND CR_PARTY_TYPE = 'P'
                  AND CR_JNL_ENTRY_TYPE_ID = 'TXN_AMT')
    WHERE     TH_TXN_ID = TD_TXN_ID
          AND TH_TXN_ID = TP_TXN_ID
          AND TP_PSP_ID = CR_PARTY_ID
          AND TD_TXN_COUNTRY = CR_COUNTRY_ID
          AND TP_PSP_ID = PSP_ID
          AND PM_PSP_ID = PSP_ID
          AND PM_BUSINESS_TYPE = PSP_TYPE
          AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   UNION ALL
   SELECT TH_TXN_ID,
          TH_APPROVAL_DATE,
          CR_COUNTRY_ID,
          CR_PRODUCT_CODE,
          CR_PARTY_TYPE,
          '' PARTY_ID,
          TP_TXN_CCY,
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
          TP_TXN_AMOUNT CR_AMOUNT
     FROM (SELECT *
             FROM TXN_HEADER
            WHERE     TH_TXN_CODE = 'PTO' 
                  AND TH_STATUS IN ('C', 'R')
                  AND TH_AR_IND = 'A'
                  AND TH_APPROVAL_DATE IS NOT NULL),
          TXN_DETAIL,
          TXN_PSP_DETAIL,
          PSP_DETAIL,
          (SELECT *
             FROM CRR_PSP_PRODUCT_CODE_MAP
            WHERE PM_DISABLED = 0),
          (SELECT *
             FROM CRR_RULE_POSTING
            WHERE     CR_DISABLED = 0
                  AND CR_TXN_CODE = 'PTO'
                  AND CR_PARTY_TYPE = 'G'
                  AND CR_JNL_ENTRY_TYPE_ID = 'PSP_TEMP')
    WHERE     TH_TXN_ID = TD_TXN_ID
          AND TH_TXN_ID = TP_TXN_ID
          AND TD_TXN_COUNTRY = CR_COUNTRY_ID
          AND TP_PSP_ID = PSP_ID
          AND PM_PSP_ID = PSP_ID
          AND PM_BUSINESS_TYPE = PSP_TYPE
          AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   UNION ALL
     SELECT TH_TXN_ID,
            TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            TP_PSP_ID,
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
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('PTO')
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            TXN_PSP_DETAIL,
            PSP_DETAIL,
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_AMOUNT,
                    TE_PARTY_TYPE
               FROM TXN_ELEMENTS TE
              WHERE TE_TXN_ELEMENT_TYPE = 'TFEE' AND TE_PARTY_TYPE = 'P'),
            (SELECT *
               FROM CRR_PSP_PRODUCT_CODE_MAP
              WHERE PM_DISABLED = 0),
            (SELECT *
               FROM CRR_RULE_POSTING
              WHERE     CR_PARTY_TYPE = 'P'
                    AND CR_JNL_ENTRY_TYPE_ID = 'D_PSP_COST'
                    AND CR_TXN_CODE = 'PTO'
                    AND CR_DISABLED = 0)
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TE_TXN_ID
            AND TH_TXN_ID = TP_TXN_ID
            AND TP_PSP_ID = CR_PARTY_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND TP_PSP_ID = PSP_ID
            AND PM_PSP_ID = PSP_ID
            AND PM_BUSINESS_TYPE = PSP_TYPE
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE
   UNION ALL
     SELECT TH_TXN_ID,
            TH_APPROVAL_DATE,
            CR_COUNTRY_ID,
            CR_PRODUCT_CODE,
            CR_PARTY_TYPE,
            '',
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
              WHERE     TH_STATUS IN ('C', 'R')
                    AND TH_AR_IND = 'A'
                    AND TH_TXN_CODE IN ('PTO')
                    AND TH_APPROVAL_DATE IS NOT NULL),
            TXN_DETAIL,
            TXN_PSP_DETAIL,
            PSP_DETAIL,
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_AMOUNT,
                    TE_PARTY_TYPE
               FROM TXN_ELEMENTS TE
              WHERE TE_TXN_ELEMENT_TYPE = 'TFEE' AND TE_PARTY_TYPE = 'P'),
            (SELECT *
               FROM CRR_PSP_PRODUCT_CODE_MAP
              WHERE PM_DISABLED = 0),
            (SELECT *
               FROM CRR_RULE_POSTING
              WHERE     CR_PARTY_TYPE = 'G'
                    AND CR_JNL_ENTRY_TYPE_ID = 'PSP_COST'
                    AND CR_TXN_CODE = 'PTO'
                    AND CR_DISABLED = 0)
      WHERE     TH_TXN_ID = TD_TXN_ID
            AND TH_TXN_ID = TE_TXN_ID
            AND TH_TXN_ID = TP_TXN_ID
            AND TD_TXN_COUNTRY = CR_COUNTRY_ID
            AND TP_PSP_ID = PSP_ID
            AND PM_PSP_ID = PSP_ID
            AND PM_BUSINESS_TYPE = PSP_TYPE
            AND PM_PRODUCT_CODE = CR_PRODUCT_CODE;

