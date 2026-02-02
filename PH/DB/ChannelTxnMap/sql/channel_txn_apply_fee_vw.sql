DROP VIEW CHANNEL_TXN_APPLY_FEE_VW;

/* Formatted on 9/13/2012 9:43:04 AM (QP5 v5.226.12202.30050) */
CREATE OR REPLACE FORCE VIEW CHANNEL_TXN_APPLY_FEE_VW
(
   CHANNEL,
   TXN_CODE,
   TXN_DESC,
   CHANNEL_DESC,
   DESCRIPTION,
   FE_DISPLAY,
   MERCHANT_FE_DISPLAY
)
AS
     SELECT ct_channel_code AS channel,
            ct_txn_code AS txn_code,
            (SELECT tc_desc
               FROM txn_code
              WHERE tc_code = ct_txn_code)
               AS txn_desc,
            (SELECT dc_desc
               FROM def_channel
              WHERE dc_code = ct_channel_code)
               AS channel_desc,
               (SELECT tc_desc
                  FROM txn_code
                 WHERE tc_code = ct_txn_code)
            || ' ['
            || (SELECT dc_desc
                  FROM def_channel
                 WHERE dc_code = ct_channel_code)
            || ']'
               AS description,
            tc_fe_display AS fe_display,
            tc_merchant_fe_display AS merchant_fe_display
       FROM channel_txn_map, txn_code
      WHERE ct_apply_fee = 1 AND tc_code = ct_txn_code
   ORDER BY ct_txn_code;

