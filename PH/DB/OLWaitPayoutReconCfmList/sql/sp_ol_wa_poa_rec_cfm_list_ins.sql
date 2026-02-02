CREATE OR REPLACE FUNCTION sp_ol_wa_poa_rec_cfm_list_ins (
   in_psp_txn_id       ol_wait_payout_recon_cfm_list.owpc_psp_txn_id%TYPE,
   in_baid_txn_id      ol_wait_payout_recon_cfm_list.owpc_baid_txn_id%TYPE,
   in_create_user      ol_wait_payout_recon_cfm_list.owpc_create_user%TYPE)
   RETURN NUMBER
IS
   iCnt   INTEGER;
BEGIN
   SELECT COUNT (*)
     INTO iCnt
     FROM ol_wait_payout_recon_cfm_list
    WHERE     owpc_psp_txn_id = in_psp_txn_id
          AND owpc_baid_txn_id = in_baid_txn_id;

   IF iCnt > 0
   THEN
      RETURN 0;
   ELSE
      INSERT INTO ol_wait_payout_recon_cfm_list (owpc_psp_txn_id,
                                              owpc_baid_txn_id,
                                              owpc_create_user,
                                              owpc_create_timestamp,
                                              owpc_update_user,
                                              owpc_update_timestamp)
           VALUES (in_psp_txn_id,
                   in_baid_txn_id,
                   in_create_user,
                   SYSDATE,
                   in_create_user,
                   SYSDATE);

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
END sp_ol_wa_poa_rec_cfm_list_ins;
/

