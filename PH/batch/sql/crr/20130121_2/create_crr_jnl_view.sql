DROP VIEW CRR_JNL_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_JNL_VIEW
(
   GL_CODE,
   GL_NAME,
   GL_ALIAS,
   SL_CODE,
   SL_NAME,
   SL_ALIAS,
   CURRENCY_ID,
   CR_IND,
   GL_ID,
   DEBIT_AMT,
   CREDIT_AMT,
   NET_CHANGE,
   DEBIT_AMT_HKD,
   CREDIT_AMT_HKD,
   NET_CHANGE_HKD,
   STATUS,
   TXN_DATE,
   JNL_ID,
   COUNTRY_CODE,
   PRODUCT_CODE,
   ACC_YEAR,
   ACC_MONTH,
   CR_BAL_IND,
   JNL_TYPE_NAME,
   JNL_TYPE_PREFIX,
   DESCRIPTION
)
AS
     SELECT CGL.GL_CODE,
            CGL.GL_NAME,
            CGL.GL_ALIAS,
            CGL.SL_CODE,
            CGL.SL_NAME,
            CGL.SL_ALIAS,
            CJD.CURRENCY_ID,
            CJD.CR_IND,
            CJD.GL_ID,
            NVL (SUM (CASE CJD.CR_IND WHEN 'D' THEN CJD.TXN_AMT ELSE 0 END), 0)
               DEBIT_AMT,
            NVL (SUM (CASE CJD.CR_IND WHEN 'C' THEN CJD.TXN_AMT ELSE 0 END), 0)
               CREDIT_AMT,
            NVL (
               SUM (
                  CASE CJD.CR_IND
                     WHEN 'D' THEN CJD.TXN_AMT
                     ELSE -1 * CJD.TXN_AMT
                  END),
               0)
               NET_CHANGE,
            NVL (SUM (CASE CJD.CR_IND WHEN 'D' THEN CJD.TXN_AMT ELSE 0 END), 0)
               DEBIT_AMT_HKD,
            NVL (SUM (CASE CJD.CR_IND WHEN 'C' THEN CJD.TXN_AMT ELSE 0 END), 0)
               CREDIT_AMT_HKD,
            NVL (
               SUM (
                  CASE CJD.CR_IND
                     WHEN 'D' THEN CJD.TXN_AMT
                     ELSE -1 * CJD.TXN_AMT
                  END),
               0)
               NET_CHANGE_HKD,
            CJH.STATUS,
            CJH.TXN_DATE,
            CJH.JNL_ID,
            CJH.COUNTRY_CODE,
            CJH.PRODUCT_CODE,
            CJH.ACC_YEAR,
            CJH.ACC_MONTH,
            CR_BAL_IND,
            JLT.NAME JNL_TYPE_NAME,
            JLT.PREFIX JNL_TYPE_PREFIX,
            CJH.DESCRIPTION
       FROM CRR_JNL_HEADER CJH,
            CRR_JNL_DETAIL CJD,
            CRR_GL_CODE CGL,
            CRR_JNL_TYPE JLT
      WHERE     CJH.DISABLED = 0
            AND CJD.DISABLED = 0
            AND CJD.CURRENCY_ID = 'HKD'
            AND CJH.JNL_ID = CJD.JNL_ID
            AND CGL.GL_ID = CJD.GL_ID
            AND JLT.JNL_TYPE_ID = CJH.JNL_TYPE_ID
   GROUP BY CGL.GL_CODE,
            CGL.GL_NAME,
            CGL.GL_ALIAS,
            CGL.SL_CODE,
            CGL.SL_NAME,
            CGL.SL_ALIAS,
            CJD.CURRENCY_ID,
            CJD.CR_IND,
            CJD.GL_ID,
            CJH.STATUS,
            CJH.TXN_DATE,
            CJH.JNL_ID,
            CJH.COUNTRY_CODE,
            CJH.PRODUCT_CODE,
            CJH.ACC_YEAR,
            CJH.ACC_MONTH,
            CR_BAL_IND,
            JLT.NAME,
            JLT.PREFIX,
            CJH.DESCRIPTION
   UNION
     SELECT CGL.GL_CODE,
            CGL.GL_NAME,
            CGL.GL_ALIAS,
            CGL.SL_CODE,
            CGL.SL_NAME,
            CGL.SL_ALIAS,
            CJD.CURRENCY_ID,
            CJD.CR_IND,
            CJD.GL_ID,
            NVL (SUM (CASE CJD.CR_IND WHEN 'D' THEN CJD.TXN_AMT ELSE 0 END), 0)
               DEBIT_AMT,
            NVL (SUM (CASE CJD.CR_IND WHEN 'C' THEN CJD.TXN_AMT ELSE 0 END), 0)
               CREDIT_AMT,
            NVL (
               SUM (
                  CASE CJD.CR_IND
                     WHEN 'D' THEN CJD.TXN_AMT
                     ELSE -1 * CJD.TXN_AMT
                  END),
               0)
               NET_CHANGE,
            NVL (
               SUM (CASE CJD.CR_IND WHEN 'D' THEN CJDA.CONVERT_AMT ELSE 0 END),
               0)
               DEBIT_AMT_HKD,
            NVL (
               SUM (CASE CJD.CR_IND WHEN 'C' THEN CJDA.CONVERT_AMT ELSE 0 END),
               0)
               CREDIT_AMT_HKD,
            NVL (
               SUM (
                  CASE CJD.CR_IND
                     WHEN 'D' THEN CJDA.CONVERT_AMT
                     ELSE -1 * CJDA.CONVERT_AMT
                  END),
               0)
               NET_CHANGE_HKD,
            CJH.STATUS,
            CJH.TXN_DATE,
            CJH.JNL_ID,
            CJH.COUNTRY_CODE,
            CJH.PRODUCT_CODE,
            CJH.ACC_YEAR,
            CJH.ACC_MONTH,
            CR_BAL_IND,
            JLT.NAME JNL_TYPE_NAME,
            JLT.PREFIX JNL_TYPE_PREFIX,
            CJH.DESCRIPTION
       FROM CRR_JNL_HEADER CJH,
            CRR_JNL_DETAIL CJD,
            CRR_GL_CODE CGL,
            CRR_JNL_DETAIL_AMT CJDA,
            CRR_JNL_TYPE JLT
      WHERE     CJH.DISABLED = 0
            AND CJD.DISABLED = 0
            AND CJD.CURRENCY_ID <> 'HKD'
            AND CJDA.DISABLED = 0
            AND CJDA.CURRENCY_ID = 'HKD'
            AND CJH.JNL_ID = CJD.JNL_ID
            AND CGL.GL_ID = CJD.GL_ID
            AND CJD.JNL_ID = CJDA.JNL_ID
            AND CJD.LINE_NO = CJDA.LINE_NO
            AND JLT.JNL_TYPE_ID = CJH.JNL_TYPE_ID
   GROUP BY CGL.GL_CODE,
            CGL.GL_NAME,
            CGL.GL_ALIAS,
            CGL.SL_CODE,
            CGL.SL_NAME,
            CGL.SL_ALIAS,
            CJD.CURRENCY_ID,
            CJD.CR_IND,
            CJD.GL_ID,
            CJH.STATUS,
            CJH.TXN_DATE,
            CJH.JNL_ID,
            CJH.COUNTRY_CODE,
            CJH.PRODUCT_CODE,
            CJH.ACC_YEAR,
            CJH.ACC_MONTH,
            CR_BAL_IND,
            JLT.NAME,
            JLT.PREFIX,
            CJH.DESCRIPTION;

