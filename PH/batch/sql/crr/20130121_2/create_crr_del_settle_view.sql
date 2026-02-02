DROP VIEW CRR_DEL_SETTLE_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_DEL_SETTLE_VIEW
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
          TE_AMOUNT CR_AMOUNT
     FROM (SELECT TH.TH_TXN_ID,
                  TH.Th_Txn_Code,
                  TH.Th_Merchant_Id,
                  TH.TH_APPROVAL_DATE
             FROM TXN_HEADER TH
            WHERE TH.TH_TXN_CODE = 'STR' AND TH.TH_AR_IND = 'A') TH,
          Txn_Detail Td,
          (SELECT TE_TXN_ID,
                  TE_CCY,
                  TE_PARTY_TYPE,
                  TE_AMOUNT,
                  TE_TXN_ELEMENT_TYPE,
                  TE_AMT_TYPE
             FROM Txn_Elements Te
            WHERE TE.TE_PARTY_TYPE = 'M' AND TE.TE_TXN_ELEMENT_TYPE = 'TAMT') TE,
          (SELECT SD_TXN_ID
             FROM Merchant_Settlement_Detail Sd
            WHERE Sd.Sd_Status = 'C') Sd,
          (SELECT *
             FROM Crr_Rule_Posting Crp
            WHERE     Crp.Cr_Txn_Code = 'STR'
                  AND CRP.CR_PARTY_TYPE = 'M'
                  AND CRP.CR_JNL_ENTRY_TYPE_ID = 'TXN_AMT'
                  AND CRP.CR_DISABLED = 0) CRP,
          (SELECT *
             FROM MERCH_DETAIL MT
             INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
             INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE) PC
    WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
          AND TE.TE_TXN_ID = TH.TH_TXN_ID
          AND SD.SD_TXN_ID = TH.TH_TXN_ID
          AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
          AND Th.Th_Txn_Code = Crp.Cr_Txn_Code
          AND TE.TE_PARTY_TYPE = CRP.CR_PARTY_TYPE
          AND Th.Th_Merchant_Id = Crp.Cr_Party_Id
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
          TE_AMOUNT CR_AMOUNT
     FROM (SELECT TH.TH_TXN_ID,
                  TH.Th_Txn_Code,
                  TH.Th_Merchant_Id,
                  TH.TH_APPROVAL_DATE
             FROM TXN_HEADER TH
            WHERE TH.TH_TXN_CODE = 'STR' AND TH.TH_AR_IND = 'A') TH,
          Txn_Detail Td,
          (SELECT TE_TXN_ID,
                  TE_CCY,
                  TE_PARTY_TYPE,
                  TE_AMOUNT,
                  TE_TXN_ELEMENT_TYPE,
                  TE_AMT_TYPE
             FROM Txn_Elements Te
            WHERE TE.TE_PARTY_TYPE = 'M' AND TE.TE_TXN_ELEMENT_TYPE = 'TFEE') TE,
          (SELECT SD_TXN_ID
             FROM MERCHANT_SETTLEMENT_DETAIL SD
            WHERE SD.SD_STATUS = 'C') SD,
          (SELECT *
             FROM Crr_Rule_Posting Crp
            WHERE     Crp.Cr_Txn_Code = 'STR'
                  AND CRP.CR_PARTY_TYPE = 'G'
                  AND CRP.CR_JNL_ENTRY_TYPE_ID = 'M_FEE'
                  AND CRP.CR_DISABLED = 0) CRP,
          (SELECT *
             FROM MERCH_DETAIL MT
             INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
             INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE) PC
    WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
          AND TE.TE_TXN_ID = TH.TH_TXN_ID
          AND SD.SD_TXN_ID = TH.TH_TXN_ID
          AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
          AND Th.Th_Txn_Code = Crp.Cr_Txn_Code
          AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
          AND PC.MERCHANT_ID = TH.TH_MERCHANT_ID
   UNION ALL
     SELECT TH.TH_TXN_ID,
            TH.TH_APPROVAL_DATE CR_TXN_DATE,
            TD.TD_TXN_COUNTRY CR_COUNTRY,
            CRP.CR_PRODUCT_CODE CR_PRODUCT,
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
               WHEN Crp.Cr_Credit_Gl_Id <> 0 THEN Crp.Cr_Credit_Gl_Id
               WHEN Crp.Cr_Debit_Gl_Id IS NOT NULL THEN Crp.Cr_Debit_Gl_Id
               ELSE 0
            END
               Cr_Gl_Id,
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
                    TH.Th_Txn_Code,
                    TH.Th_Merchant_Id,
                    TH.TH_APPROVAL_DATE
               FROM TXN_HEADER TH
              WHERE TH.TH_TXN_CODE = 'STR' AND TH.TH_AR_IND = 'A') TH,
            Txn_Detail Td,
            (SELECT TE_TXN_ID,
                    TE_CCY,
                    TE_PARTY_TYPE,
                    TE_AMOUNT,
                    TE_TXN_ELEMENT_TYPE,
                    TE_AMT_TYPE
               FROM Txn_Elements Te
              WHERE     TE.TE_AMT_TYPE IS NOT NULL
                    AND TE.TE_PARTY_TYPE = 'M'
                    AND TE.TE_TXN_ELEMENT_TYPE IN ('TAMT', 'MAMT', 'TFEE')) TE,
            (SELECT SD_TXN_ID
               FROM MERCHANT_SETTLEMENT_DETAIL SD
              WHERE SD.SD_STATUS = 'C') SD,
            (SELECT *
               FROM Crr_Rule_Posting Crp
              WHERE     Crp.Cr_Txn_Code = 'STR'
                    AND CRP.CR_PARTY_TYPE = 'G'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'DELI_AMT'
                    AND CRP.CR_DISABLED = 0) CRP,
          (SELECT *
             FROM MERCH_DETAIL MT
             INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
             INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE) PC
      WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
            AND TE.TE_TXN_ID = TH.TH_TXN_ID
            AND SD.SD_TXN_ID = TH.TH_TXN_ID
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND Th.Th_Txn_Code = Crp.Cr_Txn_Code
            AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
            AND PC.MERCHANT_ID = TH.TH_MERCHANT_ID
   GROUP BY TH.TH_TXN_ID,
            TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
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

