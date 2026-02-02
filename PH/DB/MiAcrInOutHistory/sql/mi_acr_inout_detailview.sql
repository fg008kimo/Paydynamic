DROP VIEW MI_ACR_INOUT_DETAILVIEW;

/* Formatted on 11/6/2015 4:56:05 PM (QP5 v5.252.13127.32867) */
CREATE OR REPLACE FORCE VIEW MI_ACR_INOUT_DETAILVIEW
(
   BATCH_ID,
   TXN_DATE,
   BANK_NAME,
   BANK_ID,
   BANK_CCY,
   BANK_AMT,
   TXN_CODE,
   TXN_TYPE,
   TXN_ID,
   FUND_TYPE,
   FUND_TYPE_DESC,
   TIME
)
AS
     SELECT mah_batch_id batch_id,
            mah_txn_date txn_date,
            eo_opb_name bank_name,
            mah_bank_id bank_id,
            mah_bank_ccy bank_ccy,
            th_transaction_amount bank_amt,
            mah_txn_code txn_code,
            tc_desc txn_type,
            mah_txn_id txn_id,
            mah_fund_type fund_type,
            mad_desc fund_type_desc,
            th_approval_timestamp time
       FROM mi_acr_inout_history,
            mi_entity_opb,
            txn_code,
            mi_def_acr_direction,
            txn_header
      WHERE     eo_opb_id = mah_bank_id
            AND mah_txn_code = tc_code
            AND mah_fund_type = mad_type
            AND mah_txn_id = th_txn_id
   ORDER BY time DESC;

