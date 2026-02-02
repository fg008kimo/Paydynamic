DROP VIEW CRR_VOD_SETTLE_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_VOD_SETTLE_VIEW
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
   CR_AMOUNT
)
AS
   SELECT TH.TH_ORG_TXN_ID AS TH_TXN_ID,
          TH.TH_APPROVAL_DATE CR_TXN_DATE,
          TD.TD_TXN_COUNTRY CR_COUNTRY,
          SM.SM_PRODUCT_CODE CR_PRODUCT,
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
          TE_AMOUNT CR_AMOUNT
     FROM (SELECT TH.TH_TXN_ID,
                  TH_ORG_TXN_ID,
                  TH.Th_Txn_Code,
                  TH.TH_SERVICE_CODE,
                  TH.Th_Merchant_Id,
                  TH.TH_APPROVAL_DATE
             FROM TXN_HEADER TH
            WHERE     TH.TH_TXN_CODE = 'VST'
                  AND TH.TH_STATUS = 'C'
                  AND TH.TH_AR_IND = 'A') TH,
          TXN_DETAIL TD,
          (SELECT TE_TXN_ID,
                  TE_CCY,
                  TE_PARTY_TYPE,
                  TE_AMOUNT,
                  TE_TXN_ELEMENT_TYPE,
                  TE_AMT_TYPE
             FROM TXN_ELEMENTS TE
            WHERE TE.TE_PARTY_TYPE = 'M' AND TE.TE_TXN_ELEMENT_TYPE = 'TAMT') TE,
          (SELECT SD_TXN_ID
             FROM MERCHANT_SETTLEMENT_DETAIL SD
            WHERE SD.SD_STATUS = 'C') SD,
          (SELECT *
             FROM CRR_RULE_POSTING CRP
            WHERE     CRP.CR_DISABLED = 0
                  AND CRP.CR_TXN_CODE = 'VST'
                  AND CRP.CR_PARTY_TYPE = 'M'
                  AND CRP.CR_JNL_ENTRY_TYPE_ID = 'TXN_AMT') CRP,
          (SELECT SM_CODE, SM_PRODUCT_CODE
             FROM SERVICE_MAPPING SM
            WHERE SM.SM_DISABLED = 0) SM
    WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
          AND TE.TE_TXN_ID = TH.TH_TXN_ID
          AND SD.SD_TXN_ID = TH.TH_ORG_TXN_ID
          AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
          AND SM.SM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
          AND TH.TH_TXN_CODE = CRP.CR_TXN_CODE
          AND TE.TE_PARTY_TYPE = CRP.CR_PARTY_TYPE
          AND TH.TH_MERCHANT_ID = CRP.CR_PARTY_ID
          AND SM.SM_CODE = TH.TH_SERVICE_CODE
          AND TE.TE_CCY = CRP.CR_CURRENCY_ID
   UNION ALL
   SELECT TH.TH_ORG_TXN_ID,
          TH.TH_APPROVAL_DATE CR_TXN_DATE,
          TD.TD_TXN_COUNTRY CR_COUNTRY,
          SM.SM_PRODUCT_CODE CR_PRODUCT,
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
          TE_AMOUNT CR_AMOUNT
     FROM (SELECT TH.TH_TXN_ID,
                  TH_ORG_TXN_ID,
                  TH.Th_Txn_Code,
                  TH.TH_SERVICE_CODE,
                  TH.Th_Merchant_Id,
                  TH.TH_APPROVAL_DATE
             FROM TXN_HEADER TH
            WHERE     TH.TH_TXN_CODE = 'VST'
                  AND TH.TH_STATUS = 'C'
                  AND TH.TH_AR_IND = 'A') TH,
          TXN_DETAIL TD,
          (SELECT TE_TXN_ID,
                  TE_CCY,
                  TE_PARTY_TYPE,
                  TE_AMOUNT,
                  TE_TXN_ELEMENT_TYPE,
                  TE_AMT_TYPE
             FROM TXN_ELEMENTS TE
            WHERE     TE.TE_PARTY_TYPE = 'M'
                  AND TE.TE_TXN_ELEMENT_TYPE IN ('MAMT', 'TFEE')) TE,
          (SELECT SD_TXN_ID
             FROM MERCHANT_SETTLEMENT_DETAIL SD
            WHERE SD.SD_STATUS = 'C') SD,
          (SELECT *
             FROM CRR_RULE_POSTING CRP
            WHERE     CRP.CR_DISABLED = 0
                  AND CRP.CR_TXN_CODE = 'VST'
                  AND CRP.CR_PARTY_TYPE = 'G'
                  AND CRP.CR_JNL_ENTRY_TYPE_ID = 'M_FEE') CRP,
          (SELECT SM_CODE, SM_PRODUCT_CODE
             FROM SERVICE_MAPPING SM
            WHERE SM.SM_DISABLED = 0) SM
    WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
          AND TE.TE_TXN_ID = TH.TH_TXN_ID
          AND SD.SD_TXN_ID = TH.TH_ORG_TXN_ID
          AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
          AND SM.SM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
          AND TH.TH_TXN_CODE = CRP.CR_TXN_CODE
          AND SM.SM_CODE = TH.TH_SERVICE_CODE
   UNION ALL
     SELECT TH.TH_ORG_TXN_ID,
            TH.TH_APPROVAL_DATE CR_TXN_DATE,
            TD.TD_TXN_COUNTRY CR_COUNTRY,
            SM.SM_PRODUCT_CODE CR_PRODUCT,
            'G' TE_PARTY_TYPE,
            '' PARTY_ID,
            TE.TE_AMT_TYPE,
            TE.TE_CCY CR_CURRENCY,
            'DELI_AMT' TE_TXN_ELEMENT_TYPE,
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
            SUM (
               CASE
                  WHEN TE_TXN_ELEMENT_TYPE = 'TAMT'
                  THEN
                     TE_AMOUNT
                  WHEN TE_TXN_ELEMENT_TYPE IN ('TFEE', 'MAMT')
                  THEN
                     -1 * TE_AMOUNT
                  ELSE
                     0
               END)
               CR_AMOUNT
       FROM (SELECT TH.TH_TXN_ID,
                    TH_ORG_TXN_ID,
                    TH.Th_Txn_Code,
                    TH.TH_SERVICE_CODE,
                    TH.Th_Merchant_Id,
                    TH.TH_APPROVAL_DATE
               FROM TXN_HEADER TH
              WHERE     TH.TH_TXN_CODE = 'VST'
                    AND TH.TH_STATUS = 'C'
                    AND TH.TH_AR_IND = 'A') TH,
            TXN_DETAIL TD,
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_PARTY_TYPE,
                    TE_AMOUNT,
                    TE_TXN_ELEMENT_TYPE,
                    TE_AMT_TYPE
               FROM TXN_ELEMENTS TE
              WHERE     TE.TE_PARTY_TYPE = 'M'
                    AND TE.TE_TXN_ELEMENT_TYPE IN ('TAMT', 'MAMT', 'TFEE')) TE,
            (SELECT SD_TXN_ID
               FROM MERCHANT_SETTLEMENT_DETAIL SD
              WHERE SD.SD_STATUS = 'C') SD,
            (SELECT *
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_DISABLED = 0
                    AND CRP.CR_TXN_CODE = 'VST'
                    AND CRP.CR_PARTY_TYPE = 'G'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'DELI_AMT') CRP,
            (SELECT SM_CODE, SM_PRODUCT_CODE
               FROM SERVICE_MAPPING SM
              WHERE SM.SM_DISABLED = 0) SM
      WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
            AND TE.TE_TXN_ID = TH.TH_TXN_ID
            AND SD.SD_TXN_ID = TH.TH_ORG_TXN_ID
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND SM.SM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
            AND TH.TH_TXN_CODE = CRP.CR_TXN_CODE
            AND SM.SM_CODE = TH.TH_SERVICE_CODE
   GROUP BY TH.TH_ORG_TXN_ID,
            TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            SM.SM_PRODUCT_CODE,
            TE.TE_AMT_TYPE,
            TE.TE_CCY,
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

