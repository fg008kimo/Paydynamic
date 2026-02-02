CREATE OR REPLACE FUNCTION sp_par_po_rev_txn_seq_map_ins (
        in_vnc_ref_num          par_po_rev_txn_seq_map.pr_vnc_ref_num%type,
        in_voa_txn_code         par_po_rev_txn_seq_map.pr_voa_txn_code%type,
	in_create_user		par_po_rev_txn_seq_map.pr_create_user%type
)
  RETURN NUMBER IS

BEGIN

  INSERT INTO par_po_rev_txn_seq_map(
	pr_vnc_ref_num,
	pr_voa_txn_code,
        pr_create_timestamp,
	pr_create_user,
	pr_update_timestamp,
	pr_update_user
	)
  VALUES(
	in_vnc_ref_num,
	in_voa_txn_code,
	sysdate,
	in_create_user,
	sysdate,
	in_create_user
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_par_po_rev_txn_seq_map_ins;
/

