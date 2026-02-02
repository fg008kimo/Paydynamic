CREATE OR REPLACE FUNCTION sp_ol_baid_bt_file_detail_ins (
	in_file_id			IN	ol_baid_bt_file_detail.bbd_file_id%TYPE, 
	in_seq				IN	ol_baid_bt_file_detail.bbd_seq%TYPE, 
	in_sender_bank_name		IN	ol_baid_bt_file_detail.bbd_sr_bank_name%TYPE, 
	in_sender_bank_acct_num		IN	ol_baid_bt_file_detail.bbd_sr_bank_acct_num%TYPE, 
	in_sweep_out_amt		IN	ol_baid_bt_file_detail.bbd_sweep_out_amt%TYPE, 
	in_receiver_bank_name		IN	ol_baid_bt_file_detail.bbd_rt_bank_name%TYPE, 
	in_receiver_bank_acct_num	IN	ol_baid_bt_file_detail.bbd_rt_bank_acct_num%TYPE, 
	in_sweep_out_txn_id		IN	ol_baid_bt_file_detail.bbd_sweep_out_txn_id%TYPE, 
	in_sweep_in_txn_id		IN	ol_baid_bt_file_detail.bbd_sweep_in_txn_id%TYPE, 
	in_create_user			IN	ol_baid_bt_file_detail.bbd_create_user%TYPE)
RETURN NUMBER IS
BEGIN
	INSERT INTO ol_baid_bt_file_detail (
		bbd_file_id, 
		bbd_seq, 
		bbd_sr_bank_name, 
		bbd_sr_bank_acct_num, 
		bbd_sweep_out_amt, 
		bbd_rt_bank_name, 
		bbd_rt_bank_acct_num, 
		bbd_sweep_out_txn_id, 
		bbd_sweep_in_txn_id, 
		bbd_create_user, 
		bbd_update_user)
	VALUES (
		in_file_id, 
		in_seq, 
		in_sender_bank_name, 
		in_sender_bank_acct_num, 
		in_sweep_out_amt, 
		in_receiver_bank_name, 
		in_receiver_bank_acct_num, 
		in_sweep_out_txn_id, 
		in_sweep_in_txn_id, 
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
END sp_ol_baid_bt_file_detail_ins;
/
