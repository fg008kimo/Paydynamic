DROP VIEW OP_PSP_TXN_SUMMARY_VIEW;

CREATE OR REPLACE FORCE VIEW OP_PSP_TXN_SUMMARY_VIEW
(
   APPROVAL_TIMESTAMP,
   TXN_CTY_CODE,
   TXN_CTY,
   CRR_PRODUCT_CODE,
   CRR_PRODUCT,
   SERVICE_CODE,
   SERVICE,
   CLIENT_ID,
   CLIENT,
   MERCHANT_ID,
   MERCHANT_SHORT_NAME,
   PSP_ID,
   PSP,
   PSP_ACCOUNT_ID,
   PSP_ACCOUNT_NAME,
   TXN_TYPE_CODE,
   TXN_TYPE,
   SUB_TXN_TYPE_CODE,
   SUB_TXN_TYPE,
   TXN_CCY_CODE,
   TXN_CCY,
   TXN_AMOUNT
)
AS
   SELECT th.th_approval_timestamp AS approval_timestamp,
          td.td_txn_country AS txn_cty_code,
          co.country_name AS txn_cty,
          cm.pm_product_code AS crr_product_code,
          dp.dp_desc AS crr_product,
          sp.sp_service_code AS service_code,
          sc.sc_desc AS service,
          md.client_id AS client_id,
          cl.client_name AS client,
          th.th_merchant_id AS merchant_id,
          md.short_name AS merchant_short_name,
          pm_client_id AS psp_id,
          pm.pm_client_name AS psp,
          pd.psp_id AS psp_account_id,
          pd.psp_name AS psp_account_name,
          th.th_txn_code AS txn_type_code,
          tc.tc_desc AS txn_type,
          te.te_txn_element_type AS sub_txn_type_code,
          dt.dt_desc AS sub_txn_type,
          te.te_ccy AS txn_ccy_code,
          dc.dc_desc AS txn_ccy,
          te.te_amount AS txn_amount
     FROM txn_header th
          LEFT JOIN merch_detail md ON md.merchant_id = th.th_merchant_id
          LEFT JOIN clients cl ON cl.client_id = md.client_id,
          (SELECT tc_code, tc_desc
             FROM txn_code
            WHERE tc_psp_txn_display = 1) tc,
          (SELECT td_txn_id, td_txn_country FROM txn_detail) td,
          (SELECT country_code, country_name FROM country) co,
          (SELECT te_txn_id,
                  te_txn_element_type,
                  te_ccy,
                  te_amount
             FROM txn_elements
            WHERE te_party_type = 'P') te,
          (SELECT dc_ccy_id, dc_desc FROM def_currency) dc,
          (SELECT dt_type, dt_desc FROM def_element_type) dt,
          (SELECT tp_txn_id, tp_psp_id FROM txn_psp_detail) tp,
          (SELECT psp_id,
                  psp_name,
                  client_id,
                  psp_type
             FROM psp_detail) pd,
          (SELECT pm_client_id, pm_client_name FROM psp_master) pm,
          (SELECT pp_psp_id, pp_country, pp_pay_method FROM psp_pay_method) pp,
          (SELECT sp_service_code, sp_pay_method FROM service_pay_method) sp,
          (SELECT sc_code, sc_desc FROM def_service_code) sc,
          (SELECT pm_psp_id, pm_business_type, pm_product_code
             FROM crr_psp_product_code_map) cm,
          (SELECT dp_id, dp_desc FROM def_product) dp
    WHERE     th.th_approval_timestamp IS NOT NULL
          AND tc.tc_code = th.th_txn_code
          AND td.td_txn_id = th.th_txn_id
          AND co.country_code = td.td_txn_country
          AND te.te_txn_id = th.th_txn_id
          AND dc.dc_ccy_id = te.te_ccy
          AND dt.dt_type = te.te_txn_element_type
          AND tp.tp_txn_id = th.th_txn_id
          AND pd.psp_id = tp.tp_psp_id
          AND pm.pm_client_id = pd.client_id
          AND pp.pp_country = co.country_code
          AND pp.pp_psp_id = pd.psp_id
          AND sp.sp_pay_method = pp.pp_pay_method
          AND sc.sc_code = sp.sp_service_code
          AND cm.pm_psp_id = pd.psp_id
          AND cm.pm_business_type = pd.psp_type
          AND dp.dp_id = cm.pm_product_code;

