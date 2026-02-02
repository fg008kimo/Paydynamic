DROP VIEW CRR_APL_MADJ_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_APL_MADJ_VIEW
(
   TH_TXN_ID,
   CR_TXN_DATE,
   CR_COUNTRY,
   CR_PRODUCT,
   PARTY_ID,
   CR_CURRENCY,
   CR_JNL_TYPE_ID,
   CR_JNL_ENTRY_TYPE_ID,
   CR_IND,
   CR_GL_ID,
   TXN_COUNT,
   CR_AMOUNT,
   TH_TXN_CODE,
   AT_DC_IND
)
AS
     SELECT Th.Th_Txn_Id,
            Th.Th_Approval_Date Cr_Txn_Date,
            Td.Td_Txn_Country Cr_Country,
            CRP.CR_Product_Code Cr_Product,
            DECODE (Te.Te_Party_Type, 'M', Th.Th_Merchant_Id, '') Party_Id,
            Te.Te_Ccy Cr_Currency,
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
            COUNT (DISTINCT Th_Txn_Id) Txn_Count,
            SUM (Te.Te_Amount) Cr_Amount,
            Th_Txn_Code,
            At.At_Dc_Ind
       FROM TXN_HEADER TH,
            TXN_DETAIL TD,
            TXN_ELEMENTS TE,
            merch_detail Mt,
            clients Ct,
            CRR_BUSINESS_TYPE_MAPPING CBM,
            ADJUSTMENT_TYPE AT,
            CRR_RULE_POSTING CRP
      WHERE     TH.TH_TXN_CODE = AT.AT_CODE
            AND TH.TH_STATUS = 'C'
            AND TH.TH_AR_IND = 'A'
            AND Te.Te_Amt_Type IS NOT NULL
            AND Te.Te_Txn_Element_Type = 'TAMT'
            AND TH.TH_APPROVAL_DATE IS NOT NULL
            AND Td.Td_Txn_Id = Th.Th_Txn_Id
            AND Te.Te_Txn_Id = Th.Th_Txn_Id
            AND Crp.Cr_Party_Type = 'M'
            AND Crp.Cr_Jnl_Entry_Type_Id = 'TXN_AMT'
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND At.At_Party_Type = 'M'
            AND Crp.Cr_Txn_Code = 'M' || At.At_Dc_Ind || 'A'
            AND Th.Th_Merchant_Id = Crp.Cr_Party_Id
            AND Mt.merchant_id = Th.th_merchant_id
            AND Ct.client_id = Mt.client_id
            AND CBM.BM_BUSINESS_TYPE = Ct.BUSINESS_TYPE
            AND CBM.BM_PRODUCT_CODE = Crp.Cr_Product_Code
   GROUP BY Th.Th_Txn_Id,
            Th.Th_Approval_Date,
            Td.Td_Txn_Country,
            CRP.CR_Product_Code,
            DECODE (Te.Te_Party_Type, 'M', Th.Th_Merchant_Id, ''),
            Te.Te_Ccy,
            Crp.Cr_Jnl_Type_Id,
            Crp.Cr_Jnl_Entry_Type_Id,
            CASE
               WHEN Crp.Cr_Credit_Gl_Id <> 0 THEN 'C'
               WHEN Crp.Cr_Debit_Gl_Id IS NOT NULL THEN 'D'
               ELSE ''
            END,
            CASE
               WHEN Crp.Cr_Credit_Gl_Id <> 0 THEN Crp.Cr_Credit_Gl_Id
               WHEN Crp.Cr_Debit_Gl_Id IS NOT NULL THEN Crp.Cr_Debit_Gl_Id
               ELSE 0
            END,
            Th_Txn_Code,
            At.At_Dc_Ind
   UNION ALL
     SELECT Th.Th_Txn_Id,
            Th.Th_Approval_Date Cr_Txn_Date,
            Td.Td_Txn_Country Cr_Country,
            CRP.CR_Product_Code Cr_Product,
            '' Party_Id,
            Te.Te_Ccy Cr_Currency,
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
            COUNT (DISTINCT Th_Txn_Id) Txn_Count,
            SUM (Te.Te_Amount) Cr_Amount,
            Th_Txn_Code,
            At.At_Dc_Ind
       FROM TXN_HEADER TH,
            TXN_DETAIL TD,
            TXN_ELEMENTS TE,
            merch_detail Mt,
            clients Ct,
            CRR_BUSINESS_TYPE_MAPPING CBM,
            ADJUSTMENT_TYPE AT,
            CRR_RULE_POSTING CRP
      WHERE     TH.TH_TXN_CODE = AT.AT_CODE
            AND TH.TH_STATUS = 'C'
            AND TH.TH_AR_IND = 'A'
            AND Te.Te_Amt_Type IS NOT NULL
            AND Te.Te_Txn_Element_Type = 'TFEE'
            AND TH.TH_APPROVAL_DATE IS NOT NULL
            AND Td.Td_Txn_Id = Th.Th_Txn_Id
            AND Te.Te_Txn_Id = Th.Th_Txn_Id
            AND Crp.Cr_Party_Type = 'G'
            AND Crp.Cr_Jnl_Entry_Type_Id = 'M_FEE'
            AND TD.TD_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND At.At_Party_Type = 'M'
            AND Te.TE_PARTY_TYPE = 'M'
            AND Crp.Cr_Txn_Code = 'M' || At.At_Dc_Ind || 'A'
            AND Mt.merchant_id = Th.th_merchant_id
            AND Ct.client_id = Mt.client_id
            AND CBM.BM_BUSINESS_TYPE = Ct.BUSINESS_TYPE
            AND CBM.BM_PRODUCT_CODE = Crp.Cr_Product_Code
   GROUP BY Th.Th_Txn_Id,
            Th.Th_Approval_Date,
            Td.Td_Txn_Country,
            CRP.CR_Product_Code,
            Te.Te_Ccy,
            Crp.Cr_Jnl_Type_Id,
            Crp.Cr_Jnl_Entry_Type_Id,
            CASE
               WHEN Crp.Cr_Credit_Gl_Id <> 0 THEN 'C'
               WHEN Crp.Cr_Debit_Gl_Id IS NOT NULL THEN 'D'
               ELSE ''
            END,
            CASE
               WHEN Crp.Cr_Credit_Gl_Id <> 0 THEN Crp.Cr_Credit_Gl_Id
               WHEN Crp.Cr_Debit_Gl_Id IS NOT NULL THEN Crp.Cr_Debit_Gl_Id
               ELSE 0
            END,
            Th_Txn_Code,
            At.At_Dc_Ind;

