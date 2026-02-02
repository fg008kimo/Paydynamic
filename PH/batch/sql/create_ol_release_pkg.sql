CREATE OR REPLACE PACKAGE ol_release_pkg
IS
   PROCEDURE open_reserve (
      in_merchant_id   IN     ol_txn_header.oth_merchant_id%TYPE,
      in_period        IN     ol_merch_detail.md_release_reserved_period%TYPE,
      cursor_reserve      OUT SYS_REFCURSOR);

   FUNCTION find_release_date (
      in_posting_date     IN OL_TXN_HEADER.OTH_HOST_POSTING_DATE%TYPE,
      in_country          IN OL_TXN_DETAIL.OTD_TXN_COUNTRY%TYPE,
      in_service_code     IN DEF_SERVICE_CODE.SC_CODE%TYPE,
      in_release_period   IN INT)
   RETURN VARCHAR;

END ol_release_pkg;
/

CREATE OR REPLACE PACKAGE BODY ol_release_pkg
IS
   PROCEDURE open_reserve (
      in_merchant_id   IN     ol_txn_header.oth_merchant_id%TYPE,
      in_period        IN     ol_merch_detail.md_release_reserved_period%TYPE,
      cursor_reserve      OUT SYS_REFCURSOR)
   IS
      v_ph_posting_date   system_control.sys_val%TYPE;
   BEGIN
      SELECT sys_val
        INTO v_ph_posting_date
        FROM system_control
       WHERE sys_code = 'CTPHDATE';

      OPEN cursor_reserve FOR
         SELECT oth_txn_id
           FROM ol_txn_header
          WHERE     oth_status = 'C'
                AND oth_ar_ind = 'A'
                AND oth_merchant_id = in_merchant_id
                AND oth_txn_code IN ('ODI', 'ODP', 'MRN', 'OAE')
                AND oth_reserve_amount > 0
                AND oth_approval_date <=
                       TO_CHAR (
                          (  TO_DATE (v_ph_posting_date, 'YYYYMMDD')
                           - in_period),
                          'YYYYMMDD')
                AND oth_reserved_release_date IS NULL;
   END open_reserve;

FUNCTION find_release_date (
   in_posting_date     IN OL_TXN_HEADER.OTH_HOST_POSTING_DATE%TYPE,
   in_country          IN OL_TXN_DETAIL.OTD_TXN_COUNTRY%TYPE,
   in_service_code     IN DEF_SERVICE_CODE.SC_CODE%TYPE,
   in_release_period   IN INT)
   RETURN VARCHAR
IS
   v_release_date   VARCHAR (8);
   v_current_date   VARCHAR (8);
   v_tmp_date       VARCHAR (8);
   iCnt             INTEGER := in_release_period;
   iStep            INTEGER := 1;
   iExtra           INTEGER := 0;
   iTotal           INTEGER := 0;
   iDOW             INTEGER := 0;

   iHolidayCnt      INTEGER := 0;

BEGIN
   v_release_date := in_posting_date;
   v_current_date := in_posting_date;
   v_tmp_date := in_posting_date;

   WHILE (1 > 0)
   LOOP
      SELECT TO_NUMBER (TO_CHAR (TO_DATE (v_current_date, 'YYYYMMDD'), 'D'))
        INTO iDOW
        FROM DUAL;

      SELECT NVL (COUNT (*), 0)
        INTO iHolidayCnt
        FROM holiday
       WHERE h_country = in_country AND h_date = v_current_date AND h_service_code = in_service_code AND h_is_non_holiday = 0;
       


      -- if Holiday, check previous day
      IF iHolidayCnt > 0
      THEN
         SELECT TO_CHAR (TO_DATE (v_current_date, 'YYYYMMDD') - 1,
                         'YYYYMMDD')
           INTO v_current_date
           FROM DUAL;

         CONTINUE;
      ELSE
         WHILE (iCnt > iStep)
         LOOP
            SELECT TO_CHAR (TO_DATE (v_tmp_date, 'YYYYMMDD') - 1, 'YYYYMMDD')
              INTO v_tmp_date
              FROM DUAL;

            SELECT TO_NUMBER (
                      TO_CHAR (TO_DATE (v_tmp_date, 'YYYYMMDD'), 'D'))
              INTO iDOW
              FROM DUAL;

            SELECT NVL (COUNT (*), 0)
              INTO iHolidayCnt
              FROM holiday
             WHERE h_country = in_country AND h_date = v_tmp_date AND h_service_code = in_service_code AND h_is_non_holiday = 0;
             

            -- if Holiday, check previous day
            IF  iHolidayCnt > 0
            THEN
               iExtra := iExtra + 1;
            ELSE
               iStep := iStep + 1;
            END IF;

            iTotal := iTotal + 1;
         END LOOP;

         SELECT TO_CHAR (TO_DATE (v_current_date, 'YYYYMMDD') - iTotal -1,
                         'YYYYMMDD')
           INTO v_release_date
           FROM DUAL;

       
      END IF;
      RETURN v_release_date;
   END LOOP;

END find_release_date;


END ol_release_pkg;
/
