CREATE OR REPLACE FUNCTION sp_txn_card_type_log_insert (
	in_txn_id		IN	txn_card_type_log.tcl_txn_id%TYPE, 
	in_txn_date		IN	txn_card_type_log.tcl_txn_date%TYPE, 
	in_merchant_id		IN	txn_card_type_log.tcl_merchant_id%TYPE, 
	in_service_code		IN	txn_card_type_log.tcl_service_code%TYPE, 
	in_bank_code		IN	txn_card_type_log.tcl_int_bank_code%TYPE, 
	in_psp_id		IN	txn_card_type_log.tcl_psp_id%TYPE, 
	in_card_type		IN	txn_card_type_log.tcl_card_type%TYPE, 
	in_create_user		IN	txn_card_type_log.tcl_create_user%TYPE)
RETURN NUMBER IS
BEGIN
	INSERT INTO txn_card_type_log (
		tcl_txn_id, 
		tcl_txn_date, 
		tcl_merchant_id, 
		tcl_service_code, 
		tcl_int_bank_code, 
		tcl_psp_id, 
		tcl_card_type, 
		tcl_create_user, 
		tcl_update_user)
	VALUES (
		in_txn_id, 
		in_txn_date, 
		in_merchant_id, 
		in_service_code, 
		in_bank_code, 
		in_psp_id, 
		in_card_type, 
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
END sp_txn_card_type_log_insert;
/
