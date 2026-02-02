DROP FUNCTION SP_CUSTOMER_GRP_CNT_INSERT;

CREATE OR REPLACE FUNCTION sp_customer_grp_cnt_insert (
   in_code            customer_group_counters.cgc_code%TYPE,
   in_country_id      customer_group_counters.cgc_country_id%TYPE,
   in_channel_code    customer_group_counters.cgc_channel_code%TYPE,
   in_service_code    customer_group_counters.cgc_service_code%TYPE,
   in_ccy             customer_group_counters.cgc_currency_id%TYPE,
   in_date           customer_group_counters.cgc_date%TYPE,
   in_counter         customer_group_counters.cgc_counter%TYPE,
   in_create_user     customer_group_counters.cgc_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN

   /* daily amount */
   UPDATE customer_group_counters
      SET cgc_counter = cgc_counter + in_counter,
          cgc_update_user = in_create_user,
          cgc_update_timestamp = SYSDATE
    WHERE     cgc_code = in_code
          AND cgc_country_id = in_country_id
          AND cgc_channel_code = in_channel_code
          AND cgc_service_code = in_service_code
          AND cgc_currency_id = in_ccy
	  AND cgc_date = in_date
          AND cgc_category = 'AMT';

   IF SQL%ROWCOUNT = 0
   THEN
      INSERT INTO customer_group_counters (cgc_code,
                                           cgc_country_id,
                                           cgc_channel_code,
                                           cgc_service_code,
                                           cgc_currency_id,
					   cgc_date,
                                           cgc_category,
                                           cgc_counter,
                                           cgc_create_user,
                                           cgc_create_timestamp)
           VALUES (in_code,
                   in_country_id,
                   in_channel_code,
                   in_service_code,
                   in_ccy,
		   in_date,
                   'AMT',
                   in_counter,
                   in_create_user,
                   SYSDATE);

      IF SQL%ROWCOUNT = 0
      THEN
         UPDATE customer_group_counters
            SET cgc_counter = cgc_counter + in_counter,
                cgc_update_user = in_create_user,
                cgc_update_timestamp = SYSDATE
          WHERE     cgc_code = in_code
                AND cgc_country_id = in_country_id
                AND cgc_channel_code = in_channel_code
                AND cgc_service_code = in_service_code
                AND cgc_currency_id = in_ccy
		AND cgc_date = in_date
                AND cgc_category = 'AMT';

         IF SQL%ROWCOUNT = 0
         THEN
            RETURN 1;
         END IF;
      END IF;
   END IF;
return 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_customer_grp_cnt_insert;
/

