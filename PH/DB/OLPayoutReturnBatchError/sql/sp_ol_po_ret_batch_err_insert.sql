CREATE OR REPLACE FUNCTION sp_ol_po_ret_batch_err_insert(
	in_batch_id		ol_payout_return_batch_error.pre_batch_id%type,
	in_error_msg		ol_payout_return_batch_error.pre_error_msg%type,
	in_user			ol_payout_return_batch_error.pre_create_user%type
)
  RETURN NUMBER IS

  iErrId       INTEGER := 0;

BEGIN

  select nvl(max(pre_error_id),0) +1
  into iErrId
  from ol_payout_return_batch_error;

  INSERT INTO ol_payout_return_batch_error(
	pre_error_id,
	pre_batch_id,
	pre_error_msg,
	pre_create_timestamp,
        pre_update_timestamp,
        pre_create_user,
        pre_update_user
	)

  VALUES(
	iErrId,
	in_batch_id,
	in_error_msg,
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

END sp_ol_po_ret_batch_err_insert;
/
