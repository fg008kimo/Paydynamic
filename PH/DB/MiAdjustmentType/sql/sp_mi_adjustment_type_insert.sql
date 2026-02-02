CREATE OR REPLACE FUNCTION sp_mi_adjustment_type_insert(
	in_entity_type		mi_adjustment_type.mat_entity_type%type,
	in_code			mi_adjustment_type.mat_code%type,
	in_code_in_num		mi_adjustment_type.mat_code_in_num%type,
	in_desc			mi_adjustment_type.mat_desc%type,
	in_amt_type		mi_adjustment_type.mat_amt_type%type,
	in_bal_type		mi_adjustment_type.mat_bal_type%type,
	in_nature		mi_adjustment_type.mat_nature%type,
	in_is_prorata		mi_adjustment_type.mat_is_prorata%type,
	in_disabled		mi_adjustment_type.mat_disabled%type,
	in_create_user		mi_adjustment_type.mat_create_user%type)
  RETURN NUMBEr IS
BEGIN

	INSERT INTO mi_adjustment_type (
		mat_entity_type,
		mat_code,
		mat_code_in_num,
		mat_desc,
		mat_amt_type,
		mat_bal_type,
		mat_nature,
		mat_is_prorata,
		mat_disabled,
		mat_create_timestamp,
		mat_create_user,
		mat_update_timestamp,
		mat_update_user
		)
	VALUES (	
		in_entity_type,
		in_code,
		in_code_in_num,
		in_desc,
		in_amt_type,
		in_bal_type,
		in_nature,
		in_is_prorata,
		in_disabled,
		sysdate,
		in_create_user,
		sysdate,
		in_create_user
		);

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_mi_adjustment_type_insert;
/
