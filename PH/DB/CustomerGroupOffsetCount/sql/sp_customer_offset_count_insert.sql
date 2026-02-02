DROP FUNCTION sp_customer_offset_cnt_insert;

CREATE OR REPLACE FUNCTION sp_customer_offset_cnt_insert (
   in_code            customer_group_offset_count.cgo_code%TYPE,
   in_country_id      customer_group_offset_count.cgo_country_id%TYPE,
   in_channel_code    customer_group_offset_count.cgo_channel_code%TYPE,
   in_service_code    customer_group_offset_count.cgo_service_code%TYPE,
   in_ccy             customer_group_offset_count.cgo_currency_id%TYPE,
   in_counter         customer_group_offset_count.cgo_counter%TYPE,
   in_create_user     customer_group_offset_count.cgo_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN

   /* daily amount */
   UPDATE customer_group_offset_count
      SET cgo_counter = cgo_counter + in_counter,
          cgo_update_user = in_create_user,
          cgo_update_timestamp = SYSDATE
    WHERE     cgo_code = in_code
          AND cgo_country_id = in_country_id
          AND cgo_channel_code = in_channel_code
          AND cgo_service_code = in_service_code
          AND cgo_currency_id = in_ccy
          AND cgo_category = 'AMT';

   IF SQL%ROWCOUNT = 0
   THEN
      INSERT INTO customer_group_offset_count (cgo_code,
                                           cgo_country_id,
                                           cgo_channel_code,
                                           cgo_service_code,
                                           cgo_currency_id,
                                           cgo_category,
                                           cgo_counter,
                                           cgo_create_user,
                                           cgo_create_timestamp,
					   cgo_update_user,
					   cgo_update_timestamp)
           VALUES (in_code,
                   in_country_id,
                   in_channel_code,
                   in_service_code,
                   in_ccy,
                   'AMT',
                   in_counter,
                   in_create_user,
                   SYSDATE,
                   in_create_user,
                   SYSDATE);

      IF SQL%ROWCOUNT = 0
      THEN
         UPDATE customer_group_offset_count
            SET cgo_counter = cgo_counter + in_counter,
                cgo_update_user = in_create_user,
                cgo_update_timestamp = SYSDATE
          WHERE     cgo_code = in_code
                AND cgo_country_id = in_country_id
                AND cgo_channel_code = in_channel_code
                AND cgo_service_code = in_service_code
                AND cgo_currency_id = in_ccy
                AND cgo_category = 'AMT';

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
END sp_customer_offset_cnt_insert;
/
