CREATE OR REPLACE FUNCTION TMP_SP_CRR_JNL_INSERT_FROM_CMS(
	in_date	CRR_JNL_HEADER.TXN_DATE%TYPE
)
   RETURN NUMBER
IS
   iJnlId       CRR_JNL_HEADER.JNL_ID%TYPE;
   iLineCount   CRR_JNL_DETAIL.LINE_NO%TYPE;
   iCnt         NUMBER;
   iNewCnt      NUMBER := 0;

   /*Variable to be filled*/
   iJnlTypeId	CRR_JNL_HEADER.JNL_TYPE_ID%TYPE := 53;
   iDescrip	CRR_JNL_HEADER.DESCRIPTION%TYPE := 'initial balance';
   iTxnDate	CRR_JNL_HEADER.TXN_DATE%TYPE := in_date;
   iAccYear	CRR_JNL_HEADER.ACC_YEAR%TYPE := substr(in_date, 1, 4);
   iAccMonth	CRR_JNL_HEADER.ACC_MONTH%TYPE := substr(in_date, 5, 2);
BEGIN
   DBMS_OUTPUT.PUT_LINE ('BEGIN');

   FOR C1RESULT
      IN (  SELECT OB_PRODUCT_CODE, OB_COUNTRY_CODE
              FROM TMP_CRR_CARRY_OLD_BALANCE
             WHERE OB_PRODUCT_CODE IS NOT NULL AND OB_COUNTRY_CODE IS NOT NULL
          GROUP BY OB_PRODUCT_CODE, OB_COUNTRY_CODE)
   LOOP
      SELECT COUNT (*)
        INTO iCnt
        FROM CRR_JNL_HEADER
       WHERE     JNL_TYPE_ID = iJnlTypeId
             AND TXN_DATE = iTxnDate
             AND ACC_YEAR = iAccYear
             AND ACC_MONTH = iAccMonth
             AND PRODUCT_CODE = C1RESULT.OB_PRODUCT_CODE
             AND COUNTRY_CODE = C1RESULT.OB_COUNTRY_CODE
             AND DISABLED = 0;

      IF iCnt > 1
      THEN
         SELECT JNL_ID
           INTO iJnlId
           FROM (SELECT *
                   FROM CRR_JNL_HEADER
                  WHERE     JNL_TYPE_ID = iJnlTypeId
                        AND TXN_DATE = iTxnDate
                        AND ACC_YEAR = iAccYear
                        AND ACC_MONTH = iAccMonth
                        AND PRODUCT_CODE = C1RESULT.OB_PRODUCT_CODE
                        AND COUNTRY_CODE = C1RESULT.OB_COUNTRY_CODE
                        AND DISABLED = 0)
          WHERE ROWNUM = 1;

         SELECT NVL (MAX (LINE_NO), 0) + 1
           INTO iLineCount
           FROM CRR_JNL_DETAIL
          WHERE JNL_ID = iJnlId
            AND DISABLED = 0;
      ELSE
         SELECT    'G'
                || TO_CHAR (MGT_TXN_SEQ.NEXTVAL, 'FM0999999999')
                || TO_CHAR (SYSDATE, 'SSSSS')
           INTO iJnlId
           FROM DUAL;

         iLineCount := 1;

         INSERT INTO CRR_JNL_HEADER (JNL_ID,
                                     JNL_TYPE_ID,
                                     DESCRIPTION,
                                     TXN_DATE,
                                     BANK_UPDATE_DATE,
                                     ACC_YEAR,
                                     ACC_MONTH,
                                     REF_NO,
                                     PRODUCT_CODE,
                                     COUNTRY_CODE,
                                     REMARKS,
                                     STATUS,
                                     DISABLED,
                                     CREATE_TIMESTAMP,
                                     CREATE_USER,
                                     UPDATE_TIMESTAMP,
                                     UPDATE_USER,
                                     APPROVE_TIMESTAMP,
                                     APPROVE_USER,
                                     BOOK_TIMESTAMP,
                                     BOOK_USER)
              VALUES (iJnlId,
                      iJnlTypeId,
                      iDescrip,
                      iTxnDate,
                      '',
                      iAccYear,
                      iAccMonth,
                      '',
                      C1RESULT.OB_PRODUCT_CODE,
                      C1RESULT.OB_COUNTRY_CODE,
                      '',
                      'A',
                      0,
                      SYSDATE,
                      'SYSTEM',
                      SYSDATE,
                      'SYSTEM',
                      SYSDATE,
                      'SYSTEM',
                      '',
                      '');
      END IF;

      FOR C2RESULT
         IN (SELECT *
               FROM TMP_CRR_CARRY_OLD_BALANCE
              WHERE     OB_PRODUCT_CODE = C1RESULT.OB_PRODUCT_CODE
                    AND OB_COUNTRY_CODE = C1RESULT.OB_COUNTRY_CODE
                    AND OB_CR_IND IS NOT NULL
                    AND OB_CURRENCY_ID IS NOT NULL
                    AND EXISTS
                           (SELECT CURRENCY_ID
                              FROM CURRENCY
                             WHERE CURRENCY_ID = OB_CURRENCY_ID)
                    AND OB_CMS_BAL IS NOT NULL
                    AND OB_CMS_BAL_HKD IS NOT NULL
                    AND OB_FX_RATE IS NOT NULL
                    AND EXISTS
                           (SELECT GL_ID
                              FROM CRR_GL_CODE
                             WHERE     GL_CODE = OB_GL_CODE
                                   AND (   SL_CODE = OB_SL_CODE
                                        OR SL_CODE IS NULL))
                    AND OB_FINISHED = 'N')
      LOOP
         INSERT INTO CRR_JNL_DETAIL (JNL_ID,
                                     LINE_NO,
                                     GL_ID,
                                     CURRENCY_ID,
                                     TXN_AMT,
                                     CR_IND,
                                     REMARKS,
                                     DISABLED,
                                     CREATE_TIMESTAMP,
                                     UPDATE_TIMESTAMP,
                                     CREATE_USER,
                                     UPDATE_USER,
                                     TXN_COUNT)
              VALUES (
                        iJnlId,
                        iLineCount,
                        (SELECT GL_ID
                           FROM CRR_GL_CODE
                          WHERE     GL_CODE = C2RESULT.OB_GL_CODE
                                AND (   SL_CODE = C2RESULT.OB_SL_CODE
                                     OR SL_CODE IS NULL)),
                        C2RESULT.OB_CURRENCY_ID,
                        C2RESULT.OB_CMS_BAL,
                        C2RESULT.OB_CR_IND,
                        '',
                        0,
                        SYSDATE,
                        SYSDATE,
                        'SYSTEM',
                        'SYSTEM',
                        '');

         IF C2RESULT.OB_CURRENCY_ID <> 'HKD'
         THEN
            INSERT INTO CRR_JNL_DETAIL_AMT (JNL_ID,
                                            LINE_NO,
                                            CURRENCY_ID,
                                            FX_RATE,
                                            CONVERT_AMT,
                                            DISABLED,
                                            CREATE_TIMESTAMP,
                                            UPDATE_TIMESTAMP,
                                            CREATE_USER,
                                            UPDATE_USER)
                 VALUES (iJnlId,
                         iLineCount,
                         'HKD',
                         C2RESULT.OB_FX_RATE,
                         C2RESULT.OB_CMS_BAL_HKD,
                         0,
                         SYSDATE,
                         SYSDATE,
                         'SYSTEM',
                         'SYSTEM');
         END IF;

         IF C2RESULT.OB_SL_CODE IS NULL
         THEN
            UPDATE TMP_CRR_CARRY_OLD_BALANCE
               SET OB_FINISHED = 'Y'
             WHERE     OB_GL_CODE = C2RESULT.OB_GL_CODE
                   AND OB_SL_CODE IS NULL
                   AND OB_PRODUCT_CODE = C2RESULT.OB_PRODUCT_CODE
                   AND OB_COUNTRY_CODE = C2RESULT.OB_COUNTRY_CODE
                   AND OB_CR_IND = C2RESULT.OB_CR_IND
                   AND OB_CURRENCY_ID = C2RESULT.OB_CURRENCY_ID;
         ELSE
            UPDATE TMP_CRR_CARRY_OLD_BALANCE
               SET OB_FINISHED = 'Y'
             WHERE     OB_GL_CODE = C2RESULT.OB_GL_CODE
                   AND OB_SL_CODE = C2RESULT.OB_SL_CODE
                   AND OB_PRODUCT_CODE = C2RESULT.OB_PRODUCT_CODE
                   AND OB_COUNTRY_CODE = C2RESULT.OB_COUNTRY_CODE
                   AND OB_CR_IND = C2RESULT.OB_CR_IND
                   AND OB_CURRENCY_ID = C2RESULT.OB_CURRENCY_ID
                   AND OB_CMS_BAL = C2RESULT.OB_CMS_BAL;
         END IF;

         iLineCount := iLineCount + 1;
         iNewCnt := iNewCnt + 1;
      END LOOP;

      INSERT INTO CRR_JNL_CHANGE_LOG (JNL_CHANGE_LOG_ID,
                                      JNL_ID,
                                      OLD_VALUE,
                                      NEW_VALUE,
                                      CHANGE_ACTION,
                                      JNL_STATUS,
                                      CHANGE_USER,
                                      CREATE_TIMESTAMP,
                                      CREATE_USER)
           VALUES (
                     (SELECT NVL (MAX (JNL_CHANGE_LOG_ID), 0) + 1
                        FROM CRR_JNL_CHANGE_LOG),
                     iJnlId,
                     '',
                     '',
                     'Add',
                     'A',
                     'SYSTEM',
                     SYSDATE,
                     'SYSTEM');

      INSERT INTO CRR_JNL_CHANGE_LOG (JNL_CHANGE_LOG_ID,
                                      JNL_ID,
                                      OLD_VALUE,
                                      NEW_VALUE,
                                      CHANGE_ACTION,
                                      JNL_STATUS,
                                      CHANGE_USER,
                                      CREATE_TIMESTAMP,
                                      CREATE_USER)
           VALUES (
                     (SELECT NVL (MAX (JNL_CHANGE_LOG_ID), 0) + 1
                        FROM CRR_JNL_CHANGE_LOG),
                     iJnlId,
                     '',
                     '',
                     'Approve',
                     'A',
                     'SYSTEM',
                     SYSDATE,
                     'SYSTEM');
   END LOOP;

   DBMS_OUTPUT.PUT_LINE ('Current Success Count: ' || iNewCnt);

   SELECT COUNT (*)
     INTO iCnt
     FROM TMP_CRR_CARRY_OLD_BALANCE
    WHERE OB_FINISHED = 'Y';

   DBMS_OUTPUT.PUT_LINE ('Total Success Count: ' || iCnt);

   SELECT COUNT (*)
     INTO iCnt
     FROM TMP_CRR_CARRY_OLD_BALANCE
    WHERE OB_FINISHED = 'N';

   DBMS_OUTPUT.PUT_LINE ('Total Fail Count: ' || iCnt);

   IF iNewCnt > 0 AND iCnt = 0
   THEN
      RETURN 1;
   ELSE
      RETURN 0;
   END IF;
EXCEPTION
   WHEN OTHERS
   THEN
      ROLLBACK;
      DBMS_OUTPUT.PUT_LINE ('@@@@@@@@@@@');
      DBMS_OUTPUT.PUT_LINE ('@' || SQLERRM);
      DBMS_OUTPUT.PUT_LINE ('@@@@@@@@@@@');
      RETURN 9;
END TMP_SP_CRR_JNL_INSERT_FROM_CMS;
/

