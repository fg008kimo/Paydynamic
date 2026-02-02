


CREATE OR REPLACE FORCE VIEW PSP_LIMIT_PSP_VIEW
(
   PSP_CLIENT_ID,
   PSP_CLIENT_NAME,
   PSP_ID,
   PSP_NAME,
   PSP_TYPE,
   CURRENCY_ID,
   LIMIT,
   REMAINING_LIMIT,
   PSP_REMARK,
   DEPOSIT_CARD_TYPE
)
AS
     SELECT PM_CLIENT_ID AS PSP_CLIENT_ID,
            PM_CLIENT_NAME AS PSP_CLIENT_NAME,
            RPP_PSP_ID AS PSP_ID,
            PSP_NAME AS PSP_NAME,
            PSP_TYPE AS PSP_TYPE,
            CURRENCY_ID AS CURRENCY_ID,
            RPP_LIMIT AS LIMIT,
            CASE
               WHEN RPP_LIMIT = 0 THEN RPP_LIMIT
               ELSE RPP_LIMIT - NVL (TC_TOTAL_COUNTER, 0)
            END
               AS REMAINING_LIMIT,
            PSP_REMARK,
	    DEPOSIT_CARD_TYPE
       FROM (SELECT PM_CLIENT_ID,
                    PM_CLIENT_NAME,
                    RPP_PSP_ID,
                    PSP_NAME,
                    PSP_TYPE,
                    CURRENCY_ID,
                    RPP_LIMIT,
                    PSP_REMARK,
		    DEPOSIT_CARD_TYPE
               FROM (SELECT RPP_PSP_ID, RPP_LIMIT
                       FROM RULE_PSP_LB_PSP
                      WHERE RPP_DISABLED = 0),
                    (SELECT PM_CLIENT_ID,
                            PM_CLIENT_NAME,
                            PSP_ID,
                            PSP_NAME,
                            PSP_TYPE,
                            CURRENCY_ID,
                            PSP_REMARK,
			    DEPOSIT_CARD_TYPE
                       FROM PSP_DETAIL, PSP_MASTER
                      WHERE     CLIENT_ID = PM_CLIENT_ID
                            AND DISABLED = 0
                            AND ONLINE_MODE = 'Y'
                            AND STATUS = 'O'
                            AND PM_STATUS = 'O')
              WHERE RPP_PSP_ID = PSP_ID)
            LEFT JOIN
            (  SELECT SUM (TC_TOTAL_COUNTER) AS TC_TOTAL_COUNTER,
                      TC_PARTY_ID AS PARTY_PSP_ID
                 FROM TXN_COUNTERS
                WHERE     TC_PARTY_TYPE = 'P'
                      AND TC_CATEGORY = 'AMT'
                      AND TC_TYPE = 'D'
             GROUP BY TC_PARTY_ID)
               ON RPP_PSP_ID = PARTY_PSP_ID
   ORDER BY PSP_CLIENT_NAME, PSP_NAME;

