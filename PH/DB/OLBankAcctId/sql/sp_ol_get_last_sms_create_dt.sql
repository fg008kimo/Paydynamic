CREATE OR REPLACE FUNCTION sp_ol_get_last_sms_create_dt(
	in_baid                 	OL_BANK_ACCT_ID.OBAI_BAID%type,
	in_rec_date                 	VARCHAR2,
	in_max_baid_cnt                 INTEGER,
	out_cursor       		OUT SYS_REFCURSOR)
RETURN NUMBER IS
	iCnt    integer := 0;
BEGIN

	SELECT COUNT (*)
        INTO iCnt
        FROM
	(
		SELECT 	olsd_baid,
                        ost_create_ts,
                        obai_create_timestamp,
                        row_number() over (order by obai_create_timestamp, obai_baid) as rn,
                        count(*) over () as total_count
                FROM    ol_bank_acct_id,
			ol_bank_accts,
                        (SELECT olsd_baid, to_char(max(ost_create_timestamp), 'YYYYMMDD HH24MISS') as ost_create_ts
                        FROM ol_sms_txn_log, ol_statement_detail
                        WHERE ost_create_timestamp >= to_date(in_rec_date, 'YYYYMMDD')
                        AND ost_create_timestamp < to_date(in_rec_date, 'YYYYMMDD') + 1
                        AND ost_txn_id = olsd_stat_txn_id
                        GROUP BY olsd_baid)
                WHERE olsd_baid = obai_baid
		AND obai_status = 'O'
        	AND ob_int_bank_code = obai_int_bank_code
        	AND OB_bank_acct_num = obai_bank_acct_num
        	AND ob_status_type = 'A'
                AND obai_create_timestamp >= (SELECT min(obai_create_timestamp)
                                              FROM  ol_bank_acct_id
                                              WHERE obai_baid = NVL(in_baid, obai_baid))
                AND obai_baid != NVL(in_baid, obai_baid || obai_baid)
	);	

	IF iCnt > 0 THEN

		OPEN out_cursor FOR
        	SELECT  olsd_baid,
                	ost_create_ts,
                	/* obai_create_timestamp, */
                	CASE
                        	WHEN (rn != total_count)
                        	THEN '0'
                        	ELSE '1'
                	END AS end_ind
        	FROM
        	(
                	SELECT 	olsd_baid,
                        	ost_create_ts,
                        	obai_create_timestamp,
                        	row_number() over (order by obai_create_timestamp, obai_baid) as rn,
                        	count(*) over () as total_count
                	FROM    ol_bank_acct_id,
				ol_bank_accts,
                        	(SELECT olsd_baid, to_char(max(ost_create_timestamp), 'YYYYMMDD HH24MISS') as ost_create_ts
                        	FROM ol_sms_txn_log, ol_statement_detail
                        	WHERE ost_create_timestamp >= to_date(in_rec_date, 'YYYYMMDD')
                        	AND ost_create_timestamp < to_date(in_rec_date, 'YYYYMMDD') + 1
                        	AND ost_txn_id = olsd_stat_txn_id
                        	GROUP BY olsd_baid)
                	WHERE olsd_baid = obai_baid
			AND obai_status = 'O'
        		AND ob_int_bank_code = obai_int_bank_code
        		AND OB_bank_acct_num = obai_bank_acct_num
        		AND ob_status_type = 'A'
                	AND obai_create_timestamp >= (SELECT min(obai_create_timestamp)
                                              	     FROM  ol_bank_acct_id
                                              	     WHERE obai_baid = NVL(in_baid, obai_baid))
                	AND obai_baid != NVL(in_baid, obai_baid || obai_baid)
                	ORDER BY obai_create_timestamp, obai_baid
        	)
		WHERE   rownum <= in_max_baid_cnt;

		return 0;
	ELSE
		return 2;
  	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_ol_get_last_sms_create_dt;
/
