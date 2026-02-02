DROP VIEW CRR_VOD_DEPOSIT_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_VOD_DEPOSIT_VIEW
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
            'M' TE_PARTY_TYPE,
            TH.TH_MERCHANT_ID PARTY_ID,
            TD.TD_TXN_CCY CR_CURRENCY,
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
            SUM (TH.TH_NET_AMOUNT) CR_AMOUNT
       FROM (SELECT *
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS = 'C'
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE = 'VDS'
                    AND TH.TH_APPROVAL_DATE IS NOT NULL) TH,
            TXN_DETAIL TD,
            (SELECT *
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_TXN_CODE = 'VDS'
                    AND CRP.CR_DISABLED = 0
                    AND CRP.CR_PARTY_TYPE = 'M'
                    AND CRP.CR_PARTY_TYPE = 'M'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'NET_AMT') CRP,
            (SELECT *
               FROM MERCH_DETAIL MT
               INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
               INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE) PC,
            (SELECT *
               FROM TXN_PSP_DETAIL TPD
              WHERE TPD.TP_RECON_IND = 0) TPD
      WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
            AND TPD.TP_TXN_ID = TH.TH_TXN_ID
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
            AND PC.MERCHANT_ID = TH.TH_MERCHANT_ID
            AND CRP.CR_TXN_CODE = TH.TH_TXN_CODE
            AND TH.TH_MERCHANT_ID = CRP.CR_PARTY_ID
            AND TD.TD_TXN_CCY = CRP.CR_CURRENCY_ID
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
            TH.TH_MERCHANT_ID,
            TH.TH_STATUS,
            TH.TH_AR_IND,
            TD.TD_TXN_CCY,
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
       FROM (SELECT *
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS = 'C'
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE = 'VDS'
                    AND TH.TH_APPROVAL_DATE IS NOT NULL) TH,
            TXN_DETAIL TD,
            (SELECT *
               FROM TXN_ELEMENTS TE
              WHERE     TE.TE_AMT_TYPE IS NOT NULL
                    AND TE.TE_TXN_ELEMENT_TYPE = 'TFEE'
                    AND TE.TE_PARTY_TYPE = 'M') TE,
            (SELECT *
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_TXN_CODE = 'VDS'
                    AND CRP.CR_DISABLED = 0
                    AND CRP.CR_PARTY_TYPE = 'G'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'M_FEE') CRP,
            (SELECT *
               FROM MERCH_DETAIL MT
               INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
               INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE) PC,
            (SELECT *
               FROM TXN_PSP_DETAIL TPD
              WHERE TPD.TP_RECON_IND = 0) TPD
      WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
            AND TPD.TP_TXN_ID = TH.TH_TXN_ID
            AND TE.TE_TXN_ID = TH.TH_TXN_ID
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
            AND PC.MERCHANT_ID = TH.TH_MERCHANT_ID
            AND CRP.CR_TXN_CODE = TH.TH_TXN_CODE
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
            TE.TE_PARTY_TYPE,
            TH.TH_MERCHANT_ID,
            TH.TH_STATUS,
            TH.TH_AR_IND,
            TE.TE_AMT_TYPE,
            TE_CCY,
            TE.TE_TXN_ELEMENT_TYPE,
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
       FROM (SELECT *
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS = 'C'
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE = 'VDS'
                    AND TH.TH_APPROVAL_DATE IS NOT NULL) TH,
            TXN_DETAIL TD,
            (SELECT *
               FROM TXN_ELEMENTS TE
              WHERE     TE.TE_AMT_TYPE IS NOT NULL
                    AND TE.TE_TXN_ELEMENT_TYPE = 'MAMT'
                    AND TE.TE_PARTY_TYPE = 'R') TE,
            (SELECT *
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_TXN_CODE = 'VDS'
                    AND CRP.CR_DISABLED = 0
                    AND CRP.CR_PARTY_TYPE = 'G'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'M_MU_FEE') CRP,
            (SELECT *
               FROM MERCH_DETAIL MT
               INNER JOIN CLIENTS CT ON MT.CLIENT_ID = CT.CLIENT_ID
               INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON CT.BUSINESS_TYPE = CBM.BM_BUSINESS_TYPE) PC,
            (SELECT *
               FROM TXN_PSP_DETAIL TPD
              WHERE TPD.TP_RECON_IND = 0) TPD
      WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
            AND TPD.TP_TXN_ID = TH.TH_TXN_ID
            AND TE.TE_TXN_ID = TH.TH_TXN_ID
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
            AND PC.MERCHANT_ID = TH.TH_MERCHANT_ID
            AND CRP.CR_TXN_CODE = TH.TH_TXN_CODE
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
            TE.TE_PARTY_TYPE,
            TH.TH_MERCHANT_ID,
            TH.TH_STATUS,
            TH.TH_AR_IND,
            TE.TE_AMT_TYPE,
            TE_CCY,
            TE.TE_TXN_ELEMENT_TYPE,
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
            'P',
            TPD.TP_PSP_ID PARTY_ID,
            TPD.TP_TXN_CCY CR_CURRENCY,
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
            SUM (TP_TXN_AMOUNT) CR_AMOUNT
       FROM (SELECT *
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS = 'C'
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE = 'VDS'
                    AND TH.TH_APPROVAL_DATE IS NOT NULL) TH,
            TXN_DETAIL TD,
            (SELECT *
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_TXN_CODE = 'VDS'
                    AND CRP.CR_DISABLED = 0
                    AND CRP.CR_PARTY_TYPE = 'P'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'TXN_AMT') CRP,
            (SELECT *
               FROM PSP_DETAIL TP
               INNER JOIN CRR_BUSINESS_TYPE_MAPPING CBM ON TP.PSP_TYPE = CBM.BM_BUSINESS_TYPE) PC,
            (SELECT *
               FROM TXN_PSP_DETAIL TPD
              WHERE TPD.TP_RECON_IND = 0) TPD
      WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND PC.BM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
            AND PC.PSP_ID = TPD.TP_PSP_ID
            AND CRP.CR_TXN_CODE = TH.TH_TXN_CODE
            AND TPD.TP_PSP_ID = CRP.CR_PARTY_ID
            AND TH.TH_TXN_ID = TPD.TP_TXN_ID
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
            TPD.TP_PSP_ID,
            TH.TH_STATUS,
            TH.TH_AR_IND,
            TPD.TP_TXN_CCY,
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

