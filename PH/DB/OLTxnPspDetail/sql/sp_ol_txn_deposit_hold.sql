CREATE OR REPLACE FUNCTION sp_ol_txn_deposit_hold (
   in_stat_txn_id         ol_statement_detail.olsd_stat_txn_id%TYPE,
   in_txn_ccy             ol_statement_detail.olsd_txn_ccy%TYPE,
   in_txn_amount          ol_statement_detail.olsd_txn_amount%TYPE,
   in_txn_date            ol_statement_detail.olsd_statement_date%TYPE,
   in_txn_time            ol_statement_detail.olsd_statement_time%TYPE,
   in_bank_code           ol_statement_detail.olsd_int_bank_code%TYPE,
   in_bank_acct_num       ol_statement_detail.olsd_bank_acct_num%TYPE,
   out_txn_id         OUT ol_txn_psp_detail.otp_txn_id%TYPE)
   RETURN NUMBER
IS
   TMP    ol_txn_psp_detail.otp_txn_id%TYPE;
BEGIN
   FOR RESULT1
      IN (  SELECT olsd_stat_txn_id
              FROM OL_STATEMENT_DETAIL
             WHERE     olsd_txn_ccy = in_txn_ccy
                   AND olsd_amt_type = 'CR'
                   AND olsd_txn_amount = in_txn_amount
                   AND olsd_create_timestamp >=
                            SYSDATE
                          -   (SELECT TO_NUMBER (SP_VAL)
                                 FROM SYSTEM_PARAMETER
                                WHERE SP_CODE = 'OFL_AUTO_HOLD_RANGE')
                            / 24
                   AND olsd_create_timestamp <= SYSDATE
                   AND olsd_int_bank_code = in_bank_code
                   AND olsd_bank_acct_num = in_bank_acct_num
                   AND olsd_statement_ref IS NOT NULL
          ORDER BY olsd_stat_txn_id DESC)
   LOOP
      FOR RESULT2
         IN (  SELECT ostp_txn_id
                 FROM OL_STMT_TXN_RELATION, 
		      OL_BAID_TXN	
                WHERE     obt_stat_txn_id = RESULT1.olsd_stat_txn_id
		      AND ostp_stmt_txn_id = obt_txn_id	
                      AND EXISTS
                             (SELECT oth_txn_id
                                FROM OL_TXN_HEADER
                               WHERE     oth_txn_id = ostp_txn_id
                                     AND oth_txn_code = 'OBD')
             ORDER BY ostp_txn_id DESC)
      LOOP
         SELECT oth_txn_id
           INTO TMP
           FROM OL_TXN_HEADER
          WHERE oth_txn_id = RESULT2.ostp_txn_id
         FOR UPDATE;

         UPDATE OL_TXN_PSP_DETAIL
            SET OTP_UPDATE_USER = 'SYSTEM',
                OTP_UPDATE_TIMESTAMP = SYSDATE,
                OTP_TXN_HOLD_IND = 1
          WHERE     OTP_TXN_ID = RESULT2.ostp_txn_id
                AND EXISTS
                       (SELECT oth_txn_id
                          FROM OL_TXN_HEADER
                         WHERE     oth_txn_id = RESULT2.ostp_txn_id
                               AND oth_txn_code = 'OBD'
                               AND oth_status = 'C'
                               AND oth_ar_ind = 'A'
                               AND oth_sub_status IN ('139'));

         IF SQL%ROWCOUNT = 1
         THEN
            INSERT INTO ol_txn_deposit_hold_log (otdh_txn_id,
                                                 otdh_exec_seq,
                                                 otdh_txn_hold_ind,
                                                 otdh_stat_txn_id,
                                                 otdh_remark,
                                                 otdh_create_user,
                                                 otdh_create_timestamp)
                 VALUES (RESULT2.ostp_txn_id,
                         (SELECT NVL (MAX (otdh_exec_seq), 0) + 1
                            FROM ol_txn_deposit_hold_log
                           WHERE otdh_txn_id = RESULT2.ostp_txn_id),
                         1,
                         in_stat_txn_id,
                         'System Hold',
                         'SYSTEM',
                         SYSDATE);

            out_txn_id := RESULT2.ostp_txn_id;
         ELSE
            INSERT INTO ol_txn_deposit_hold_log (otdh_txn_id,
                                                 otdh_exec_seq,
                                                 otdh_txn_hold_ind,
                                                 otdh_stat_txn_id,
                                                 otdh_remark,
                                                 otdh_create_user,
                                                 otdh_create_timestamp)
                 VALUES (RESULT2.ostp_txn_id,
                         (SELECT NVL (MAX (otdh_exec_seq), 0) + 1
                            FROM ol_txn_deposit_hold_log
                           WHERE otdh_txn_id = RESULT2.ostp_txn_id),
                         0,
                         in_stat_txn_id,
                         'System Hold Unsuccess',
                         'SYSTEM',
                         SYSDATE);
         END IF;

         RETURN 0;
      END LOOP;

      RETURN 0;
   END LOOP;

   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_ol_txn_deposit_hold;
/

