CREATE OR REPLACE FUNCTION sp_ol_dsi_match_pair_delete (
   in_stmt_txn_id              ol_deposit_match_pair.odmp_stmt_txn_id%TYPE,
   in_merch_txn_id             ol_deposit_match_pair.odmp_merch_txn_id%TYPE,
   in_removal_action           ol_deposit_match_pair_log.odml_removal_action%TYPE,
   in_removal_reason           ol_deposit_match_pair_log.odml_removal_reason%TYPE,
   in_removal_action_txn_id    ol_deposit_match_pair_log.odml_removal_action_txn_id%TYPE,
   in_create_user              ol_deposit_match_pair_log.odml_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   INSERT INTO ol_deposit_match_pair_log (odml_stmt_txn_id,
                                          odml_merch_txn_id,
                                          odml_merch_id,
                                          odml_pair_up_timestamp,
                                          odml_removal_timestamp,
                                          odml_removal_action,
                                          odml_removal_reason,
                                          odml_removal_action_txn_id,
                                          odml_create_timestamp,
                                          odml_create_user,
                                          odml_update_timestamp,
                                          odml_update_user)
      SELECT in_stmt_txn_id,
             in_merch_txn_id,
             odmp_merch_id,
             odmp_create_timestamp,
             SYSDATE,
             in_removal_action,
             in_removal_reason,
             in_removal_action_txn_id,
             SYSDATE,
             in_create_user,
             SYSDATE,
             in_create_user
        FROM DUAL
             CROSS JOIN
             (SELECT odmp_merch_id, odmp_create_timestamp
                FROM ol_deposit_match_pair
               WHERE     odmp_stmt_txn_id = in_stmt_txn_id
                     AND odmp_merch_txn_id = in_merch_txn_id);

   IF SQL%ROWCOUNT = 0
   THEN
      RETURN 1;
   ELSE
      DELETE FROM ol_deposit_match_pair
            WHERE     odmp_stmt_txn_id = in_stmt_txn_id
                  AND odmp_merch_txn_id = in_merch_txn_id;

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
END sp_ol_dsi_match_pair_delete;
/

