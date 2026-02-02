DROP FUNCTION sp_customer_offset_log_insert;

CREATE OR REPLACE FUNCTION sp_customer_offset_log_insert (
   in_code            customer_group_offset_log.cgl_code%TYPE,
   in_country_id      customer_group_offset_log.cgl_country_id%TYPE,
   in_channel_code    customer_group_offset_log.cgl_channel_code%TYPE,
   in_service_code    customer_group_offset_log.cgl_service_code%TYPE,
   in_ccy             customer_group_offset_log.cgl_currency_id%TYPE,
   in_adj_value       customer_group_offset_log.cgl_adj_value%TYPE,
   in_create_user     customer_group_offset_log.cgl_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN

      INSERT INTO customer_group_offset_log(cgl_code,
                                           cgl_country_id,
                                           cgl_channel_code,
                                           cgl_service_code,
                                           cgl_currency_id,
                                           cgl_category,
                                           cgl_adj_value,
                                           cgl_create_user,
                                           cgl_create_timestamp,
					   cgl_update_user,
					   cgl_update_timestamp)
           VALUES (in_code,
                   in_country_id,
                   in_channel_code,
                   in_service_code,
                   in_ccy,
                   'AMT',
                   in_adj_value,
                   in_create_user,
                   SYSDATE,
                   in_create_user,
                   SYSDATE);

      IF SQL%ROWCOUNT = 0
      THEN
         RETURN 1;
      END IF;
return 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_customer_offset_log_insert;
/
