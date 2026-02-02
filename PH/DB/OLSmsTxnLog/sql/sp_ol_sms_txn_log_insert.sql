CREATE OR REPLACE FUNCTION sp_ol_sms_txn_log_insert (
   in_txn_id               ol_sms_txn_log.ost_txn_id%TYPE,
   in_sender               ol_sms_txn_log.ost_sender%TYPE,
   in_text                 ol_sms_txn_log.ost_text%TYPE,
   in_scts                 ol_sms_txn_log.ost_scts%TYPE,
   in_tag                  ol_sms_txn_log.ost_tag%TYPE,
   in_has_missing_parts    ol_sms_txn_log.ost_has_missing_parts%TYPE,
   in_smsc                 ol_sms_txn_log.ost_smsc%TYPE,
   in_ref_num              ol_sms_txn_log.ost_ref_num%TYPE,
   in_sender_num_type      ol_sms_txn_log.ost_sender_num_type%TYPE,
   in_seq_num              ol_sms_txn_log.ost_seq_num%TYPE,
   in_total                ol_sms_txn_log.ost_total%TYPE,
   in_req_bank_acc         ol_sms_txn_log.ost_req_bank_acc%TYPE,
   in_req_bank_year        ol_sms_txn_log.ost_req_bank_year%TYPE,
   in_req_bank_month       ol_sms_txn_log.ost_req_bank_month%TYPE,
   in_req_bank_day         ol_sms_txn_log.ost_req_bank_day%TYPE,
   in_req_bank_time        ol_sms_txn_log.ost_req_bank_time%TYPE,
   in_req_bank_amount      VARCHAR2,
   in_req_payee            ol_sms_txn_log.ost_req_payee%TYPE,
   in_req_payer            ol_sms_txn_log.ost_req_payer%TYPE,
   in_req_payer_acc        ol_sms_txn_log.ost_req_payer_acc%TYPE,
   in_req_bank_bal         VARCHAR2,
   in_req_bank_name        ol_sms_txn_log.ost_req_bank_name%TYPE,
   in_req_bank_channel     ol_sms_txn_log.ost_req_bank_channel%TYPE,
   in_req_status           ol_sms_txn_log.ost_req_status%TYPE,
   in_req_ip               ol_sms_txn_log.ost_req_ip%TYPE,
   in_user                 ol_sms_txn_log.ost_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   UPDATE ol_sms_txn_log
      SET ost_sender = in_sender,
          ost_text = in_text,
          ost_scts = in_scts,
          ost_tag = in_tag,
          ost_has_missing_parts = in_has_missing_parts,
          ost_smsc = in_smsc,
          ost_ref_num = in_ref_num,
          ost_sender_num_type = in_sender_num_type,
          ost_seq_num = in_seq_num,
          ost_total = in_total,
          ost_req_bank_acc = in_req_bank_acc,
          ost_req_bank_year = in_req_bank_year,
          ost_req_bank_month = in_req_bank_month,
          ost_req_bank_day = in_req_bank_day,
          ost_req_bank_time = in_req_bank_time,
          ost_req_bank_amount =
             NVL (TO_NUMBER (REPLACE (in_req_bank_amount, ',', '')), 0),
          ost_req_payee = in_req_payee,
          ost_req_payer = in_req_payer,
          ost_req_payer_acc = in_req_payer_acc,
          ost_req_bank_bal =
             NVL (TO_NUMBER (REPLACE (in_req_bank_bal, ',', '')), 0),
          ost_req_bank_name = in_req_bank_name,
          ost_req_bank_channel = in_req_bank_channel,
          ost_req_status = in_req_status,
          ost_req_ip = in_req_ip,
          ost_update_timestamp = SYSDATE,
          ost_update_user = in_user
    WHERE ost_txn_id = in_txn_id;

   IF SQL%ROWCOUNT = 0
   THEN
      INSERT INTO ol_sms_txn_log (ost_txn_id,
                                  ost_sender,
                                  ost_text,
                                  ost_scts,
                                  ost_tag,
                                  ost_has_missing_parts,
                                  ost_smsc,
                                  ost_ref_num,
                                  ost_sender_num_type,
                                  ost_seq_num,
                                  ost_total,
                                  ost_req_bank_acc,
                                  ost_req_bank_year,
                                  ost_req_bank_month,
                                  ost_req_bank_day,
                                  ost_req_bank_time,
                                  ost_req_bank_amount,
                                  ost_req_payee,
                                  ost_req_payer,
                                  ost_req_payer_acc,
                                  ost_req_bank_bal,
                                  ost_req_bank_name,
                                  ost_req_bank_channel,
                                  ost_req_status,
                                  ost_req_ip,
                                  ost_create_timestamp,
                                  ost_create_user,
                                  ost_update_timestamp,
                                  ost_update_user)
              VALUES (
                        in_txn_id,
                        in_sender,
                        in_text,
                        in_scts,
                        in_tag,
                        in_has_missing_parts,
                        in_smsc,
                        in_ref_num,
                        in_sender_num_type,
                        in_seq_num,
                        in_total,
                        in_req_bank_acc,
                        in_req_bank_year,
                        in_req_bank_month,
                        in_req_bank_day,
                        in_req_bank_time,
                        NVL (
                           TO_NUMBER (REPLACE (in_req_bank_amount, ',', '')),
                           0),
                        in_req_payee,
                        in_req_payer,
                        in_req_payer_acc,
                        NVL (TO_NUMBER (REPLACE (in_req_bank_bal, ',', '')),
                             0),
                        in_req_bank_name,
                        in_req_bank_channel,
                        in_req_status,
                        in_req_ip,
                        SYSDATE,
                        in_user,
                        SYSDATE,
                        in_user);

      IF SQL%ROWCOUNT = 0
      THEN
         RETURN 1;
      ELSE
         RETURN 0;
      END IF;
   ELSE
      RETURN 0;
   END IF;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_ol_sms_txn_log_insert;
/

