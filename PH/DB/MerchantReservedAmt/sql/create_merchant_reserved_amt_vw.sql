DROP VIEW MERCHANT_RESERVED_AMT_VIEW;

/* Formatted on 8/29/2012 11:19:40 AM (QP5 v5.185.11230.41888) */
CREATE OR REPLACE FORCE VIEW MERCHANT_RESERVED_AMT_VIEW
(
   MR_MERCHANT_ID,
   MR_CURRENCY_ID,
   MR_COUNTRY_ID,
   MR_SERVICE_CODE,
   MR_DAY_OF_WEEK,
   MR_TYPE,
   MR_RESERVED_AMOUNT,
   MR_REMAIN_RESERVED_AMOUNT,
   MR_STATUS,
   MR_EFFECT_DATE,
   MR_APPROVE_USER,
   MR_APPROVE_TIMESTAMP,
   MR_CREATE_TIMESTAMP,
   MR_UPDATE_TIMESTAMP,
   MR_CREATE_USER,
   MR_UPDATE_USER,
   MERCHANT_ID,
   CURRENCY_ID,
   COUNTRY_ID,
   SERVICE_CODE,
   DAY_OF_WEEK,
   EFFECT_DATE,
   AMOUNT_TYPE
)
AS
     SELECT "MR_MERCHANT_ID",
            "MR_CURRENCY_ID",
            "MR_COUNTRY_ID",
            "MR_SERVICE_CODE",
            "MR_DAY_OF_WEEK",
            "MR_TYPE",
            "MR_RESERVED_AMOUNT",
	    "MR_REMAIN_RESERVED_AMOUNT",
            "MR_STATUS",
            "MR_EFFECT_DATE",
            "MR_APPROVE_USER",
            "MR_APPROVE_TIMESTAMP",
            "MR_CREATE_TIMESTAMP",
            "MR_UPDATE_TIMESTAMP",
            "MR_CREATE_USER",
            "MR_UPDATE_USER",
            "MERCHANT_ID",
            "CURRENCY_ID",
            "COUNTRY_ID",
            "SERVICE_CODE",
            "DAY_OF_WEEK",
            "EFFECT_DATE",
            "AMOUNT_TYPE"
       FROM merchant_reserved_amt,
            (  SELECT mr_merchant_id AS merchant_id,
                      mr_currency_id AS currency_id,
                      mr_country_id AS country_id,
                      mr_service_code AS service_code,
                      mr_day_of_week AS day_of_week,
                      MAX (mr_effect_date) AS effect_date,
                      mr_type AS amount_type
                 FROM merchant_reserved_amt
                WHERE mr_status = 'A'
             GROUP BY mr_merchant_id,
                      mr_currency_id,
                      mr_country_id,
                      mr_service_code,
                      mr_day_of_week,
                      mr_type)
      WHERE     mr_merchant_id = merchant_id
            AND mr_currency_id = currency_id
            AND mr_country_id = country_id
            AND mr_service_code = service_code
            AND mr_effect_date = effect_date
            AND mr_day_of_week = day_of_week
            AND mr_type = amount_type
   ORDER BY mr_merchant_id,
            mr_currency_id,
            mr_country_id,
            mr_service_code,
            mr_type,
            mr_day_of_week;

