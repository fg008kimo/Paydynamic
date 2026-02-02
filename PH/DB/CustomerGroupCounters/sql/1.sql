DROP FUNCTION SP_CUSTOMER_GRP_CNT_INSERT;

CREATE OR REPLACE FUNCTION sp_customer_grp_cnt_insert (
   in_code            customer_group_counters.cgc_code%TYPE,
   in_country_id      customer_group_counters.cgc_country_id%TYPE,
   in_channel_code    customer_group_counters.cgc_channel_code%TYPE,
   in_service_code    customer_group_counters.cgc_service_code%TYPE,
   in_ccy             customer_group_counters.cgc_currency_id%TYPE,
   in_month           customer_group_counters.cgc_month%TYPE,
   in_counter         customer_group_counters.cgc_counter%TYPE,
   in_create_user     customer_group_counters.cgc_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN

      INSERT INTO customer_group_counters (cgc_code,
                                           cgc_country_id,
                                           cgc_channel_code,
                                           cgc_service_code,
                                           cgc_category,
                                           cgc_currency_id,
                                           cgc_counter,
                                           cgc_create_user,
                                           cgc_create_timestamp)
           VALUES (in_code,
                   in_country_id,
                   in_channel_code,
                   in_service_code,
                   'AMT',
                   in_ccy,
                   in_counter,
                   in_create_user,
                   SYSDATE);


         IF SQL%ROWCOUNT = 0
         THEN
            RETURN 1;
         END IF;

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_customer_grp_cnt_insert;
/

