DROP FUNCTION sp_ol_psp_settle_detail_insert;

CREATE OR REPLACE FUNCTION sp_ol_psp_settle_detail_insert(
	in_txn_id		ol_psp_settlement_detail.psd_txn_id%type,
	in_merch_type		ol_psp_settlement_detail.psd_merch_type%type,
	in_txn_ccy		ol_psp_settlement_detail.psd_txn_ccy%type,
	in_txn_country		ol_psp_settlement_detail.psd_txn_country%type,
	in_amount		ol_psp_settlement_detail.psd_amount%type,
	in_create_user		ol_psp_settlement_detail.psd_create_user%type
	)
RETURN NUMBER IS

BEGIN
	INSERT INTO ol_psp_settlement_detail(
		psd_txn_id,
		psd_merch_type,
		psd_txn_ccy,
		psd_txn_country,
		psd_amount,
		psd_create_timestamp,
		psd_update_timestamp,
		psd_create_user,
		psd_update_user
	)
	VALUES(
		in_txn_id,
		in_merch_type,
		in_txn_ccy,
		in_txn_country,
		in_amount,
		sysdate,
		sysdate,
		in_create_user,
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
END sp_ol_psp_settle_detail_insert;
/


