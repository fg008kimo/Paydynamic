CREATE OR REPLACE FUNCTION sp_ol_merch_psp_bat_rel_insert(
	in_batch_id		ol_merch_psp_batch_relation.ompbr_batch_id%type,
	in_pair_seq		ol_merch_psp_batch_relation.ompbr_pair_seq%type,
	in_merchant_txn_id	ol_merch_psp_batch_relation.ompbr_merchant_txn_id%type,
	in_baid_txn_id		ol_merch_psp_batch_relation.ompbr_baid_txn_id%type,
	in_create_user		ol_merch_psp_batch_relation.ompbr_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO ol_merch_psp_batch_relation (
		ompbr_batch_id,
		ompbr_pair_seq,
		ompbr_merchant_txn_id,
		ompbr_baid_txn_id,
		ompbr_create_timestamp,
		ompbr_create_user,
		ompbr_update_timestamp,
		ompbr_update_user
		)
	VALUES (
		in_batch_id,
		in_pair_seq,
		in_merchant_txn_id,
		in_baid_txn_id,
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

END sp_ol_merch_psp_bat_rel_insert;
/
