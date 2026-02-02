DROP VIEW PSP_RECON_VIEW;

/* Formatted on 4/2/2013 7:53:41 PM (QP5 v5.240.12305.39476) */
CREATE OR REPLACE FORCE VIEW PSP_RECON_VIEW
(
   PSP_TXN_DATE,
   RECON_DATE,
   PR_RECON_DATE,
   PR_ID,
   TP_PSP_ID,
   PSP_NAME,
   TD_TXN_COUNTRY,
   COUNTRY_NAME,
   TP_TXN_CCY,
   TOTAL_TXN_AMT,
   TOTAL_FEE_AMT,
   TXN_COUNT,
   MATCH_COUNT,
   RECON_COUNT,
   RECON_AMOUNT,
   DM_COUNT,
   DM_AMOUNT,
   M_PSP_COUNT,
   M_PH_COUNT,
   M_MERCHANT_COUNT,
   MM_COUNT,
   RE_M_COUNT,
   RE_M_AMOUNT
)
AS
     SELECT d.t_date psp_txn_date,
            rh.pr_create_timestamp recon_date,
            rh.pr_recon_date,
            rh.pr_id,
            dt.tp_psp_id,
            dt.psp_name,
            dt.country td_txn_country,
            dt.country_name,
            dt.tp_txn_ccy,
            dt.total_amt TOTAL_TXN_AMT,
            dt.total_fee TOTAL_FEE_AMT,
            dt.txn_count,
            dt.match_count,
            NVL (rh.txn_count, 0) RECON_COUNT,
            NVL (rh.txn_amt, 0) RECON_AMOUNT,
            NVL (mismatch.mis_cnt, 0) DM_COUNT,
            NVL (mismatch.mis_amt, 0) DM_AMOUNT,
            NVL (mismatch.psp_cnt, 0) M_PSP_COUNT,
            NVL (mismatch.ph_cnt, 0) M_PH_COUNT,
            0 M_MERCHANT_COUNT,
            NVL (mismatch.matched_cnt, 0) MM_COUNT,
            NVL (rematch.re_cnt, 0) RE_M_COUNT,
            NVL (rematch.re_amt, 0) RE_M_AMOUNT
       FROM (SELECT UNIQUE tp_txn_date t_date
               FROM txn_psp_detail
              WHERE tp_txn_date IS NOT NULL
             UNION
             SELECT UNIQUE th_approval_date t_date
               FROM txn_header
              WHERE th_approval_date IS NOT NULL) d
            LEFT JOIN
            (  SELECT un.txn_date,
                      un.tp_psp_id,
                      un.psp_name psp_name,
                      un.country country,
                      un.country_name country_name,
                      un.tp_txn_ccy,
                      SUM (un.total_amt) total_amt,
                      SUM (un.total_fee) total_fee,
                      SUM (un.txn_count) txn_count,
                      SUM (un.match_count) match_count
                 FROM ( (  SELECT tp_txn_date txn_date,
                                  tp_psp_id,
                                  pd.psp_name,
                                  pc.country,
                                  c.country_name,
                                  tp_txn_ccy,
                                  SUM (tp_txn_amount) total_amt,
                                  SUM (tp_service_fee) total_fee,
                                  NVL (COUNT (*), 0) txn_count,
                                  NVL (
                                     SUM (
                                        CASE
                                           WHEN tp_txn_date = tp_match_date
                                           THEN
                                              tp_match_ind
                                           ELSE
                                              0
                                        END),
                                     0)
                                     match_count
                             FROM txn_psp_detail tpd,
                                  txn_header th,
                                  psp_country pc,
                                  psp_detail pd,
                                  country c
                            WHERE     tpd.tp_txn_id = th.th_txn_id
                                  AND th.th_txn_code IN ('DSI', 'DSP')
                                  AND th_ar_ind = 'A'
                                  AND pc.psp_id = tpd.tp_psp_id
                                  AND pd.psp_id = tpd.tp_psp_id
                                  AND c.country_code = pc.country
                                  AND tpd.tp_txn_date IS NOT NULL
                         GROUP BY tp_txn_date,
                                  tp_psp_id,
                                  pd.psp_name,
                                  c.country_name,
                                  pc.country,
                                  tp_txn_ccy)
                       UNION ALL
                       (  SELECT tp_match_date txn_date,
                                 tp_psp_id,
                                 pd.psp_name,
                                 pc.country,
                                 c.country_name,
                                 tp_txn_ccy,
                                 0 total_amt,
                                 0 total_fee,
                                 0 txn_count,
                                 0 match_count
                            FROM txn_psp_detail tpd,
                                 txn_header th,
                                 psp_country pc,
                                 psp_detail pd,
                                 country c
                           WHERE     tpd.tp_txn_id = th.th_txn_id
                                 AND th.th_txn_code IN ('DSI', 'DSP')
                                 AND th_ar_ind = 'A'
                                 AND pc.psp_id = tpd.tp_psp_id
                                 AND pd.psp_id = tpd.tp_psp_id
                                 AND c.country_code = pc.country
                                 AND tpd.tp_txn_date IS NOT NULL
                                 AND (tpd.tp_txn_date <> tpd.tp_match_date)
                        GROUP BY tp_match_date,
                                 tp_psp_id,
                                 pd.psp_name,
                                 c.country_name,
                                 pc.country,
                                 tp_txn_ccy)) un
             GROUP BY txn_date,
                      tp_psp_id,
                      psp_name,
                      country_name,
                      country,
                      tp_txn_ccy) dt
               ON dt.txn_date = d.t_date
            LEFT JOIN
            (  SELECT pr_id,
                      pr_psp_id,
                      pr_txn_ccy,
                      pr_txn_country,
                      pr_psp_txn_date,
                      pr_recon_date,
                      pr_create_timestamp,
                      SUM (pr_txn_count) txn_count,
                      SUM (pr_txn_amount) txn_amt
                 FROM psp_recon_history
             GROUP BY pr_id,
                      pr_psp_id,
                      pr_psp_txn_date,
                      pr_create_timestamp,
                      pr_recon_date,
                      pr_txn_ccy,
                      pr_txn_country) rh
               ON     rh.pr_psp_txn_date = dt.txn_date
                  AND rh.pr_psp_id = dt.tp_psp_id
                  AND rh.pr_txn_ccy = dt.tp_txn_ccy
                  AND rh.pr_txn_country = dt.country
            LEFT JOIN
            (  SELECT dm_party_id,
                      dm_txn_date,
                      NVL (COUNT (*), 0) mis_cnt,
                      SUM (CASE WHEN DM_ABSENT = 'PSP' THEN 1 ELSE 0 END) psp_cnt,
                      SUM (CASE WHEN DM_ABSENT = 'PH' THEN 1 ELSE 0 END) ph_cnt,
                      SUM (CASE NVL (DM_MATCH_IND, 0) WHEN 1 THEN 1 ELSE 0 END)
                         matched_cnt,
                      SUM (tp_txn_amount) mis_amt
                 FROM (SELECT dm_party_id,
                              dm_txn_date,
                              dm_absent,
                              dm_match_ind,
                              tp_txn_amount
                         FROM DEPOSIT_MISMATCH, txn_psp_detail
                        WHERE DM_PARTY_TYPE = 'P' AND tp_txn_id = dm_txn_id)
             GROUP BY dm_party_id, dm_txn_date) mismatch
               ON     mismatch.dm_txn_date = dt.txn_date
                  AND mismatch.dm_party_id = dt.tp_psp_id
            LEFT JOIN
            (  SELECT DM_PARTY_ID,
                      DM_MATCH_DATE,
                      SUM (CASE NVL (DM_MATCH_IND, 0) WHEN 1 THEN 1 ELSE 0 END)
                         re_cnt,
                      SUM (tp_txn_amount) re_amt
                 FROM (SELECT dm_party_id,
                              dm_match_date,
                              dm_match_ind,
                              tp_txn_amount
                         FROM DEPOSIT_MISMATCH, txn_psp_detail
                        WHERE     DM_PARTY_TYPE = 'P'
                              AND dm_match_ind = 1
                              AND tp_txn_id = dm_txn_id)
             GROUP BY DM_PARTY_ID, DM_match_DATE) rematch
               ON     rematch.dm_match_date = dt.txn_date
                  AND rematch.dm_party_id = dt.tp_psp_id
      WHERE dt.tp_psp_id IS NOT NULL
   ORDER BY d.t_date DESC, dt.tp_psp_id;

