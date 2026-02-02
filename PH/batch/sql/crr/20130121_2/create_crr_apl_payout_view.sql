DROP VIEW CRR_APL_PAYOUT_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_APL_PAYOUT_VIEW
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
     SELECT TH.TH_APPROVAL_DATE CR_TXN_DATE,
            TD.TD_TXN_COUNTRY CR_COUNTRY,
            CRP.CR_PRODUCT_CODE CR_PRODUCT,
            TE.TE_PARTY_TYPE,
            TH.TH_MERCHANT_ID PARTY_ID,
            TE.TE_CCY CR_CURRENCY,
            CRP.CR_JNL_TYPE_ID,
            CRP.CR_JNL_ENTRY_TYPE_ID,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN 'C'
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
               ELSE ''
            END
               CR_IND,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN CRP.CR_CREDIT_GL_ID
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN CRP.CR_DEBIT_GL_ID
               ELSE 0
            END
               CR_GL_ID,
            COUNT (DISTINCT TH_TXN_ID) TXN_COUNT,
            SUM (TE_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID,
                    TH_APPROVAL_DATE,
                    TH_MERCHANT_ID
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS IN ('C', 'R')
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE IN ('POA')
                    AND TH.TH_APPROVAL_DATE IS NOT NULL) TH
            INNER JOIN TXN_DETAIL TD ON TD.TD_TXN_ID = TH.TH_TXN_ID
            INNER JOIN
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_AMOUNT,
                    TE_PARTY_TYPE
               FROM TXN_ELEMENTS TE
              WHERE     TE.TE_PARTY_TYPE = 'M'
                    AND TE.TE_TXN_ELEMENT_TYPE IN ('TAMT', 'TFEE')) TE
               ON TE.TE_TXN_ID = TH.TH_TXN_ID
            INNER JOIN (
                      SELECT *
                      FROM MERCH_DETAIL MT
                      INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
                      INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE
                       ) PC
                ON PC.MERCHANT_ID = TH.TH_MERCHANT_ID
            INNER JOIN
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
              WHERE     CRP.CR_PARTY_TYPE = 'M'
                    AND CRP.CR_TXN_CODE = 'POA'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'TXN_AMT'
                    AND CRP.CR_DISABLED = 0) CRP
               ON     TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
                  AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
                  AND TE.TE_PARTY_TYPE = CRP.CR_PARTY_TYPE
                  AND TH.TH_MERCHANT_ID = CRP.CR_PARTY_ID
                  AND TE.TE_CCY = CRP.CR_CURRENCY_ID
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
            TE.TE_PARTY_TYPE,
            TH.TH_MERCHANT_ID,
            TE_CCY,
            CRP.CR_JNL_TYPE_ID,
            CRP.CR_JNL_ENTRY_TYPE_ID,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN 'C'
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
               ELSE ''
            END,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN CRP.CR_CREDIT_GL_ID
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN CRP.CR_DEBIT_GL_ID
               ELSE 0
            END
   UNION ALL
     SELECT TH.TH_APPROVAL_DATE CR_TXN_DATE,
            TD.TD_TXN_COUNTRY CR_COUNTRY,
            CRP.CR_PRODUCT_CODE CR_PRODUCT,
            CRP.CR_PARTY_TYPE,
            '' PARTY_ID,
            TE.TE_CCY CR_CURRENCY,
            CRP.CR_JNL_TYPE_ID,
            CRP.CR_JNL_ENTRY_TYPE_ID,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN 'C'
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
               ELSE ''
            END
               CR_IND,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN CRP.CR_CREDIT_GL_ID
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN CRP.CR_DEBIT_GL_ID
               ELSE 0
            END
               CR_GL_ID,
            COUNT (DISTINCT TH_TXN_ID) TXN_COUNT,
            SUM (TE_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID,
                    TH_APPROVAL_DATE,
                    TH_MERCHANT_ID
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS IN ('C', 'R')
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE IN ('POA')
                    AND TH.TH_APPROVAL_DATE IS NOT NULL) TH
            INNER JOIN TXN_DETAIL TD ON TD.TD_TXN_ID = TH.TH_TXN_ID
            INNER JOIN
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_AMOUNT,
                    TE_PARTY_TYPE
               FROM TXN_ELEMENTS TE
              WHERE TE.TE_PARTY_TYPE = 'M' AND TE.TE_TXN_ELEMENT_TYPE = 'TFEE') TE
               ON TE.TE_TXN_ID = TH.TH_TXN_ID
            INNER JOIN (
                      SELECT *
                      FROM MERCH_DETAIL MT
                      INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
                      INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE
                       ) PC
                ON PC.MERCHANT_ID = TH.TH_MERCHANT_ID
            INNER JOIN
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
              WHERE     CRP.CR_PARTY_TYPE = 'G'
                    AND CRP.CR_TXN_CODE = 'POA'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'M_FEE'
                    AND CRP.CR_DISABLED = 0) CRP
               ON     TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
                  AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
            CRP.CR_PARTY_TYPE,
            TE_CCY,
            CRP.CR_JNL_TYPE_ID,
            CRP.CR_JNL_ENTRY_TYPE_ID,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN 'C'
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
               ELSE ''
            END,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN CRP.CR_CREDIT_GL_ID
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN CRP.CR_DEBIT_GL_ID
               ELSE 0
            END
   UNION ALL
     SELECT TH.TH_APPROVAL_DATE CR_TXN_DATE,
            TD.TD_TXN_COUNTRY CR_COUNTRY,
            CRP.CR_PRODUCT_CODE CR_PRODUCT,
            CRP.CR_PARTY_TYPE,
            '' PARTY_ID,
            TE.TE_CCY CR_CURRENCY,
            CRP.CR_JNL_TYPE_ID,
            CRP.CR_JNL_ENTRY_TYPE_ID,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN 'C'
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
               ELSE ''
            END
               CR_IND,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN CRP.CR_CREDIT_GL_ID
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN CRP.CR_DEBIT_GL_ID
               ELSE 0
            END
               CR_GL_ID,
            COUNT (DISTINCT TH_TXN_ID) TXN_COUNT,
            SUM (TE_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID,
                    TH_APPROVAL_DATE,
                    TH_MERCHANT_ID,
                    TH.TH_NET_CCY
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS IN ('C', 'R')
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE IN ('POA')
                    AND TH.TH_APPROVAL_DATE IS NOT NULL) TH
            INNER JOIN TXN_DETAIL TD ON TD.TD_TXN_ID = TH.TH_TXN_ID
            INNER JOIN
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_AMOUNT,
                    TE_PARTY_TYPE
               FROM TXN_ELEMENTS TE
              WHERE TE.TE_PARTY_TYPE = 'R' AND TE.TE_TXN_ELEMENT_TYPE = 'MAMT') TE
               ON TE.TE_TXN_ID = TH.TH_TXN_ID
            INNER JOIN (
                      SELECT *
                      FROM MERCH_DETAIL MT
                      INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
                      INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE
                       ) PC
                ON PC.MERCHANT_ID = TH.TH_MERCHANT_ID
            INNER JOIN
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
              WHERE     CRP.CR_PARTY_TYPE = 'G'
                    AND CRP.CR_TXN_CODE = 'POA'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'M_FXMU_FEE'
                    AND CRP.CR_DISABLED = 0) CRP
               ON     TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
                  AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
            CRP.CR_PARTY_TYPE,
            TE_CCY,
            CRP.CR_JNL_TYPE_ID,
            CRP.CR_JNL_ENTRY_TYPE_ID,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN 'C'
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
               ELSE ''
            END,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN CRP.CR_CREDIT_GL_ID
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN CRP.CR_DEBIT_GL_ID
               ELSE 0
            END
   UNION ALL
     SELECT TH.TH_APPROVAL_DATE CR_TXN_DATE,
            TD.TD_TXN_COUNTRY CR_COUNTRY,
            CRP.CR_PRODUCT_CODE CR_PRODUCT,
            CRP.CR_PARTY_TYPE,
            '' PARTY_ID,
            TE.TE_CCY CR_CURRENCY,
            CRP.CR_JNL_TYPE_ID,
            CRP.CR_JNL_ENTRY_TYPE_ID,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN 'C'
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
               ELSE ''
            END
               CR_IND,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN CRP.CR_CREDIT_GL_ID
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN CRP.CR_DEBIT_GL_ID
               ELSE 0
            END
               CR_GL_ID,
            COUNT (DISTINCT TH_TXN_ID) TXN_COUNT,
            SUM (TE_AMOUNT) CR_AMOUNT
       FROM (SELECT TH_TXN_ID,
                    TH_APPROVAL_DATE,
                    TH_MERCHANT_ID
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS IN ('C', 'R')
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE IN ('POA')
                    AND TH.TH_APPROVAL_DATE IS NOT NULL) TH
            INNER JOIN TXN_DETAIL TD ON TD.TD_TXN_ID = TH.TH_TXN_ID
            INNER JOIN
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_AMOUNT,
                    TE_PARTY_TYPE
               FROM TXN_ELEMENTS TE
              WHERE TE.TE_PARTY_TYPE = 'M' AND TE.TE_TXN_ELEMENT_TYPE = 'TAMT') TE
               ON TE.TE_TXN_ID = TH.TH_TXN_ID
            INNER JOIN (
                      SELECT *
                      FROM MERCH_DETAIL MT
                      INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
                      INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE
                    ) PC
                ON PC.MERCHANT_ID = TH.TH_MERCHANT_ID
            INNER JOIN
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
              WHERE     CRP.CR_PARTY_TYPE = 'G'
                    AND CRP.CR_TXN_CODE = 'POA'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'NET_AMT'
                    AND CRP.CR_DISABLED = 0) CRP
               ON     TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
                  AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
            CRP.CR_PARTY_TYPE,
            TE_CCY,
            CRP.CR_JNL_TYPE_ID,
            CRP.CR_JNL_ENTRY_TYPE_ID,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN 'C'
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN 'D'
               ELSE ''
            END,
            CASE
               WHEN CRP.CR_CREDIT_GL_ID <> 0 THEN CRP.CR_CREDIT_GL_ID
               WHEN CRP.CR_DEBIT_GL_ID IS NOT NULL THEN CRP.CR_DEBIT_GL_ID
               ELSE 0
            END;

