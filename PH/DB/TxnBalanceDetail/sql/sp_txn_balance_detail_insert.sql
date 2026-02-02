CREATE OR REPLACE FUNCTION sp_txn_balance_detail_insert (
	in_txn_id			IN	txn_balance_detail.tbd_txn_id%TYPE, 
	in_txn_aprv_date		IN	txn_balance_detail.tbd_txn_aprv_date%TYPE, 
	in_upd_status			IN	txn_balance_detail.tbd_upd_status%TYPE, 
	in_txn_code			IN	txn_balance_detail.tbd_txn_code%TYPE, 
	in_merchant_id			IN	txn_balance_detail.tbd_merchant_id%TYPE, 
	in_service_code			IN	txn_balance_detail.tbd_service_code%TYPE, 
	in_country_id			IN	txn_balance_detail.tbd_country_id%TYPE, 
	in_net_ccy			IN	txn_balance_detail.tbd_net_ccy%TYPE, 
	in_open_bal			IN	txn_balance_detail.tbd_open_bal%TYPE, 
	in_current_bal			IN	txn_balance_detail.tbd_current_bal%TYPE, 
	in_total_float			IN	txn_balance_detail.tbd_total_float%TYPE, 
	in_total_reserved_amount	IN	txn_balance_detail.tbd_total_reserved_amount%TYPE, 
	in_total_hold			IN	txn_balance_detail.tbd_total_hold%TYPE, 
	in_fundin_payout		IN	txn_balance_detail.tbd_fundin_payout%TYPE, 
	in_reserved_payout		IN	txn_balance_detail.tbd_reserved_payout%TYPE, 
	in_total_float_after_payout	IN	txn_balance_detail.tbd_total_float_after_payout%TYPE, 
	in_open_bal_settlement		IN	txn_balance_detail.tbd_open_bal_settlement%TYPE, 
	in_current_bal_settlement 	IN	txn_balance_detail.tbd_current_bal_settlement%TYPE, 
	in_total_float_settlement	IN	txn_balance_detail.tbd_total_float_settlement%TYPE, 
	in_total_hold_settlement	IN	txn_balance_detail.tbd_total_hold_settlement%TYPE, 
	in_psp_id			IN	txn_balance_detail.tbd_psp_id%TYPE, 
	in_psp_ccy			IN	txn_balance_detail.tbd_psp_ccy%TYPE, 
	in_psp_bal			IN	txn_balance_detail.tbd_psp_bal%TYPE, 
	in_psp_total_float		IN	txn_balance_detail.tbd_psp_total_float%TYPE, 
	in_psp_hold			IN	txn_balance_detail.tbd_psp_hold%TYPE, 
	in_create_user			IN	txn_balance_detail.tbd_create_user%TYPE)
RETURN NUMBER IS
BEGIN
	INSERT INTO txn_balance_detail (
		tbd_txn_id, 
		tbd_txn_aprv_date, 
		tbd_upd_status, 
		tbd_txn_code, 
		tbd_merchant_id, 
		tbd_service_code, 
		tbd_country_id, 
		tbd_net_ccy, 
		tbd_open_bal, 
		tbd_current_bal, 
		tbd_total_float, 
		tbd_total_reserved_amount, 
		tbd_total_hold, 
		tbd_fundin_payout, 
		tbd_reserved_payout, 
		tbd_total_float_after_payout, 
		tbd_open_bal_settlement, 
		tbd_current_bal_settlement, 
		tbd_total_float_settlement, 
		tbd_total_hold_settlement, 
		tbd_psp_id, 
		tbd_psp_ccy, 
		tbd_psp_bal, 
		tbd_psp_total_float, 
		tbd_psp_hold, 
		tbd_create_user, 
		tbd_update_user)
	VALUES (
		in_txn_id, 
		in_txn_aprv_date, 
		in_upd_status, 
		in_txn_code, 
		in_merchant_id, 
		in_service_code, 
		in_country_id, 
		in_net_ccy, 
		in_open_bal, 
		in_current_bal, 
		in_total_float, 
		in_total_reserved_amount, 
		in_total_hold, 
		in_fundin_payout, 
		in_reserved_payout, 
		in_total_float_after_payout, 
		in_open_bal_settlement, 
		in_current_bal_settlement, 
		in_total_float_settlement, 
		in_total_hold_settlement, 
		in_psp_id, 
		in_psp_ccy, 
		in_psp_bal, 
		in_psp_total_float, 
		in_psp_hold, 
		in_create_user, 
		in_create_user);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_txn_balance_detail_insert;
/
