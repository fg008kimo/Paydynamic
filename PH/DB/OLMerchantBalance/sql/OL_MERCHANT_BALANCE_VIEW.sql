
  CREATE OR REPLACE FORCE VIEW "OL_MERCHANT_BALANCE_VIEW" ("MERCHANT_ID", "CURRENCY_ID", "COUNTRY_ID", "SERVICE_CODE", "CURRENT_BAL", "TOTAL_FLOAT", "RESERVED_BAL", "FUNDIN_PAYOUT", "RESERVED_PAYOUT", "SECURITY_BAL", "AVA_PO", "REMAINING_PO_AMOUNT", "REMAINING_PO_AMOUNT_WITH_FEE", "MERCHANT_AVA_PO", "MERCHANT_AVA_PO_FOR_MOVE", "APPRO_PO_FEE_RATE", "MERCHANT_BAL", "AVA_SETT", "TOTAL_AVA_SETT", "SETT_IN_TRANSIT") AS 
  SELECT DISTINCT
          om_merchant_id,
          om_currency_id,
          om_country_id,
          om_service_code,
          current_bal,
          total_float,
          reserved_bal,
          om_fundin_payout,
          om_reserved_payout,
          security_bal,
          CASE
             WHEN ava_po > current_bal
             THEN
                CASE WHEN current_bal <= 0 THEN 0 ELSE current_bal END
             ELSE
                ava_po
          END
             AS ava_po,
          CASE
             WHEN remaining_po_amount > current_bal
             THEN
                CASE WHEN current_bal <= 0 THEN 0 ELSE current_bal END
             ELSE
                remaining_po_amount
          END
             AS remaining_po_amount,
          CASE
             WHEN remaining_po_amount_with_fee > (current_bal / (1 + rate))
             THEN
                CASE
                   WHEN current_bal <= 0 THEN 0
                   ELSE current_bal / (1 + rate)
                END
             ELSE
                remaining_po_amount_with_fee
          END
             AS remaining_po_amount_with_fee,
          CASE
             WHEN remaining_po_amount_with_fee > (current_bal / (1 + rate))
             THEN
                CASE
                   WHEN current_bal <= 0 THEN 0
                   ELSE (current_bal / (1 + rate)) - req_amt
                END
             ELSE
                remaining_po_amount_with_fee - req_amt
          END
             AS merchant_ava_po,
          CASE
             WHEN (ava_po) > om_fundin_payout
             THEN
                (ava_po - om_fundin_payout)
             ELSE
                0
          END
             AS merchant_ava_po_for_move,
          appro_po_fee_rate,
          merchant_bal,
          ava_sett,
          total_ava_sett,
          sett_in_transit
     FROM (SELECT om_merchant_id,
                  om_currency_id,
                  om_country_id,
                  om_service_code,
                    om_current_bal
                  + om_current_bal_settlement
                  - om_total_hold
                  - om_total_hold_settlement
                  - om_total_reserved_amount
                     AS current_bal,
                  --CASE
                  --   WHEN OMB_TXN_TYPE <> 'D'
                  --   THEN
                  om_total_float_after_payout + om_total_float_settlement
                     --   ELSE
                     --        om_total_float_after_payout
                     --      + om_total_float_settlement
                     --      - om_total_hold
                     --END
                     AS total_float,
                  om_total_reserved_amount AS reserved_bal,
                  om_fundin_payout,
                  om_reserved_payout,
                  om_total_hold + om_total_hold_settlement AS security_bal,
                    --CASE
                    --   WHEN OMB_TXN_TYPE = 'D'
                    --   THEN
                    --      0
                    --   ELSE
                    om_current_bal
                  - om_total_hold
                  - om_total_float_after_payout
                     --END
                     AS ava_po,
                  --CASE
                  --   WHEN OMB_TXN_TYPE = 'D'
                  --   THEN
                  --      0
                  --   ELSE
                  CASE
                     WHEN NVL (omr_reserved_amount, 0) = 0
                     THEN
                        (  om_current_bal
                         - om_total_hold
                         - om_total_float_after_payout)
                     WHEN NVL (omr_remain_reserved_amount, 0) = 0
                     THEN
                        NVL (omr_remain_reserved_amount, 0)
                     WHEN (  om_current_bal
                           - om_total_hold
                           - om_total_float_after_payout) >
                             NVL (omr_remain_reserved_amount, 0)
                     THEN
                        NVL (omr_remain_reserved_amount, 0)
                     ELSE
                        (  om_current_bal
                         - om_total_hold
                         - om_total_float_after_payout)
                  END
                     --END
                     AS remaining_po_amount,
                  --CASE
                  --   WHEN OMB_TXN_TYPE = 'D'
                  --   THEN
                  --      0
                  --   ELSE
                  CASE
                     WHEN NVL (omr_reserved_amount, 0) = 0
                     THEN
                          FLOOR (
                               (  (  om_current_bal
                                   - om_total_hold
                                   - om_total_float_after_payout)
                                / (1 + rate))
                             * 100)
                        / 100
                     WHEN NVL (omr_remain_reserved_amount, 0) = 0
                     THEN
                          FLOOR (
                               (  NVL (omr_remain_reserved_amount, 0)
                                / (1 + rate))
                             * 100)
                        / 100
                     WHEN (  om_current_bal
                           - om_total_hold
                           - om_total_float_after_payout) >
                             NVL (omr_remain_reserved_amount, 0)
                     THEN
                          FLOOR (
                               (  NVL (omr_remain_reserved_amount, 0)
                                / (1 + rate))
                             * 100)
                        / 100
                     ELSE
                          FLOOR (
                               (  (  om_current_bal
                                   - om_total_hold
                                   - om_total_float_after_payout)
                                / (1 + rate))
                             * 100)
                        / 100
                  END
                     --END
                     AS REMAINING_PO_AMOUNT_WITH_FEE,
                  rate * 100 AS appro_po_fee_rate,
                  (om_current_bal + om_current_bal_settlement)
                     AS merchant_bal,
                  (  om_current_bal_settlement
                   - om_total_float_settlement
                   - om_total_hold_settlement
                   - om_total_reserved_amount
                   - om_settlement_in_transit)
                     AS ava_sett,
                  (  om_current_bal_settlement
                   - om_total_float_settlement
                   - om_total_hold_settlement
                   - om_total_reserved_amount)
                     AS total_ava_sett,
                  om_settlement_in_transit AS sett_in_transit,
                  NVL (seb_bal, 0),
                  rate,
                  NVL (req_amt, 0) req_amt,
                  NVL (req_amt_with_fee, 0) req_amt_with_fee
             FROM                                       --ol_merchant_balance,
                  --ol_merchant_bank_acct,
                  --ol_bank_accts,
                  (SELECT DISTINCT om_merchant_Id,
                                   om_currency_id,
                                   om_service_code,
                                   om_country_id,
                                   om_current_bal,
                                   om_current_bal_settlement,
                                   om_total_float_after_payout,
                                   om_total_float_settlement,
                                   om_total_reserved_amount,
                                   om_fundin_payout,
                                   om_reserved_payout,
                                   om_total_hold,
                                   om_total_hold_settlement,
                                   om_settlement_in_transit
                     FROM                                   /*ol_bank_accts,*/
                         ol_merchant_balance /*,
                                             ol_merchant_bank_acct*/
                                            /*WHERE     om_merchant_Id = omb_merchant_id
                                                  AND  om_currency_id = ob_acct_ccy
                                                  AND omb_bank_acct_num = ob_bank_acct_num
                                                  AND omb_int_bank_code = ob_int_bank_code
                                                  AND om_service_code = omb_service_code*/
                  ),
                  --def_bank,
                  (  SELECT s_bank_ccy, SUM (s_bank_bal) AS seb_bal
                       FROM seb_balance
                   GROUP BY s_bank_ccy),
                  (SELECT md_merchant_id,
                          (md_approximate_fee_rate / 100) AS rate
                     FROM ol_merch_detail),
                  (SELECT omr_merchant_id,
                          omr_currency_id,
                          omr_country_id,
                          omr_service_code,
                          omr_reserved_amount,
                          omr_remain_reserved_amount
                     FROM ol_merchant_reserved_amt_view
                    WHERE     omr_type = 'D'
                          AND omr_day_of_week =
                                 (SELECT   TO_NUMBER (
                                              TO_CHAR (
                                                 TO_DATE (sys_val,
                                                          'YYYYMMDD'),
                                                 'D'))
                                         - 1
                                            AS day_of_week
                                    FROM (SELECT sys_val
                                            FROM system_control
                                           WHERE sys_code = 'CTPHDATE'))),
                  (  SELECT req_mid,
                            req_service,
                            req_country,
                            req_ccy,
                            SUM (amount) AS req_amt,
                            SUM (amount_with_fee) AS req_amt_with_fee
                       FROM (  SELECT ouh_merchant_id AS req_mid,
                                      ouh_service_code AS req_service,
                                      oud_country AS req_country,
                                      oud_request_currency AS req_ccy,
                                      SUM (oud_request_amount) AS amount,
                                      SUM (
                                           FLOOR (
                                                (  oud_request_amount
                                                 * (  1
                                                    + (  NVL (
                                                            md_approximate_fee_rate,
                                                            0)
                                                       / 100)))
                                              * 100)
                                         / 100)
                                         AS amount_with_fee
                                 FROM ol_merchant_upload_file_detail,
                                      ol_merchant_upload_file_header,
                                      ol_merch_detail
                                WHERE     oud_batch_id = ouh_batch_id
                                      AND oud_status IN (69, 75)
                                      AND ouh_merchant_id = md_merchant_id
                             GROUP BY ouh_merchant_id,
                                      ouh_service_code,
                                      oud_country,
                                      oud_request_currency
                             UNION ALL
								SELECT oth_merchant_id AS req_mid,
								       oth_service_code AS req_service,
								       otd_txn_country AS req_country,
								       opr_request_currency AS req_ccy,
								       SUM(opr_request_amount) AS amount,
                                       SUM (
                                           FLOOR (
                                                (  opr_request_amount
                                                 * (  1
                                                    + (  NVL (
                                                            md_approximate_fee_rate,
                                                            0)
                                                       / 100)))
                                              * 100)
                                         / 100)
                                         AS amount_with_fee
								FROM ol_payout_request,
								     ol_txn_header,
								     ol_txn_detail,
								     ol_merch_detail
								WHERE opr_txn_id = oth_txn_id
								     AND oth_txn_id = otd_txn_id
								     AND oth_merchant_id = md_merchant_id
								     AND opr_status = 69
								GROUP BY oth_merchant_id,
								         oth_service_code,
								         otd_txn_country,
								         opr_request_currency
                             UNION ALL
                               SELECT oth_merchant_id AS req_mid,
                                      oth_service_code AS req_service,
                                      otd_txn_country AS req_country,
                                      oth_net_ccy AS req_ccy,
                                      SUM (oth_transaction_amount) AS amount,
                                      SUM (oth_transaction_amount)
                                         AS amount_with_fee
                                 FROM ol_txn_header, ol_txn_detail
                                WHERE     oth_txn_code = 'ORF'
                                      AND oth_status = 'P'
                                      AND oth_txn_id = otd_txn_id
                             GROUP BY oth_merchant_id,
                                      oth_service_code,
                                      otd_txn_country,
                                      oth_net_ccy)
                   GROUP BY req_mid,
                            req_service,
                            req_country,
                            req_ccy)
            WHERE     om_merchant_id = omr_merchant_id(+)
                  AND om_currency_id = omr_currency_id(+)
                  AND om_country_id = omr_country_id(+)
                  AND om_service_code = omr_service_code(+)
                  AND om_merchant_id = md_merchant_id(+)
                  AND om_currency_id = s_bank_ccy(+)
                  AND om_merchant_Id = req_mid(+)
                  AND om_service_code = req_service(+)
                  AND om_country_id = req_country(+)
                  AND om_currency_id = req_ccy(+));
