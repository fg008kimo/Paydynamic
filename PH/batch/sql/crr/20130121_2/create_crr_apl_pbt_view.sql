DROP VIEW CRR_APL_PBT_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_APL_PBT_VIEW
(
   TH_TXN_ID,
   CR_TXN_DATE,
   CR_COUNTRY,
   CR_PRODUCT,
   TE_PARTY_TYPE,
   PARTY_ID,
   TE_AMT_TYPE,
   CR_CURRENCY,
   TE_TXN_ELEMENT_TYPE,
   CR_JNL_TYPE_ID,
   CR_JNL_ENTRY_TYPE_ID,
   CR_IND,
   CR_GL_ID,
   TXN_COUNT,
   CR_AMOUNT,
   CR_REMARKS
)
AS
   SELECT TH.TH_TXN_ID,
          TH.TH_APPROVAL_DATE CR_TXN_DATE,
          TD.TD_TXN_COUNTRY CR_COUNTRY,
          CRP.CR_PRODUCT_CODE CR_PRODUCT,
          TE.TE_PARTY_TYPE,
          DECODE (TE.TE_PARTY_TYPE, 'M', TH.TH_MERCHANT_ID, '') PARTY_ID,
          TE.TE_AMT_TYPE,
          TE.TE_CCY CR_CURRENCY,
          TE.TE_TXN_ELEMENT_TYPE,
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
          1 TXN_COUNT,
          TE_AMOUNT CR_AMOUNT,
          TH.TH_TXN_ID CR_REMARKS
     FROM (SELECT *
             FROM TXN_HEADER TH
            WHERE     TH.TH_TXN_CODE IN ('RTF', 'TFF')
                  AND TH.TH_STATUS = 'C'
                  AND TH.TH_AR_IND = 'A'
                  AND TH.TH_APPROVAL_DATE IS NOT NULL) TH,
          TXN_DETAIL TD,
          (SELECT *
             FROM TXN_ELEMENTS TE
            WHERE     TE.TE_AMT_TYPE IS NOT NULL
                  AND TE.TE_PARTY_TYPE = 'M'
                  AND TE.TE_TXN_ELEMENT_TYPE IN
                         ('TAMT', 'MFIN', 'MFLT', 'MPOR')) TE,
          (SELECT *
             FROM CRR_RULE_POSTING CRP
            WHERE     CRP.CR_DISABLED = 0
                  AND CRP.CR_TXN_CODE = 'TFR'
                  AND CRP.CR_PARTY_TYPE = 'M'
                  AND CRP.CR_JNL_ENTRY_TYPE_ID = 'TXN_AMT') CRP,
          (SELECT *
             FROM MERCH_DETAIL MT
             INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
             INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE) PC
    WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
          AND TE.TE_TXN_ID = TH.TH_TXN_ID
          AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
          AND TE.TE_PARTY_TYPE = CRP.CR_PARTY_TYPE
          AND TH.TH_MERCHANT_ID = CRP.CR_PARTY_ID
          AND TE.TE_CCY = CRP.CR_CURRENCY_ID
          AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
          AND PC.MERCHANT_ID = TH.TH_MERCHANT_ID
   UNION ALL
   SELECT TH.TH_TXN_ID,
          TH.TH_APPROVAL_DATE CR_TXN_DATE,
          TD.TD_TXN_COUNTRY CR_COUNTRY,
          CRP.CR_PRODUCT_CODE CR_PRODUCT,
          TE.TE_PARTY_TYPE,
          DECODE (TE.TE_PARTY_TYPE, 'M', TH.TH_MERCHANT_ID, '') PARTY_ID,
          TE.TE_AMT_TYPE,
          TE.TE_CCY CR_CURRENCY,
          TE.TE_TXN_ELEMENT_TYPE,
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
          1 TXN_COUNT,
          TE_AMOUNT CR_AMOUNT,
          TH.TH_TXN_ID CR_REMARKS
     FROM (SELECT *
             FROM TXN_HEADER TH
            WHERE     TH.TH_TXN_CODE IN ('RTF', 'TFF')
                  AND TH.TH_STATUS = 'C'
                  AND TH.TH_AR_IND = 'A'
                  AND TH.TH_APPROVAL_DATE IS NOT NULL) TH,
          TXN_DETAIL TD,
          (SELECT *
             FROM TXN_ELEMENTS TE
            WHERE     TE.TE_AMT_TYPE IS NOT NULL
                  AND TE.TE_PARTY_TYPE = 'M'
                  AND TE.TE_TXN_ELEMENT_TYPE = 'TFEE') TE,
          (SELECT *
             FROM CRR_RULE_POSTING CRP
            WHERE     CRP.CR_DISABLED = 0
                  AND CRP.CR_TXN_CODE = 'TFR'
                  AND CRP.CR_PARTY_TYPE = 'G'
                  AND CRP.CR_JNL_ENTRY_TYPE_ID = 'S_M_FEE') CRP,
          (SELECT *
             FROM MERCH_DETAIL MT
             INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
             INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE) PC
    WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
          AND TE.TE_TXN_ID = TH.TH_TXN_ID
          AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
          AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
          AND PC.MERCHANT_ID = TH.TH_MERCHANT_ID
   UNION ALL
   SELECT TH.TH_ORG_TXN_ID TH_TXN_ID,
          TH.TH_APPROVAL_DATE CR_TXN_DATE,
          TD.TD_TXN_COUNTRY CR_COUNTRY,
          CRP.CR_PRODUCT_CODE CR_PRODUCT,
          TE.TE_PARTY_TYPE,
          DECODE (TE.TE_PARTY_TYPE, 'M', TH.TH_MERCHANT_ID, '') PARTY_ID,
          TE.TE_AMT_TYPE,
          TE.TE_CCY CR_CURRENCY,
          TE.TE_TXN_ELEMENT_TYPE,
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
          1 TXN_COUNT,
          TE_AMOUNT CR_AMOUNT,
          TH.TH_TXN_ID CR_REMARKS
     FROM (SELECT *
             FROM TXN_HEADER TH
            WHERE     TH.TH_TXN_CODE IN ('RTT', 'TFT')
                  AND TH.TH_STATUS = 'C'
                  AND TH.TH_AR_IND = 'A'
                  AND TH.TH_APPROVAL_DATE IS NOT NULL) TH,
          TXN_DETAIL TD,
          (SELECT *
             FROM TXN_ELEMENTS TE
            WHERE     TE.TE_AMT_TYPE IS NOT NULL
                  AND TE.TE_PARTY_TYPE = 'M'
                  AND TE.TE_TXN_ELEMENT_TYPE IN
                         ('TAMT', 'MFIN', 'MFLT', 'MPOR')) TE,
          (SELECT *
             FROM CRR_RULE_POSTING CRP
            WHERE     CRP.CR_DISABLED = 0
                  AND CRP.CR_TXN_CODE = 'TFR'
                  AND CRP.CR_PARTY_TYPE = 'M'
                  AND CRP.CR_JNL_ENTRY_TYPE_ID = 'NET_AMT') CRP,
          (SELECT *
             FROM MERCH_DETAIL MT
             INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
             INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE) PC
    WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
          AND TE.TE_TXN_ID = TH.TH_TXN_ID
          AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
          AND TE.TE_PARTY_TYPE = CRP.CR_PARTY_TYPE
          AND TH.TH_MERCHANT_ID = CRP.CR_PARTY_ID
          AND TE.TE_CCY = CRP.CR_CURRENCY_ID
          AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
          AND PC.MERCHANT_ID = TH.TH_MERCHANT_ID
   UNION ALL
   SELECT TH.TH_TXN_ID,
          TH.TH_APPROVAL_DATE CR_TXN_DATE,
          TD.TD_TXN_COUNTRY CR_COUNTRY,
          CRP.CR_PRODUCT_CODE CR_PRODUCT,
          TE.TE_PARTY_TYPE,
          DECODE (TE.TE_PARTY_TYPE, 'M', TH.TH_MERCHANT_ID, '') PARTY_ID,
          TE.TE_AMT_TYPE,
          TE.TE_CCY CR_CURRENCY,
          TE.TE_TXN_ELEMENT_TYPE,
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
          1 TXN_COUNT,
          TE_AMOUNT CR_AMOUNT,
          TH.TH_TXN_ID CR_REMARKS
     FROM (SELECT *
             FROM TXN_HEADER TH
            WHERE     TH.TH_TXN_CODE IN ('RTT', 'TFT')
                  AND TH.TH_STATUS = 'C'
                  AND TH.TH_AR_IND = 'A'
                  AND TH.TH_APPROVAL_DATE IS NOT NULL) TH,
          TXN_DETAIL TD,
          (SELECT *
             FROM TXN_ELEMENTS TE
            WHERE     TE.TE_AMT_TYPE IS NOT NULL
                  AND TE.TE_PARTY_TYPE = 'M'
                  AND TE.TE_TXN_ELEMENT_TYPE = 'TFEE') TE,
          (SELECT *
             FROM CRR_RULE_POSTING CRP
            WHERE     CRP.CR_DISABLED = 0
                  AND CRP.CR_TXN_CODE = 'TFR'
                  AND CRP.CR_PARTY_TYPE = 'G'
                  AND CRP.CR_JNL_ENTRY_TYPE_ID = 'D_M_FEE') CRP,
          (SELECT *
             FROM MERCH_DETAIL MT
             INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
             INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE) PC
    WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
          AND TE.TE_TXN_ID = TH.TH_TXN_ID
          AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
          AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
          AND PC.MERCHANT_ID = TH.TH_MERCHANT_ID
   UNION ALL
   SELECT TH.TH_TXN_ID,
          TH.TH_APPROVAL_DATE CR_TXN_DATE,
          TD.TD_TXN_COUNTRY CR_COUNTRY,
          CRP.CR_PRODUCT_CODE CR_PRODUCT,
          TE.TE_PARTY_TYPE,
          DECODE (TE.TE_PARTY_TYPE, 'M', TH.TH_MERCHANT_ID, '') PARTY_ID,
          TE.TE_AMT_TYPE,
          TE.TE_CCY CR_CURRENCY,
          TE.TE_TXN_ELEMENT_TYPE,
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
          1 TXN_COUNT,
          TE_AMOUNT CR_AMOUNT,
          TH.TH_TXN_ID CR_REMARKS
     FROM (SELECT *
             FROM TXN_HEADER TH
            WHERE     TH.TH_TXN_CODE IN ('RTT', 'TFT')
                  AND TH.TH_STATUS = 'C'
                  AND TH.TH_AR_IND = 'A'
                  AND TH.TH_APPROVAL_DATE IS NOT NULL) TH,
          TXN_DETAIL TD,
          (SELECT *
             FROM TXN_ELEMENTS TE
            WHERE     TE.TE_AMT_TYPE IS NOT NULL
                  AND TE.TE_PARTY_TYPE = 'M'
                  AND TE.TE_TXN_ELEMENT_TYPE = 'MAMT') TE,
          (SELECT *
             FROM CRR_RULE_POSTING CRP
            WHERE     CRP.CR_DISABLED = 0
                  AND CRP.CR_TXN_CODE = 'TFR'
                  AND CRP.CR_PARTY_TYPE = 'G'
                  AND CRP.CR_JNL_ENTRY_TYPE_ID = 'D_M_FXMU_FEE') CRP,
          (SELECT *
             FROM MERCH_DETAIL MT
             INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
             INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE) PC
    WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
          AND TE.TE_TXN_ID = TH.TH_TXN_ID
          AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
          AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
          AND PC.MERCHANT_ID = TH.TH_MERCHANT_ID

