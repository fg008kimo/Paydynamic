CREATE OR REPLACE FUNCTION sp_get_next_consumer_url (
   in_merchant_id         service_consumer_url.cu_merchant_id%TYPE,
   in_service_code    	  service_consumer_url.cu_service_code%TYPE,
   in_country         	  service_consumer_url.cu_country%TYPE,
   out_url            OUT service_consumer_url.cu_url%TYPE)
   RETURN NUMBER
IS
   iCnt   INTEGER := 0;
BEGIN
   SELECT COUNT (1)
     INTO iCnt
     FROM (  SELECT cu_merchant_id,
                    cu_service_code,
                    cu_country,
                    cu_url,
                    cu_disabled,
                    cu_priority
               FROM service_consumer_url
              WHERE     cu_merchant_id = in_merchant_id
		    AND	cu_service_code = in_service_code
		    AND cu_country = in_country
                    AND cu_disabled = 1
                    AND cu_effect_date <= SYSDATE
                    AND cu_priority IN (SELECT cu_priority
                                          FROM service_consumer_url
                                         WHERE     cu_merchant_id = in_merchant_id
					       AND cu_service_code = in_service_code
					       AND cu_country = in_country
                                               AND cu_disabled = 1
                                               AND cu_effect_date <= SYSDATE)
                    AND cu_priority >
                           (SELECT cu_priority
                              FROM service_consumer_url
                             WHERE     cu_merchant_id = in_merchant_id
				   AND cu_service_code = in_service_code
				   AND cu_country = in_country
                                   AND cu_disabled = 0
                                   AND cu_effect_date <= SYSDATE)
           ORDER BY cu_priority)
    WHERE ROWNUM = 1;

   IF iCnt > 0
   THEN
      SELECT 
             cu_url
        INTO 
             out_url
        FROM (  SELECT cu_merchant_id,
                       cu_service_code,
                       cu_country,
                       cu_url,
                       cu_disabled,
                       cu_priority
                  FROM service_consumer_url
                 WHERE     cu_merchant_id = in_merchant_id
		       AND cu_service_code = in_service_code
		       AND cu_country = in_country
                       AND cu_disabled = 1
                       AND cu_effect_date <= SYSDATE
                       AND cu_priority IN (SELECT cu_priority
                                             FROM service_consumer_url
                                            WHERE     cu_merchant_id = in_merchant_id
					          AND cu_service_code = in_service_code
					          AND cu_country = in_country
                                                  AND cu_disabled = 1
                                                  AND cu_effect_date <= SYSDATE)
                       AND cu_priority >
                              (SELECT cu_priority
                                 FROM service_consumer_url
                                WHERE     cu_merchant_id = in_merchant_id
				      AND cu_service_code = in_service_code
				      AND cu_country = in_country
                                      AND cu_disabled = 0
                                      AND cu_effect_date <= SYSDATE)
              ORDER BY cu_priority)
       WHERE ROWNUM = 1;

      RETURN 1;
   ELSE
      RETURN 0;
   END IF;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 0;
END sp_get_next_consumer_url;
/
