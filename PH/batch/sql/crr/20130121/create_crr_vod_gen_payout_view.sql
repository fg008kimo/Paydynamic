DROP VIEW CRR_VOD_GEN_PAYOUT_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_VOD_GEN_PAYOUT_VIEW
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
            PP.PP_PRODUCT_ID CR_PRODUCT,
            TE.TE_PARTY_TYPE,
            TP.TP_PSP_ID PARTY_ID,
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
       FROM (SELECT TH_TXN_ID, TH_APPROVAL_DATE, TH_TXN_CODE
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS = 'C'
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE IN ('VOG')) TH,
            TXN_DETAIL TD,
            (SELECT TE_TXN_ID,
                    TE_PARTY_TYPE,
                    TE_CCY,
                    TE_AMOUNT
               FROM TXN_ELEMENTS TE
              WHERE     TE.TE_AMT_TYPE IS NOT NULL
                    AND TE.TE_TXN_ELEMENT_TYPE = 'TAMT'
                    AND TE.TE_PARTY_TYPE = 'P') TE,
            TXN_PSP_DETAIL TP,
            (SELECT CR_COUNTRY_ID,
                    CR_PRODUCT_CODE,
                    CR_TXN_CODE,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_JNL_ENTRY_TYPE_ID = 'PSP_AMT'
                    AND CRP.CR_TXN_CODE = 'VOG'
                    AND CRP.CR_PARTY_TYPE = 'P'
                    AND CRP.CR_DISABLED = 0) CRP,
            PSP_PRODUCT PP
      WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
            AND TP.TP_TXN_ID = TH.TH_TXN_ID
            AND TE.TE_TXN_ID = TH.TH_TXN_ID
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND CRP.CR_TXN_CODE = TH.TH_TXN_CODE
            AND TE.TE_PARTY_TYPE = CRP.CR_PARTY_TYPE
            AND TP.TP_PSP_ID = CRP.CR_PARTY_ID
            AND PP.PP_PSP_ID = TP.TP_PSP_ID
            AND CRP.CR_PRODUCT_CODE = PP.PP_PRODUCT_ID
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            PP.PP_PRODUCT_ID,
            TE.TE_PARTY_TYPE,
            TP.TP_PSP_ID,
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
            PP.PP_PRODUCT_ID CR_PRODUCT,
            TE.TE_PARTY_TYPE,
            TP.TP_PSP_ID PARTY_ID,
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
       FROM (SELECT TH_TXN_ID, TH_APPROVAL_DATE, TH_TXN_CODE
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS = 'C'
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE IN ('VOG')) TH,
            TXN_DETAIL TD,
            (SELECT TE_TXN_ID,
                    TE_PARTY_TYPE,
                    TE_CCY,
                    TE_AMOUNT
               FROM TXN_ELEMENTS TE
              WHERE     TE.TE_AMT_TYPE IS NOT NULL
                    AND TE.TE_TXN_ELEMENT_TYPE = 'TFEE'
                    AND TE.TE_PARTY_TYPE = 'P') TE,
            TXN_PSP_DETAIL TP,
            (SELECT CR_COUNTRY_ID,
                    CR_PRODUCT_CODE,
                    CR_TXN_CODE,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_JNL_ENTRY_TYPE_ID = 'PSP_AMT'
                    AND CRP.CR_TXN_CODE = 'VOG'
                    AND CRP.CR_PARTY_TYPE = 'P'
                    AND CRP.CR_DISABLED = 0) CRP,
            PSP_PRODUCT PP
      WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
            AND TP.TP_TXN_ID = TH.TH_TXN_ID
            AND TE.TE_TXN_ID = TH.TH_TXN_ID
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND CRP.CR_TXN_CODE = TH.TH_TXN_CODE
            AND TE.TE_PARTY_TYPE = CRP.CR_PARTY_TYPE
            AND TP.TP_PSP_ID = CRP.CR_PARTY_ID
            AND PP.PP_PSP_ID = TP.TP_PSP_ID
            AND CRP.CR_PRODUCT_CODE = PP.PP_PRODUCT_ID
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            PP.PP_PRODUCT_ID,
            TE.TE_PARTY_TYPE,
            TP.TP_PSP_ID,
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
            PP.PP_PRODUCT_ID CR_PRODUCT,
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
       FROM (SELECT TH_TXN_ID, TH_APPROVAL_DATE, TH_TXN_CODE
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS = 'C'
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE IN ('VOG')) TH,
            TXN_DETAIL TD,
            (SELECT TE_TXN_ID,
                    TE_PARTY_TYPE,
                    TE_CCY,
                    TE_AMOUNT
               FROM TXN_ELEMENTS TE
              WHERE     TE.TE_AMT_TYPE IS NOT NULL
                    AND TE.TE_TXN_ELEMENT_TYPE IN ('TAMT', 'TFEE')
                    AND TE.TE_PARTY_TYPE = 'P') TE,
            TXN_PSP_DETAIL TP,
            (SELECT CR_COUNTRY_ID,
                    CR_PRODUCT_CODE,
                    CR_TXN_CODE,
                    CR_PARTY_TYPE,
                    CR_PARTY_ID,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_JNL_ENTRY_TYPE_ID = 'NET_AMT'
                    AND CRP.CR_TXN_CODE = 'VOG'
                    AND CRP.CR_PARTY_TYPE = 'G'
                    AND CRP.CR_DISABLED = 0) CRP,
            PSP_PRODUCT PP
      WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
            AND TP.TP_TXN_ID = TH.TH_TXN_ID
            AND TE.TE_TXN_ID = TH.TH_TXN_ID
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND CRP.CR_TXN_CODE = TH.TH_TXN_CODE
            AND PP.PP_PSP_ID = TP.TP_PSP_ID
            AND CRP.CR_PRODUCT_CODE = PP.PP_PRODUCT_ID
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            PP.PP_PRODUCT_ID,
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

