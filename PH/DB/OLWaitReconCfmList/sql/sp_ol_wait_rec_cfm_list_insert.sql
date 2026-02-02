CREATE OR REPLACE FUNCTION sp_ol_wait_rec_cfm_list_insert (
   in_baid_txn_id_1    ol_wait_recon_cfm_list.owrc_baid_txn_id_1%TYPE,
   in_bank_acct_type_1 ol_wait_recon_cfm_list.owrc_bank_acct_type_1%TYPE,
   in_baid_txn_id_2    ol_wait_recon_cfm_list.owrc_baid_txn_id_2%TYPE,
   in_bank_acct_type_2 ol_wait_recon_cfm_list.owrc_bank_acct_type_2%TYPE,
   in_recon_type       ol_wait_recon_cfm_list.owrc_recon_type%TYPE,
   in_create_user      ol_wait_recon_cfm_list.owrc_create_user%TYPE)
   RETURN NUMBER
IS
   iCnt   INTEGER;
BEGIN
   SELECT COUNT (*)
     INTO iCnt
     FROM ol_wait_recon_cfm_list
    WHERE     owrc_baid_txn_id_1 = in_baid_txn_id_1
          AND owrc_baid_txn_id_2 = in_baid_txn_id_2;

   IF iCnt > 0
   THEN
      RETURN 0;
   ELSE
      INSERT INTO ol_wait_recon_cfm_list (owrc_baid_txn_id_1,
                                              owrc_bank_acct_type_1,
                                              owrc_baid_txn_id_2,
                                              owrc_bank_acct_type_2,
                                              owrc_recon_type,
                                              owrc_create_timestamp,
                                              owrc_create_user,
                                              owrc_update_timestamp,
                                              owrc_update_user)
           VALUES (in_baid_txn_id_1,
                   in_bank_acct_type_1,
                   in_baid_txn_id_2,
                   in_bank_acct_type_2,
                   in_recon_type,
                   SYSDATE,
                   in_create_user,
                   SYSDATE,
                   in_create_user);

      IF SQL%ROWCOUNT = 0
      THEN
         RETURN 1;
      ELSE
         RETURN 0;
      END IF;
   END IF;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_ol_wait_rec_cfm_list_insert;
/

