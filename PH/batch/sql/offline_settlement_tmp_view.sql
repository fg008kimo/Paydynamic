DROP VIEW OFFLINE_SETTLEMENT_TMP_VIEW;

/* Formatted on 4/2/2013 6:44:45 PM (QP5 v5.240.12305.39476) */
CREATE OR REPLACE FORCE VIEW OFFLINE_SETTLEMENT_TMP_VIEW
(
   OUT_ID,
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
   SELECT ost.th_txn_id out_id,
          ost.th_txn_code out_code,
          ost.th_approval_date out_date,
          ost.td_txn_country country,
          ost.th_net_ccy out_ccy,
          ost.th_transaction_amount out_amt,
          ost.dm_status_desc out_status,
          ost.ds_name out_sub_status,
          ost.td_remark out_remark,
          ost.th_update_timestamp,
          osd.th_txn_id in_id,
          osd.th_txn_code in_code,
          osd.th_approval_date in_date,
          osd.th_net_ccy in_ccy,
          osd.th_transaction_amount in_amt,
          osd.dm_status_desc in_status,
          osd.ds_name in_sub_status,
          osd.td_remark in_remark,
          osd.th_update_timestamp
     FROM (  SELECT th_txn_id,
                    th_txn_code,
                    th_approval_date,
                    th_transaction_amount,
                    th_net_ccy,
                    td_txn_country,
                    dm_status_desc,
                    ds_name,
                    td_remark,
                    th_update_timestamp
               FROM txn_header,
                    txn_detail,
                    def_txn_status_map,
                    def_sub_status
              WHERE     th_txn_code = 'OST'
                    AND th_txn_id = td_txn_id
                    AND th_ar_ind = dm_ar_ind
                    AND th_status = dm_status
                    AND th_txn_code = dm_txn_code
                    AND dm_type = 'A'
                    AND th_sub_status = ds_sub_status
           ORDER BY th_update_timestamp DESC) ost
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
              WHERE     th_txn_code = 'OSD'
                    AND th_txn_id = td_txn_id
                    AND th_ar_ind = dm_ar_ind
                    AND th_status = dm_status
                    AND th_txn_code = dm_txn_code
                    AND dm_type = 'A'
                    AND th_sub_status = ds_sub_status
           --AND th_status = 'C'
           --AND th_ar_ind = 'A'
           ORDER BY th_update_timestamp DESC) osd
             ON ost.th_txn_id = osd.th_org_txn_id;

