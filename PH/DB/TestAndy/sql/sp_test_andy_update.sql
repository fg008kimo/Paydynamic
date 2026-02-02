CREATE OR REPLACE FUNCTION sp_test_andy_update (
	in_bank_code	test_andy.ta_bank_code%type,
	in_type			test_andy.ta_type%type,
	in_support_po	test_andy.ta_support_po%type,
	in_min_amt		test_andy.ta_min_amt%type,
	in_remark		test_andy.ta_remark%type,
	in_update_user	test_andy.ta_update_user%type)
RETURN NUMBER IS
BEGIN
	UPDATE test_andy 
	SET ta_type = in_type,
		ta_support_po = in_support_po,
		ta_min_amt = in_min_amt,
		ta_remark = in_remark,
		ta_update_user = in_update_user,
		ta_update_timestamp = sysdate
	WHERE ta_bank_code = in_bank_code;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_test_andy_update;
/
