DROP VIEW channel_txn_apply_uni_num_vw;

CREATE OR REPLACE FORCE VIEW channel_txn_apply_uni_num_vw
(
   CHANNEL,
   TXN_CODE,
   TXN_DESC,
   CHANNEL_DESC,
   DESCRIPTION,
   merch_unique,
   psp_unique,
   FE_DISPLAY,
   MERCHANT_FE_DISPLAY,
   OFL_FE_DISPLAY,
   OFL_MERCHANT_FE_DISPLAY
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
	    ct_apply_m_unique_num as merch_unique,
	    ct_apply_p_unique_num as psp_unique,
            tc_fe_display AS fe_display,
            tc_merchant_fe_display AS merchant_fe_display,
	    TC_OFL_FE_DISPLAY AS ofl_fe_display,
            TC_OFL_MERCHANT_FE_DISPLAY AS ofl_merchant_fe_display
       FROM channel_txn_map, txn_code
      WHERE (ct_apply_m_unique_num = 1 or ct_apply_p_unique_num = 1)
      AND tc_code = ct_txn_code
   ORDER BY ct_txn_code;
