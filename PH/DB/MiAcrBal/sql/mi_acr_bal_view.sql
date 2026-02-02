DROP VIEW MI_ACR_BAL_VIEW;

/* Formatted on 11/16/2015 2:52:43 PM (QP5 v5.252.13127.32867) */
CREATE OR REPLACE FORCE VIEW MI_ACR_BAL_VIEW
(
   MA_FROM_CCY,
   MA_BANK_CCY,
   MA_BANK_BAL,
   MA_RATE,
   RATIO,
   EID_CCY_TOTAL,
   EID_CCY_ALL_TOTAL,
   CNT_FOR_PRORATA,
   MA_CREATE_USER,
   MA_UPDATE_USER,
   MA_CREATE_TIMESTAMP,
   MA_UPDATE_TIMESTAMP
)
AS
     SELECT ma_from_ccy,
            ma_bank_ccy,
            ma_bank_bal,
            ma_rate,
            CASE
               WHEN     SUM (
                           CASE
                              WHEN ma_bank_bal > 0 THEN ma_bank_bal
                              ELSE 0
                           END)
                        OVER (PARTITION BY ma_bank_ccy) > 0
                    AND ma_bank_bal > 0
               THEN
                  ROUND (
                       ma_bank_bal
                     / (SUM (
                           CASE
                              WHEN ma_bank_bal > 0 THEN ma_bank_bal
                              ELSE 0
                           END)
                        OVER (PARTITION BY ma_bank_ccy)),
                     5)
               ELSE
                  0
            END
               AS ratio,
            SUM (CASE WHEN ma_bank_bal > 0 THEN ma_bank_bal ELSE 0 END)
               OVER (PARTITION BY ma_bank_ccy)
               AS eid_ccy_total,
            SUM (ma_bank_bal) OVER (PARTITION BY ma_bank_ccy)
               AS eid_ccy_all_total,
            COUNT (CASE WHEN ma_bank_bal > 0 THEN ma_from_ccy ELSE NULL END)
               OVER (PARTITION BY ma_bank_ccy)
               AS cnt_for_prorata,
            ma_create_user,
            ma_update_user,
            ma_create_timestamp,
            ma_update_timestamp
       FROM MI_ACR_BAL
   ORDER BY ma_bank_bal DESC;

