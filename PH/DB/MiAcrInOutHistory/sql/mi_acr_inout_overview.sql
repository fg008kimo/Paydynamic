DROP VIEW PHUSER.MI_ACR_INOUT_OVERVIEW;

CREATE OR REPLACE FORCE VIEW PHUSER.MI_ACR_INOUT_OVERVIEW
(
   BATCH_ID,
   TXN_DATE,
   BANK_NAME,
   BANK_ID,
   ENTITY_ID,
   FROM_CCY,
   FROM_AMT,
   BANK_CCY,
   BANK_AMT,
   OLD_RATE,
   NEW_RATE,
   ORG_BANK_BAL,
   BANK_BAL,
   TXN_CODE,
   TXN_TYPE,
   TXN_ID,
   FUND_TYPE,
   FUND_TYPE_DESC,
   TIME,
   ACR_PRORATA,
   VIEW_DT
)
AS
     SELECT mah_batch_id batch_id,
            mah_txn_date txn_date,
            eo_opb_name bank_name,
            mah_bank_id bank_id,
            eo_entity_id entity_id,
            mah_from_ccy from_ccy,
            mah_from_amt from_amt,
            mah_bank_ccy bank_ccy,
            mah_bank_amt bank_amt,
            mah_old_rate old_rate,
            mah_new_rate new_rate,
            mah_org_bank_bal org_bank_bal,
            mah_bank_bal bank_bal,
            mah_txn_code txn_code,
            tc_desc txn_type,
            MIN (mah_txn_id) txn_id,
            mah_fund_type fund_type,
            mad_desc fund_type_desc,
            MIN (mah_time) time,
            mah_acr_prorata acr_prorata,
            CASE WHEN COUNT (mah_txn_id) > 1 THEN 1 ELSE 0 END AS view_dt
       FROM mi_acr_inout_history,
            mi_entity_opb,
            txn_code,
            mi_def_acr_direction
      WHERE     eo_opb_id = mah_bank_id
            AND mah_txn_code = tc_code
            AND mah_fund_type = mad_type
            AND mah_txn_id IS NOT NULL
   GROUP BY mah_batch_id,
            mah_txn_date,
            eo_opb_name,
            mah_bank_id,
            eo_entity_id,
            mah_from_ccy,
            mah_from_amt,
            mah_bank_ccy,
            mah_bank_amt,
            mah_old_rate,
            mah_new_rate,
            mah_org_bank_bal,
            mah_bank_bal,
            mah_txn_code,
            tc_desc,
            mah_fund_type,
            mad_desc,
            mah_acr_prorata
   ORDER BY txn_id DESC,
            time DESC,
            mah_bank_ccy,
            mah_from_ccy;

