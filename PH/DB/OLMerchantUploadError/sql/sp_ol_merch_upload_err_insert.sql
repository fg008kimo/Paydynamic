CREATE OR REPLACE FUNCTION sp_ol_merch_upload_err_insert(
	in_batch_id		ol_merchant_upload_error.oue_batch_id%type,
	in_record		ol_merchant_upload_error.oue_record%type,
	in_user			ol_merchant_upload_error.oue_create_user%type
)
  RETURN NUMBER IS

  iErrId       INTEGER := 0;

BEGIN

  select nvl(max(oue_error_id),0) +1
  into iErrId
  from ol_merchant_upload_error;

  INSERT INTO ol_merchant_upload_error(
	oue_error_id,
	oue_batch_id,
	oue_record,
	oue_create_timestamp,
        oue_update_timestamp,
        oue_create_user,
        oue_update_user
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

END sp_ol_merch_upload_err_insert;
/
