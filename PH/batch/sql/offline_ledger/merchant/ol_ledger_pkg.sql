CREATE OR REPLACE PACKAGE OL_LEDGER_PKG
IS
   FUNCTION F_CB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
      RETURN ol_cb_ledger_tab;

   PROCEDURE open_cur_cb_ledger (
      in_host_posting_date   IN     ol_txn_header.oth_host_posting_date%TYPE,
      in_merchant_id         IN     ol_txn_header.oth_merchant_id%TYPE,
      in_country             IN     ol_txn_detail.otd_txn_country%TYPE,
      in_service_code        IN     ol_txn_header.oth_service_code%TYPE,
      in_ccy                 IN     ol_txn_detail.otd_txn_ccy%TYPE,
      cursor_cb_ledger       IN OUT SYS_REFCURSOR);

   FUNCTION F_CNT_CB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
      RETURN NUMBER;

   FUNCTION F_SB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
      RETURN ol_sb_ledger_tab;

   PROCEDURE open_cur_sb_ledger (
      in_host_posting_date   IN     ol_txn_header.oth_host_posting_date%TYPE,
      in_merchant_id         IN     ol_txn_header.oth_merchant_id%TYPE,
      in_country             IN     ol_txn_detail.otd_txn_country%TYPE,
      in_service_code        IN     ol_txn_header.oth_service_code%TYPE,
      in_ccy                 IN     ol_txn_detail.otd_txn_ccy%TYPE,
      cursor_sb_ledger       IN OUT SYS_REFCURSOR);

   FUNCTION F_CNT_SB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
      RETURN NUMBER;

   FUNCTION F_RB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
      RETURN ol_rb_ledger_tab;

   PROCEDURE open_cur_rb_ledger (
      in_host_posting_date   IN     ol_txn_header.oth_host_posting_date%TYPE,
      in_merchant_id         IN     ol_txn_header.oth_merchant_id%TYPE,
      in_country             IN     ol_txn_detail.otd_txn_country%TYPE,
      in_service_code        IN     ol_txn_header.oth_service_code%TYPE,
      in_ccy                 IN     ol_txn_detail.otd_txn_ccy%TYPE,
      cursor_rb_ledger       IN OUT SYS_REFCURSOR);

   FUNCTION F_CNT_RB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
      RETURN NUMBER;

END OL_LEDGER_PKG;
/

CREATE OR REPLACE PACKAGE BODY OL_LEDGER_PKG
IS
   FUNCTION F_CB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
      RETURN ol_cb_ledger_tab
   IS
      /* Amended on 20180504, mantis 1079 performance tuning */
      TYPE cursor_rec IS RECORD
      (
         v_txn_id 					VARCHAR (16),
         v_merchant_ref 			ol_txn_header.oth_merchant_ref%TYPE,
         v_txn_code 				ol_txn_header.oth_txn_code%TYPE,
         v_txn_code_desc 			txn_code.tc_desc%TYPE,

         v_amt_type					ol_txn_elements.ote_amt_type%TYPE,
         v_amount					ol_txn_elements.ote_amount%TYPE,

         v_txn_element_type			ol_txn_elements.ote_txn_element_type%TYPE,
         v_txn_element_type_desc	def_element_type.dt_desc%TYPE,
         v_exec_seq					ol_txn_elements.ote_exec_seq%TYPE,
         v_ccy						ol_txn_elements.ote_ccy%TYPE,
         v_approval_timestamp		ol_txn_header.oth_approval_timestamp%TYPE,
         v_approval_date			ol_txn_header.oth_approval_date%TYPE,
         v_void_txn_id				ol_txn_header.oth_org_txn_id%TYPE,
         v_party_type				ol_txn_elements.ote_party_type%TYPE
      );

      TYPE t_cursor_tab IS TABLE OF cursor_rec;
      l_cursor   					t_cursor_tab := t_cursor_tab();

      Result                       ol_cb_ledger_tab := ol_cb_ledger_tab ();
      n                            INTEGER := 0;
      dBal                         NUMBER := 0.0;
      dOpeningBal                  NUMBER := 0.0;
      lTxnId                       ol_txn_header.oth_txn_id%TYPE;

      p_reserve_amount             ol_txn_header.oth_transaction_amount%TYPE;
      p_closing_amount             ol_txn_detail.otd_current_bal%TYPE;
      iCnt                         INTEGER := 0;

      last_open_bal                ol_txn_detail.otd_current_bal%TYPE;
      last_open_bal_settlement     ol_txn_detail.otd_current_bal_settlement%TYPE;
      last_total_reserve_amount    OL_TXN_DETAIL.OTD_TOTAL_RESERVED_AMOUNT%TYPE;
      last_total_hold              ol_txn_detail.otd_total_hold%TYPE;
      last_total_hold_settlement   ol_txn_detail.otd_total_hold_settlement%TYPE;

	  CURSOR cb_ledger_cur
      IS
           SELECT ote_txn_id,
                  oth_merchant_ref,
                  oth_txn_code,
                  tc_desc,
                  ote_amt_type,
                  ote_amount,
                  ote_txn_element_type,
                  --dt_desc,
                  nvl(mt_desc,dt_desc),
                  ote_exec_seq,
                  ote_ccy,
                  oth_approval_timestamp,
                  oth_approval_date,
                  void_txn_id,
                  ote_party_type
             FROM ol_txn_detail,
                  (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                         ote_txn_id,
                          ol_txn_header.oth_merchant_ref,
                          ote_txn_element_type,
                          dt_desc,
                          ote_exec_seq,
                          ote_amount,
                          ote_ccy,
                          ote_amt_type,
                          ol_txn_header.oth_txn_code,
                          tc_desc,
                          ol_txn_header.oth_approval_timestamp,
                          oth_approval_date,
                          oth_reserve_amount,
                          void_th.oth_txn_id void_txn_id,
                          ote_party_type
                     FROM ol_txn_elements,
                          (SELECT oth_txn_id,
                                  oth_txn_code,
                                  oth_approval_timestamp,
                                  oth_approval_date,
                                  oth_merchant_ref,
                                  oth_reserve_amount
                             FROM ol_txn_header
                            WHERE     oth_approval_timestamp >=
                                         in_approval_date_from
                                  AND oth_approval_timestamp <
                                         in_approval_date_to
                                  AND oth_merchant_id = in_merchant_id
                                  AND oth_ar_ind = 'A'
                                  and oth_txn_code not in ('MFM')
                                  AND oth_service_code = in_service_code) ol_txn_header,
                          def_element_type,
                          txn_code,
                          (SELECT oth_txn_id, oth_org_txn_id
                             FROM ol_txn_header
                            WHERE     oth_merchant_id IS NOT NULL
                                  AND oth_ar_ind = 'A'
                                  AND oth_org_txn_id IN
                                         (SELECT oth_txn_id
                                            FROM ol_txn_header
                                           WHERE     oth_approval_timestamp >=
                                                        in_approval_date_from
                                                 AND oth_approval_timestamp <
                                                        in_approval_date_to
                                                 AND oth_merchant_id =
                                                        in_merchant_id
                                                 AND oth_ar_ind = 'A'
                                                 AND oth_service_code =
                                                        in_service_code)
                                  AND oth_txn_code not in ('RLR','ORT','OTT')) void_th
                    WHERE     ote_txn_element_type IN
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
                          AND ote_party_type = 'M'
                          AND ote_ccy = in_ccy
                          AND ote_txn_id = ol_txn_header.oth_txn_id
                          AND ote_txn_element_type = dt_type
                          AND ol_txn_header.oth_txn_code = tc_code
                          AND ol_txn_header.oth_txn_id = void_th.oth_org_txn_id(+))
                          left join map_txn_element on
                          ote_txn_element_type = mt_element      and   oth_txn_code = mt_txn_code
            WHERE otd_txn_id = ote_txn_id AND otd_txn_country = in_country
         ORDER BY oth_approval_timestamp, ote_exec_seq;
   BEGIN
      --dbms_output.put_line('CB Checkpoint 1: '||sysdate);

      /* Retrieve last current balance */
      BEGIN
         SELECT current_bal,
                current_bal_settlement,
                total_reserved_amount,
                total_hold,
                total_hold_settlement
           INTO last_open_bal,
                last_open_bal_settlement,
                last_total_reserve_amount,
                last_total_hold,
                last_total_hold_settlement
           FROM (SELECT NVL (otd_current_bal, 0) as current_bal,
                         NVL (otd_current_bal_settlement, 0) as current_bal_settlement,
                         NVL (otd_total_reserved_amount, 0) as total_reserved_amount,
                         NVL (otd_total_hold, 0) as total_hold,
                         NVL (otd_total_hold_settlement, 0) as total_hold_settlement
                    FROM ol_txn_detail,
                         ol_txn_header
                   WHERE oth_approval_timestamp < in_approval_date_from
                   AND oth_merchant_id = in_merchant_id
                   AND oth_ar_ind = 'A'
                   AND oth_service_code = in_service_code
                   AND oth_net_ccy = in_ccy
                   AND oth_txn_id = otd_txn_id
                   AND otd_txn_country = in_country
                ORDER BY oth_approval_timestamp desc)
           WHERE rownum = 1;


         dBal :=
              last_open_bal
            + last_open_bal_settlement
            - last_total_reserve_amount
            - last_total_hold
            - last_total_hold_settlement;
      EXCEPTION WHEN NO_DATA_FOUND THEN
         --dbms_output.put_line('last current balance - NO_DATA_FOUND');
         dBal := 0;
      END;

	  p_reserve_amount := 0;
	  p_closing_amount := 0;

      OPEN cb_ledger_cur;
      LOOP
	     --dbms_output.put_line('CB Checkpoint 2: '||sysdate);

         /* Amended on 20180504 to use bulk collect, mantis 1079 performance tuning */
         FETCH cb_ledger_cur BULK COLLECT INTO l_cursor limit 1000;

         --dbms_output.put_line('CB Checkpoint 3: '||sysdate);

         /* Amended on 20180504 to extend once for each bulk collect, mantis 1079 performance tuning */
         Result.EXTEND(l_cursor.COUNT);
         --dbms_output.put_line('CB Checkpoint 4: '||sysdate);

         FOR i IN 1..l_cursor.COUNT
         LOOP
            --dbms_output.put_line('CB Checkpoint 5: '||sysdate);

            IF (n = 0)
            THEN
               lTxnId := l_cursor(i).v_txn_id;
               p_closing_amount := 0;
            ELSE
               dBal := p_closing_amount;
            END IF;

            dOpeningBal := dBal;

            IF (l_cursor(i).v_amt_type = 'DR')
            THEN
               IF (l_cursor(i).v_txn_code = 'ODI' or l_cursor(i).v_txn_code = 'MRN')
               THEN
                  IF (l_cursor(i).v_txn_element_type != 'RAMT')
                  THEN
                     --dBal := dBal - v_amount - p_reserve_amount;
                     dBal := dBal - l_cursor(i).v_amount;
                  ELSE
                     dBal := dBal - l_cursor(i).v_amount;
                  END IF;
               ELSE
                  dBal := dBal - l_cursor(i).v_amount;
               END IF;
            ELSE
				IF (l_cursor(i).v_txn_code = 'ODI' or l_cursor(i).v_txn_code = 'MRN')
				THEN
				   IF (l_cursor(i).v_txn_element_type = 'RAMT')
				   THEN
					  --dBal := dBal + v_amount - p_reserve_amount;
					  dBal := dBal + l_cursor(i).v_amount;
				   ELSE
					  dBal := dBal + l_cursor(i).v_amount;
				   END IF;
				ELSE
				   dBal := dBal + l_cursor(i).v_amount;
				END IF;
            END IF;

            --Result.EXTEND;
            n := n + 1;
            --dbms_output.put_line('CB Checkpoint 6: '||sysdate);

            result (n) :=
               ol_cb_ledger_OBJ (l_cursor(i).v_txn_id,
							     l_cursor(i).v_merchant_ref,
							     l_cursor(i).v_txn_code,
							     l_cursor(i).v_txn_code_desc,
							     dOpeningBal,
							     l_cursor(i).v_amt_type,
							     l_cursor(i).v_amount,
							     dBal,
							     l_cursor(i).v_txn_element_type,
							     l_cursor(i).v_txn_element_type_desc,
							     l_cursor(i).v_exec_seq,
							     l_cursor(i).v_ccy,
							     l_cursor(i).v_approval_timestamp,
							     l_cursor(i).v_approval_date,
							     l_cursor(i).v_void_txn_id,
							     l_cursor(i).v_party_type);

            lTxnId := l_cursor(i).v_txn_id;

            IF (l_cursor(i).v_txn_element_type = 'RAMT')
            THEN
               p_reserve_amount := l_cursor(i).v_amount;
            ELSE
               p_reserve_amount := 0;
            END IF;

            p_closing_amount := dBal;
            --dbms_output.put_line('CB Checkpoint 7: '||sysdate);
         END LOOP;--end for loop

         EXIT WHEN cb_ledger_cur%notfound;
      END LOOP;--end cursor loop
	  CLOSE cb_ledger_cur;

      --dbms_output.put_line('CB Checkpoint 8: '||sysdate);
      RETURN (Result);
   END F_CB_LEDGER;

   PROCEDURE open_cur_cb_ledger (
      in_host_posting_date   IN     ol_txn_header.oth_host_posting_date%TYPE,
      in_merchant_id         IN     ol_txn_header.oth_merchant_id%TYPE,
      in_country             IN     ol_txn_detail.otd_txn_country%TYPE,
      in_service_code        IN     ol_txn_header.oth_service_code%TYPE,
      in_ccy                 IN     ol_txn_detail.otd_txn_ccy%TYPE,
      cursor_cb_ledger       IN OUT SYS_REFCURSOR)
   IS
   BEGIN
      OPEN cursor_cb_ledger FOR
         SELECT *
           FROM TABLE (ol_ledger_pkg.f_cb_ledger (
                          TO_DATE (in_host_posting_date, 'YYYYMMDD'),
                          TO_DATE (in_host_posting_date, 'yyyymmdd') + 1,
                          in_merchant_id,
                          in_country,
                          in_service_code,
                          in_ccy));
   END open_cur_cb_ledger;

   FUNCTION F_CNT_CB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
      RETURN NUMBER IS
		n_count NUMBER;
   BEGIN
           SELECT COUNT(*) INTO n_count
             FROM ol_txn_detail,
                  (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                         ote_txn_id,
                          ol_txn_header.oth_merchant_ref,
                          ote_txn_element_type,
                          dt_desc,
                          ote_exec_seq,
                          ote_amount,
                          ote_ccy,
                          ote_amt_type,
                          ol_txn_header.oth_txn_code,
                          tc_desc,
                          ol_txn_header.oth_approval_timestamp,
                          oth_approval_date,
                          oth_reserve_amount,
                          void_th.oth_txn_id void_txn_id,
                          ote_party_type
                     FROM ol_txn_elements,
                          (SELECT oth_txn_id,
                                  oth_txn_code,
                                  oth_approval_timestamp,
                                  oth_approval_date,
                                  oth_merchant_ref,
                                  oth_reserve_amount
                             FROM ol_txn_header
                            WHERE     oth_approval_timestamp >=
                                         in_approval_date_from
                                  AND oth_approval_timestamp <
                                         in_approval_date_to
                                  AND oth_merchant_id = in_merchant_id
                                  AND oth_ar_ind = 'A'
                                  and oth_txn_code not in ('MFM')
                                  AND oth_service_code = in_service_code) ol_txn_header,
                          def_element_type,
                          txn_code,
                          (SELECT oth_txn_id, oth_org_txn_id
                             FROM ol_txn_header
                            WHERE     oth_merchant_id IS NOT NULL
                                  AND oth_ar_ind = 'A'
                                  AND oth_org_txn_id IN
                                         (SELECT oth_txn_id
                                            FROM ol_txn_header
                                           WHERE     oth_approval_timestamp >=
                                                        in_approval_date_from
                                                 AND oth_approval_timestamp <
                                                        in_approval_date_to
                                                 AND oth_merchant_id =
                                                        in_merchant_id
                                                 AND oth_ar_ind = 'A'
                                                 AND oth_service_code =
                                                        in_service_code)
                                  AND oth_txn_code not in ('RLR','ORT','OTT')) void_th
                    WHERE     ote_txn_element_type IN
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
                          AND ote_party_type = 'M'
                          AND ote_ccy = in_ccy
                          AND ote_txn_id = ol_txn_header.oth_txn_id
                          AND ote_txn_element_type = dt_type
                          AND ol_txn_header.oth_txn_code = tc_code
                          AND ol_txn_header.oth_txn_id = void_th.oth_org_txn_id(+))
                          left join map_txn_element on
                          ote_txn_element_type = mt_element      and   oth_txn_code = mt_txn_code
            WHERE otd_txn_id = ote_txn_id AND otd_txn_country = in_country;

      RETURN n_count;

   EXCEPTION
   WHEN NO_DATA_FOUND THEN
      RETURN 0;
   END F_CNT_CB_LEDGER;

   FUNCTION F_SB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
      RETURN ol_sb_ledger_tab
   IS
      /* Amended on 20180504, mantis 1079 performance tuning */
      TYPE cursor_rec IS RECORD
      (
         v_txn_id 					VARCHAR (16),
         v_merchant_ref 			ol_txn_header.oth_merchant_ref%TYPE,
         v_txn_code 				ol_txn_header.oth_txn_code%TYPE,
         v_txn_code_desc 			txn_code.tc_desc%TYPE,

         v_amt_type					ol_txn_elements.ote_amt_type%TYPE,
         v_amount					ol_txn_elements.ote_amount%TYPE,

         v_txn_element_type			ol_txn_elements.ote_txn_element_type%TYPE,
         v_txn_element_type_desc	def_element_type.dt_desc%TYPE,
         v_exec_seq					ol_txn_elements.ote_exec_seq%TYPE,
         v_ccy						ol_txn_elements.ote_ccy%TYPE,
         v_approval_timestamp		ol_txn_header.oth_approval_timestamp%TYPE,
         v_approval_date			ol_txn_header.oth_approval_date%TYPE,
         --v_void_txn_id			ol_txn_header.oth_org_txn_id%TYPE,
         v_party_type				ol_txn_elements.ote_party_type%TYPE
      );

      TYPE t_cursor_tab IS TABLE OF cursor_rec;
      l_cursor   					t_cursor_tab := t_cursor_tab();

      Result                       ol_sb_ledger_tab := ol_sb_ledger_tab ();
      n                            INTEGER := 0;
      dBal                         NUMBER := 0.0;
      dOpeningBal                  NUMBER := 0.0;
      lTxnId                       ol_txn_header.oth_txn_id%TYPE;

      p_reserve_amount             ol_txn_header.oth_transaction_amount%TYPE;
      p_closing_amount             ol_txn_detail.otd_current_bal%TYPE;
      iCnt                         INTEGER := 0;

      last_total_hold              ol_txn_detail.otd_total_hold%TYPE;
      last_total_hold_settlement   ol_txn_detail.otd_total_hold_settlement%TYPE;

	  CURSOR sb_ledger_cur
      IS
           SELECT ote_txn_id,
                  oth_merchant_ref,
                  oth_txn_code,
                  tc_desc,
				  DECODE (ote_amt_type,  'DR', 'CR',  'CR', 'DR'),
				  ote_amount,
                  ote_txn_element_type,
                  dt_desc,
                  ote_exec_seq,
                  ote_ccy,
                  oth_approval_timestamp,
                  oth_approval_date,
                  ote_party_type
             FROM ol_txn_detail,
                  (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                         ote_txn_id,
                          ol_txn_header.oth_merchant_ref,
                          ote_txn_element_type,
                          dt_desc,
                          ote_exec_seq,
                          ote_amount,
                          ote_ccy,
                          ote_amt_type,
                          ol_txn_header.oth_txn_code,
                          tc_desc,
                          ol_txn_header.oth_approval_timestamp,
                          ol_txn_header.oth_approval_date,
                          oth_reserve_amount,
                          ote_party_type
                     FROM ol_txn_elements,
                          (SELECT oth_txn_id,
                                  oth_txn_code,
                                  oth_approval_timestamp,
                                  oth_approval_date,
                                  oth_merchant_ref,
                                  oth_reserve_amount
                             FROM ol_txn_header
                            WHERE     oth_approval_timestamp >=
                                         in_approval_date_from
                                  AND oth_approval_timestamp <
                                         in_approval_date_to
                                  AND oth_merchant_id = in_merchant_id
                                  AND oth_ar_ind = 'A'
                                  AND oth_service_code = in_service_code) ol_txn_header,
                          def_element_type,
                          txn_code
                    WHERE     ote_txn_element_type IN ('UAMT', 'HAMT','HOPO','UOPO')
                          AND ote_party_type = 'M'
                          AND ote_ccy = in_ccy
                          AND ote_txn_id = ol_txn_header.oth_txn_id
                          AND ote_txn_element_type = dt_type
                          AND ol_txn_header.oth_txn_code = tc_code)
            WHERE otd_txn_id = ote_txn_id AND otd_txn_country = in_country
         ORDER BY oth_approval_timestamp, ote_exec_seq;
   BEGIN
      --dbms_output.put_line('SB Checkpoint 1: '||sysdate);

      /* Retrieve last lien balance */
      BEGIN
         SELECT total_hold, total_hold_settlement
           INTO last_total_hold, last_total_hold_settlement
           FROM (SELECT NVL (otd_total_hold, 0) as total_hold,
                         NVL (otd_total_hold_settlement, 0) as total_hold_settlement
                    FROM ol_txn_detail,
                         ol_txn_header
                   WHERE oth_approval_timestamp < in_approval_date_from
                   AND oth_merchant_id = in_merchant_id
                   AND oth_ar_ind = 'A'
                   AND oth_service_code = in_service_code
                   AND oth_net_ccy = in_ccy
                   AND oth_txn_id = otd_txn_id
                   AND otd_txn_country = in_country
                ORDER BY oth_approval_timestamp desc)
           WHERE rownum = 1;


         dBal := last_total_hold + last_total_hold_settlement;
      EXCEPTION WHEN NO_DATA_FOUND THEN
         --dbms_output.put_line('last lien balance - NO_DATA_FOUND');
         dBal := 0;
      END;

      p_reserve_amount := 0;
      p_closing_amount := 0;

      OPEN sb_ledger_cur;
	  LOOP
	     --dbms_output.put_line('SB Checkpoint 2: '||sysdate);

         /* Amended on 20180504 to use bulk collect, mantis 1079 performance tuning */
         FETCH sb_ledger_cur BULK COLLECT INTO l_cursor limit 1000;

         --dbms_output.put_line('SB Checkpoint 3: '||sysdate);

         /* Amended on 20180504 to extend once for each bulk collect, mantis 1079 performance tuning */
         Result.EXTEND(l_cursor.COUNT);
         --dbms_output.put_line('SB Checkpoint 4: '||sysdate);

         FOR i IN 1..l_cursor.COUNT
         LOOP
            --dbms_output.put_line('SB Checkpoint 5: '||sysdate);

            IF (n = 0)
            THEN
               lTxnId := l_cursor(i).v_txn_id;
               p_closing_amount := 0;
            ELSE
               dBal := p_closing_amount;
            END IF;

            dOpeningBal := dBal;

            IF (l_cursor(i).v_amt_type = 'DR')
            THEN
               dBal := dBal - l_cursor(i).v_amount;
            ELSE
               dBal := dBal + l_cursor(i).v_amount;
            END IF;

            --Result.EXTEND;
            n := n + 1;
			--dbms_output.put_line('SB Checkpoint 6: '||sysdate);

            result (n) :=
               ol_sb_ledger_OBJ (l_cursor(i).v_txn_id,
                                 l_cursor(i).v_merchant_ref,
                                 l_cursor(i).v_txn_code,
                                 l_cursor(i).v_txn_code_desc,
                                 dOpeningBal,
                                 l_cursor(i).v_amt_type,
                                 l_cursor(i).v_amount,
                                 dBal,
                                 l_cursor(i).v_txn_element_type,
                                 l_cursor(i).v_txn_element_type_desc,
                                 l_cursor(i).v_exec_seq,
                                 l_cursor(i).v_ccy,
                                 l_cursor(i).v_approval_timestamp,
                                 l_cursor(i).v_approval_date,
                                 l_cursor(i).v_party_type);

            lTxnId := l_cursor(i).v_txn_id;

            IF (l_cursor(i).v_txn_element_type = 'RAMT')
            THEN
               p_reserve_amount := l_cursor(i).v_amount;
            ELSE
               p_reserve_amount := 0;
            END IF;

            p_closing_amount := dBal;
            --dbms_output.put_line('SB Checkpoint 7: '||sysdate);
         END LOOP;--end for loop

         EXIT WHEN sb_ledger_cur%notfound;
      END LOOP;--end cursor loop
	  CLOSE sb_ledger_cur;

      --dbms_output.put_line('SB Checkpoint 8: '||sysdate);
      RETURN (Result);
   END F_SB_LEDGER;

   PROCEDURE open_cur_sb_ledger (
      in_host_posting_date   IN     ol_txn_header.oth_host_posting_date%TYPE,
      in_merchant_id         IN     ol_txn_header.oth_merchant_id%TYPE,
      in_country             IN     ol_txn_detail.otd_txn_country%TYPE,
      in_service_code        IN     ol_txn_header.oth_service_code%TYPE,
      in_ccy                 IN     ol_txn_detail.otd_txn_ccy%TYPE,
      cursor_sb_ledger       IN OUT SYS_REFCURSOR)
   IS
   BEGIN
      OPEN cursor_sb_ledger FOR
         SELECT *
           FROM TABLE (ol_ledger_pkg.f_sb_ledger (
                          TO_DATE (in_host_posting_date, 'YYYYMMDD'),
                          TO_DATE (in_host_posting_date, 'yyyymmdd') + 1,
                          in_merchant_id,
                          in_country,
                          in_service_code,
                          in_ccy));
   END open_cur_sb_ledger;

   FUNCTION F_CNT_SB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
      RETURN NUMBER IS
		n_count NUMBER;
   BEGIN
           SELECT COUNT(*) INTO n_count
             FROM ol_txn_detail,
                  (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                         ote_txn_id,
                          ol_txn_header.oth_merchant_ref,
                          ote_txn_element_type,
                          dt_desc,
                          ote_exec_seq,
                          ote_amount,
                          ote_ccy,
                          ote_amt_type,
                          ol_txn_header.oth_txn_code,
                          tc_desc,
                          ol_txn_header.oth_approval_timestamp,
                          oth_approval_date,
                          oth_reserve_amount,
                          ote_party_type
                     FROM ol_txn_elements,
                          (SELECT oth_txn_id,
                                  oth_txn_code,
                                  oth_approval_timestamp,
                                  oth_approval_date,
                                  oth_merchant_ref,
                                  oth_reserve_amount
                             FROM ol_txn_header
                            WHERE     oth_approval_timestamp >=
                                         in_approval_date_from
                                  AND oth_approval_timestamp <
                                         in_approval_date_to
                                  AND oth_merchant_id = in_merchant_id
                                  AND oth_ar_ind = 'A'
                                  AND oth_service_code = in_service_code) ol_txn_header,
                          def_element_type,
                          txn_code
                     WHERE     ote_txn_element_type IN ('UAMT', 'HAMT','HOPO','UOPO')
                          AND ote_party_type = 'M'
                          AND ote_ccy = in_ccy
                          AND ote_txn_id = ol_txn_header.oth_txn_id
                          AND ote_txn_element_type = dt_type
                          AND ol_txn_header.oth_txn_code = tc_code)
            WHERE otd_txn_id = ote_txn_id AND otd_txn_country = in_country;

    RETURN n_count;

   EXCEPTION
   WHEN NO_DATA_FOUND THEN
      RETURN 0;
   END F_CNT_SB_LEDGER;

   FUNCTION F_RB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
      RETURN ol_rb_ledger_tab
   IS
      /* Amended on 20180504, mantis 1079 performance tuning */
      TYPE cursor_rec IS RECORD
      (
         v_txn_id 					VARCHAR (16),
         v_merchant_ref 			ol_txn_header.oth_merchant_ref%TYPE,
         v_txn_code 				ol_txn_header.oth_txn_code%TYPE,
         v_txn_code_desc 			txn_code.tc_desc%TYPE,

         v_amt_type					ol_txn_elements.ote_amt_type%TYPE,
         v_amount					ol_txn_elements.ote_amount%TYPE,

         v_txn_element_type			ol_txn_elements.ote_txn_element_type%TYPE,
         v_txn_element_type_desc	def_element_type.dt_desc%TYPE,
         v_exec_seq					ol_txn_elements.ote_exec_seq%TYPE,
         v_ccy						ol_txn_elements.ote_ccy%TYPE,
         v_approval_timestamp		ol_txn_header.oth_approval_timestamp%TYPE,
         v_approval_date			ol_txn_header.oth_approval_date%TYPE,
         v_void_txn_id				ol_txn_header.oth_org_txn_id%TYPE,
         v_party_type				ol_txn_elements.ote_party_type%TYPE
      );

      TYPE t_cursor_tab IS TABLE OF cursor_rec;
      l_cursor   					t_cursor_tab := t_cursor_tab();

      Result                       ol_rb_ledger_tab := ol_rb_ledger_tab ();
      n                            INTEGER := 0;
      dBal                         NUMBER := 0.0;
      dOpeningBal                  NUMBER := 0.0;
      lTxnId                       ol_txn_header.oth_txn_id%TYPE;

      p_reserve_amount             ol_txn_header.oth_transaction_amount%TYPE;
      p_closing_amount             ol_txn_detail.otd_current_bal%TYPE;
      iCnt                         INTEGER := 0;

      last_total_reserve_amount    OL_TXN_DETAIL.OTD_TOTAL_RESERVED_AMOUNT%TYPE;

      CURSOR rb_ledger_cur
      IS
           SELECT ote_txn_id,
                  oth_merchant_ref,
                  oth_txn_code,
                  tc_desc,
				  DECODE (ote_amt_type,  'DR', 'CR',  'CR', 'DR'),
				  ote_amount,
                  ote_txn_element_type,
                  --dt_desc,
                  nvl(mt_desc,dt_desc),
                  ote_exec_seq,
                  ote_ccy,
                  oth_approval_timestamp,
                  oth_approval_date,
                  void_txn_id,
                  ote_party_type
             FROM ol_txn_detail,
                  (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                         ote_txn_id,
                          ol_txn_header.oth_merchant_ref,
                          ote_txn_element_type,
                          dt_desc,
                          ote_exec_seq,
                          ote_amount,
                          ote_ccy,
                          ote_amt_type,
                          ol_txn_header.oth_txn_code,
                          tc_desc,
                          ol_txn_header.oth_approval_timestamp,
                          ol_txn_header.oth_approval_date,
                          oth_reserve_amount,
                          void_th.oth_txn_id void_txn_id,
                          ote_party_type
                     FROM ol_txn_elements,
                          (SELECT oth_txn_id,
                                  oth_txn_code,
                                  oth_approval_timestamp,
                                  oth_approval_date,
                                  oth_merchant_ref,
                                  oth_reserve_amount
                             FROM ol_txn_header
                            WHERE     oth_approval_timestamp >=
                                         in_approval_date_from
                                  AND oth_approval_timestamp <
                                         in_approval_date_to
                                  AND oth_merchant_id = in_merchant_id
                                  AND oth_ar_ind = 'A'
                                  AND oth_service_code = in_service_code
                                  ) ol_txn_header,
                          def_element_type,
                          txn_code,
                          (SELECT oth_txn_id, oth_org_txn_id
                             FROM ol_txn_header
                            WHERE     oth_merchant_id IS NOT NULL
                                  AND oth_ar_ind = 'A'
                                  AND oth_org_txn_id IN
                                         (SELECT oth_txn_id
                                            FROM ol_txn_header
                                           WHERE     oth_approval_timestamp >=
                                                        in_approval_date_from
                                                 AND oth_approval_timestamp <
                                                        in_approval_date_to
                                                 AND oth_merchant_id =
                                                        in_merchant_id
                                                 AND oth_ar_ind = 'A'
                                                 AND oth_service_code =
                                                        in_service_code)
                                  AND oth_txn_code not in ('RLR')
                    ) void_th
                    WHERE     ote_txn_element_type IN ('RAMT')
                          AND ote_party_type = 'M'
                          AND ote_ccy = in_ccy
                          AND ote_txn_id = ol_txn_header.oth_txn_id
                          AND ote_txn_element_type = dt_type
                          AND ol_txn_header.oth_txn_code = tc_code
                          AND ol_txn_header.oth_txn_id = void_th.oth_org_txn_id(+))
                          left join map_txn_element on
                          ote_txn_element_type = mt_element      and   oth_txn_code = mt_txn_code
            WHERE otd_txn_id = ote_txn_id AND otd_txn_country = in_country
         ORDER BY oth_approval_timestamp, ote_exec_seq;
   BEGIN
      --dbms_output.put_line('RB Checkpoint 1: '||sysdate);

      /* Retrieve last holdback balance */
      BEGIN
         SELECT total_reserved_amount
           INTO last_total_reserve_amount
           FROM (SELECT NVL (otd_total_reserved_amount, 0) as total_reserved_amount
                    FROM ol_txn_detail,
                         ol_txn_header
                   WHERE oth_approval_timestamp < in_approval_date_from
                   AND oth_merchant_id = in_merchant_id
                   AND oth_ar_ind = 'A'
                   AND oth_service_code = in_service_code
                   AND oth_net_ccy = in_ccy
                   AND oth_txn_id = otd_txn_id
                   AND otd_txn_country = in_country
                ORDER BY oth_approval_timestamp desc)
           WHERE rownum = 1;


         dBal := last_total_reserve_amount;
      EXCEPTION WHEN NO_DATA_FOUND THEN
         --dbms_output.put_line('last holdback balance - NO_DATA_FOUND');
         dBal := 0;
      END;

      p_reserve_amount := 0;
      p_closing_amount := 0;

      OPEN rb_ledger_cur;
      LOOP
         --dbms_output.put_line('RB Checkpoint 2: '||sysdate);

         /* Amended on 20180504 to use bulk collect, mantis 1079 performance tuning */
         FETCH rb_ledger_cur BULK COLLECT INTO l_cursor limit 1000;

         --dbms_output.put_line('RB Checkpoint 3: '||sysdate);

         /* Amended on 20180504 to extend once for each bulk collect, mantis 1079 performance tuning */
         Result.EXTEND(l_cursor.COUNT);
         --dbms_output.put_line('RB Checkpoint 4: '||sysdate);

         FOR i IN 1..l_cursor.COUNT
         LOOP
            --dbms_output.put_line('RB Checkpoint 5: '||sysdate);

            IF (n = 0)
            THEN
				lTxnId := l_cursor(i).v_txn_id;
				p_closing_amount := 0;
            ELSE
				dBal := p_closing_amount;
            END IF;

            dOpeningBal := dBal;

            IF (l_cursor(i).v_amt_type = 'DR')
            THEN
               dBal := dBal - l_cursor(i).v_amount;
            ELSE
               dBal := dBal + l_cursor(i).v_amount;
            END IF;

            --Result.EXTEND;
            n := n + 1;
            --dbms_output.put_line('RB Checkpoint 6: '||sysdate);

            result (n) :=
               ol_rb_ledger_OBJ (l_cursor(i).v_txn_id,
                                 l_cursor(i).v_merchant_ref,
                                 l_cursor(i).v_txn_code,
                                 l_cursor(i).v_txn_code_desc,
                                 dOpeningBal,
                                 l_cursor(i).v_amt_type,
                                 l_cursor(i).v_amount,
                                 dBal,
                                 l_cursor(i).v_txn_element_type,
                                 l_cursor(i).v_txn_element_type_desc,
                                 l_cursor(i).v_exec_seq,
                                 l_cursor(i).v_ccy,
                                 l_cursor(i).v_approval_timestamp,
                                 l_cursor(i).v_approval_date,
                                 l_cursor(i).v_void_txn_id,
                                 l_cursor(i).v_party_type);

            lTxnId := l_cursor(i).v_txn_id;

            IF (l_cursor(i).v_txn_element_type = 'RAMT')
            THEN
               p_reserve_amount := l_cursor(i).v_amount;
            ELSE
               p_reserve_amount := 0;
            END IF;

            p_closing_amount := dBal;
            --dbms_output.put_line('RB Checkpoint 7: '||sysdate);
         END LOOP;--end for loop

         EXIT WHEN rb_ledger_cur%notfound;
      END LOOP;--end cursor loop
	  CLOSE rb_ledger_cur;

      --dbms_output.put_line('RB Checkpoint 8: '||sysdate);
      RETURN (Result);
   END F_RB_LEDGER;

   PROCEDURE open_cur_rb_ledger (
      in_host_posting_date   IN     ol_txn_header.oth_host_posting_date%TYPE,
      in_merchant_id         IN     ol_txn_header.oth_merchant_id%TYPE,
      in_country             IN     ol_txn_detail.otd_txn_country%TYPE,
      in_service_code        IN     ol_txn_header.oth_service_code%TYPE,
      in_ccy                 IN     ol_txn_detail.otd_txn_ccy%TYPE,
      cursor_rb_ledger       IN OUT SYS_REFCURSOR)
   IS
   BEGIN
      OPEN cursor_rb_ledger FOR
         SELECT *
           FROM TABLE (ol_ledger_pkg.f_rb_ledger (
                          TO_DATE (in_host_posting_date, 'YYYYMMDD'),
                          TO_DATE (in_host_posting_date, 'yyyymmdd') + 1,
                          in_merchant_id,
                          in_country,
                          in_service_code,
                          in_ccy));
   END open_cur_rb_ledger;

   FUNCTION F_CNT_RB_LEDGER (
      in_approval_date_from    ol_txn_header.oth_approval_timestamp%TYPE,
      in_approval_date_to      ol_txn_header.oth_approval_timestamp%TYPE,
      in_merchant_id           ol_txn_header.oth_merchant_id%TYPE,
      in_country               ol_txn_detail.otd_txn_country%TYPE,
      in_service_code          ol_txn_header.oth_service_code%TYPE,
      in_ccy                   ol_txn_detail.otd_txn_ccy%TYPE)
     RETURN NUMBER IS
		n_count NUMBER;
   BEGIN
           SELECT COUNT(*) INTO n_count
             FROM ol_txn_detail,
                  (SELECT --/*+ LEADING (TXN_ELEMENTS) */
                         ote_txn_id,
                          ol_txn_header.oth_merchant_ref,
                          ote_txn_element_type,
                          dt_desc,
                          ote_exec_seq,
                          ote_amount,
                          ote_ccy,
                          ote_amt_type,
                          ol_txn_header.oth_txn_code,
                          tc_desc,
                          ol_txn_header.oth_approval_timestamp,
                          ol_txn_header.oth_approval_date,
                          oth_reserve_amount,
                          void_th.oth_txn_id void_txn_id,
              ote_party_type
                     FROM ol_txn_elements,
                          (SELECT oth_txn_id,
                                  oth_txn_code,
                                  oth_approval_timestamp,
                                  oth_approval_date,
                                  oth_merchant_ref,
                                  oth_reserve_amount
                             FROM ol_txn_header
                            WHERE     oth_approval_timestamp >=
                                         in_approval_date_from
                                  AND oth_approval_timestamp <
                                         in_approval_date_to
                                  AND oth_merchant_id = in_merchant_id
                                  AND oth_ar_ind = 'A'
                                  AND oth_service_code = in_service_code
                                  ) ol_txn_header,
                          def_element_type,
                          txn_code,
                          (SELECT oth_txn_id, oth_org_txn_id
                             FROM ol_txn_header
                            WHERE     oth_merchant_id IS NOT NULL
                                  AND oth_ar_ind = 'A'
                                  AND oth_org_txn_id IN
                                         (SELECT oth_txn_id
                                            FROM ol_txn_header
                                           WHERE     oth_approval_timestamp >=
                                                        in_approval_date_from
                                                 AND oth_approval_timestamp <
                                                        in_approval_date_to
                                                 AND oth_merchant_id =
                                                        in_merchant_id
                                                 AND oth_ar_ind = 'A'
                                                 AND oth_service_code =
                                                        in_service_code)
                                    AND oth_txn_code not in ('RLR')
                    ) void_th
                    WHERE     ote_txn_element_type IN ('RAMT')
                          AND ote_party_type = 'M'
                          AND ote_ccy = in_ccy
                          AND ote_txn_id = ol_txn_header.oth_txn_id
                          AND ote_txn_element_type = dt_type
                          AND ol_txn_header.oth_txn_code = tc_code
                          AND ol_txn_header.oth_txn_id = void_th.oth_org_txn_id(+))
                          left join map_txn_element on
                          ote_txn_element_type = mt_element      and   oth_txn_code = mt_txn_code
            WHERE otd_txn_id = ote_txn_id AND otd_txn_country = in_country;

      RETURN n_count;

   EXCEPTION
   WHEN NO_DATA_FOUND THEN
      RETURN 0;
   END F_CNT_RB_LEDGER;

END OL_LEDGER_PKG;
/

