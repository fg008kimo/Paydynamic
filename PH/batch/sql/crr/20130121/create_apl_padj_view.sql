DROP VIEW CRR_APL_PADJ_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_APL_PADJ_VIEW
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
   TH_TXN_CODE
)
AS
   SELECT Th.Th_Txn_Id,
          Th.Th_Approval_Date Cr_Txn_Date,
          Td.Td_Txn_Country Cr_Country,
          PP.PP_product_id Cr_Product,
          Te.Te_Party_Type,
          DECODE (TE.TE_PARTY_TYPE, 'P', TPD.TP_PSP_ID, '') PARTY_ID,
          TE.TE_AMT_TYPE,
          TE.TE_CCY CR_CURRENCY,
          TE.TE_TXN_ELEMENT_TYPE,
          '' AS CR_JNL_TYPE_ID,
          '' AS CR_JNL_ENTRY_TYPE_ID,
          '' Cr_Ind,
          '' Cr_Gl_Id,
          1 Txn_Count,
          Te_Amount Cr_Amount,
          Th_Txn_Code
     FROM TXN_HEADER TH,
          TXN_DETAIL TD,
          TXN_ELEMENTS TE,
          PSP_PRODUCT PP,
          TXN_PSP_DETAIL TPD
    WHERE     pp.pp_Disabled = 0
          AND TH.TH_TXN_CODE LIKE ('p%')
          AND TH.TH_STATUS = 'C'
          AND TH.TH_AR_IND = 'A'
          AND TE.TE_AMT_TYPE IS NOT NULL
          AND Th.Th_Approval_Date IS NOT NULL
          AND PP.PP_PSP_ID = TPD.TP_PSP_ID
          AND Td.Td_Txn_Id = Th.Th_Txn_Id
          AND Te.Te_Txn_Id = Th.Th_Txn_Id
          AND Tpd.Tp_Txn_Id = Th.Th_Txn_Id
          AND te.te_txn_element_type IN ('TAMT')
   UNION ALL
   SELECT Th.Th_Txn_Id,
          Th.Th_Approval_Date Cr_Txn_Date,
          Td.Td_Txn_Country Cr_Country,
          PP.PP_product_id Cr_Product,
          'G' Te_Party_Type,
          '' PARTY_ID,
          TE.TE_AMT_TYPE,
          TE.TE_CCY CR_CURRENCY,
          TE.TE_TXN_ELEMENT_TYPE,
          '' AS CR_JNL_TYPE_ID,
          '' AS CR_JNL_ENTRY_TYPE_ID,
          '' Cr_Ind,
          '' Cr_Gl_Id,
          1 Txn_Count,
          Te_Amount Cr_Amount,
          Th_Txn_Code
     FROM TXN_HEADER TH,
          TXN_DETAIL TD,
          TXN_ELEMENTS TE,
          PSP_PRODUCT PP,
          TXN_PSP_DETAIL TPD
    WHERE     pp.pp_Disabled = 0
          AND TH.TH_TXN_CODE LIKE ('p%')
          AND TH.TH_STATUS = 'C'
          AND TH.TH_AR_IND = 'A'
          AND TE.TE_AMT_TYPE IS NOT NULL
          AND Th.Th_Approval_Date IS NOT NULL
          AND PP.PP_PSP_ID = TPD.TP_PSP_ID
          AND Td.Td_Txn_Id = Th.Th_Txn_Id
          AND Te.Te_Txn_Id = Th.Th_Txn_Id
          AND Tpd.Tp_Txn_Id = Th.Th_Txn_Id
          AND Te.Te_Txn_Element_Type IN ('TFEE');

