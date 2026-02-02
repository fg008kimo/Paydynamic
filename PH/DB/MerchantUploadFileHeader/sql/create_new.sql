DROP VIEW PHUSER.PAYOUT_FILE_SUMMARY_VIEW;

/* Formatted on 8/24/2012 11:02:22 AM (QP5 v5.185.11230.41888) */
CREATE OR REPLACE FORCE VIEW PHUSER.PAYOUT_FILE_SUMMARY_VIEW
(
   UH_BATCH_ID,
   UH_MERCHANT_ID,
   UH_SERVICE_CODE,
   UH_FILENAME,
   UH_TXN_COUNT,
   UH_TOTAL_TXN_AMT,
   APPROVED_COUNT,
   APPROVED_AMOUNT,
   APPROVED_CURRENCY,
   REVERSED_COUNT,
   REVERSED_AMOUNT,
   REVERSED_CURRENCY,
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
   UPDATE_TIMESTAMP
)
AS
     SELECT uh_batch_id,
            uh_merchant_id,
            uh_service_code,
            uh_filename,
            uh_txn_count,
            uh_total_txn_amt,
            NVL (detail_65.counts, 0) AS approved_count,
            NVL (detail_65.amount, 0) AS approved_amount,
            detail_65.ud_request_currency AS approved_currency,
            NVL (detail_66.counts, 0) AS reversed_count,
            NVL (detail_66.amount, 0) AS reversed_amount,
            detail_66.ud_request_currency AS reversed_currency,
            NVL (detail_67.counts, 0) AS cancelled_count,
            NVL (detail_67.amount, 0) AS cancelled_amount,
            detail_67.ud_request_currency AS cancelled_currency,
            NVL (detail_68.counts, 0) AS declined_count,
            NVL (detail_68.amount, 0) AS declined_amount,
            detail_68.ud_request_currency AS declined_currency,
            NVL (detail_69.counts, 0) AS confirmed_count,
            NVL (detail_69.amount, 0) AS confirmed_amount,
            detail_69.ud_request_currency AS confirmed_currency,
            NVL (detail_70.counts, 0) AS generated_count,
            NVL (detail_70.amount, 0) AS generated_amount,
            detail_70.ud_request_currency AS generated_currency,
            NVL (detail_75.counts, 0) AS uploaded_count,
            NVL (detail_75.amount, 0) AS uploaded_amount,
            detail_75.ud_request_currency AS uploaded_currency,
	    time.timestamp AS update_timestamp
       FROM merchant_upload_file_header,
	    (select ud_batch_id,
        	    max(ud_update_timestamp) as timestamp
	     from    merchant_upload_file_detail
	     GROUP BY ud_batch_id) time,
            (SELECT ud_batch_id,
                    counts,
                    amount,
                    ud_request_currency,
                    ud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT ud_batch_id,
                              COUNT (*) AS counts,
                              SUM (ud_request_amount) AS amount,
                              ud_status,
                              ud_request_currency
                         FROM merchant_upload_file_detail
                        WHERE ud_status = 65
                     GROUP BY ud_batch_id, ud_status, ud_request_currency)
              WHERE dp_status_id = ud_status) detail_65,
            (SELECT ud_batch_id,
                    counts,
                    amount,
                    ud_request_currency,
                    ud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT ud_batch_id,
                              COUNT (*) AS counts,
                              SUM (ud_request_amount) AS amount,
                              ud_status,
                              ud_request_currency
                         FROM merchant_upload_file_detail
                        WHERE ud_status = 66
                     GROUP BY ud_batch_id, ud_status, ud_request_currency)
              WHERE dp_status_id = ud_status) detail_66,
            (SELECT ud_batch_id,
                    counts,
                    amount,
                    ud_request_currency,
                    ud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT ud_batch_id,
                              COUNT (*) AS counts,
                              SUM (ud_request_amount) AS amount,
                              ud_status,
                              ud_request_currency
                         FROM merchant_upload_file_detail
                        WHERE ud_status = 67
                     GROUP BY ud_batch_id, ud_status, ud_request_currency)
              WHERE dp_status_id = ud_status) detail_67,
	    (SELECT ud_batch_id,
                    counts,
                    amount,
                    ud_request_currency,
                    ud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT ud_batch_id,
                              COUNT (*) AS counts,
                              SUM (ud_request_amount) AS amount,
                              ud_status,
                              ud_request_currency
                         FROM merchant_upload_file_detail
                        WHERE ud_status = 68
                     GROUP BY ud_batch_id, ud_status, ud_request_currency)
              WHERE dp_status_id = ud_status) detail_68,
            (SELECT ud_batch_id,
                    counts,
                    amount,
                    ud_request_currency,
                    ud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT ud_batch_id,
                              COUNT (*) AS counts,
                              SUM (ud_request_amount) AS amount,
                              ud_status,
                              ud_request_currency
                         FROM merchant_upload_file_detail
                        WHERE ud_status = 69
                     GROUP BY ud_batch_id, ud_status, ud_request_currency)
              WHERE dp_status_id = ud_status) detail_69,
            (SELECT ud_batch_id,
                    counts,
                    amount,
                    ud_request_currency,
                    ud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT ud_batch_id,
                              COUNT (*) AS counts,
                              SUM (ud_request_amount) AS amount,
                              ud_status,
                              ud_request_currency
                         FROM merchant_upload_file_detail
                        WHERE ud_status = 70
                     GROUP BY ud_batch_id, ud_status, ud_request_currency)
              WHERE dp_status_id = ud_status) detail_70,
            (SELECT ud_batch_id,
                    counts,
                    amount,
                    ud_request_currency,
                    ud_status,
                    dp_desc
               FROM def_payout_batch_status,
                    (  SELECT ud_batch_id,
                              COUNT (*) AS counts,
                              SUM (ud_request_amount) AS amount,
                              ud_status,
                              ud_request_currency
                         FROM merchant_upload_file_detail
                        WHERE ud_status = 75
                     GROUP BY ud_batch_id, ud_status, ud_request_currency)
              WHERE dp_status_id = ud_status) detail_75
      WHERE     uh_batch_id = detail_65.ud_batch_id(+)
            AND uh_batch_id = detail_66.ud_batch_id(+)
            AND uh_batch_id = detail_67.ud_batch_id(+)
            AND uh_batch_id = detail_68.ud_batch_id(+)
            AND uh_batch_id = detail_69.ud_batch_id(+)
            AND uh_batch_id = detail_70.ud_batch_id(+)
            AND uh_batch_id = detail_75.ud_batch_id(+)
	    AND uh_batch_id = time.ud_batch_id(+)
   ORDER BY uh_batch_id;

