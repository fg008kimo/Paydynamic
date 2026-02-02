DROP VIEW PSP_LIMIT_MERCHANT_VIEW;

CREATE OR REPLACE FORCE VIEW PSP_LIMIT_MERCHANT_VIEW
(
    CLIENT_ID,
    CLIENT_NAME,
    MERCHANT_ID,
    SHORT_NAME,
    BUSINESS_TYPE,
    PSP_CLIENT_ID,
    PSP_CLIENT_NAME,
    PSP_ID,
    PSP_NAME,
    PSP_REMARK,
    CURRENCY_ID,
    LIMIT,
    REMAINING_LIMIT,
    DEPOSIT_CARD_TYPE,
    PID_GROUP,
    MIN_TRANSACTION_AMOUNT,
    MAX_TRANSACTION_AMOUNT,
    CUSTOMER_SEGMENT,
    CRITERIA_POOL_ID,
    POOL_ID,
    SERVICE_CODE,
    POOL_RATIO,
    POOL_RM_RATIO,
    ALLOW_SPECIAL_REGION,
    CARD_TYPE_OPT
)
AS
      SELECT MERCH_DETAIL.CLIENT_ID               AS CLIENT_ID,
             MERCH_DETAIL.CLIENT_NAME             AS CLIENT_NAME,
             MERCH_DETAIL.MERCHANT_ID             AS MERCHANT_ID,
             MERCH_DETAIL.SHORT_NAME              AS SHORT_NAME,
             MERCH_DETAIL.BUSINESS_TYPE,
             PSP_DETAIL.PSP_CLIENT_ID             AS PSP_CLIENT_ID,
             PSP_DETAIL.PSP_CLIENT_NAME           AS PSP_CLIENT_NAME,
             PSP_DETAIL.PSP_ID                    AS PSP_ID,
             PSP_DETAIL.PSP_NAME                  AS PSP_NAME,
             PSP_DETAIL.PSP_REMARK                AS PSP_REMARK,
             PSP_DETAIL.CURRENCY_ID               AS CURRENCY_ID,
             PSP_DETAIL.LIMIT                     AS LIMIT,
             PSP_DETAIL.REMAINING_LIMIT           AS REMAINING_LIMIT,
             PSP_DETAIL.DEPOSIT_CARD_TYPE         AS DEPOSIT_CARD_TYPE,
             PSP_DETAIL.PID_GROUP                 AS PID_GROUP,
             MERCH_DETAIL.RC_MIN_TRANSACTION_AMOUNT AS MIN_TRANSACTION_AMOUNT,
             MERCH_DETAIL.RC_MAX_TRANSACTION_AMOUNT AS MAX_TRANSACTION_AMOUNT,
             MERCH_DETAIL.RC_CUSTOMER_SEGMENT     AS CUSTOMER_SEGMENT,
             MERCH_DETAIL.RC_CRITERIA_POOL_ID     AS CRITERIA_POOL_ID,
             MERCH_DETAIL.RP_POOL_ID              AS POOL_ID,
             MERCH_DETAIL.RC_SERVICE_CODE         AS SERVICE_CODE,
             MERCH_DETAIL.RP_RATIO                AS POOL_RATIO,
             MERCH_DETAIL.RM_RATIO                AS POOL_RM_RATIO,
             MERCH_DETAIL.RC_ALLOW_SPECIAL_REGION AS ALLOW_SPECIAL_REGION,
             MERCH_DETAIL.RC_CARD_TYPE_OPT        AS ALLOW_CARD_TYPE_OPT
        FROM (  SELECT CLIENT_ID,
                       CLIENT_NAME,
                       MERCHANT_ID,
                       SHORT_NAME,
                       BUSINESS_TYPE,
                       RC_SERVICE_CODE,
                       RC_MIN_TRANSACTION_AMOUNT,
                       RC_MAX_TRANSACTION_AMOUNT,
                       RC_CUSTOMER_SEGMENT,
                       RM_PSP_ID,
                       RC_CRITERIA_POOL_ID,
                       RP_POOL_ID,
                       RP_RATIO,
                       RM_RATIO,
                       RC_ALLOW_SPECIAL_REGION,
                       RC_CARD_TYPE_OPT
                  FROM (SELECT RC_CHANNEL_CODE,
                               RC_SERVICE_CODE,
                               RC_PAYMENT_METHOD,
                               RC_COUNTRY,
                               RC_CCY,
                               RC_PARTY_TYPE,
                               RC_PARTY_ID,
                               RC_BUSINESS_TYPE,
                               RC_CRITERIA_POOL_ID,
                               RC_MIN_TRANSACTION_AMOUNT,
                               RC_MAX_TRANSACTION_AMOUNT,
                               RC_CUSTOMER_SEGMENT,
                               RP_CRITERIA_POOL_ID,
                               RP_POOL_ID,
                               RP_RATIO,
                               RC_ALLOW_SPECIAL_REGION,
                               RC_CARD_TYPE_OPT
                          FROM RULE_PSP_LB_CRITERIA, RULE_PSP_LB_POOLS
                         WHERE     RULE_SCHEDULE_PKG.INRUNNINGPERIOD (
                                       RC_SCHEDULER_ID) =
                                   1
                               AND RC_CRITERIA_POOL_ID = RP_CRITERIA_POOL_ID
                               AND RP_DISABLED = 0
                               AND RC_DISABLED = 0),
                       (SELECT BUSINESS_TYPE,
                               MERCHANT_ID,
                               SHORT_NAME,
                               CLIENTS.CLIENT_ID,
                               CLIENTS.CLIENT_NAME
                          FROM MERCH_DETAIL, CLIENTS
                         WHERE     DISABLED = 0
                               AND MERCH_DETAIL.STATUS = 'O'
                               AND MERCH_DETAIL.CLIENT_ID = CLIENTS.CLIENT_ID
                               AND CLIENTS.STATUS = 'O'),
                       RULE_PSP_LB_MAPPING
                 WHERE     RC_BUSINESS_TYPE = BUSINESS_TYPE
                       AND RP_POOL_ID = RM_POOL_ID
                       AND RM_DISABLED = 0
                       AND (   (RC_PARTY_TYPE = 'M' AND RC_PARTY_ID = MERCHANT_ID)
                            OR (RC_PARTY_TYPE = 'C' AND RC_PARTY_ID = CLIENT_ID)
                            OR (RC_PARTY_TYPE = 'G'))
              GROUP BY CLIENT_ID,
                       CLIENT_NAME,
                       MERCHANT_ID,
                       SHORT_NAME,
                       BUSINESS_TYPE,
                       RC_SERVICE_CODE,
                       RC_MIN_TRANSACTION_AMOUNT,
                       RC_MAX_TRANSACTION_AMOUNT,
                       RC_CUSTOMER_SEGMENT,
                       RM_PSP_ID,
                       RC_CRITERIA_POOL_ID,
                       RP_POOL_ID,
                       RP_RATIO,
                       RM_RATIO,
                       RC_ALLOW_SPECIAL_REGION,
                       RC_CARD_TYPE_OPT) MERCH_DETAIL,
             psp_limit_psp_view PSP_DETAIL
       WHERE     MERCH_DETAIL.RM_PSP_ID = PSP_DETAIL.PSP_ID
             AND (   (    MERCH_DETAIL.RC_CARD_TYPE_OPT = 'C'
                      AND PSP_DETAIL.DEPOSIT_CARD_TYPE <> 'D')
                  OR (    MERCH_DETAIL.RC_CARD_TYPE_OPT = 'D'
                      AND PSP_DETAIL.DEPOSIT_CARD_TYPE <> 'C'))
    ORDER BY CLIENT_NAME,
             SHORT_NAME,
             PSP_CLIENT_NAME,
             PSP_NAME;
