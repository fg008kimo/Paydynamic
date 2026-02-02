DROP VIEW OL_MERCHANT_RESERVED_AMT_VIEW;

/* Formatted on 8/29/2012 11:19:40 AM (QP5 v5.185.11230.41888) */
CREATE OR REPLACE FORCE VIEW OL_MERCHANT_RESERVED_AMT_VIEW
(
   OMR_MERCHANT_ID,
   OMR_CURRENCY_ID,
   OMR_COUNTRY_ID,
   OMR_SERVICE_CODE,
   OMR_DAY_OF_WEEK,
   OMR_TYPE,
   OMR_RESERVED_AMOUNT,
   OMR_REMAIN_RESERVED_AMOUNT,
   OMR_STATUS,
   OMR_EFFECT_DATE,
   OMR_APPROVE_USER,
   OMR_APPROVE_TIMESTAMP,
   OMR_CREATE_TIMESTAMP,
   OMR_UPDATE_TIMESTAMP,
   OMR_CREATE_USER,
   OMR_UPDATE_USER,
   MERCHANT_ID,
   CURRENCY_ID,
   COUNTRY_ID,
   SERVICE_CODE,
   DAY_OF_WEEK,
   EFFECT_DATE,
   AMOUNT_TYPE
)
AS
     SELECT "OMR_MERCHANT_ID",
            "OMR_CURRENCY_ID",
            "OMR_COUNTRY_ID",
            "OMR_SERVICE_CODE",
            "OMR_DAY_OF_WEEK",
            "OMR_TYPE",
            "OMR_RESERVED_AMOUNT",
	    "OMR_REMAIN_RESERVED_AMOUNT",
            "OMR_STATUS",
            "OMR_EFFECT_DATE",
            "OMR_APPROVE_USER",
            "OMR_APPROVE_TIMESTAMP",
            "OMR_CREATE_TIMESTAMP",
            "OMR_UPDATE_TIMESTAMP",
            "OMR_CREATE_USER",
            "OMR_UPDATE_USER",
            "MERCHANT_ID",
            "CURRENCY_ID",
            "COUNTRY_ID",
            "SERVICE_CODE",
            "DAY_OF_WEEK",
            "EFFECT_DATE",
            "AMOUNT_TYPE"
       FROM ol_merchant_reserved_amt,
            (  SELECT omr_merchant_id AS merchant_id,
                      omr_currency_id AS currency_id,
                      omr_country_id AS country_id,
                      omr_service_code AS service_code,
                      omr_day_of_week AS day_of_week,
                      MAX (omr_effect_date) AS effect_date,
                      omr_type AS amount_type
                 FROM ol_merchant_reserved_amt
                WHERE omr_status = 'A'
             GROUP BY omr_merchant_id,
                      omr_currency_id,
                      omr_country_id,
                      omr_service_code,
                      omr_day_of_week,
                      omr_type)
      WHERE     omr_merchant_id = merchant_id
            AND omr_currency_id = currency_id
            AND omr_country_id = country_id
            AND omr_service_code = service_code
            AND omr_effect_date = effect_date
            AND omr_day_of_week = day_of_week
            AND omr_type = amount_type
   ORDER BY omr_merchant_id,
            omr_currency_id,
            omr_country_id,
            omr_service_code,
            omr_type,
            omr_day_of_week;

