CREATE OR REPLACE FUNCTION sp_merch_upload_hd_insert(
	in_batch_id		merchant_upload_file_header.uh_batch_id%type,
	in_posting_date		merchant_upload_file_header.uh_posting_date%type,
	in_merchant_id		merchant_upload_file_header.uh_merchant_id%type,
	in_service_code		merchant_upload_file_header.uh_service_code%type,
	in_filename		merchant_upload_file_header.uh_filename%type,
	in_txn_count		merchant_upload_file_header.uh_txn_count%type,
	in_txn_amt		merchant_upload_file_header.uh_total_txn_amt%type,
	in_status		merchant_upload_file_header.uh_status%type,
	in_user			merchant_upload_file_header.uh_create_user%type
)
  RETURN NUMBER IS

BEGIN
  INSERT INTO merchant_upload_file_header(
	uh_batch_id,
	uh_posting_date,
	uh_merchant_id,
	uh_service_code,
	uh_filename,
	uh_txn_count,
	uh_total_txn_amt,
	uh_status,
	uh_create_timestamp,
        uh_update_timestamp,
        uh_create_user,
        uh_update_user
	)

  VALUES(
	in_batch_id,
	in_posting_date,
	in_merchant_id,
	in_service_code,
	in_filename,
	in_txn_count,
	in_txn_amt,
	in_status,
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

END sp_merch_upload_hd_insert;
/
