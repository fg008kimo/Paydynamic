DROP VIEW CRR_MMS_TXN_VIEW;

CREATE OR REPLACE FORCE VIEW CRR_MMS_TXN_VIEW
(
   MTD_TXN_ID,
   CR_TXN_DATE,
   MTD_TXN_CODE,
   CR_COUNTRY,
   CR_PRODUCT,
   CR_PARTY_TYPE,
   PARTY_ID,
   CR_CURRENCY,
   CR_AMOUNT,
   MTD_PROCESSING_COST,
   MTD_ISD_IND,
   MTD_STATUS,
   MTD_FILING_NUMBER
)
AS
   SELECT MTD.MTD_TXN_ID,
          SUBSTR (MTD.MTD_TRANSMISSION_DATETIME, 0, 8) CR_TXN_DATE,
          MTD.MTD_TXN_CODE,
          MTD.MTD_COUNTRY CR_COUNTRY,
          'SHD' CR_PRODUCT,
          MTD.MTD_SRC_PARTY_TYPE CR_PARTY_TYPE,
          CASE
             WHEN MTD.MTD_ISD_IND = 'I' OR MTD.MTD_ISD_IND = 'S'
             THEN
                CASE MTD.MTD_SRC_PARTY_TYPE
                   WHEN 'PSP' THEN MTD.MTD_PSP_ID
                   WHEN 'MB' THEN MTD.MTD_MB_ID
                   WHEN 'BANK' THEN MTD.MTD_BANK_ID
                   ELSE NULL
                END
             WHEN MTD.MTD_ISD_IND = 'D'
             THEN
                CASE MTD.MTD_DST_PARTY_TYPE
                   WHEN 'PSP' THEN MTD.MTD_PSP_ID
                   WHEN 'MB' THEN MTD.MTD_MB_ID
                   WHEN 'BANK' THEN MTD.MTD_BANK_ID
                   ELSE NULL
                END
          END
             PARTY_ID,
          MTD.MTD_TXN_CCY CR_CURRENCY,
          MTD.MTD_TXN_AMT CR_AMOUNT,
          MTD.MTD_PROCESSING_COST,
          MTD.MTD_ISD_IND,
          MTD.MTD_STATUS,
          MTD.MTD_FILING_NUMBER
     FROM MMS_TXN_DETAIL MTD;

