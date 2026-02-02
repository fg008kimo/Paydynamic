CREATE OR REPLACE FUNCTION sp_ol_payout_gen_dt_get_new (
   in_file_id             ol_payout_generated_file_dt.ofd_file_id%TYPE,
   in_txn_list            VARCHAR2,
   in_upload_status       ol_merchant_upload_file_detail.oud_status%TYPE,
   in_status              ol_payout_generated_file_dt.ofd_status%TYPE,
   out_cursor         OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
   iCnt   INTEGER := 0;
BEGIN
   SELECT COUNT (*)
     INTO iCnt
     FROM ol_payout_generated_file_dt,
          ol_payout_generated_file_hd
    WHERE (exists (select 1 from ol_merchant_upload_file_detail 
                   where ofd_upload_txn_id = oud_txn_id
                   and (oud_status = in_upload_status OR in_upload_status IS NULL)
                   and oud_disabled = 0) 
           or
           exists (select 1 from ol_payout_request
                   where ofd_upload_txn_id = opr_txn_id
                   and (opr_status = in_upload_status OR in_upload_status IS NULL))
          )
	  AND ofd_file_id = ofh_file_id
          AND ofh_status = 1
          AND (ofd_status = in_status OR in_status IS NULL)
          AND (ofd_file_id = in_file_id OR in_file_id IS NULL)
          AND (   ofd_upload_txn_id IN (    SELECT REGEXP_SUBSTR (in_txn_list,
                                                                  '[^,]+',
                                                                  1,
                                                                  LEVEL)
                                                      token
                                              FROM DUAL
                                        CONNECT BY LEVEL <=
                                                        LENGTH (in_txn_list)
                                                      - LENGTH (
                                                           REPLACE (
                                                              in_txn_list,
                                                              ',',
                                                              ''))
                                                      + 1)
               OR in_txn_list IS NULL)
      	  ;

   IF iCnt > 0
   THEN
      OPEN out_cursor FOR
           SELECT ofd_file_id,
                  ofd_batch_id,
                  ofd_seq_num,
                  oth_txn_id,
                  ofd_upload_txn_id,
                  ofd_txn_id,
                  ofd_merchant_ref,
                  ofd_country,
                  ofd_identity_id,
                  ofd_account_num,
                  ofd_account_name,
                  ofd_bank_name,
                  ofd_bank_code,
                  ofd_branch,
                  ofd_phone_num,
                  ofd_province,
                  ofd_city,
                  ofd_payout_amount,
                  ofd_unique_amount,
                  ofd_request_amount,
                  ofd_payout_currency,
                  ofd_request_currency,
                  ofh_filename,
                  ofh_file_pid,
                  opd_client_id,
                  ofh_ccy_id,
                  ofh_txn_count,
                  ofh_total_txn_amt,
                  otp_cost,
                  ofd_version_no
             FROM ol_payout_generated_file_dt,
                  ol_txn_header,
                  ol_txn_psp_detail,
                  ol_bank_acct_id,
                  ol_payout_generated_file_hd,
                  ol_psp_detail
            WHERE (exists (select 1 from ol_merchant_upload_file_detail
                           where ofd_upload_txn_id = oud_txn_id
                           and (oud_status = in_upload_status OR in_upload_status IS NULL)
                           and oud_disabled = 0)
                   or
                   exists (select 1 from ol_payout_request
                           where ofd_upload_txn_id = opr_txn_id
                           and (opr_status = in_upload_status OR in_upload_status IS NULL))
                  )
		  AND ofd_file_id = ofh_file_id
                  AND ofh_status = 1
                  AND (ofd_status = in_status OR in_status IS NULL)
                  AND (ofd_file_id = in_file_id OR in_file_id IS NULL)
                  AND (   ofd_upload_txn_id IN (    SELECT REGEXP_SUBSTR (
                                                              in_txn_list,
                                                              '[^,]+',
                                                              1,
                                                              LEVEL)
                                                              token
                                                      FROM DUAL
                                                CONNECT BY LEVEL <=
                                                                LENGTH (
                                                                   in_txn_list)
                                                              - LENGTH (
                                                                   REPLACE (
                                                                      in_txn_list,
                                                                      ',',
                                                                      ''))
                                                              + 1)
                       OR in_txn_list IS NULL)
                  AND opd_psp_id = ofh_file_pid
                  AND otp_tracking_txn_id = ofd_txn_id
                  AND oth_txn_id = otp_txn_id
                  AND oth_status = 'C'
                  AND oth_ar_ind = 'A'
                  AND oth_txn_code = 'OPG'
                  AND oth_recon_status = 'U'
                  AND obai_baid = otp_baid
                  AND obai_category = 'TEMP'
         ORDER BY ofd_batch_id, ofd_seq_num;

      RETURN 1;
   END IF;

   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 0;
END sp_ol_payout_gen_dt_get_new;
/

