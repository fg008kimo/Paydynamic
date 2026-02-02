CREATE OR REPLACE FUNCTION sp_ol_po_gen_fl_dt_map_insert (
   in_action_type	ol_payout_gen_file_dt_map.odm_action_type%TYPE,
   in_org_txn_id	ol_payout_gen_file_dt_map.odm_org_txn_id%TYPE,
   in_new_txn_id	ol_payout_gen_file_dt_map.odm_new_txn_id%TYPE,
   in_add_user		ol_payout_gen_file_dt_map.odm_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   INSERT INTO ol_payout_gen_file_dt_map (odm_action_type,
					  odm_org_txn_id,
                                          odm_new_txn_id,
                                          odm_create_user,
                                          odm_update_user,
                                          odm_create_timestamp,
                                          odm_update_timestamp)
        VALUES (in_action_type,
		in_org_txn_id,
                in_new_txn_id,
                in_add_user,
                in_add_user,
                SYSDATE,
                SYSDATE);

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
END sp_ol_po_gen_fl_dt_map_insert;
/

