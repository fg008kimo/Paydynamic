CREATE OR REPLACE PACKAGE CRRJNL_PKG is

	TYPE   RPT001_type is REF cursor return report_rpt001_view%rowtype;

	function F_RPT001(in_approval_date_from  txn_header.th_approval_timestamp%type,
                    in_approval_date_to  txn_header.th_approval_timestamp%type,
                    in_merchant_id   txn_header.th_merchant_id%type,
                    in_country       txn_detail.td_txn_country%type,
                    in_service_code  txn_header.th_service_code%type,
                    in_ccy           txn_detail.td_txn_ccy%type
                  ) return rpt001_tab;
	procedure open_cur_rpt001(
       	    in_host_posting_date in     txn_header.th_host_posting_date%type,
            in_merchant_id       in     txn_header.th_merchant_id%type,
            in_country           in     txn_detail.td_txn_country%type,
            in_service_code      in     txn_header.th_service_code%type,
            in_ccy               IN     txn_detail.td_txn_ccy%type,
            cursor_rpt001        IN OUT RPT001_type);

end CRRJNL_PKG;
/

CREATE OR REPLACE PACKAGE BODY CRRJNL_PKG
IS
   FUNCTION F_RPT001 (
      in_approval_date_from    txn_header.th_approval_timestamp%TYPE,
      in_approval_date_to      txn_header.th_approval_timestamp%TYPE,
      in_merchant_id           txn_header.th_merchant_id%TYPE,
      in_country               txn_detail.td_txn_country%TYPE,
      in_service_code          txn_header.th_service_code%TYPE,
      in_ccy                   txn_detail.td_txn_ccy%TYPE)
      RETURN rpt001_tab
   IS
      Result                    rpt001_tab := rpt001_tab ();
      n                         INTEGER := 0;
      dBal                      NUMBER := 0.0;
      dOpeningBal               NUMBER := 0.0;
      lTxnId                    txn_header.th_txn_id%TYPE;

      v_txn_id                  txn_header.th_txn_id%TYPE;
      v_merchant_ref            txn_header.th_merchant_ref%TYPE;
      v_txn_code                txn_header.th_txn_code%TYPE;
      v_txn_code_desc           txn_code.tc_desc%TYPE;
      v_open_bal                txn_elements.te_amount%TYPE;
      v_current_bal             txn_elements.te_amount%TYPE;
      v_txn_element_type        txn_elements.te_txn_element_type%TYPE;
      v_txn_element_type_desc   def_element_type.dt_desc%TYPE;
      v_exec_seq                txn_elements.te_exec_seq%TYPE;
      v_amount                  txn_elements.te_amount%TYPE;
      v_ccy                     txn_elements.te_ccy%TYPE;
      v_amt_type                txn_elements.te_amt_type%TYPE;
      v_approval_date           txn_header.th_approval_timestamp%TYPE;
      v_void_txn_id             txn_header.th_org_txn_id%TYPE;


      CURSOR rpt001_cur
      IS
           SELECT te_txn_id,
                  th_merchant_ref,
                  th_txn_code,
                  tc_desc,
                  NVL (td_open_bal, 0),
                  td_current_bal,
                  te_txn_element_type,
                  dt_desc,
                  te_exec_seq,
                  te_amount,
                  te_ccy,
                  te_amt_type,
                  th_approval_timestamp,
                  void_txn_id
             FROM txn_detail,
                  (SELECT /*+ LEADING (TXN_ELEMENTS) */
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
                          void_th.th_txn_id void_txn_id
                     FROM txn_elements,
                          (SELECT th_txn_id,
                                  th_txn_code,
                                  th_approval_timestamp,
                                  th_merchant_ref
                             FROM txn_header
                            WHERE     th_approval_timestamp >=
                                         in_approval_date_from
                                  AND th_approval_timestamp <
                                         in_approval_date_to
                                  AND th_merchant_id = in_merchant_id
                                  AND th_ar_ind = 'A'
                                  AND th_service_code = in_service_code) txn_header,
                          def_element_type,
                          txn_code,
                          (select th_txn_id, th_org_txn_id from txn_header where th_merchant_id IS NOT NULL) void_th
                    WHERE     te_txn_element_type IN ('TAMT', 'TFEE')
                          AND te_party_type = 'M'
                          AND te_ccy = in_ccy
                          AND te_txn_id = txn_header.th_txn_id
                          AND te_txn_element_type = dt_type
                          AND txn_header.th_txn_code = tc_code
                          AND txn_header.th_txn_id = void_th.th_org_txn_id(+))
            WHERE td_txn_id = te_txn_id AND td_txn_country = in_country
         ORDER BY th_approval_timestamp, te_exec_seq;
   BEGIN
      OPEN rpt001_cur;

      LOOP
         FETCH rpt001_cur
         INTO v_txn_id,
              v_merchant_ref,
              v_txn_code,
              v_txn_code_desc,
              v_open_bal,
              v_current_bal,
              v_txn_element_type,
              v_txn_element_type_desc,
              v_exec_seq,
              v_amount,
              v_ccy,
              v_amt_type,
              v_approval_date,
              v_void_txn_id;

         EXIT WHEN rpt001_cur%NOTFOUND;

         IF (n = 0)
         THEN
            lTxnId := v_txn_id;
            dBal := v_open_bal;
         END IF;

         IF (lTxnId != v_txn_id)
         THEN
            dBal := v_open_bal;
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
            RPT001_OBj (v_txn_id,
                        v_merchant_ref,
                        v_txn_code,
                        v_txn_code_desc,
                        dOpeningBal,
                        v_current_bal,
                        v_txn_element_type,
                        v_txn_element_type_desc,
                        v_exec_seq,
                        v_amount,
                        v_ccy,
                        v_amt_type,
                        dBal,
                        v_approval_date,
                        v_void_txn_id);
         lTxnId := v_txn_id;
      END LOOP;

      CLOSE rpt001_cur;

      RETURN (Result);
   END;

   PROCEDURE open_cur_rpt001 (
      in_host_posting_date   IN     txn_header.th_host_posting_date%TYPE,
      in_merchant_id         IN     txn_header.th_merchant_id%TYPE,
      in_country             IN     txn_detail.td_txn_country%TYPE,
      in_service_code        IN     txn_header.th_service_code%TYPE,
      in_ccy                 IN     txn_detail.td_txn_ccy%TYPE,
      cursor_rpt001          IN OUT RPT001_type)
   IS
   BEGIN
      OPEN cursor_rpt001 FOR
         SELECT *
           FROM TABLE (CRRJNL_PKG.F_rpt001 (
                          TO_DATE (in_host_posting_date, 'yyyymmdd'),
                          TO_DATE (in_host_posting_date, 'yyyymmdd') + 1,
                          in_merchant_id,
                          in_country,
                          in_service_code,
                          in_ccy));
   END open_cur_rpt001;


END CRRJNL_PKG;
/
