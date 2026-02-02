DROP VIEW CRR_APL_DEPOSIT_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_APL_DEPOSIT_VIEW
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
            SM.SM_PRODUCT_CODE CR_PRODUCT,
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
            COUNT (DISTINCT Th_Txn_Id) Txn_Count,
            SUM (Th.Th_Net_Amount) Cr_Amount
       FROM (SELECT Th_Txn_Id,
                    DECODE (Th_Txn_Code,
                            'DSI', 'DSP',
                            'DSR', 'DSP',
                            Th_Txn_Code)
                       Th_Txn_Code,
                    Th_Approval_Date,
                    Th_Service_Code,
                    Th_Merchant_Id,
                    Th_Net_Amount
               FROM Txn_Header Th
              WHERE     Th.Th_Status = 'C'
                    AND Th.Th_Ar_Ind = 'A'
                    AND Th.Th_Txn_Code IN ('DSI', 'DSP', 'DSR')
                    AND Th.Th_Approval_Date IS NOT NULL) Th
            INNER JOIN Txn_Detail Td ON Td.Td_Txn_Id = Th.Th_Txn_Id
            INNER JOIN Service_Mapping Sm ON SM.SM_CODE = TH.TH_SERVICE_CODE
            INNER JOIN
            (SELECT Cr_Country_Id,
                    Cr_Party_Type,
                    Cr_Party_Id,
                    Cr_Jnl_Type_Id,
                    Cr_Jnl_Entry_Type_Id,
                    Cr_Txn_Code,
                    Cr_Product_Code,
                    Cr_Currency_Id,
                    Cr_Credit_Gl_Id,
                    Cr_Debit_Gl_Id
               FROM Crr_Rule_Posting Crp
              WHERE     Crp.Cr_Party_Type = 'M'
                    AND Crp.Cr_Jnl_Entry_Type_Id = 'NET_AMT'
                    AND Crp.Cr_Txn_Code = 'DSP'
                    AND Crp.Cr_Disabled = 0) Crp
               ON     TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
                  AND TH.TH_MERCHANT_ID = CRP.CR_PARTY_ID
                  AND Sm.Sm_Product_Code = Crp.Cr_Product_Code
                  AND Td.Td_Txn_Ccy = Crp.Cr_Currency_Id
                  AND Th.Th_Txn_Code = Crp.Cr_Txn_Code
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            SM.SM_PRODUCT_CODE,
            TH.TH_MERCHANT_ID,
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
            SM.SM_PRODUCT_CODE CR_PRODUCT,
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
       FROM (SELECT Th_Txn_Id,
                    DECODE (TH_TXN_CODE,
                            'DSI', 'DSP',
                            'DSR', 'DSP',
                            TH_TXN_CODE)
                       TH_TXN_CODE,
                    Th_Approval_Date,
                    Th_Service_Code
               FROM Txn_Header Th
              WHERE     Th.Th_Status = 'C'
                    AND Th.Th_Ar_Ind = 'A'
                    AND Th.Th_Txn_Code IN ('DSI', 'DSP', 'DSR')
                    AND Th.Th_Approval_Date IS NOT NULL) Th
            INNER JOIN Txn_Detail Td ON Td.Td_Txn_Id = Th.Th_Txn_Id
            INNER JOIN Service_Mapping Sm ON Sm.Sm_Code = Th.Th_Service_Code
            INNER JOIN
            (SELECT CR_COUNTRY_ID,
                    CR_PARTY_TYPE,
                    CR_JNL_TYPE_ID,
                    CR_JNL_ENTRY_TYPE_ID,
                    CR_TXN_CODE,
                    Cr_Product_Code,
                    CR_CREDIT_GL_ID,
                    CR_DEBIT_GL_ID
               FROM Crr_Rule_Posting Crp
              WHERE     Crp.Cr_Party_Type = 'G'
                    AND Crp.Cr_Jnl_Entry_Type_Id = 'M_FEE'
                    AND Crp.Cr_Txn_Code = 'DSP'
                    AND Crp.Cr_Disabled = 0) Crp
               ON     CRP.CR_TXN_CODE = TH.TH_TXN_CODE
                  AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
                  AND Sm.Sm_Product_Code = Crp.Cr_Product_Code
            INNER JOIN
            (SELECT Te_Txn_Id,
                    Te_Txn_Element_Type,
                    TE_CCY,
                    TE_AMOUNT
               FROM Txn_Elements Te
              WHERE Te.Te_Txn_Element_Type = 'TFEE' AND TE.TE_PARTY_TYPE = 'M') TE
               ON Te.Te_Txn_Id = Th.Th_Txn_Id
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            SM.SM_PRODUCT_CODE,
            CRP.CR_PARTY_TYPE,
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
            SM.SM_PRODUCT_CODE CR_PRODUCT,
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
       FROM (SELECT *
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS = 'C'
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE IN ('DSI', 'DSP', 'DSR')
                    AND TH.TH_APPROVAL_DATE IS NOT NULL) TH,
            TXN_DETAIL TD,
            (SELECT *
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_PARTY_TYPE = 'G'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'M_MU_FEE'
                    AND CRP.CR_TXN_CODE = 'DSP'
                    AND CRP.CR_DISABLED = 0) CRP,
            (SELECT *
               FROM SERVICE_MAPPING SM
              WHERE SM.SM_DISABLED = 0) SM,
            (SELECT *
               FROM TXN_ELEMENTS TE
              WHERE     TE.TE_AMT_TYPE IS NOT NULL
                    AND TE.TE_TXN_ELEMENT_TYPE = 'MAMT'
                    AND TE.TE_PARTY_TYPE = 'R') TE
      WHERE     TD.TD_TXN_ID = TH.TH_TXN_ID
            AND TE.TE_TXN_ID = TH.TH_TXN_ID
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND SM.SM_CODE = TH.TH_SERVICE_CODE
            AND SM.SM_PRODUCT_CODE = CRP.CR_PRODUCT_CODE
            AND CRP.CR_TXN_CODE =
                   DECODE (TH.TH_TXN_CODE,
                           'DSI', 'DSP',
                           'DSR', 'DSP',
                           TH.TH_TXN_CODE)
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            SM.SM_PRODUCT_CODE,
            CRP.CR_PARTY_TYPE,
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
            SM.SM_PRODUCT_CODE CR_PRODUCT,
            'P',
            TP.TP_PSP_ID PARTY_ID,
            TP.TP_TXN_CCY CR_CURRENCY,
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
       FROM (SELECT Th_Txn_Id,
                    DECODE (TH_TXN_CODE,
                            'DSI', 'DSP',
                            'DSR', 'DSP',
                            TH_TXN_CODE)
                       TH_TXN_CODE,
                    Th_Approval_Date,
                    Th_Service_Code
               FROM TXN_HEADER TH
              WHERE     TH.TH_STATUS = 'C'
                    AND TH.TH_AR_IND = 'A'
                    AND TH.TH_TXN_CODE IN ('DSI', 'DSP', 'DSR')
                    AND Th.Th_Approval_Date IS NOT NULL) Th
            INNER JOIN Txn_Detail Td ON Td.Td_Txn_Id = Th.Th_Txn_Id
            INNER JOIN Service_Mapping Sm ON Sm.Sm_Code = Th.Th_Service_Code
            INNER JOIN Txn_Psp_Detail Tp ON TH.TH_TXN_ID = TP.TP_TXN_ID
            INNER JOIN
            (SELECT Cr_Country_Id,
                    Cr_Party_Type,
                    Cr_Jnl_Type_Id,
                    Cr_Jnl_Entry_Type_Id,
                    Cr_Txn_Code,
                    Cr_Product_Code,
                    Cr_Party_Id,
                    Cr_Credit_Gl_Id,
                    Cr_Debit_Gl_Id
               FROM Crr_Rule_Posting Crp
              WHERE     CRP.CR_PARTY_TYPE = 'P'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'TXN_AMT'
                    AND CRP.CR_TXN_CODE = 'DSP'
                    AND Crp.Cr_Disabled = 0) Crp
               ON     TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
                  AND Sm.Sm_Product_Code = Crp.Cr_Product_Code
                  AND Tp.Tp_Psp_Id = Crp.Cr_Party_Id
                  AND th.th_txn_code = crp.cr_txn_code
   GROUP BY TH.TH_APPROVAL_DATE,
            TD.TD_TXN_COUNTRY,
            SM.SM_PRODUCT_CODE,
            TP.TP_PSP_ID,
            TP.TP_TXN_CCY,
            CRP.CR_JNL_TYPE_ID,
            CRP.CR_JNL_ENTRY_TYPE_ID,
            CASE
               WHEN Crp.Cr_Credit_Gl_Id <> 0 THEN 'C'
               WHEN Crp.Cr_Debit_Gl_Id IS NOT NULL THEN 'D'
               ELSE ''
            END,
            CASE
               WHEN Crp.Cr_Credit_Gl_Id <> 0 THEN Crp.Cr_Credit_Gl_Id
               WHEN Crp.Cr_Debit_Gl_Id IS NOT NULL THEN Crp.Cr_Debit_Gl_Id
               ELSE 0
            END;

