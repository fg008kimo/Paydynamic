DROP VIEW PSP_TXN_VIEW;

/* Formatted on 11/30/2012 12:20:40 PM (QP5 v5.226.12202.30050) */
CREATE OR REPLACE FORCE VIEW PSP_TXN_VIEW
(
   TP_PSP_ID,
   TP_TXN_CCY,
   TP_TXN_AMOUNT,
   TP_SERVICE_FEE,
   TP_TXN_DATE,
   TH_TXN_CODE,
   TC_DESC
)
AS

   SELECT tp_psp_id,
          tp_txn_ccy,
          tp_txn_amount,
          tp_service_fee,
          tp_txn_date,
          th_txn_code,
          tc_desc
     FROM (SELECT tp_psp_id,
                  tp_txn_ccy,
                  tp_txn_amount,
                  tp_service_fee,
                  tp_txn_date,
                  th_txn_code
             FROM txn_psp_detail, txn_header
            WHERE     tp_txn_id = th_txn_id
                  AND th_ar_ind = 'A'
                  AND th_status IN ('C', 'R')
                  AND th_txn_code IN
                         ('DSI','DSP','POG','PBU', 'VOG', 'VDS', 'PST', 'HDP', 'UDP')),
          txn_code
    WHERE th_txn_code = tc_code
