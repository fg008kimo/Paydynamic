CREATE OR REPLACE FUNCTION sp_par_payout_upload_insert (
	in_file_id		par_payout_upload.pu_file_id%type,
	in_batch_id		par_payout_upload.pu_batch_id%type,
	in_create_user		par_payout_upload.pu_create_user%type
)
  RETURN NUMBER IS

BEGIN

  INSERT INTO par_payout_upload (
	pu_file_id,
	pu_batch_id,
        pu_create_timestamp,
	pu_create_user,
	pu_update_timestamp,
	pu_update_user
	)
  VALUES(
	in_file_id,
	in_batch_id,
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

END sp_par_payout_upload_insert;
/

