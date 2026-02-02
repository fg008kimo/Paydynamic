


CREATE OR REPLACE FUNCTION sp_customer_psp_cnt_housekeep (
    in_date    customer_psp_counters_hist.cch_date%TYPE)
    RETURN NUMBER
IS
    iCnt   INTEGER := 0;
BEGIN
    SELECT COUNT (*)
      INTO iCnt
      FROM customer_psp_counters
     WHERE cpc_date = in_date;

    MERGE INTO customer_psp_counters_hist
         USING (SELECT *
                  FROM customer_psp_counters
                 WHERE cpc_date = in_date)
            ON (    cch_cust_id = cpc_cust_id
                AND cch_psp_id = cpc_psp_id
                AND cch_date = in_date
                AND cch_category = cpc_category)
    WHEN MATCHED
    THEN
        UPDATE SET
            cch_update_timestamp = SYSDATE,
            cch_update_user = 'SYSTEM',
            cch_counter = cch_counter + cpc_counter
    WHEN NOT MATCHED
    THEN
        INSERT     (cch_cust_id,
                    cch_psp_id,
                    cch_date,
                    cch_category,
                    cch_counter,
                    cch_create_user,
                    cch_create_timestamp,
                    cch_update_user,
                    cch_update_timestamp)
            VALUES (cpc_cust_id,
                    cpc_psp_id,
                    in_date,
                    cpc_category,
                    cpc_counter,
                    'SYSTEM',
                    SYSDATE,
                    'SYSTEM',
                    SYSDATE);

    IF SQL%ROWCOUNT <> iCnt
    THEN
        RETURN 1;
    END IF;

    DELETE FROM customer_psp_counters
          WHERE cpc_date = in_date;

    RETURN 0;
EXCEPTION
    WHEN OTHERS
    THEN
        RETURN 9;
END sp_customer_psp_cnt_housekeep;
/

