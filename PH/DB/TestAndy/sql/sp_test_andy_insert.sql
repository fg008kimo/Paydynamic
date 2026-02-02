CREATE OR REPLACE FUNCTION sp_test_andy_insert (
	in_bank_code            test_andy.ta_bank_code%type,
	in_type	                test_andy.ta_type%type,
	in_support_po           test_andy.ta_support_po%type,
	in_min_amt              test_andy.ta_min_amt%type,
	in_remark               test_andy.ta_remark%type,
	in_create_user          test_andy.ta_create_user%type)
RETURN NUMBER IS
BEGIN
	INSERT INTO test_andy (
		ta_bank_code,
		ta_type,
		ta_support_po,
		ta_min_amt,
		ta_remark,
		ta_create_user,
		ta_update_user) 
	VALUES (
		in_bank_code,
		in_type,
		in_support_po,
		in_min_amt,
		in_remark,
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
END sp_test_andy_insert;
/
