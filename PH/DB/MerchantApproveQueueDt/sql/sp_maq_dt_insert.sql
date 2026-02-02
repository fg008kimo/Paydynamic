CREATE OR REPLACE FUNCTION sp_maq_dt_insert(
	in_approve_id		merchant_approve_queue_dt.qd_approve_id%type,
	in_batch_id		merchant_approve_queue_dt.qd_batch_id%type,
	in_seq_num		merchant_approve_queue_dt.qd_seq_num%type,
	in_status		merchant_approve_queue_dt.qd_status%type,
	in_add_user		merchant_approve_queue_dt.qd_create_user%type
)
  RETURN NUMBER IS

BEGIN
  INSERT INTO merchant_approve_queue_dt(
	qd_approve_id,
	qd_batch_id,
	qd_seq_num,
	qd_status,
	qd_create_timestamp,
        qd_update_timestamp,
        qd_create_user,
        qd_update_user
	)

  VALUES(
	in_approve_id,
	in_batch_id,
	in_seq_num,
	in_status,
	sysdate,
        sysdate,
        in_add_user,
        in_add_user
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_maq_dt_insert;
/
