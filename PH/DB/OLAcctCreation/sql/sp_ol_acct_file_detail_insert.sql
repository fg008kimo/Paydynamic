CREATE OR REPLACE FUNCTION sp_ol_acct_file_detail_insert (
	in_file_id		IN	ol_acct_file_detail.afd_file_id%TYPE, 
	in_seq			IN	ol_acct_file_detail.afd_seq%TYPE, 
	in_provider_name	IN	ol_acct_file_detail.afd_provider_name%TYPE, 
	in_provider_id		IN	ol_acct_file_detail.afd_provider_id%TYPE, 
	in_acct_type		IN	ol_acct_file_detail.afd_acct_type%TYPE, 
	in_bank_name		IN	ol_acct_file_detail.afd_bank_name%TYPE, 
	in_int_bank_code	IN	ol_acct_file_detail.afd_int_bank_code%TYPE, 
	in_bank_acct_num	IN	ol_acct_file_detail.afd_bank_acct_num%TYPE, 
	in_bank_acct_short_name	IN	ol_acct_file_detail.afd_bank_acct_short_name%TYPE, 
	in_owner_name		IN	ol_acct_file_detail.afd_owner_name%TYPE, 
	in_province		IN	ol_acct_file_detail.afd_province%TYPE, 
	in_city			IN	ol_acct_file_detail.afd_city%TYPE, 
	in_branch_name		IN	ol_acct_file_detail.afd_branch_name%TYPE, 
	in_init_bal		IN	ol_acct_file_detail.afd_init_bal%TYPE, 
	in_support_sms_stmt	IN	ol_acct_file_detail.afd_support_sms_stmt%TYPE, 
	in_registered_mobile	IN	ol_acct_file_detail.afd_registered_mobile%TYPE, 
	in_apply_deposit_cost	IN	ol_acct_file_detail.afd_apply_deposit_cost%TYPE, 
	in_merchant_short_name 	IN	ol_acct_file_detail.afd_merchant_short_name%TYPE, 
	in_merchant_id		IN	ol_acct_file_detail.afd_merchant_id%TYPE, 
	in_create_user		IN	ol_acct_file_detail.afd_create_user%TYPE)
RETURN NUMBER IS
BEGIN
	INSERT INTO ol_acct_file_detail (
		afd_file_id, 
		afd_seq, 
		afd_provider_name, 
		afd_provider_id, 
		afd_acct_type, 
		afd_bank_name, 
		afd_int_bank_code, 
		afd_bank_acct_num, 
		afd_bank_acct_short_name, 
		afd_owner_name, 
		afd_province, 
		afd_city, 
		afd_branch_name, 
		afd_init_bal, 
		afd_support_sms_stmt, 
		afd_registered_mobile, 
		afd_apply_deposit_cost, 
		afd_merchant_short_name, 
		afd_merchant_id, 
		afd_create_user, 
		afd_update_user)
	VALUES (
		in_file_id, 
		in_seq, 
		in_provider_name, 
		in_provider_id, 
		in_acct_type, 
		in_bank_name, 
		in_int_bank_code, 
		in_bank_acct_num, 
		in_bank_acct_short_name, 
		in_owner_name, 
		in_province, 
		in_city, 
		in_branch_name, 
		in_init_bal, 
		in_support_sms_stmt, 
		in_registered_mobile, 
		in_apply_deposit_cost, 
		in_merchant_short_name, 
		in_merchant_id, 
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
END sp_ol_acct_file_detail_insert;
/
