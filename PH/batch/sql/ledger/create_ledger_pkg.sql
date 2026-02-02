CREATE OR REPLACE PACKAGE LEDGER_PKG
 IS
    FUNCTION F_CB_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_merchant_id           txn_header.th_merchant_id%TYPE,
       in_country               txn_detail.td_txn_country%TYPE,
       in_service_code          txn_header.th_service_code%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN cb_ledger_tab;

    PROCEDURE open_cur_cb_ledger (
       in_host_posting_date   IN     txn_header.th_host_posting_date%TYPE,
       in_merchant_id         IN     txn_header.th_merchant_id%TYPE,
       in_country             IN     txn_detail.td_txn_country%TYPE,
       in_service_code        IN     txn_header.th_service_code%TYPE,
       in_ccy                 IN     txn_detail.td_txn_ccy%TYPE,
       cursor_cb_ledger       IN OUT SYS_REFCURSOR);


    FUNCTION F_SB_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_merchant_id           txn_header.th_merchant_id%TYPE,
       in_country               txn_detail.td_txn_country%TYPE,
       in_service_code          txn_header.th_service_code%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN sb_ledger_tab;


    PROCEDURE open_cur_sb_ledger (
       in_host_posting_date   IN     txn_header.th_host_posting_date%TYPE,
       in_merchant_id         IN     txn_header.th_merchant_id%TYPE,
       in_country             IN     txn_detail.td_txn_country%TYPE,
       in_service_code        IN     txn_header.th_service_code%TYPE,
       in_ccy                 IN     txn_detail.td_txn_ccy%TYPE,
       cursor_sb_ledger       IN OUT SYS_REFCURSOR);


    FUNCTION F_RB_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_merchant_id           txn_header.th_merchant_id%TYPE,
       in_country               txn_detail.td_txn_country%TYPE,
       in_service_code          txn_header.th_service_code%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN rb_ledger_tab;

    PROCEDURE open_cur_rb_ledger (
       in_host_posting_date   IN     txn_header.th_host_posting_date%TYPE,
       in_merchant_id         IN     txn_header.th_merchant_id%TYPE,
       in_country             IN     txn_detail.td_txn_country%TYPE,
       in_service_code        IN     txn_header.th_service_code%TYPE,
       in_ccy                 IN     txn_detail.td_txn_ccy%TYPE,
       cursor_rb_ledger       IN OUT SYS_REFCURSOR);

    FUNCTION F_APO_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_merchant_id           txn_header.th_merchant_id%TYPE,
       in_country               txn_detail.td_txn_country%TYPE,
       in_service_code          txn_header.th_service_code%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN APO_ledger_tab;

    PROCEDURE open_cur_apo_ledger (
       in_host_posting_date   IN     txn_header.th_host_posting_date%TYPE,
       in_merchant_id         IN     txn_header.th_merchant_id%TYPE,
       in_country             IN     txn_detail.td_txn_country%TYPE,
       in_service_code        IN     txn_header.th_service_code%TYPE,
       in_ccy                 IN     txn_detail.td_txn_ccy%TYPE,
       cursor_apo_ledger      IN OUT SYS_REFCURSOR);

    FUNCTION F_PSP_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_psp_id                txn_psp_detail.tp_psp_id%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN PSP_ledger_tab;
	
	FUNCTION F_PSP_HOLD_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_psp_id                txn_psp_detail.tp_psp_id%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN PSP_ledger_tab;
	
 END LEDGER_PKG;
/

CREATE OR REPLACE PACKAGE BODY LEDGER_PKG
 IS
    FUNCTION F_CB_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_merchant_id           txn_header.th_merchant_id%TYPE,
       in_country               txn_detail.td_txn_country%TYPE,
       in_service_code          txn_header.th_service_code%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN cb_ledger_tab
    IS
       Result                       cb_ledger_tab := cb_ledger_tab ();
       n                            INTEGER := 0;
       dBal                         NUMBER := 0.0;
       dOpeningBal                  NUMBER := 0.0;
       lTxnId                       txn_header.th_txn_id%TYPE;

       v_txn_id                     VARCHAR (16);
       v_merchant_ref               txn_header.th_merchant_ref%TYPE;
       v_txn_code                   txn_header.th_txn_code%TYPE;
       v_txn_code_desc              txn_code.tc_desc%TYPE;
       v_txn_element_type           txn_elements.te_txn_element_type%TYPE;
       v_txn_element_type_desc      def_element_type.dt_desc%TYPE;
       v_exec_seq                   txn_elements.te_exec_seq%TYPE;
       v_amount                     txn_elements.te_amount%TYPE;
       v_ccy                        txn_elements.te_ccy%TYPE;
       v_amt_type                   txn_elements.te_amt_type%TYPE;
       v_approval_timestamp         txn_header.th_approval_timestamp%TYPE;
       v_approval_date              txn_header.th_approval_date%TYPE;
       v_void_txn_id                txn_header.th_org_txn_id%TYPE;
       v_party_type                 txn_elements.te_party_type%TYPE;

       p_reserve_amount             txn_header.th_reserve_amount%TYPE;
       p_closing_amount             txn_header.th_reserve_amount%TYPE;
       iCnt                         INTEGER := 0;

       last_open_bal                txn_detail.td_current_bal%TYPE;
       last_open_bal_settlement     txn_detail.td_current_bal_settlement%TYPE;
       last_total_reserve_amount    TXN_DETAIL.TD_TOTAL_RESERVED_AMOUNT%TYPE;
       last_total_hold              txn_detail.td_total_hold%TYPE;
       last_total_hold_settlement   txn_detail.td_total_hold_settlement%TYPE;

       CURSOR cb_ledger_cur
       IS
            SELECT te_txn_id,
                   th_merchant_ref,
                   th_txn_code,
                   tc_desc,
                   te_txn_element_type,
                   --dt_desc,
                   nvl(mt_desc,dt_desc),
                   te_exec_seq,
                   te_amount,
                   te_ccy,
                   te_amt_type,
                   th_approval_timestamp,
                   th_approval_date,
                   void_txn_id,
                   te_party_type
              FROM txn_detail,
                   (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                          te_txn_id,
                           txn_header.th_merchant_ref,
                           te_txn_element_type,
                           dt_desc,
                           te_exec_seq,
                           te_amount,
                           te_ccy,
                           te_amt_type,
                           txn_header.th_txn_code,
                           tc_desc,
                           txn_header.th_approval_timestamp,
                           th_approval_date,
                           th_reserve_amount,
                           void_th.th_txn_id void_txn_id,
                           te_party_type
                      FROM txn_elements,
                           (SELECT th_txn_id,
                                   th_txn_code,
                                   th_approval_timestamp,
                                   th_approval_date,
                                   th_merchant_ref,
                                   th_reserve_amount
                              FROM txn_header
                             WHERE     th_approval_timestamp >=
                                          in_approval_date_from
                                   AND th_approval_timestamp <
                                          in_approval_date_to
                                   AND th_merchant_id = in_merchant_id
                                   AND th_ar_ind = 'A'
                                   and th_txn_code not in ('RLS','RLA')
                                   AND th_service_code = in_service_code) txn_header,
                           def_element_type,
                           txn_code,
                           (SELECT th_txn_id, th_org_txn_id
                              FROM txn_header
                             WHERE     th_merchant_id IS NOT NULL
                                   AND th_ar_ind = 'A'
                                   AND th_org_txn_id IN
                                          (SELECT th_txn_id
                                             FROM txn_header
                                            WHERE     th_approval_timestamp >=
                                                         in_approval_date_from
                                                  AND th_approval_timestamp <
                                                         in_approval_date_to
                                                  AND th_merchant_id =
                                                         in_merchant_id
                                                  AND th_ar_ind = 'A'
                                                  AND th_service_code =
                                                         in_service_code)
                                                  AND th_txn_code not in ('RLR','RTT','TFT')) void_th
                     WHERE     te_txn_element_type IN
                                  ('TAMT',
                                   'TFEE',
                                   'TRNF',
                                   --'MAMT',
                                   'RAMT',
                                   'UAMT',
                                   'HAMT',
                                   'MFIN',
                                   'MPOR',
                                   'MAPO',
                                   'MAPF',
                                   'MFLT',
                                   'HOPO',
                                   'UOPO')
                           AND te_party_type = 'M'
                           AND te_ccy = in_ccy
                           AND te_txn_id = txn_header.th_txn_id
                           AND te_txn_element_type = dt_type
                           AND txn_header.th_txn_code = tc_code
                           AND txn_header.th_txn_id = void_th.th_org_txn_id(+))
                           left join map_txn_element on
                           te_txn_element_type = mt_element      and   th_txn_code = mt_txn_code
             WHERE td_txn_id = te_txn_id AND td_txn_country = in_country
          ORDER BY th_approval_timestamp, te_exec_seq;
    BEGIN
	execute immediate 'alter session set nls_sort=binary';
       /*
       SELECT COUNT (*)
         INTO icnt
         FROM txn_header,
              txn_detail
        WHERE     th_approval_timestamp < in_approval_date_from
              AND th_merchant_id = in_merchant_id
              AND th_ar_ind = 'A'
              AND th_service_code = in_service_code
              AND th_net_ccy = in_ccy
              AND th_txn_id = td_txn_id
              AND td_txn_country = in_country;
       */

       SELECT CASE WHEN EXISTS(
             SELECT 1
             FROM txn_header, txn_detail
              WHERE th_approval_timestamp < in_approval_date_from
              AND th_merchant_id = in_merchant_id
              AND th_ar_ind = 'A'
              AND th_service_code = in_service_code
              AND th_net_ccy = in_ccy
              AND th_txn_id = td_txn_id
              AND td_txn_country = in_country)
              THEN 1
             ELSE 0 END AS Cnt
       INTO  icnt
       FROM DUAL;

       IF icnt = 0
       THEN
          dBal := 0;
       ELSE
          SELECT /*+ opt_param('optimizer_index_cost_adj',1) opt_param('optimizer_index_caching',99) */ current_bal,
                 current_bal_settlement,
                 total_reserved_amount,
                 total_hold,
                 total_hold_settlement
            INTO last_open_bal,
                 last_open_bal_settlement,
                 last_total_reserve_amount,
                 last_total_hold,
                 last_total_hold_settlement
            FROM (SELECT NVL (td_current_bal, 0) as current_bal,
                         NVL (td_current_bal_settlement, 0) as current_bal_settlement,
                         NVL (td_total_reserved_amount, 0) as total_reserved_amount,
                         NVL (td_total_hold, 0) as total_hold,
                         NVL (td_total_hold_settlement, 0) as total_hold_settlement
                    FROM txn_detail,
                         txn_header
                   WHERE th_approval_timestamp < in_approval_date_from
                     AND th_merchant_id = in_merchant_id
                     AND th_ar_ind = 'A'
                     AND th_service_code = in_service_code
                     AND th_net_ccy = in_ccy
                     AND th_txn_id = td_txn_id
                     AND td_txn_country = in_country
                ORDER BY th_approval_timestamp desc, th_txn_id desc)
           WHERE rownum      < 2 ;

          dBal :=
               last_open_bal
             + last_open_bal_settlement
             - last_total_reserve_amount
             - last_total_hold
             - last_total_hold_settlement;
       END IF;

       OPEN cb_ledger_cur;

       p_reserve_amount := 0;
       p_closing_amount := 0;

       LOOP
          FETCH cb_ledger_cur
             INTO v_txn_id,
                  v_merchant_ref,
                  v_txn_code,
                  v_txn_code_desc,
                  v_txn_element_type,
                  v_txn_element_type_desc,
                  v_exec_seq,
                  v_amount,
                  v_ccy,
                  v_amt_type,
                  v_approval_timestamp,
                  v_approval_date,
                  v_void_txn_id,
				  v_party_type;

          EXIT WHEN cb_ledger_cur%NOTFOUND;

          IF (n = 0)
          THEN
             lTxnId := v_txn_id;
             p_closing_amount := 0;
          ELSE
             dBal := p_closing_amount;
          END IF;

          dOpeningBal := dBal;

          IF (v_amt_type = 'DR')
          THEN
             IF (v_txn_code = 'DSI' OR v_txn_code = 'DSP')
             THEN
                IF (v_txn_element_type != 'RAMT')
                THEN
                   dBal := dBal - v_amount - p_reserve_amount;
                ELSE
                   dBal := dBal - v_amount;
                END IF;
             ELSE
                dBal := dBal - v_amount;
             END IF;
          ELSE
             IF (v_txn_code = 'DSI' OR v_txn_code = 'DSP')
             THEN
                IF (v_txn_element_type = 'RAMT')
                THEN
                   dBal := dBal + v_amount - p_reserve_amount;
                ELSE
                   dBal := dBal + v_amount;
                END IF;
             ELSE
                dBal := dBal + v_amount;
             END IF;
          END IF;

          Result.EXTEND;
          n := n + 1;


          result (n) :=
             cb_ledger_OBJ (v_txn_id,
                            v_merchant_ref,
                            v_txn_code,
                            v_txn_code_desc,
                            dOpeningBal,
                            v_amt_type,
                            v_amount,
                            dBal,
                            v_txn_element_type,
                            v_txn_element_type_desc,
                            v_exec_seq,
                            v_ccy,
                            v_approval_timestamp,
                            v_approval_date,
                            v_void_txn_id,
							v_party_type);

          lTxnId := v_txn_id;

          IF (v_txn_element_type = 'RAMT')
          THEN
             p_reserve_amount := v_amount;
          ELSE
             p_reserve_amount := 0;
          END IF;

          p_closing_amount := dBal;
       END LOOP;

       CLOSE cb_ledger_cur;

       RETURN (Result);
	execute immediate 'alter session set nls_sort=binary_ci';
    END;

    PROCEDURE open_cur_cb_ledger (
       in_host_posting_date   IN     txn_header.th_host_posting_date%TYPE,
       in_merchant_id         IN     txn_header.th_merchant_id%TYPE,
       in_country             IN     txn_detail.td_txn_country%TYPE,
       in_service_code        IN     txn_header.th_service_code%TYPE,
       in_ccy                 IN     txn_detail.td_txn_ccy%TYPE,
       cursor_cb_ledger       IN OUT SYS_REFCURSOR)
    IS
    BEGIN
       OPEN cursor_cb_ledger FOR
          SELECT *
            FROM TABLE (ledger_pkg.F_cb_ledger (
                           TO_DATE (in_host_posting_date, 'YYYYMMDD'),
                           TO_DATE (in_host_posting_date, 'yyyymmdd') + 1,
                           in_merchant_id,
                           in_country,
                           in_service_code,
                           in_ccy));
    END open_cur_cb_ledger;

    FUNCTION F_SB_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_merchant_id           txn_header.th_merchant_id%TYPE,
       in_country               txn_detail.td_txn_country%TYPE,
       in_service_code          txn_header.th_service_code%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN sb_ledger_tab
    IS
       Result                       sb_ledger_tab := sb_ledger_tab ();
       n                            INTEGER := 0;
       dBal                         NUMBER := 0.0;
       dOpeningBal                  NUMBER := 0.0;
       lTxnId                       txn_header.th_txn_id%TYPE;

       v_txn_id                     VARCHAR (16);
       v_merchant_ref               txn_header.th_merchant_ref%TYPE;
       v_txn_code                   txn_header.th_txn_code%TYPE;
       v_txn_code_desc              txn_code.tc_desc%TYPE;
       v_txn_element_type           txn_elements.te_txn_element_type%TYPE;
       v_txn_element_type_desc      def_element_type.dt_desc%TYPE;
       v_exec_seq                   txn_elements.te_exec_seq%TYPE;
       v_amount                     txn_elements.te_amount%TYPE;
       v_ccy                        txn_elements.te_ccy%TYPE;
       v_amt_type                   txn_elements.te_amt_type%TYPE;
       v_approval_timestamp         txn_header.th_approval_timestamp%TYPE;
       v_approval_date              txn_header.th_approval_date%TYPE;
       v_party_type                 txn_elements.te_party_type%TYPE;

       p_reserve_amount             txn_header.th_reserve_amount%TYPE;
       p_closing_amount             txn_header.th_reserve_amount%TYPE;
       iCnt                         INTEGER := 0;

       last_total_hold              txn_detail.td_total_hold%TYPE;
       last_total_hold_settlement   txn_detail.td_total_hold_settlement%TYPE;

       CURSOR sb_ledger_cur
       IS
            SELECT te_txn_id,
                   th_merchant_ref,
                   th_txn_code,
                   tc_desc,
                   te_txn_element_type,
                   dt_desc,
                   te_exec_seq,
                   te_amount,
                   te_ccy,
                   DECODE (te_amt_type,  'DR', 'CR',  'CR', 'DR'),
                   th_approval_timestamp,
                   th_approval_date,
				   te_party_type
              FROM txn_detail,
                   (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                          te_txn_id,
                           txn_header.th_merchant_ref,
                           te_txn_element_type,
                           dt_desc,
                           te_exec_seq,
                           te_amount,
                           te_ccy,
                           te_amt_type,
                           txn_header.th_txn_code,
                           tc_desc,
                           txn_header.th_approval_timestamp,
                           txn_header.th_approval_date,
                           th_reserve_amount,
						   te_party_type
                      FROM txn_elements,
                           (SELECT th_txn_id,
                                   th_txn_code,
                                   th_approval_timestamp,
                                   th_approval_date,
                                   th_merchant_ref,
                                   th_reserve_amount
                              FROM txn_header
                             WHERE     th_approval_timestamp >=
                                          in_approval_date_from
                                   AND th_approval_timestamp <
                                          in_approval_date_to
                                   AND th_merchant_id = in_merchant_id
                                   AND th_ar_ind = 'A'
                                   AND th_service_code = in_service_code) txn_header,
                           def_element_type,
                           txn_code
                     WHERE     te_txn_element_type IN ('UAMT', 'HAMT','HOPO','UOPO')
                           AND te_party_type = 'M'
                           AND te_ccy = in_ccy
                           AND te_txn_id = txn_header.th_txn_id
                           AND te_txn_element_type = dt_type
                           AND txn_header.th_txn_code = tc_code)
             WHERE td_txn_id = te_txn_id AND td_txn_country = in_country
          ORDER BY th_approval_timestamp, te_exec_seq;
    BEGIN
	execute immediate 'alter session set nls_sort=binary';
       /*
       SELECT COUNT (*)
         INTO icnt
         FROM txn_header,
              txn_detail
        WHERE     th_approval_timestamp < in_approval_date_from
              AND th_merchant_id = in_merchant_id
              AND th_ar_ind = 'A'
              AND th_service_code = in_service_code
              AND th_net_ccy = in_ccy
              AND th_txn_id = td_txn_id
              AND td_txn_country = in_country;
       */

       SELECT CASE WHEN EXISTS(
             SELECT 1
             FROM txn_header, txn_detail
              WHERE th_approval_timestamp < in_approval_date_from
              AND th_merchant_id = in_merchant_id
              AND th_ar_ind = 'A'
              AND th_service_code = in_service_code
              AND th_net_ccy = in_ccy
              AND th_txn_id = td_txn_id
              AND td_txn_country = in_country)
              THEN 1
             ELSE 0 END AS Cnt
       INTO  icnt
       FROM DUAL;



       IF icnt = 0
       THEN
          dBal := 0;
       ELSE

           SELECT /*+ opt_param('optimizer_index_cost_adj',1) opt_param('optimizer_index_caching',99) */ total_hold,
                  total_hold_settlement
             INTO last_total_hold,
                  last_total_hold_settlement
             FROM (SELECT NVL (td_total_hold, 0) as total_hold,
                          NVL (td_total_hold_settlement, 0) as total_hold_settlement
                     FROM txn_detail,
                          txn_header
                    WHERE th_approval_timestamp < in_approval_date_from
                      AND th_merchant_id = in_merchant_id
                      AND th_ar_ind = 'A'
                      AND th_service_code = in_service_code
                      AND th_net_ccy = in_ccy
                      AND th_txn_id = td_txn_id
                      AND td_txn_country = in_country
                 ORDER BY th_approval_timestamp desc, th_txn_id desc)
           WHERE rownum      < 2 ;

          dBal := last_total_hold + last_total_hold_settlement;
       END IF;


       OPEN sb_ledger_cur;

       p_reserve_amount := 0;
       p_closing_amount := 0;

       LOOP
          FETCH sb_ledger_cur
             INTO v_txn_id,
                  v_merchant_ref,
                  v_txn_code,
                  v_txn_code_desc,
                  v_txn_element_type,
                  v_txn_element_type_desc,
                  v_exec_seq,
                  v_amount,
                  v_ccy,
                  v_amt_type,
                  v_approval_timestamp,
                  v_approval_date,
				  v_party_type;

          EXIT WHEN sb_ledger_cur%NOTFOUND;

          IF (n = 0)
          THEN
             lTxnId := v_txn_id;
             p_closing_amount := 0;
          ELSE
             dBal := p_closing_amount;
          END IF;

          dOpeningBal := dBal;

          IF (v_amt_type = 'DR')
          THEN
             dBal := dBal - v_amount;
          ELSE
             dBal := dBal + v_amount;
          END IF;

          Result.EXTEND;
          n := n + 1;


          result (n) :=
             sb_ledger_OBJ (v_txn_id,
                            v_merchant_ref,
                            v_txn_code,
                            v_txn_code_desc,
                            dOpeningBal,
                            v_amt_type,
                            v_amount,
                            dBal,
                            v_txn_element_type,
                            v_txn_element_type_desc,
                            v_exec_seq,
                            v_ccy,
                            v_approval_timestamp,
                            v_approval_date,
						    v_party_type);

          lTxnId := v_txn_id;

          IF (v_txn_element_type = 'RAMT')
          THEN
             p_reserve_amount := v_amount;
          ELSE
             p_reserve_amount := 0;
          END IF;

          p_closing_amount := dBal;
       END LOOP;

       CLOSE sb_ledger_cur;

       RETURN (Result);
	execute immediate 'alter session set nls_sort=binary_ci';
    END;

    PROCEDURE open_cur_sb_ledger (
       in_host_posting_date   IN     txn_header.th_host_posting_date%TYPE,
       in_merchant_id         IN     txn_header.th_merchant_id%TYPE,
       in_country             IN     txn_detail.td_txn_country%TYPE,
       in_service_code        IN     txn_header.th_service_code%TYPE,
       in_ccy                 IN     txn_detail.td_txn_ccy%TYPE,
       cursor_sb_ledger       IN OUT SYS_REFCURSOR)
    IS
    BEGIN
       OPEN cursor_sb_ledger FOR
          SELECT *
            FROM TABLE (ledger_pkg.F_sb_ledger (
                           TO_DATE (in_host_posting_date, 'YYYYMMDD'),
                           TO_DATE (in_host_posting_date, 'yyyymmdd') + 1,
                           in_merchant_id,
                           in_country,
                           in_service_code,
                           in_ccy));
    END open_cur_sb_ledger;

    FUNCTION F_RB_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_merchant_id           txn_header.th_merchant_id%TYPE,
       in_country               txn_detail.td_txn_country%TYPE,
       in_service_code          txn_header.th_service_code%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN rb_ledger_tab
    IS
       Result                      rb_ledger_tab := rb_ledger_tab ();
       n                           INTEGER := 0;
       dBal                        NUMBER := 0.0;
       dOpeningBal                 NUMBER := 0.0;
       lTxnId                      txn_header.th_txn_id%TYPE;

       v_txn_id                    VARCHAR (16);
       v_merchant_ref              txn_header.th_merchant_ref%TYPE;
       v_txn_code                  txn_header.th_txn_code%TYPE;
       v_txn_code_desc             txn_code.tc_desc%TYPE;
       v_txn_element_type          txn_elements.te_txn_element_type%TYPE;
       v_txn_element_type_desc     def_element_type.dt_desc%TYPE;
       v_exec_seq                  txn_elements.te_exec_seq%TYPE;
       v_amount                    txn_elements.te_amount%TYPE;
       v_ccy                       txn_elements.te_ccy%TYPE;
       v_amt_type                  txn_elements.te_amt_type%TYPE;
       v_approval_timestamp        txn_header.th_approval_timestamp%TYPE;
       v_approval_date             txn_header.th_approval_date%TYPE;
       v_void_txn_id               txn_header.th_org_txn_id%TYPE;
       v_party_type                 txn_elements.te_party_type%TYPE;

       p_reserve_amount            txn_header.th_reserve_amount%TYPE;
       p_closing_amount            txn_header.th_reserve_amount%TYPE;
       iCnt                        INTEGER := 0;


       last_total_reserve_amount   TXN_DETAIL.TD_TOTAL_RESERVED_AMOUNT%TYPE;

       CURSOR rb_ledger_cur
       IS
            SELECT te_txn_id,
                   th_merchant_ref,
                   th_txn_code,
                   tc_desc,
                   te_txn_element_type,
                   --dt_desc,
                   nvl(mt_desc,dt_desc),
                   te_exec_seq,
                   te_amount,
                   te_ccy,
                   DECODE (te_amt_type,  'DR', 'CR',  'CR', 'DR'),
                   th_approval_timestamp,
                   th_approval_date,
                   void_txn_id,
				   te_party_type
              FROM txn_detail,
                   (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                          te_txn_id,
                           txn_header.th_merchant_ref,
                           te_txn_element_type,
                           dt_desc,
                           te_exec_seq,
                           te_amount,
                           te_ccy,
                           te_amt_type,
                           txn_header.th_txn_code,
                           tc_desc,
                           txn_header.th_approval_timestamp,
                           txn_header.th_approval_date,
                           th_reserve_amount,
                           void_th.th_txn_id void_txn_id,
						   te_party_type
                      FROM txn_elements,
                           (SELECT th_txn_id,
                                   th_txn_code,
                                   th_approval_timestamp,
                                   th_approval_date,
                                   th_merchant_ref,
                                   th_reserve_amount
                              FROM txn_header
                             WHERE     th_approval_timestamp >=
                                          in_approval_date_from
                                   AND th_approval_timestamp <
                                          in_approval_date_to
                                   AND th_merchant_id = in_merchant_id
                                   AND th_ar_ind = 'A'
                                   AND th_service_code = in_service_code
                                   ) txn_header,
                           def_element_type,
                           txn_code,
                           (SELECT th_txn_id, th_org_txn_id
                              FROM txn_header
                             WHERE     th_merchant_id IS NOT NULL
                                   AND th_ar_ind = 'A'
                                   AND th_org_txn_id IN
                                          (SELECT th_txn_id
                                             FROM txn_header
                                            WHERE     th_approval_timestamp >=
                                                         in_approval_date_from
                                                  AND th_approval_timestamp <
                                                         in_approval_date_to
                                                  AND th_merchant_id =
                                                         in_merchant_id
                                                  AND th_ar_ind = 'A'
                                                  AND th_service_code =
                                                         in_service_code)
								  AND th_txn_code not in ('RLR')) void_th
                     WHERE     te_txn_element_type IN ('RAMT')
                           AND te_party_type = 'M'
                           AND te_ccy = in_ccy
                           AND te_txn_id = txn_header.th_txn_id
                           AND te_txn_element_type = dt_type
                           AND txn_header.th_txn_code = tc_code
                           AND txn_header.th_txn_id = void_th.th_org_txn_id(+))
                           left join map_txn_element on
                           te_txn_element_type = mt_element      and   th_txn_code = mt_txn_code
             WHERE td_txn_id = te_txn_id AND td_txn_country = in_country
          ORDER BY th_approval_timestamp, te_exec_seq;
    BEGIN
	execute immediate 'alter session set nls_sort=binary';
       /*
       SELECT COUNT (*)
         INTO icnt
         FROM txn_header,
              txn_detail
        WHERE     th_approval_timestamp < in_approval_date_from
              AND th_merchant_id = in_merchant_id
              AND th_ar_ind = 'A'
              AND th_service_code = in_service_code
              AND th_net_ccy = in_ccy
              AND th_txn_id = td_txn_id
              AND td_txn_country = in_country;
       */

       SELECT CASE WHEN EXISTS(
             SELECT 1
             FROM txn_header, txn_detail
              WHERE th_approval_timestamp < in_approval_date_from
              AND th_merchant_id = in_merchant_id
              AND th_ar_ind = 'A'
              AND th_service_code = in_service_code
              AND th_net_ccy = in_ccy
              AND th_txn_id = td_txn_id
              AND td_txn_country = in_country)
              THEN 1
             ELSE 0 END AS Cnt
       INTO  icnt
       FROM DUAL;


       IF icnt = 0
       THEN
          dBal := 0;
       ELSE
           SELECT /*+ opt_param('optimizer_index_cost_adj',1) opt_param('optimizer_index_caching',99) */ total_reserved_amount
             INTO last_total_reserve_amount
             FROM (SELECT NVL (td_total_reserved_amount, 0) as total_reserved_amount
                   FROM txn_detail,
                        txn_header
                  WHERE th_approval_timestamp < in_approval_date_from
                    AND th_merchant_id = in_merchant_id
                    AND th_ar_ind = 'A'
                    AND th_service_code = in_service_code
                    AND th_net_ccy = in_ccy
                    AND th_txn_id = td_txn_id
                    AND td_txn_country = in_country
               ORDER BY th_approval_timestamp desc, th_txn_id desc)
            WHERE rownum      < 2 ;

          dBal := last_total_reserve_amount;
       END IF;

       OPEN rb_ledger_cur;

       p_reserve_amount := 0;
       p_closing_amount := 0;

       LOOP
          FETCH rb_ledger_cur
             INTO v_txn_id,
                  v_merchant_ref,
                  v_txn_code,
                  v_txn_code_desc,
                  v_txn_element_type,
                  v_txn_element_type_desc,
                  v_exec_seq,
                  v_amount,
                  v_ccy,
                  v_amt_type,
                  v_approval_timestamp,
                  v_approval_date,
                  v_void_txn_id,
				  v_party_type;

          EXIT WHEN rb_ledger_cur%NOTFOUND;

          IF (n = 0)
          THEN
             lTxnId := v_txn_id;
             p_closing_amount := 0;
          ELSE
             dBal := p_closing_amount;
          END IF;

          dOpeningBal := dBal;

          IF (v_amt_type = 'DR')
          THEN
             dBal := dBal - v_amount;
          ELSE
             dBal := dBal + v_amount;
          END IF;

          Result.EXTEND;
          n := n + 1;


          result (n) :=
             rb_ledger_OBJ (v_txn_id,
                            v_merchant_ref,
                            v_txn_code,
                            v_txn_code_desc,
                            dOpeningBal,
                            v_amt_type,
                            v_amount,
                            dBal,
                            v_txn_element_type,
                            v_txn_element_type_desc,
                            v_exec_seq,
                            v_ccy,
                            v_approval_timestamp,
                            v_approval_date,
                            v_void_txn_id,
							v_party_type);

          lTxnId := v_txn_id;

          IF (v_txn_element_type = 'RAMT')
          THEN
             p_reserve_amount := v_amount;
          ELSE
             p_reserve_amount := 0;
          END IF;

          p_closing_amount := dBal;
       END LOOP;

       CLOSE rb_ledger_cur;

       RETURN (Result);
	execute immediate 'alter session set nls_sort=binary_ci';
    END;

    PROCEDURE open_cur_rb_ledger (
       in_host_posting_date   IN     txn_header.th_host_posting_date%TYPE,
       in_merchant_id         IN     txn_header.th_merchant_id%TYPE,
       in_country             IN     txn_detail.td_txn_country%TYPE,
       in_service_code        IN     txn_header.th_service_code%TYPE,
       in_ccy                 IN     txn_detail.td_txn_ccy%TYPE,
       cursor_rb_ledger       IN OUT SYS_REFCURSOR)
    IS
    BEGIN
       OPEN cursor_rb_ledger FOR
          SELECT *
            FROM TABLE (ledger_pkg.F_rb_ledger (
                           TO_DATE (in_host_posting_date, 'YYYYMMDD'),
                           TO_DATE (in_host_posting_date, 'yyyymmdd') + 1,
                           in_merchant_id,
                           in_country,
                           in_service_code,
                           in_ccy));
    END open_cur_rb_ledger;


    FUNCTION F_APO_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_merchant_id           txn_header.th_merchant_id%TYPE,
       in_country               txn_detail.td_txn_country%TYPE,
       in_service_code          txn_header.th_service_code%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN apo_ledger_tab
    IS
       Result                      apo_ledger_tab := apo_ledger_tab ();
       n                           INTEGER := 0;
       dBal                        NUMBER := 0.0;
       dOpeningBal                 NUMBER := 0.0;
       lTxnId                      txn_header.th_txn_id%TYPE;

       v_txn_id                    VARCHAR (16);
       v_merchant_ref              txn_header.th_merchant_ref%TYPE;
       v_txn_code                  txn_header.th_txn_code%TYPE;
       v_txn_code_desc             txn_code.tc_desc%TYPE;
       v_txn_element_type          txn_elements.te_txn_element_type%TYPE;
       v_txn_element_type_desc     def_element_type.dt_desc%TYPE;
       v_exec_seq                  txn_elements.te_exec_seq%TYPE;
       v_amount                    txn_elements.te_amount%TYPE;
       v_ccy                       txn_elements.te_ccy%TYPE;
       v_amt_type                  txn_elements.te_amt_type%TYPE;
       v_approval_timestamp        txn_header.th_approval_timestamp%TYPE;
       v_approval_date             txn_header.th_approval_date%TYPE;
       v_void_txn_id               txn_header.th_org_txn_id%TYPE;
       v_party_type                txn_elements.te_party_type%TYPE;

       p_reserve_amount            txn_header.th_reserve_amount%TYPE;
       p_closing_amount            txn_header.th_reserve_amount%TYPE;
       iCnt                        INTEGER := 0;


       last_total_reserve_amount   TXN_DETAIL.TD_TOTAL_RESERVED_AMOUNT%TYPE;

       CURSOR apo_ledger_cur
       IS
            SELECT te_txn_id,
                   th_merchant_ref,
                   th_txn_code,
                   tc_desc,
                   te_txn_element_type,
                   nvl(mt_desc,dt_desc),
                   te_exec_seq,
                   te_amount,
                   te_ccy,
                   te_amt_type,
                   th_approval_timestamp,
                   th_approval_date,
				   te_party_type
              FROM txn_detail,
                   (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                          te_txn_id,
                           txn_header.th_merchant_ref,
                           te_txn_element_type,
                           dt_desc,
                           te_exec_seq,
                           te_amount,
                           te_ccy,
                           te_amt_type,
                           txn_header.th_txn_code,
                           tc_desc,
                           txn_header.th_approval_timestamp,
                           txn_header.th_approval_date,
                           th_reserve_amount,
						   te_party_type
                      FROM txn_elements,
                           (SELECT th_txn_id,
                                   th_txn_code,
                                   th_approval_timestamp,
                                   th_approval_date,
                                   th_merchant_ref,
                                   th_reserve_amount
                              FROM txn_header
                             WHERE     th_approval_timestamp >=
                                          in_approval_date_from
                                   AND th_approval_timestamp <
                                          in_approval_date_to
                                   AND th_merchant_id = in_merchant_id
                                   AND th_ar_ind = 'A'
                                   AND th_service_code = in_service_code) txn_header,
                           def_element_type,
                           txn_code
                     WHERE     te_txn_element_type IN
                                  ('MAPO',
                                   'MAPF',
                                   'TAMT',
                                   'TFEE',
                                   'MFIN',
                                   'MPOR',
                                   'MFLT',
                                   --'MAMT',
                                   'HOPO',
                                   'UOPO')
                           AND te_party_type = 'M'
                           AND te_ccy = in_ccy
                           AND te_txn_id = txn_header.th_txn_id
                           AND te_txn_element_type = dt_type
                           AND txn_header.th_txn_code = tc_code
                           AND txn_header.th_txn_code IN
                                  ('POA',
                                   'RLS',
                                   'RLA',
                                   'VOA',
                                   'VRA',
                                   'FPM',
                                   'VPM',
                                   'RTF',
                                   'RTT',
                                   'HOD',
                                   'UOD'))
                    left join map_txn_element on
                           te_txn_element_type = mt_element and th_txn_code = mt_txn_code
             WHERE td_txn_id = te_txn_id AND td_txn_country = in_country

          ORDER BY th_approval_timestamp, te_exec_seq;
    BEGIN
	execute immediate 'alter session set nls_sort=binary';
       /*
       SELECT COUNT (*)
         INTO icnt
         FROM txn_header,
              txn_detail
        WHERE     th_approval_timestamp < in_approval_date_from
              AND th_merchant_id = in_merchant_id
              AND th_ar_ind = 'A'
              AND th_service_code = in_service_code
              AND th_net_ccy = in_ccy
              AND th_txn_id = td_txn_id
              AND td_txn_country = in_country;
       */

       SELECT CASE WHEN EXISTS(
             SELECT 1
             FROM txn_header, txn_detail
              WHERE th_approval_timestamp < in_approval_date_from
              AND th_merchant_id = in_merchant_id
              AND th_ar_ind = 'A'
              AND th_service_code = in_service_code
              AND th_net_ccy = in_ccy
              AND th_txn_id = td_txn_id
              AND td_txn_country = in_country)
              THEN 1
             ELSE 0 END AS Cnt
       INTO  icnt
       FROM DUAL;

       IF icnt = 0
       THEN
          dBal := 0;
       ELSE

          SELECT /*+ opt_param('optimizer_index_cost_adj',1) opt_param('optimizer_index_caching',99) */ last_total_apo
            INTO last_total_reserve_amount
            FROM (SELECT td_current_bal - td_total_float - td_total_hold - td_total_float_after_payout AS last_total_apo
                    FROM txn_detail,
                         txn_header
                   WHERE th_approval_timestamp < in_approval_date_from
                     AND th_merchant_id = in_merchant_id
                     AND th_ar_ind = 'A'
                     AND th_service_code = in_service_code
                     AND th_net_ccy = in_ccy
                     AND th_txn_id = td_txn_id
                     AND td_txn_country = in_country
                ORDER BY th_approval_timestamp desc, th_txn_id desc)
           WHERE rownum      < 2 ;

          dBal := last_total_reserve_amount;
       END IF;

       OPEN apo_ledger_cur;

       p_reserve_amount := 0;
       p_closing_amount := 0;

       LOOP
          FETCH apo_ledger_cur
             INTO v_txn_id,
                  v_merchant_ref,
                  v_txn_code,
                  v_txn_code_desc,
                  v_txn_element_type,
                  v_txn_element_type_desc,
                  v_exec_seq,
                  v_amount,
                  v_ccy,
                  v_amt_type,
                  v_approval_timestamp,
                  v_approval_date,
				  v_party_type;

          EXIT WHEN apo_ledger_cur%NOTFOUND;

          IF v_txn_code in ('VOA','VRA')
          THEN
             IF (v_txn_element_type = 'TAMT' OR v_txn_element_type = 'TFEE')
             THEN
                CONTINUE;
             END IF;
          END IF;

          IF (n = 0)
          THEN
             lTxnId := v_txn_id;
             p_closing_amount := 0;
          ELSE
             dBal := p_closing_amount;
          END IF;

          dOpeningBal := dBal;

          IF (v_amt_type = 'DR')
          THEN
             dBal := dBal - v_amount;
          ELSE
             dBal := dBal + v_amount;
          END IF;

          Result.EXTEND;
          n := n + 1;


          result (n) :=
             apo_ledger_OBJ (v_txn_id,
                             v_merchant_ref,
                             v_txn_code,
                             v_txn_code_desc,
                             dOpeningBal,
                             v_amt_type,
                             v_amount,
                             dBal,
                             v_txn_element_type,
                             v_txn_element_type_desc,
                             v_exec_seq,
                             v_ccy,
                             v_approval_timestamp,
                             v_approval_date,
							 v_party_type);

          lTxnId := v_txn_id;

          IF (v_txn_element_type = 'RAMT')
          THEN
             p_reserve_amount := v_amount;
          ELSE
             p_reserve_amount := 0;
          END IF;

          p_closing_amount := dBal;
       END LOOP;

       CLOSE apo_ledger_cur;

       RETURN (Result);
	execute immediate 'alter session set nls_sort=binary_ci';
    END;

    PROCEDURE open_cur_apo_ledger (
       in_host_posting_date   IN     txn_header.th_host_posting_date%TYPE,
       in_merchant_id         IN     txn_header.th_merchant_id%TYPE,
       in_country             IN     txn_detail.td_txn_country%TYPE,
       in_service_code        IN     txn_header.th_service_code%TYPE,
       in_ccy                 IN     txn_detail.td_txn_ccy%TYPE,
       cursor_apo_ledger      IN OUT SYS_REFCURSOR)
    IS
    BEGIN
       OPEN cursor_apo_ledger FOR
          SELECT *
            FROM TABLE (ledger_pkg.F_apo_ledger (
                           TO_DATE (in_host_posting_date, 'YYYYMMDD'),
                           TO_DATE (in_host_posting_date, 'yyyymmdd') + 1,
                           in_merchant_id,
                           in_country,
                           in_service_code,
                           in_ccy));
    END open_cur_apo_ledger;

    FUNCTION F_PSP_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_psp_id                txn_psp_detail.tp_psp_id%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN psp_ledger_tab
    IS
       Result                       psp_ledger_tab := psp_ledger_tab ();
       n                            INTEGER := 0;
       dBal                         NUMBER := 0.0;
       dOpeningBal                  NUMBER := 0.0;
       lTxnId                       txn_header.th_txn_id%TYPE;

       v_txn_id                     VARCHAR (16);
       v_tid                        txn_psp_detail.tp_tid%TYPE;
       v_txn_code                   txn_header.th_txn_code%TYPE;
       v_txn_code_desc              txn_code.tc_desc%TYPE;
       v_txn_element_type           txn_elements.te_txn_element_type%TYPE;
       v_txn_element_type_desc      def_element_type.dt_desc%TYPE;
       v_exec_seq                   txn_elements.te_exec_seq%TYPE;
       v_amount                     txn_elements.te_amount%TYPE;
       v_ccy                        txn_elements.te_ccy%TYPE;
       v_amt_type                   txn_elements.te_amt_type%TYPE;
       v_approval_timestamp         txn_header.th_approval_timestamp%TYPE;
       v_approval_date              txn_header.th_approval_date%TYPE;
       v_void_txn_id                txn_header.th_org_txn_id%TYPE;
       v_report_date                txn_psp_detail.tp_report_date%TYPE;
       v_party_type                 txn_elements.te_party_type%TYPE;

       p_reserve_amount             txn_header.th_reserve_amount%TYPE;
       p_closing_amount             txn_header.th_reserve_amount%TYPE;
       iCnt                         INTEGER := 0;

       last_open_bal                txn_psp_detail.tp_bal%TYPE;
       last_total_float             txn_psp_detail.tp_total_float%TYPE;
       last_total_hold              txn_psp_detail.tp_total_hold%TYPE;

       CURSOR psp_ledger_cur
       IS
            SELECT te_txn_id,
                   tp_tid,
                   th_txn_code,
                   tc_desc,
                   te_txn_element_type,
                   dt_desc,
                   te_exec_seq,
                   te_amount,
                   te_ccy,
                   te_amt_type,
                   th_approval_timestamp,
                   th_approval_date,
                   tp_report_date,
                   void_txn_id,
				   te_party_type
              FROM txn_detail,
                   (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                          te_txn_id,
                           tp_tid,
                           te_txn_element_type,
                           dt_desc,
                           te_exec_seq,
                           te_amount,
                           te_ccy,
                           te_amt_type,
                           txn_header.th_txn_code,
                           tc_desc,
                           txn_header.th_approval_timestamp,
                           th_approval_date,
                           tp_report_date,
                           th_reserve_amount,
                           void_th.th_txn_id void_txn_id,
						   te_party_type
                      FROM txn_elements,
                           (SELECT th_txn_id,
                                   th_txn_code,
                                   th_approval_timestamp,
                                   th_approval_date,
                                   th_merchant_ref,
                                   th_reserve_amount
                              FROM txn_header
                              WHERE	   th_approval_timestamp >= in_approval_date_from
                                   AND th_approval_timestamp < in_approval_date_to
                                   AND th_ar_ind = 'A'
								   AND th_txn_code <> 'PBU') txn_header,
                           def_element_type,
                           txn_code,
                           txn_psp_detail,
                           (SELECT th_txn_id, th_org_txn_id
                              FROM txn_header
                             WHERE    th_ar_ind = 'A'
                                   AND th_org_txn_id IN
                                          (SELECT th_txn_id
                                             FROM txn_header
                                            WHERE     th_approval_timestamp >=
                                                         in_approval_date_from
                                                  AND th_approval_timestamp <
                                                         in_approval_date_to
                                                  AND th_ar_ind = 'A')
								  AND th_txn_code <> 'RLR') void_th
                     WHERE     te_txn_element_type IN
                                  ('TAMT',
                                   'TFEE',
                                   'TRNF',
                                   'RAMT',
                                   'UAMT',
                                   'HAMT'
                                   )
                           AND te_party_type = 'P'
                           AND te_ccy = in_ccy
                           AND te_txn_id = txn_header.th_txn_id
                           AND te_txn_element_type = dt_type
                           AND tp_txn_id = txn_header.th_txn_id
                           AND tp_psp_id = in_psp_id
                           AND txn_header.th_txn_code = tc_code
                           AND txn_header.th_txn_id = void_th.th_org_txn_id(+))
             WHERE td_txn_id = te_txn_id
          ORDER BY th_approval_timestamp, te_exec_seq;
    BEGIN
	execute immediate 'alter session set nls_sort=binary';
       /*
       SELECT COUNT (*)
         INTO icnt
         FROM txn_header, txn_psp_detail
        WHERE     th_approval_timestamp < in_approval_date_from
              AND tp_psp_id = in_psp_id
              AND th_ar_ind = 'A'
              AND th_net_ccy = in_ccy
              AND th_txn_id = tp_txn_id;
	      AND th_txn_code <> 'PBU'
       */

       SELECT CASE WHEN EXISTS(
			 SELECT 1
			 FROM txn_header, txn_psp_detail
			 WHERE th_approval_timestamp < in_approval_date_from
				AND tp_psp_id = in_psp_id
				AND th_ar_ind = 'A'
				AND tp_txn_ccy = in_ccy
				AND th_txn_id = tp_txn_id
				AND th_txn_code <> 'PBU'
             ) THEN 1
        ELSE 0 END AS Result
        INTO icnt
        FROM DUAL;
 
       IF icnt = 0
       THEN
          dBal := 0;
       ELSE
           SELECT /*+ opt_param('optimizer_index_cost_adj',1) opt_param('optimizer_index_caching',99) */ bal,
                  total_float,
                  total_hold
             INTO last_open_bal,
                  last_total_float,
                  last_total_hold
             FROM (SELECT NVL (tp_bal, 0) as bal,
                          NVL (tp_total_float, 0) as total_float,
                          NVL (tp_total_hold, 0) as total_hold
                     FROM txn_psp_detail,
                          txn_header
                    WHERE th_approval_timestamp < in_approval_date_from
                      AND tp_psp_id = in_psp_id
                      AND th_ar_ind = 'A'
                      AND tp_txn_ccy = in_ccy
                      AND th_txn_id = tp_txn_id
		      AND th_txn_code <> 'PBU'
                 ORDER BY th_approval_timestamp desc, th_txn_id desc)
            WHERE rownum < 2 ;

          dBal :=
               last_open_bal
             + last_total_float
             - last_total_hold;
       END IF;

       OPEN psp_ledger_cur;

       p_reserve_amount := 0;
       p_closing_amount := 0;

       LOOP
          FETCH psp_ledger_cur
             INTO v_txn_id,
                  v_tid,
                  v_txn_code,
                  v_txn_code_desc,
                  v_txn_element_type,
                  v_txn_element_type_desc,
                  v_exec_seq,
                  v_amount,
                  v_ccy,
                  v_amt_type,
                  v_approval_timestamp,
                  v_approval_date,
                  v_report_date,
                  v_void_txn_id,
				  v_party_type;

          EXIT WHEN psp_ledger_cur%NOTFOUND;

          IF (n = 0)
          THEN
             lTxnId := v_txn_id;
             p_closing_amount := 0;
          ELSE
             dBal := p_closing_amount;
          END IF;

          dOpeningBal := dBal;

          IF (v_amt_type = 'DR')
          THEN
			dBal := dBal - v_amount;
		  END IF;

          IF (v_amt_type = 'CR')
		  THEN
			dBal := dBal + v_amount;
          END IF;

          Result.EXTEND;
          n := n + 1;
 
          result (n) :=
             psp_ledger_OBJ (v_txn_id,
                             v_tid,
                             v_txn_code,
                             v_txn_code_desc,
                             dOpeningBal,
                             v_amt_type,
                             v_amount,
                             dBal,
                             v_txn_element_type,
                             v_txn_element_type_desc,
                             v_exec_seq,
                             v_ccy,
                             v_approval_timestamp,
                             v_approval_date,
                             v_report_date,
                             v_void_txn_id,
							 v_party_type);

          lTxnId := v_txn_id;

          IF (v_txn_element_type = 'RAMT')
          THEN
             p_reserve_amount := v_amount;
          ELSE
             p_reserve_amount := 0;
          END IF; 
		  
		  p_closing_amount := dBal;
		  
       END LOOP;

       CLOSE psp_ledger_cur;

       RETURN (Result);
	execute immediate 'alter session set nls_sort=binary_ci';
    END;
	
	
	FUNCTION F_PSP_HOLD_LEDGER (
       in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
       in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
       in_psp_id                txn_psp_detail.tp_psp_id%TYPE,
       in_ccy                   txn_detail.td_txn_ccy%TYPE)
       RETURN psp_ledger_tab
    IS
       Result                       psp_ledger_tab := psp_ledger_tab ();
       n                            INTEGER := 0;
       dBal                         NUMBER := 0.0;
       dOpeningBal                  NUMBER := 0.0;
       lTxnId                       txn_header.th_txn_id%TYPE;

       v_txn_id                     VARCHAR (16);
       v_tid                        txn_psp_detail.tp_tid%TYPE;
       v_txn_code                   txn_header.th_txn_code%TYPE;
       v_txn_code_desc              txn_code.tc_desc%TYPE;
       v_txn_element_type           txn_elements.te_txn_element_type%TYPE;
       v_txn_element_type_desc      def_element_type.dt_desc%TYPE;
       v_exec_seq                   txn_elements.te_exec_seq%TYPE;
       v_amount                     txn_elements.te_amount%TYPE;
       v_ccy                        txn_elements.te_ccy%TYPE;
       v_amt_type                   txn_elements.te_amt_type%TYPE;
       v_approval_timestamp         txn_header.th_approval_timestamp%TYPE;
       v_approval_date              txn_header.th_approval_date%TYPE;
       v_void_txn_id                txn_header.th_org_txn_id%TYPE;
       v_report_date                txn_psp_detail.tp_report_date%TYPE;
       v_party_type                 txn_elements.te_party_type%TYPE;

       p_reserve_amount             txn_header.th_reserve_amount%TYPE;
       p_closing_amount             txn_header.th_reserve_amount%TYPE;
       iCnt                         INTEGER := 0;

       last_open_bal                txn_psp_detail.tp_bal%TYPE;
       last_total_float             txn_psp_detail.tp_total_float%TYPE;
       last_total_hold              txn_psp_detail.tp_total_hold%TYPE;

       CURSOR psp_ledger_cur
       IS
            SELECT te_txn_id,
                   tp_tid,
                   th_txn_code,
                   tc_desc,
                   te_txn_element_type,
                   dt_desc,
                   te_exec_seq,
                   te_amount,
                   te_ccy,
                   te_amt_type,
                   th_approval_timestamp,
                   th_approval_date,
                   tp_report_date,
                   void_txn_id,
				   te_party_type
              FROM txn_detail,
                   (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                          te_txn_id,
                           tp_tid,
                           te_txn_element_type,
                           dt_desc,
                           te_exec_seq,
                           te_amount,
                           te_ccy,
                           DECODE (te_amt_type,  'DR', 'CR',  'CR', 'DR') te_amt_type,
                           txn_header.th_txn_code,
                           tc_desc,
                           txn_header.th_approval_timestamp,
                           th_approval_date,
                           tp_report_date,
                           th_reserve_amount,
                           void_th.th_txn_id void_txn_id,
						   te_party_type
                      FROM txn_elements,
                           (SELECT th_txn_id,
                                   th_txn_code,
                                   th_approval_timestamp,
                                   th_approval_date,
                                   th_merchant_ref,
                                   th_reserve_amount
                              FROM txn_header
                              WHERE	   th_approval_timestamp >= in_approval_date_from
                                   AND th_approval_timestamp < in_approval_date_to
                                   AND th_ar_ind = 'A'
								   AND th_txn_code <> 'PBU') txn_header,
                           def_element_type,
                           txn_code,
                           txn_psp_detail,
                           (SELECT th_txn_id, th_org_txn_id
                              FROM txn_header
                             WHERE     th_ar_ind = 'A'
                                   AND th_org_txn_id IN
                                          (SELECT th_txn_id
                                             FROM txn_header
                                            WHERE     th_approval_timestamp >=
                                                         in_approval_date_from
                                                  AND th_approval_timestamp <
                                                         in_approval_date_to
                                                  AND th_ar_ind = 'A')
								  AND th_txn_code <> 'RLR') void_th
                     WHERE     te_txn_element_type IN
                                  ( 
                                   'UAMT',
                                   'HAMT'
                                   )
                           AND te_party_type = 'P'
                           AND te_ccy = in_ccy
                           AND te_txn_id = txn_header.th_txn_id
                           AND te_txn_element_type = dt_type
                           AND tp_txn_id = txn_header.th_txn_id
                           AND tp_psp_id = in_psp_id
                           AND txn_header.th_txn_code = tc_code
                           AND txn_header.th_txn_id = void_th.th_org_txn_id(+))
             WHERE td_txn_id = te_txn_id
          ORDER BY th_approval_timestamp, te_exec_seq;
    BEGIN
	execute immediate 'alter session set nls_sort=binary';
       /*
       SELECT COUNT (*)
         INTO icnt
         FROM txn_header, txn_psp_detail
        WHERE     th_approval_timestamp < in_approval_date_from
              AND tp_psp_id = in_psp_id
              AND th_ar_ind = 'A'
              AND th_net_ccy = in_ccy
              AND th_txn_id = tp_txn_id;
	      AND th_txn_code <> 'PBU'
       */

       SELECT CASE WHEN EXISTS(
			 SELECT 1
			 FROM txn_header, txn_psp_detail
			 WHERE th_approval_timestamp < in_approval_date_from
				AND tp_psp_id = in_psp_id
				AND th_ar_ind = 'A'
				AND tp_txn_ccy = in_ccy
				AND th_txn_id = tp_txn_id
				AND th_txn_code <> 'PBU'
             ) THEN 1
        ELSE 0 END AS Result
        INTO icnt
        FROM DUAL;
 
       IF icnt = 0
       THEN
          dBal := 0;
       ELSE
           SELECT /*+ opt_param('optimizer_index_cost_adj',1) opt_param('optimizer_index_caching',99) */ bal,
                  total_float,
                  total_hold
             INTO last_open_bal,
                  last_total_float,
                  last_total_hold
             FROM (SELECT NVL (tp_bal, 0) as bal,
                          NVL (tp_total_float, 0) as total_float,
                          NVL (tp_total_hold, 0) as total_hold
                     FROM txn_psp_detail,
                          txn_header
                    WHERE th_approval_timestamp < in_approval_date_from
                      AND tp_psp_id = in_psp_id
                      AND th_ar_ind = 'A'
                      AND tp_txn_ccy = in_ccy
                      AND th_txn_id = tp_txn_id
		      AND th_txn_code <> 'PBU'
                 ORDER BY th_approval_timestamp desc, th_txn_id desc)
            WHERE rownum < 2 ;

          dBal := last_total_hold;
		  
       END IF;

       OPEN psp_ledger_cur;

       p_reserve_amount := 0;
       p_closing_amount := 0;

       LOOP
          FETCH psp_ledger_cur
             INTO v_txn_id,
                  v_tid,
                  v_txn_code,
                  v_txn_code_desc,
                  v_txn_element_type,
                  v_txn_element_type_desc,
                  v_exec_seq,
                  v_amount,
                  v_ccy,
                  v_amt_type,
                  v_approval_timestamp,
                  v_approval_date,
                  v_report_date,
                  v_void_txn_id,
				  v_party_type;

          EXIT WHEN psp_ledger_cur%NOTFOUND;

          IF (n = 0)
          THEN
             lTxnId := v_txn_id;
             p_closing_amount := 0;
          ELSE
             dBal := p_closing_amount;
          END IF;

          dOpeningBal := dBal;

          IF (v_amt_type = 'DR')
          THEN
			dBal := dBal - v_amount;
		  END IF;

          IF (v_amt_type = 'CR')
		  THEN
			dBal := dBal + v_amount;
          END IF;

          Result.EXTEND;
          n := n + 1;
 
          result (n) :=
             psp_ledger_OBJ (v_txn_id,
                             v_tid,
                             v_txn_code,
                             v_txn_code_desc,
                             dOpeningBal,
                             v_amt_type,
                             v_amount,
                             NVL (dBal, 0.00),
                             v_txn_element_type,
                             v_txn_element_type_desc,
                             v_exec_seq,
                             v_ccy,
                             v_approval_timestamp,
                             v_approval_date,
                             v_report_date,
                             v_void_txn_id,
							 v_party_type);

          lTxnId := v_txn_id;

          IF (v_txn_element_type = 'RAMT')
          THEN
             p_reserve_amount := v_amount;
          ELSE
             p_reserve_amount := 0;
          END IF; 
		  
		  p_closing_amount := dBal;
		  
       END LOOP;

       CLOSE psp_ledger_cur;

       RETURN (Result);
	execute immediate 'alter session set nls_sort=binary_ci';
    END;
 END LEDGER_PKG;
/
