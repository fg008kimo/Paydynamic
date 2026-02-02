CREATE OR REPLACE FUNCTION sp_ol_acct_file_error_insert (
	in_file_id	IN	ol_acct_file_error.afe_file_id%TYPE, 
	in_seq		IN	ol_acct_file_error.afe_seq%TYPE, 
	in_msg_code	IN	ol_acct_file_error.afe_msg_code%TYPE, 
	in_line_content	IN	ol_acct_file_error.afe_line_content%TYPE, 
	in_create_user	IN	ol_acct_file_error.afe_create_user%TYPE)
RETURN NUMBER IS
BEGIN
	INSERT INTO ol_acct_file_error (
		afe_error_id, 
		afe_file_id, 
		afe_seq, 
		afe_msg_code, 
		afe_line_content, 
		afe_create_user, 
		afe_update_user)
	VALUES (
		(SELECT NVL(MAX(afe_error_id), 0) + 1 FROM ol_acct_file_error), 
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
END sp_ol_acct_file_error_insert;
/
