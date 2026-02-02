CREATE OR REPLACE FUNCTION sp_payout_header_insert(
	in_batch_id		payout_header.batch_id%type,
	in_txn_date		payout_header.txn_date%type,
	in_merchant_id		payout_header.merchant_id%type,
	in_num_of_record	payout_header.num_of_record%type,
	in_checksum		payout_header.checksum%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO payout_header(
	batch_id,
	txn_date,
	merchant_id,
	num_of_record,
	checksum
	)

  VALUES(
	in_batch_id,
	in_txn_date,
	in_merchant_id,
	in_num_of_record,
	in_checksum
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_payout_header_insert;
/
