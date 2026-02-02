CREATE OR REPLACE FUNCTION sp_test_update_with_get(
	in_key			test_create.tc_key%Type,
	in_field		test_create.tc_field%Type,
	in_ccy			test_create.tc_ccy%Type,
	in_disabled		test_create.tc_disabled%Type,
	in_amount		test_create.tc_amount%Type,
	out_cursor	out	sys_refcursor
)

RETURN NUMBER Is
	v_field		test_create.tc_field%type := NULL;
        v_ccy		test_create.tc_ccy%type := NULL;
        v_disabled	test_create.tc_disabled%type := -1;
        v_amount	test_create.tc_amount%type := -1;
Begin

	update test_create
	set tc_field = in_field,
	    tc_ccy = in_ccy,
	    tc_disabled = in_disabled,
	    tc_amount = tc_amount + in_amount
	where tc_key = in_key
	returning tc_field, tc_ccy, tc_disabled, tc_amount
	into	  v_field, v_ccy, v_disabled, v_amount;

	
	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE

		OPEN out_cursor for
        	select	v_field	   field,
			v_ccy	   ccy,
        		v_disabled disabled,
			v_amount   amount
        	from dual;

		RETURN 0;
	END IF;

exception
 WHEN OTHERS THEN
	RETURN 9;
END sp_test_update_with_get;
/
