CREATE OR REPLACE FUNCTION sp_merch_upload_error_insert(
	in_batch_id		merchant_upload_error.ue_batch_id%type,
	in_record		merchant_upload_error.ue_record%type,
	in_user			merchant_upload_error.ue_create_user%type
)
  RETURN NUMBER IS

  iErrId       INTEGER := 0;

BEGIN

  select nvl(max(ue_error_id),0) +1
  into iErrId
  from merchant_upload_error;

  INSERT INTO merchant_upload_error(
	ue_error_id,
	ue_batch_id,
	ue_record,
	ue_create_timestamp,
        ue_update_timestamp,
        ue_create_user,
        ue_update_user
	)

  VALUES(
	iErrId,
	in_batch_id,
	in_record,
	sysdate,
        sysdate,
        in_user,
        in_user
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_merch_upload_error_insert;
/
