CREATE OR REPLACE FUNCTION sp_psp_recon_his_delete(
	in_txn_id		psp_recon_history.pr_id%type
	)
  RETURN NUMBER IS

BEGIN
  DELETE FROM psp_recon_history
	WHERE	pr_id=in_txn_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_psp_recon_his_delete;
/
