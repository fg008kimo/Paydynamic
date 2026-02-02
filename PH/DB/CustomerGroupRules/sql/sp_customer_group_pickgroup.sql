DROP FUNCTION sp_customer_group_pickgroup;

CREATE OR REPLACE FUNCTION sp_customer_group_pickgroup (
   in_merchant_id           customer_group_rules.cgr_merchant_id%TYPE,
   in_country_id            customer_group_counters.cgc_country_id%TYPE,
   in_channel_code          customer_group_counters.cgc_channel_code%TYPE,
   in_service_code          customer_group_counters.cgc_service_code%TYPE,
   in_ccy                   customer_group_counters.cgc_currency_id%TYPE,
   in_date                  customer_group_counters.cgc_date%TYPE,
   in_grp_list              VARCHAR2,
   out_customer_group   OUT customer_group_counters.cgc_code%TYPE)
   RETURN NUMBER
IS
BEGIN
   SELECT code
     INTO out_customer_group
     FROM (  SELECT code
               FROM (  SELECT code, SUM (counter) counter
    FROM (  SELECT SUM (NVL (cgc_counter, 0) + NVL (cgc_delta_changes, 0))
                      AS counter,
                   cgr_group_code code,
                   cgc_country_id country,
                   cgc_channel_code channel,
                   cgc_service_code service,
                   cgc_currency_id ccy
              FROM customer_group_counters,
                   (SELECT cgr_group_code
                      FROM customer_group_rules
                     WHERE     cgr_merchant_id = in_merchant_id
                           AND cgr_from_group_code IS NULL
                           AND cgr_disabled = 0
                           AND cgr_group_code 
                           IN (SELECT REGEXP_SUBSTR (in_grp_list,'[^,]+',1,LEVEL)
                                      token FROM DUAL  CONNECT BY LEVEL <= LENGTH (in_grp_list)
                                                        - LENGTH (REPLACE (in_grp_list,',',''))  + 1)
                           )
             WHERE     cgc_code(+) = cgr_group_code
                   AND cgc_country_id(+) = in_country_id
                   AND cgc_channel_code(+) = in_channel_code
                   AND cgc_service_code(+) = in_service_code
                   AND cgc_currency_id(+) = in_ccy
                   AND cgc_category(+) = 'AMT'
                   AND cgc_date(+) >=
                          TO_CHAR (TO_DATE ( in_date, 'YYYYMMDD') - 29,
                                   'YYYYMMDD')
                   AND cgc_date(+) <= in_date
          GROUP BY cgr_group_code,
                   cgc_country_id,
                   cgc_channel_code,
                   cgc_service_code,
                   cgc_currency_id
          UNION ALL
          SELECT NVL (cgo_counter, 0) counter,
                 cgr_group_code code,
                 cgo_country_id country,
                 cgo_channel_code channel,
                 cgo_service_code service,
                 cgo_currency_id ccy
            FROM customer_group_offset_count,
                 (SELECT cgr_group_code
                    FROM customer_group_rules
                   WHERE     cgr_merchant_id = in_merchant_id
                         AND cgr_from_group_code IS NULL
                         AND cgr_disabled = 0
                         AND cgr_group_code 
                           IN (SELECT REGEXP_SUBSTR (in_grp_list,'[^,]+',1,LEVEL)
                                      token FROM DUAL  CONNECT BY LEVEL <= LENGTH (in_grp_list)
                                                        - LENGTH (REPLACE (in_grp_list,',',''))  + 1)
                         )
           WHERE     cgo_code(+) = cgr_group_code
                 AND cgo_country_id(+) = in_country_id
                 AND cgo_channel_code(+) = in_channel_code
                 AND cgo_service_code(+) = in_service_code
                 AND cgo_currency_id(+) = in_ccy
                 AND cgo_category(+) = 'AMT')
GROUP BY code
               )
              WHERE counter =
                       (SELECT MIN (counter)
                          FROM (  SELECT code, SUM (counter) counter
    FROM (  SELECT SUM (NVL (cgc_counter, 0) + NVL (cgc_delta_changes, 0))
                      AS counter,
                   cgr_group_code code,
                   cgc_country_id country,
                   cgc_channel_code channel,
                   cgc_service_code service,
                   cgc_currency_id ccy
              FROM customer_group_counters,
                   (SELECT cgr_group_code
                      FROM customer_group_rules
                     WHERE     cgr_merchant_id = in_merchant_id
                           AND cgr_from_group_code IS NULL
                           AND cgr_disabled = 0
                           AND cgr_group_code 
                           IN (SELECT REGEXP_SUBSTR (in_grp_list,'[^,]+',1,LEVEL)
                                      token FROM DUAL  CONNECT BY LEVEL <= LENGTH (in_grp_list)
                                                        - LENGTH (REPLACE (in_grp_list,',',''))  + 1)
                           )
             WHERE     cgc_code(+) = cgr_group_code
                   AND cgc_country_id(+) = in_country_id
                   AND cgc_channel_code(+) = in_channel_code
                   AND cgc_service_code(+) = in_service_code
                   AND cgc_currency_id(+) = in_ccy
                   AND cgc_category(+) = 'AMT'
                   AND cgc_date(+) >=
                          TO_CHAR (TO_DATE ( in_date, 'YYYYMMDD') - 29,
                                   'YYYYMMDD')
                   AND cgc_date(+) <= in_date
          GROUP BY cgr_group_code,
                   cgc_country_id,
                   cgc_channel_code,
                   cgc_service_code,
                   cgc_currency_id
          UNION ALL
          SELECT NVL (cgo_counter, 0) counter,
                 cgr_group_code code,
                 cgo_country_id country,
                 cgo_channel_code channel,
                 cgo_service_code service,
                 cgo_currency_id ccy
            FROM customer_group_offset_count,
                 (SELECT cgr_group_code
                    FROM customer_group_rules
                   WHERE     cgr_merchant_id = in_merchant_id
                         AND cgr_from_group_code IS NULL
                         AND cgr_disabled = 0
                         AND cgr_group_code 
                           IN (SELECT REGEXP_SUBSTR (in_grp_list,'[^,]+',1,LEVEL)
                                      token FROM DUAL  CONNECT BY LEVEL <= LENGTH (in_grp_list)
                                                        - LENGTH (REPLACE (in_grp_list,',',''))  + 1)
                         )
           WHERE     cgo_code(+) = cgr_group_code
                 AND cgo_country_id(+) = in_country_id
                 AND cgo_channel_code(+) = in_channel_code
                 AND cgo_service_code(+) = in_service_code
                 AND cgo_currency_id(+) = in_ccy
                 AND cgo_category(+) = 'AMT')
GROUP BY code))
           ORDER BY DBMS_RANDOM.VALUE)
    WHERE ROWNUM = 1;

    return 0;

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_customer_group_pickgroup;
/
