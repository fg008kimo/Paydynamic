DROP VIEW OL_PAYOUT_FILE_SUMMARY_VIEW;

/* Formatted on 2/24/2014 6:06:05 PM (QP5 v5.252.13127.32867) */
CREATE OR REPLACE FORCE VIEW OL_PAYOUT_FILE_SUMMARY_VIEW
(
   OUH_BATCH_ID,
   OUH_MERCHANT_ID,
   OUH_SERVICE_CODE,
   OUH_FILENAME,
   OUH_TXN_COUNT,
   OUH_TOTAL_TXN_AMT,
   APPROVED_COUNT,
   APPROVED_AMOUNT,
   APPROVED_CURRENCY,
   REVERSED_COUNT,
   REVERSED_AMOUNT,
   REVERSED_CURRENCY,
   REFUNDED_COUNT,
   REFUNDED_AMOUNT,
   REFUNDED_CURRENCY,
   CANCELLED_COUNT,
   CANCELLED_AMOUNT,
   CANCELLED_CURRENCY,
   DECLINED_COUNT,
   DECLINED_AMOUNT,
   DECLINED_CURRENCY,
   CONFIRMED_COUNT,
   CONFIRMED_AMOUNT,
   CONFIRMED_CURRENCY,
   GENERATED_COUNT,
   GENERATED_AMOUNT,
   GENERATED_CURRENCY,
   UPLOADED_COUNT,
   UPLOADED_AMOUNT,
   UPLOADED_CURRENCY,
   UPDATE_TIMESTAMP,
   REQ_CURRENCY
)
AS
     SELECT ouh_batch_id,
            ouh_merchant_id,
            ouh_service_code,
            ouh_filename,
            ouh_txn_count,
            ouh_total_txn_amt,
            NVL (detail_65.counts, 0) AS approved_count,
            NVL (detail_65.amount, 0) AS approved_amount,
            detail_65.oud_request_currency AS approved_currency,
            NVL (detail_66.counts, 0) AS reversed_count,
            NVL (detail_66.amount, 0) AS reversed_amount,
            detail_66.oud_request_currency AS reversed_currency,
            NVL (detail_66_123.counts, 0) AS refunded_count,
            NVL (detail_66_123.amount, 0) AS refunded_amount,
            detail_66_123.oud_request_currency AS refunded_currency,
            NVL (detail_67.counts, 0) AS cancelled_count,
            NVL (detail_67.amount, 0) AS cancelled_amount,
            detail_67.oud_request_currency AS cancelled_currency,
            NVL (detail_68.counts, 0) AS declined_count,
            NVL (detail_68.amount, 0) AS declined_amount,
            detail_68.oud_request_currency AS declined_currency,
            NVL (detail_69.counts, 0) AS confirmed_count,
            NVL (detail_69.amount, 0) AS confirmed_amount,
            detail_69.oud_request_currency AS confirmed_currency,
            NVL (detail_70.counts, 0) + NVL (detail_78.counts, 0)
               AS generated_count,
            NVL (detail_70.amount, 0) + NVL (detail_78.amount, 0)
               AS generated_amount,
            detail_70.oud_request_currency AS generated_currency,
            NVL (detail_75.counts, 0) AS uploaded_count,
            NVL (detail_75.amount, 0) AS uploaded_amount,
            detail_75.oud_request_currency AS uploaded_currency,
            NVL (time.timestamp,
                 ol_merchant_upload_file_header.ouh_update_timestamp)
               AS update_timestamp,
            req_currency
       FROM ol_merchant_upload_file_header,
            (  SELECT oud_batch_id, MAX (oud_update_timestamp) AS TIMESTAMP
                 FROM ol_merchant_upload_file_detail
             GROUP BY oud_batch_id) TIME,
            (  SELECT oud_batch_id, oud_request_currency AS req_currency
                 FROM ol_merchant_upload_file_detail
             GROUP BY oud_batch_id, oud_request_currency) ccy,
            (SELECT oud_batch_id,
                    counts,
                    amount,
                    oud_request_currency,
                    oud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT oud_batch_id,
                              COUNT (*) AS counts,
                              SUM (oud_request_amount) AS amount,
                              oud_status,
                              oud_request_currency
                         FROM ol_merchant_upload_file_detail
                        WHERE oud_status = 65
                     GROUP BY oud_batch_id, oud_status, oud_request_currency)
              WHERE dp_status_id = oud_status) detail_65,
            (SELECT oud_batch_id,
                    counts,
                    amount,
                    oud_request_currency,
                    oud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT oud_batch_id,
                              COUNT (*) AS counts,
                              SUM (oud_request_amount) AS amount,
                              oud_status,
                              oud_request_currency
                         FROM ol_merchant_upload_file_detail
                        WHERE oud_status = 66
                     GROUP BY oud_batch_id, oud_status, oud_request_currency)
              WHERE dp_status_id = oud_status) detail_66,
            (SELECT oud_batch_id,
                    counts,
                    amount,
                    oud_request_currency,
                    oud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT oud_batch_id,
                              COUNT (*) AS counts,
                              SUM (oud_request_amount) AS amount,
                              oud_status,
                              oud_request_currency
                         FROM ol_merchant_upload_file_detail
                              INNER JOIN ol_txn_header
                                 ON ol_txn_header.oth_txn_id =
                                       ol_merchant_upload_file_detail.oud_txn_id
                        WHERE oud_status = 66 AND oth_sub_status = 123
                     GROUP BY oud_batch_id, oud_status, oud_request_currency)
              WHERE dp_status_id = oud_status) detail_66_123,
            (SELECT oud_batch_id,
                    counts,
                    amount,
                    oud_request_currency,
                    oud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT oud_batch_id,
                              COUNT (*) AS counts,
                              SUM (oud_request_amount) AS amount,
                              oud_status,
                              oud_request_currency
                         FROM ol_merchant_upload_file_detail
                        WHERE oud_status = 67
                     GROUP BY oud_batch_id, oud_status, oud_request_currency)
              WHERE dp_status_id = oud_status) detail_67,
            (SELECT oud_batch_id,
                    counts,
                    amount,
                    oud_request_currency,
                    oud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT oud_batch_id,
                              COUNT (*) AS counts,
                              SUM (oud_request_amount) AS amount,
                              oud_status,
                              oud_request_currency
                         FROM ol_merchant_upload_file_detail
                        WHERE oud_status = 68
                     GROUP BY oud_batch_id, oud_status, oud_request_currency)
              WHERE dp_status_id = oud_status) detail_68,
            (SELECT oud_batch_id,
                    counts,
                    amount,
                    oud_request_currency,
                    oud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT oud_batch_id,
                              COUNT (*) AS counts,
                              SUM (oud_request_amount) AS amount,
                              oud_status,
                              oud_request_currency
                         FROM ol_merchant_upload_file_detail
                        WHERE oud_status = 69
                     GROUP BY oud_batch_id, oud_status, oud_request_currency)
              WHERE dp_status_id = oud_status) detail_69,
            (SELECT oud_batch_id,
                    counts,
                    amount,
                    oud_request_currency,
                    oud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT oud_batch_id,
                              COUNT (*) AS counts,
                              SUM (oud_request_amount) AS amount,
                              oud_status,
                              oud_request_currency
                         FROM ol_merchant_upload_file_detail
                        WHERE oud_status = 70
                     GROUP BY oud_batch_id, oud_status, oud_request_currency)
              WHERE dp_status_id = oud_status) detail_70,
            (SELECT oud_batch_id,
                    counts,
                    amount,
                    oud_request_currency,
                    oud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT oud_batch_id,
                              COUNT (*) AS counts,
                              SUM (oud_request_amount) AS amount,
                              oud_status,
                              oud_request_currency
                         FROM ol_merchant_upload_file_detail
                        WHERE oud_status = 75
                     GROUP BY oud_batch_id, oud_status, oud_request_currency)
              WHERE dp_status_id = oud_status) detail_75,
            (SELECT oud_batch_id,
                    counts,
                    amount,
                    oud_request_currency,
                    oud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT oud_batch_id,
                              COUNT (*) AS counts,
                              SUM (oud_request_amount) AS amount,
                              oud_status,
                              oud_request_currency
                         FROM ol_merchant_upload_file_detail
                        WHERE oud_status = 78
                     GROUP BY oud_batch_id, oud_status, oud_request_currency)
              WHERE dp_status_id = oud_status) detail_78
      WHERE     ouh_batch_id = detail_65.oud_batch_id(+)
            AND ouh_batch_id = detail_66.oud_batch_id(+)
            AND ouh_batch_id = detail_66_123.oud_batch_id(+)
            AND ouh_batch_id = detail_67.oud_batch_id(+)
            AND ouh_batch_id = detail_68.oud_batch_id(+)
            AND ouh_batch_id = detail_69.oud_batch_id(+)
            AND ouh_batch_id = detail_70.oud_batch_id(+)
            AND ouh_batch_id = detail_75.oud_batch_id(+)
            AND ouh_batch_id = detail_78.oud_batch_id(+)
            AND ouh_batch_id = time.oud_batch_id(+)
            AND ouh_batch_id = ccy.oud_batch_id(+)
   ORDER BY ouh_batch_id;

