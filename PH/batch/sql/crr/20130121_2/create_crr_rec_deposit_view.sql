DROP VIEW CRR_REC_DEPOSIT_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_REC_DEPOSIT_VIEW
(
   CR_TXN_DATE,
   RECON_DATE,
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
     SELECT PRH.PR_PSP_TXN_DATE CR_TXN_DATE,
            PRH.PR_RECON_DATE RECON_DATE,
            PRH.PR_TXN_COUNTRY CR_COUNTRY,
            CRP.CR_PRODUCT_CODE CR_PRODUCT,
            'P' TE_PARTY_TYPE,
            PRH.PR_PSP_ID PARTY_ID,
            PRH.PR_TXN_CCY CR_CURRENCY,
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
            COUNT (DISTINCT PRH.PR_ID) TXN_COUNT,
            SUM (PRH.PR_TXN_AMOUNT) CR_AMOUNT
       FROM PSP_RECON_HISTORY PRH,
            (SELECT *
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_PARTY_TYPE = 'P'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'TXN_AMT'
                    AND CRP.CR_TXN_CODE = 'PBU'
                    AND CRP.CR_DISABLED = 0) CRP,
            PSP_DETAIL PD,
            CRR_BUSINESS_TYPE_MAPPING CBM
      WHERE     PRH.PR_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND PRH.PR_PSP_ID = CRP.CR_PARTY_ID
            AND PD.PSP_ID = PRH.PR_PSP_ID
            AND PD.PSP_TYPE = CBM.BM_BUSINESS_TYPE
            AND CBM.BM_PRODUCT_CODE = Crp.Cr_Product_Code 
   GROUP BY PRH.PR_PSP_TXN_DATE,
            PRH.PR_RECON_DATE,
            PRH.PR_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
            PRH.PR_PSP_ID,
            PRH.PR_TXN_CCY,
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
     SELECT PRH.PR_PSP_TXN_DATE CR_TXN_DATE,
            PRH.PR_RECON_DATE RECON_DATE,
            PRH.PR_TXN_COUNTRY CR_COUNTRY,
            CRP.CR_PRODUCT_CODE CR_PRODUCT,
            'P' TE_PARTY_TYPE,
            PRH.PR_PSP_ID PARTY_ID,
            PRH.PR_TXN_CCY CR_CURRENCY,
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
            COUNT (DISTINCT PRH.PR_ID) TXN_COUNT,
            SUM (PRH.PR_TXN_AMOUNT - PRH.PR_INPUT_FEE) CR_AMOUNT
       FROM PSP_RECON_HISTORY PRH,
            (SELECT *
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_PARTY_TYPE = 'P'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'NET_AMT'
                    AND CRP.CR_TXN_CODE = 'PBU'
                    AND CRP.CR_DISABLED = 0) CRP,
            PSP_DETAIL PD,
            CRR_BUSINESS_TYPE_MAPPING CBM
      WHERE     PRH.PR_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND PRH.PR_PSP_ID = CRP.CR_PARTY_ID
            AND PD.PSP_ID = PRH.PR_PSP_ID
            AND PD.PSP_TYPE = CBM.BM_BUSINESS_TYPE
            AND CBM.BM_PRODUCT_CODE = Crp.Cr_Product_Code 
   GROUP BY PRH.PR_PSP_TXN_DATE,
            PRH.PR_RECON_DATE, 
            PRH.PR_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
            PRH.PR_PSP_ID,
            PRH.PR_TXN_CCY,
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
     SELECT PRH.PR_PSP_TXN_DATE CR_TXN_DATE,
            PRH.PR_RECON_DATE RECON_DATE,
            PRH.PR_TXN_COUNTRY CR_COUNTRY,
            CRP.CR_PRODUCT_CODE CR_PRODUCT,
            'G' TE_PARTY_TYPE,
            '' PARTY_ID,
            PRH.PR_TXN_CCY CR_CURRENCY,
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
            COUNT (DISTINCT PRH.PR_ID) TXN_COUNT,
            SUM (PRH.PR_INPUT_FEE) CR_AMOUNT
       FROM PSP_RECON_HISTORY PRH,
            (SELECT *
               FROM CRR_RULE_POSTING CRP
              WHERE     CRP.CR_PARTY_TYPE = 'G'
                    AND CRP.CR_JNL_ENTRY_TYPE_ID = 'PSP_COST'
                    AND CRP.CR_TXN_CODE = 'PBU'
                    AND CRP.CR_DISABLED = 0) CRP,
            PSP_DETAIL PD,
            CRR_BUSINESS_TYPE_MAPPING CBM
      WHERE     PRH.PR_TXN_COUNTRY = CRP.CR_COUNTRY_ID
            AND PD.PSP_ID = PRH.PR_PSP_ID
            AND PD.PSP_TYPE = CBM.BM_BUSINESS_TYPE
            AND CBM.BM_PRODUCT_CODE = Crp.Cr_Product_Code 
   GROUP BY PRH.PR_PSP_TXN_DATE,
            PRH.PR_RECON_DATE, 
            PRH.PR_TXN_COUNTRY,
            CRP.CR_PRODUCT_CODE,
            PRH.PR_TXN_CCY,
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

