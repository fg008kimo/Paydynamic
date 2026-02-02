CREATE OR REPLACE FUNCTION sp_ol_merch_upload_hd_insert(
	in_batch_id		ol_merchant_upload_file_header.ouh_batch_id%type,
	in_posting_date		ol_merchant_upload_file_header.ouh_posting_date%type,
	in_merchant_id		ol_merchant_upload_file_header.ouh_merchant_id%type,
	in_service_code		ol_merchant_upload_file_header.ouh_service_code%type,
	in_filename		ol_merchant_upload_file_header.ouh_filename%type,
	in_txn_count		ol_merchant_upload_file_header.ouh_txn_count%type,
	in_txn_amt		ol_merchant_upload_file_header.ouh_total_txn_amt%type,
	in_status               ol_merchant_upload_file_header.ouh_status%type,
	in_user			ol_merchant_upload_file_header.ouh_create_user%type
)
  RETURN NUMBER IS

BEGIN
  INSERT INTO ol_merchant_upload_file_header(
	ouh_batch_id,
	ouh_posting_date,
	ouh_merchant_id,
	ouh_service_code,
	ouh_filename,
	ouh_txn_count,
	ouh_total_txn_amt,
	ouh_status,
	ouh_create_timestamp,
        ouh_update_timestamp,
        ouh_create_user,
        ouh_update_user
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

END sp_ol_merch_upload_hd_insert;
/
