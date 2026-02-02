DROP VIEW OFFLINE_SETTLEMENT_VIEW;

/* Formatted on 4/2/2013 7:53:13 PM (QP5 v5.240.12305.39476) */
CREATE OR REPLACE FORCE VIEW OFFLINE_SETTLEMENT_VIEW
(
   OUT_ID,
   OUT_CODE,
   OUT_DATE,
   COUNTRY,
   OUT_CCY,
   OUT_AMT,
   IN_ID,
   IN_CODE,
   IN_CCY,
   IN_AMT,
   OUT_STATUS,
   OUT_SUB_STATUS,
   IN_REMARK,
   IN_TIMESTAMP,
   CAN_VOID
)
AS
     SELECT vw.out_id,
            vw.out_code,
            vw.out_date,
            vw.country,
            vw.out_ccy,
            vw.out_amt,
            --vw.out_remark,
            --vw.out_timestamp,
            vw.in_id,
            vw.in_code,
            --vw.in_date,
            vw.in_ccy,
            vw.in_amt,
            vw.out_status,
            vw.out_sub_status,
            vw.in_remark,
            vw.in_timestamp,
            MAX.can_void
       FROM OFFLINE_SETTLEMENT_TMP_VIEW vw
            LEFT JOIN
            (  SELECT out_ccy,
                      in_ccy,
                      MAX (in_timestamp) timestamp,
                      1 AS can_void
                 FROM (SELECT out_id,
                              out_code,
                              out_ccy,
                              in_id,
                              in_code,
                              in_ccy,
                              in_timestamp
                         FROM OFFLINE_SETTLEMENT_TMP_VIEW
                        WHERE     out_status = 'Approved'
                              AND out_sub_status = 'Approved'
                       UNION
                       SELECT out_id,
                              out_code,
                              out_ccy,
                              in_id,
                              in_code,
                              in_ccy,
                              in_timestamp
                         FROM psp_settle_deliver_tmp_view
                        WHERE     out_status = 'Approved'
                              AND out_sub_status = 'Delivered')
             GROUP BY out_ccy, in_ccy) MAX
               ON     MAX.out_ccy = vw.out_ccy
                  AND MAX.in_ccy = vw.in_ccy
                  AND MAX.timestamp = vw.in_timestamp
   ORDER BY vw.in_timestamp DESC;

