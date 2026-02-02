DROP VIEW PSP_SETTLE_DELIVER_TMP_VIEW;

/* Formatted on 4/2/2013 6:39:11 PM (QP5 v5.240.12305.39476) */
CREATE OR REPLACE FORCE VIEW PSP_SETTLE_DELIVER_TMP_VIEW
(
   OUT_ID,
   PSP_ID,
   OUT_CODE,
   OUT_DATE,
   COUNTRY,
   OUT_CCY,
   OUT_AMT,
   OUT_STATUS,
   OUT_SUB_STATUS,
   OUT_REMARK,
   OUT_TIMESTAMP,
   IN_ID,
   IN_CODE,
   IN_DATE,
   IN_CCY,
   IN_AMT,
   IN_STATUS,
   IN_SUB_STATUS,
   IN_REMARK,
   IN_TIMESTAMP
)
AS
   SELECT psf.th_txn_id out_id,
          psf.tp_psp_id,
          psf.th_txn_code out_code,
          psf.th_approval_date out_date,
          psf.td_txn_country country,
          psf.th_net_ccy out_ccy,
          psf.th_transaction_amount out_amt,
          psf.dm_status_desc out_status,
          psf.ds_name out_sub_status,
          psf.td_remark out_remark,
          psf.th_update_timestamp,
          psd.th_txn_id in_id,
          psd.th_txn_code in_code,
          psd.th_approval_date in_date,
          psd.th_net_ccy in_ccy,
          psd.th_transaction_amount in_amt,
          psd.dm_status_desc in_status,
          psd.ds_name in_sub_status,
          psd.td_remark in_remark,
          psd.th_update_timestamp
     FROM (  SELECT th_txn_id,
                    --tp_description,
                    tp_psp_id,
                    th_txn_code,
                    th_approval_date,
                    th_transaction_amount,
                    th_net_ccy,
                    tp_service_fee,
                    td_txn_country,
                    dm_status_desc,
                    ds_name,
                    td_remark,
                    th_update_timestamp
               FROM txn_header,
                    txn_psp_detail,
                    txn_detail,
                    def_txn_status_map,
                    def_sub_status
              WHERE     th_txn_code = 'PSF'
                    AND th_txn_id = tp_txn_id
                    AND th_txn_id = td_txn_id
                    AND th_ar_ind = dm_ar_ind
                    AND th_status = dm_status
                    AND th_txn_code = dm_txn_code
                    AND dm_type = 'A'
                    AND th_sub_status = ds_sub_status
           ORDER BY th_update_timestamp DESC) psf
          LEFT JOIN
          (  SELECT th_txn_id,
                    th_org_txn_id,
                    th_txn_code,
                    th_approval_date,
                    th_transaction_amount,
                    th_net_ccy,
                    dm_status_desc,
                    ds_name,
                    td_remark,
                    th_update_timestamp
               FROM txn_header,
                    txn_detail,
                    def_txn_status_map,
                    def_sub_status
              WHERE     th_txn_code = 'PSD'
                    AND th_txn_id = td_txn_id
                    AND th_ar_ind = dm_ar_ind
                    AND th_status = dm_status
                    AND th_txn_code = dm_txn_code
                    AND dm_type = 'A'
                    AND th_sub_status = ds_sub_status
                    AND th_status = 'C'
                    AND th_ar_ind = 'A'
           ORDER BY th_update_timestamp DESC) psd
             ON psf.th_txn_id = psd.th_org_txn_id;

