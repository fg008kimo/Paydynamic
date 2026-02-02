CREATE OR REPLACE PACKAGE SEGMENT_LIMIT_CHECK_PKG
IS
   PROCEDURE P_SEGMENT_PSP_LIMIT (
      in_group_code         IN     CUSTOMER_GROUP_LIMIT_CHECK.CLC_GROUP_CODE%TYPE,
      out_cursor            IN OUT SYS_REFCURSOR);

   FUNCTION F_CHECK_FIND (
      in_group_code         IN     CUSTOMER_GROUP_LIMIT_CHECK.CLC_GROUP_CODE%TYPE,
      out_cursor            IN OUT SYS_REFCURSOR)
      RETURN NUMBER;

END SEGMENT_LIMIT_CHECK_PKG;
/
CREATE OR REPLACE PACKAGE BODY SEGMENT_LIMIT_CHECK_PKG
IS
   PROCEDURE P_SEGMENT_PSP_LIMIT (
      in_group_code   IN     CUSTOMER_GROUP_LIMIT_CHECK.CLC_GROUP_CODE%TYPE,
      out_cursor    IN OUT SYS_REFCURSOR)
   IS
   BEGIN
      OPEN out_cursor FOR
           SELECT CLIENT_ID AS CLIENT_ID,
                  CLIENT_NAME AS CLIENT_NAME,
                  MERCHANT_ID AS MERCHANT_ID,
                  SHORT_NAME AS SHORT_NAME,
                  BUSINESS_TYPE AS BUSINESS_TYPE,
                  CURRENCY_ID AS CURRENCY_ID,
		          CUSTOMER_SEGMENT AS CUSTOMER_SEGMENT,
                  MIN_TRANSACTION_AMOUNT,
                  MAX_TRANSACTION_AMOUNT,
                  ALLOW_SPECIAL_REGION,
                  pid_group,
                  SUM (LIMIT) AS LIMIT,
                  SUM (REMAINING_LIMIT) AS REMAINING_LIMIT
             FROM (  SELECT CLIENT_ID,
                            CLIENT_NAME,
                            MERCHANT_ID,
                            SHORT_NAME,
                            BUSINESS_TYPE,
                            CURRENCY_ID,
                            MIN_TRANSACTION_AMOUNT,
                            MAX_TRANSACTION_AMOUNT,
			                CUSTOMER_SEGMENT,
                            ALLOW_SPECIAL_REGION,
                            LIMIT,
                            REMAINING_LIMIT,
                            PSP_ID,
                            pid_group
                       FROM PSP_LIMIT_SEGMENT_PID_VIEW
                   GROUP BY CLIENT_ID,
                            CLIENT_NAME,
                            MERCHANT_ID,
                            SHORT_NAME,
                            BUSINESS_TYPE,
                            CURRENCY_ID,
                            MIN_TRANSACTION_AMOUNT,
                            MAX_TRANSACTION_AMOUNT,
			                CUSTOMER_SEGMENT,
                            ALLOW_SPECIAL_REGION,
                            LIMIT,
                            REMAINING_LIMIT,
                            PSP_ID,
                            pid_group)
            WHERE 1 = 1 AND (CUSTOMER_SEGMENT = in_group_code OR in_group_code IS NULL)
         GROUP BY CLIENT_ID,
                  CLIENT_NAME,
                  MERCHANT_ID,
                  SHORT_NAME,
                  BUSINESS_TYPE,
                  CURRENCY_ID,
		          CUSTOMER_SEGMENT,
                  MIN_TRANSACTION_AMOUNT,
                  MAX_TRANSACTION_AMOUNT,
                  ALLOW_SPECIAL_REGION,
                  pid_group;
   END P_SEGMENT_PSP_LIMIT;


   FUNCTION F_CHECK_FIND (
      in_group_code      IN     CUSTOMER_GROUP_LIMIT_CHECK.CLC_GROUP_CODE%TYPE,
      out_cursor         IN OUT SYS_REFCURSOR)
      RETURN NUMBER
   IS
      iCnt   INTEGER := 0;
   BEGIN
      SELECT COUNT (*)
        INTO iCnt
        FROM CUSTOMER_GROUP_LIMIT_CHECK
       WHERE CLC_GROUP_CODE = in_group_code
         AND CLC_DISABLED = 0;

      IF iCnt > 0
      THEN
         OPEN out_cursor FOR
            SELECT CLC_ALERT_LEVEL,
                   CLC_ALERT_REMAIN_AMT,
                   TO_CHAR (CLC_LAST_CHECKING_TIME, 'YYYYMMDDHH24MISS')
              FROM CUSTOMER_GROUP_LIMIT_CHECK
	      WHERE CLC_GROUP_CODE = in_group_code
	      AND CLC_DISABLED = 0;

         RETURN 1;
      ELSE
         SELECT COUNT (*)
           INTO iCnt
           FROM CUSTOMER_GROUP_LIMIT_CHECK
	   WHERE CLC_GROUP_CODE = '000'
	   AND CLC_DISABLED = 0;

         IF iCnt > 0
         THEN
            OPEN out_cursor FOR
               SELECT CLC_ALERT_LEVEL,
                      CLC_ALERT_REMAIN_AMT,
                      TO_CHAR (CLC_LAST_CHECKING_TIME, 'YYYYMMDDHH24MISS')
                 FROM CUSTOMER_GROUP_LIMIT_CHECK
		 WHERE CLC_GROUP_CODE = '000'
		 AND CLC_DISABLED = 0;

            RETURN 1;
         END IF;
      END IF;

      RETURN 0;
   END F_CHECK_FIND;
END SEGMENT_LIMIT_CHECK_PKG;
/
