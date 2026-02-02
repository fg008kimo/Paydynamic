CREATE OR REPLACE FUNCTION sp_ol_wait_rec_cfm_list_del_or (
   in_baid_txn_id    ol_wait_recon_cfm_list.owrc_baid_txn_id_1%TYPE)
   RETURN NUMBER
IS
BEGIN
   DELETE FROM ol_wait_recon_cfm_list
         WHERE     owrc_baid_txn_id_1 = in_baid_txn_id
               OR owrc_baid_txn_id_2 = in_baid_txn_id;

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
END sp_ol_wait_rec_cfm_list_del_or;
/

