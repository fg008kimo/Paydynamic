DROP FUNCTION SP_PSP_DETAIL_INSERT;

CREATE OR REPLACE FUNCTION sp_psp_detail_insert(
	in_psp_id		psp_detail.psp_id%type,
	in_psp_name		psp_detail.psp_name%type,
	in_disabled		psp_detail.disabled%type,
	in_online_mode		psp_detail.online_mode%type,
	in_psp_type		psp_detail.psp_type%type,
	in_create_user		psp_detail.create_user%type,
	in_client_id		psp_detail.client_id%type,
	in_psp_merchant_id	psp_detail.psp_merchant_id%type,
	in_psp_channel_code	psp_detail.psp_channel_code%type,
	in_txn_type		psp_detail.txn_type%type,
	in_ccy			psp_detail.currency_id%type,
	in_status		psp_detail.status%type
	)
  RETURN NUMBER IS

BEGIN
  INSERT INTO psp_detail(
	psp_id,
	psp_name,
	disabled,
	online_mode,
	psp_type,
	create_timestamp,
	create_user,
	update_timestamp,
	update_user,
	client_id,
	psp_merchant_id,
	psp_channel_code,
	txn_type,
	currency_id,
	status
	)

  VALUES(
	in_psp_id,
	in_psp_name,
	in_disabled,
	in_online_mode,
	in_psp_type,
	sysdate,
	in_create_user,
	sysdate,
	in_create_user,
	in_client_id,
	in_psp_merchant_id,
	in_psp_channel_code,
	in_txn_type,
	in_ccy,
	in_status
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_psp_detail_insert;
/


