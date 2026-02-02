CREATE OR REPLACE FUNCTION sp_ol_statement_sms_upd_v3 (
   in_stat_txn_id            ol_statement_detail.olsd_stat_txn_id%TYPE,
   in_int_bank_code          ol_statement_detail.olsd_int_bank_code%TYPE,
   in_bank_acct_num          ol_statement_detail.olsd_bank_acct_num%TYPE,
   in_statement_date         ol_statement_detail.olsd_statement_date%TYPE,
   in_amt_type               ol_statement_detail.olsd_amt_type%TYPE,
   in_txn_amount             ol_statement_detail.olsd_txn_amount%TYPE,
   in_file_id                ol_statement_detail.olsd_file_id%TYPE,
   in_statement_seq          ol_statement_detail.olsd_statement_seq%TYPE,
   in_statement_ref          ol_statement_detail.olsd_statement_ref%TYPE,
   in_statement_time         ol_statement_detail.olsd_statement_time%TYPE,
   in_tfr_bank_name          ol_statement_detail.olsd_tfr_bank_name%TYPE,
   in_tfr_bank_acct_num      ol_statement_detail.olsd_tfr_bank_acct_num%TYPE,
   in_tfr_type               ol_statement_detail.olsd_tfr_type%TYPE,
   in_tfr_channel            ol_statement_detail.olsd_tfr_channel%TYPE,
   in_tfr_text               ol_statement_detail.olsd_tfr_text%TYPE,
   in_tfr_customer_text      ol_statement_detail.olsd_tfr_customer_text%TYPE,
   in_sender_name            ol_statement_detail.olsd_sender_name%TYPE,
   in_txn_ref_num            ol_statement_detail.olsd_txn_ref_num%TYPE,
   in_keywords_mapping       ol_statement_detail.olsd_keywords_mapping%TYPE,
   in_balance                ol_statement_detail.olsd_balance%TYPE,
   in_update_user            ol_statement_detail.olsd_update_user%TYPE,
   in_raw_date               ol_statement_detail.olsd_raw_date%TYPE,
   in_raw_time               ol_statement_detail.olsd_raw_time%TYPE,
   in_sender_baid_name       ol_statement_detail.olsd_sender_baid_name%TYPE,
   in_recipient_baid_name    ol_statement_detail.olsd_recipient_baid_name%TYPE,
   in_client_name            ol_statement_detail.olsd_client_name%TYPE,
   in_txn_location           ol_statement_detail.olsd_txn_location%TYPE,
   in_txn_type               ol_statement_detail.olsd_txn_type%TYPE,
   in_txn_reference          ol_statement_detail.olsd_txn_reference%TYPE)
   RETURN NUMBER
IS
BEGIN
   UPDATE ol_statement_detail
      SET olsd_update_timestamp = SYSDATE,
          olsd_update_user = NVL (in_update_user, olsd_update_user),
          olsd_file_id = NVL (in_file_id, olsd_file_id),
          olsd_statement_seq = NVL (in_statement_seq, olsd_statement_seq),
          olsd_statement_ref = NVL (in_statement_ref, olsd_statement_ref),
          olsd_statement_date = NVL (in_statement_date, olsd_statement_date),
          olsd_statement_time = NVL (in_statement_time, olsd_statement_time),
          olsd_statement_timestamp =
             TO_DATE (
                   in_statement_date
                || NVL (in_statement_time, olsd_statement_time),
                'YYYYMMDDHH24MISS'),
          olsd_tfr_bank_name = NVL (in_tfr_bank_name, olsd_tfr_bank_name),
          olsd_tfr_bank_acct_num =
             NVL (in_tfr_bank_acct_num, olsd_tfr_bank_acct_num),
          olsd_tfr_type = NVL (in_tfr_type, olsd_tfr_type),
          olsd_tfr_channel = NVL (in_tfr_channel, olsd_tfr_channel),
          olsd_tfr_text = NVL (in_tfr_text, olsd_tfr_text),
          olsd_tfr_customer_text =
             NVL (in_tfr_customer_text, olsd_tfr_customer_text),
          olsd_sender_name = NVL (in_sender_name, olsd_sender_name),
          olsd_txn_ref_num = NVL (in_txn_ref_num, olsd_txn_ref_num),
          olsd_keywords_mapping =
             NVL (in_keywords_mapping, olsd_keywords_mapping),
          olsd_balance = NVL (in_balance, olsd_balance),
          olsd_raw_date = NVL (in_raw_date, olsd_raw_date),
          olsd_raw_time = NVL (in_raw_time, olsd_raw_time),
          olsd_sender_baid_name =
             NVL (in_sender_baid_name, olsd_sender_baid_name),
          olsd_recipient_baid_name =
             NVL (in_recipient_baid_name, olsd_recipient_baid_name),
          olsd_client_name = NVL (in_client_name, olsd_client_name),
          olsd_txn_location = NVL (in_txn_location, olsd_txn_location),
          olsd_txn_type = NVL (in_txn_type, olsd_txn_type),
          olsd_txn_reference = NVL (in_txn_reference, olsd_txn_reference)
    WHERE olsd_stat_txn_id = in_stat_txn_id;

   IF SQL%ROWCOUNT = 0
   THEN
      RETURN 1;
   ELSE
      RETURN 0;
   END IF;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_ol_statement_sms_upd_v3;
/

