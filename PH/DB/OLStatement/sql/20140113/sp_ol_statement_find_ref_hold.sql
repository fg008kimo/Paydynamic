CREATE OR REPLACE FUNCTION sp_ol_statement_find_ref_hold (
   in_filename             ol_statement_detail.olsd_filename%TYPE,
   in_statement_seq        ol_statement_detail.olsd_statement_seq%TYPE,
   in_int_bank_code        ol_statement_detail.olsd_int_bank_code%TYPE,
   in_bank_acct_num        ol_statement_detail.olsd_bank_acct_num%TYPE,
   out_statement_ref   OUT ol_statement_detail.olsd_statement_ref%TYPE)
   RETURN NUMBER
IS
   TXN_AMOUNT        ol_statement_detail.olsd_txn_amount%TYPE;
   AMT_TYPE          ol_statement_detail.olsd_amt_type%TYPE;
   CREATE_DATETIME   VARCHAR2 (14);
   STMT_DATETIME     VARCHAR2 (14);
BEGIN
   SELECT OLSD_STATEMENT_REF,
          OLSD_TXN_AMOUNT,
          OLSD_AMT_TYPE,
          TO_CHAR (OLSD_CREATE_TIMESTAMP, 'YYYYMMDDHH24MISS'),
          TO_CHAR (OLSD_STATEMENT_TIMESTAMP, 'YYYYMMDDHH24MISS')
     INTO out_statement_ref,
          TXN_AMOUNT,
          AMT_TYPE,
          CREATE_DATETIME,
          STMT_DATETIME
     FROM OL_STATEMENT_DETAIL
    WHERE     OLSD_FILENAME = in_filename
          AND OLSD_STATEMENT_SEQ = in_statement_seq;

   IF AMT_TYPE = 'DR'
   THEN
      /* Find lastest CR Record within 1 hr */
      BEGIN
         SELECT OLSD_STATEMENT_REF
           INTO out_statement_ref
           FROM (  SELECT OLSD_STATEMENT_REF
                     FROM OL_STATEMENT_DETAIL
                    WHERE     (   (    OLSD_FILENAME = in_filename
                                   AND OLSD_STATEMENT_SEQ < in_statement_seq)
                               OR (    OLSD_FILENAME != in_filename
                                   AND OLSD_CREATE_TIMESTAMP <=
                                          TO_DATE (CREATE_DATETIME,
                                                   'YYYYMMDDHH24MISS')))
                          AND OLSD_INT_BANK_CODE = in_int_bank_code
                          AND OLSD_STATEMENT_TIMESTAMP >=
                                   TO_DATE (STMT_DATETIME, 'YYYYMMDDHH24MISS')
                                 - 1 / 24
                          AND OLSD_STATEMENT_TIMESTAMP <=
                                 TO_DATE (STMT_DATETIME, 'YYYYMMDDHH24MISS')
                          AND OLSD_AMT_TYPE = 'CR'
                          AND OLSD_TXN_AMOUNT = TXN_AMOUNT
                          AND OLSD_STATUS = 'U'
                 ORDER BY OLSD_STATEMENT_REF DESC)
          WHERE ROWNUM = 1;
      EXCEPTION
         WHEN OTHERS
         THEN
            RETURN 0;
      END;
   END IF;

   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_ol_statement_find_ref_hold;
/

