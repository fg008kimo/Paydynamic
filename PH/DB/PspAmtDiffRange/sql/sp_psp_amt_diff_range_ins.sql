CREATE OR REPLACE FUNCTION sp_psp_amt_diff_range_ins (
	in_psp_id	IN	psp_amt_diff_range.pr_psp_id%TYPE, 
	in_type		IN	psp_amt_diff_range.pr_type%TYPE, 
	in_sign		IN	psp_amt_diff_range.pr_sign%TYPE, 
	in_value	IN	psp_amt_diff_range.pr_value%TYPE, 
	in_disabled	IN	psp_amt_diff_range.pr_disabled%TYPE, 
	in_create_user	IN	psp_amt_diff_range.pr_create_user%TYPE)
RETURN NUMBER IS
BEGIN
	UPDATE	psp_amt_diff_range 
	SET	pr_type = in_type, 
		pr_sign = in_sign, 
		pr_value = in_value, 
		pr_disabled = in_disabled, 
		pr_update_user = in_create_user, 
		pr_update_timestamp = sysdate 
	WHERE	pr_psp_id = in_psp_id;

	IF SQL%ROWCOUNT = 0 THEN
		INSERT INTO psp_amt_diff_range (
			pr_psp_id, 
			pr_type, 
			pr_sign, 
			pr_value, 
			pr_disabled, 
			pr_create_user, 
			pr_update_user) 
		VALUES (
			in_psp_id, 
			in_type, 
			in_sign, 
			in_value, 
			in_disabled, 
			in_create_user, 
			in_create_user);

		IF SQL%ROWCOUNT = 0 THEN
			RETURN 1;
		ELSE
			RETURN 0;
		END IF;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_psp_amt_diff_range_ins;
/
