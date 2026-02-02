CREATE OR REPLACE FUNCTION sp_ol_baid_bt_file_error_ins (
	in_file_id	IN	ol_baid_bt_file_error.bbe_file_id%TYPE, 
	in_seq		IN	ol_baid_bt_file_error.bbe_seq%TYPE, 
	in_msg_code	IN	ol_baid_bt_file_error.bbe_msg_code%TYPE, 
	in_line_content	IN	ol_baid_bt_file_error.bbe_line_content%TYPE, 
	in_create_user	IN	ol_baid_bt_file_error.bbe_create_user%TYPE)
RETURN NUMBER IS
BEGIN
	INSERT INTO ol_baid_bt_file_error (
		bbe_error_id, 
		bbe_file_id, 
		bbe_seq, 
		bbe_msg_code, 
		bbe_line_content, 
		bbe_create_user, 
		bbe_update_user)
	VALUES (
		OL_BAID_BT_FILE_ERROR_SEQ.NEXTVAL, 
		in_file_id, 
		in_seq, 
		in_msg_code, 
		in_line_content, 
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
END sp_ol_baid_bt_file_error_ins;
/
