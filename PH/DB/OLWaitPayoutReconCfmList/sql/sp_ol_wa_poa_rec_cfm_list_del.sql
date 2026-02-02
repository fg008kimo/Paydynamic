CREATE OR REPLACE FUNCTION sp_ol_wa_poa_rec_cfm_list_del (
   in_psp_txn_id     ol_wait_payout_recon_cfm_list.owpc_psp_txn_id%TYPE,
   in_baid_txn_id    ol_wait_payout_recon_cfm_list.owpc_baid_txn_id%TYPE)
   RETURN NUMBER
IS
BEGIN
   DELETE FROM ol_wait_payout_recon_cfm_list
         WHERE     owpc_psp_txn_id = in_psp_txn_id
               AND owpc_baid_txn_id = in_baid_txn_id;

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
END sp_ol_wa_poa_rec_cfm_list_del;
/

