CREATE OR REPLACE FUNCTION sp_rule_lb_get_custgrp (
   in_merchant_id        MERCH_DETAIL.MERCHANT_ID%TYPE,
   in_service_code       RULE_PSP_LB_CRITERIA.RC_SERVICE_CODE%TYPE,
   in_ccy                RULE_PSP_LB_CRITERIA.RC_CCY%TYPE,
   in_bank_code          bank_mapping.bm_int_bank_code%TYPE,
   out_cursor        OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
BEGIN
   OPEN out_cursor FOR

  SELECT rc_customer_segment
    FROM (SELECT rc_customer_segment,
                 rm_psp_id,
                 psp_name,
                 currency_id,
                 rpp_limit,
                 remaining_limit,
                 bm_int_bank_code,
                 rb_scheduler_id,
                 NVL (disabled_now, 0) disabled_now
            FROM (SELECT rc_customer_segment,
                         rm_psp_id,
                         psp_name,
                         currency_id,
                         rpp_limit,
                         remaining_limit,
                         bm_int_bank_code,
                         client_id
                    FROM (  SELECT rc_customer_segment, rm_psp_id
                              FROM (SELECT rc_party_id,
                                           rc_customer_segment,
                                           rp_pool_id,
                                           rc_business_type
                                      FROM rule_psp_lb_criteria,
                                           rule_psp_lb_pools
                                     WHERE     rc_criteria_pool_id =
                                                  rp_criteria_pool_id
                                           AND rc_disabled = 0
                                           AND rp_disabled = 0
                                           AND rc_customer_segment IS NOT NULL
                                           AND rc_party_id = in_merchant_id
                                           AND rc_service_code = in_service_code
                                           AND rc_ccy = in_ccy),
                                   (SELECT business_type
                                      FROM merch_detail, clients
                                     WHERE     merchant_id = in_merchant_id
                                           AND disabled = 0
                                           AND merch_detail.status = 'O'
                                           AND merch_detail.client_id =
                                                  clients.client_id
                                           AND clients.status = 'O'),
                                   (SELECT rm_pool_id, rm_psp_id
                                      FROM rule_psp_lb_mapping
                                     WHERE rm_disabled = 0)
                             WHERE     rp_pool_id = rm_pool_id
                                   AND rc_business_type = business_type
                          GROUP BY rc_customer_segment, rm_psp_id),
                         (SELECT psp_name,
                                 client_id,
                                 psp_channel_code,
                                 overrided_bank_code_channel,
                                 rpp_psp_id,
                                 currency_id,
                                 rpp_limit,
                                 CASE
                                    WHEN rpp_limit = 0 THEN rpp_limit
                                    ELSE rpp_limit - NVL (tc_total_counter, 0)
                                 END
                                    AS remaining_limit
                            FROM (SELECT rpp_psp_id,
                                         currency_id,
                                         rpp_limit,
                                         client_id,
                                         psp_name,
                                         psp_channel_code,
                                         overrided_bank_code_channel
                                    FROM (SELECT rpp_psp_id, rpp_limit
                                            FROM rule_psp_lb_psp
                                           WHERE rpp_disabled = 0),
                                         (SELECT PSP_ID AS r_psp_id,
                                                 currency_id,
                                                 client_id,
                                                 psp_name,
                                                 psp_channel_code,
                                                 overrided_bank_code_channel
                                            FROM psp_detail, psp_master
                                           WHERE     client_id = pm_client_id
                                                 AND disabled = 0
                                                 AND online_mode = 'Y'
                                                 AND status = 'O'
                                                 AND pm_status = 'O')
                                   WHERE rpp_psp_id = r_psp_id)
                                 LEFT JOIN
                                 (  SELECT SUM (tc_total_counter)
                                              AS tc_total_counter,
                                           tc_party_id AS party_psp_id
                                      FROM txn_counters
                                     WHERE     tc_party_type = 'P'
                                           AND tc_category = 'AMT'
                                           AND tc_type = 'D'
                                  GROUP BY tc_party_id)
                                    ON rpp_psp_id = party_psp_id),
                         (SELECT bm_psp_channel_id, bm_int_bank_code
                            FROM bank_mapping
                           WHERE     BANK_MAPPING.bm_disabled = 0
                                 AND BANK_MAPPING.bm_int_bank_code =
                                        in_bank_code)
                   WHERE     rm_psp_id = rpp_psp_id
                         AND (   (    overrided_bank_code_channel IS NOT NULL
                                  AND bm_psp_channel_id =
                                         overrided_bank_code_channel)
                              OR (    overrided_bank_code_channel IS NULL
                                  AND bm_psp_channel_id = psp_channel_code)))
                 LEFT JOIN
                 (SELECT rb_bank_code,
                         rb_type,
                         rb_party_id,
                         rb_scheduler_id,
                         rb_note_id,
                         1 disabled_now
                    FROM rule_disabled_bank
                   WHERE     rb_disabled = 0
                         AND RULE_TXN_LIMIT_PKG.FINDSCHEDULE (rb_scheduler_id) = 1
                         AND rb_channel_code = 'WEB'
                         AND rb_type IN ('C', 'P'))
                    ON     rb_bank_code = bm_int_bank_code
                       AND (   (rb_type = 'C' AND rb_party_id = client_id)
                            OR (rb_type = 'P' AND rb_party_id = rm_psp_id))
           --WHERE remaining_limit > 0
           )
   WHERE disabled_now = 0
GROUP BY rc_customer_segment;
                        




   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_rule_lb_get_custgrp;
/
